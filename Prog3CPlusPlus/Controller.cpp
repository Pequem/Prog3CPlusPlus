/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Controller.cpp
 * Author: rodri
 * 
 * Created on 17 de Julho de 2017, 01:52
 */

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cstring>
#include "Controller.h"
Controller::Controller(string d, string v, string p, string q, string r, string a) {
	string qualiVector[8] = { string("A1"), string("A2"), string("B1"), string("B2"), string("B3"), string("B4"), string("B5"), string("C") };
	for (string s : qualiVector) {
		qualis.insert(pair<string, Qualis>(s, Qualis(s)));
	}
	readDocentes(d);
	readVeiculos(v);
	readPublicacoes(p);
	readQualificacoes(q);
	readRegras(r);
	anoRecredenciamento = atoi(a.data());
	cout << "Leitura Comcluida" << endl;
}

Controller::~Controller() {
	for (Publicacao *p : publicacoes) {
		delete(p);
	}
}

void Controller::readDocentes(string d){
    using namespace cpp_util;
	using namespace std;
    ifstream in(d);
    string linha;
    Tokenizer *t;
    vector<string> token;
    
    if(!in.good()) throw CustomException("Erro de I/O");
    getline(in, linha);
    
    while(getline(in, linha)){
        t = new Tokenizer(linha, tokenDelimit);
        token = t->remaining();
		delete(t);
		for (string &t1: token) {
			trim(t1);
		}
		if (docentes.count(atoll(token.at(0).data()) > 0)) throw CustomException("Código repetido para docente: " + atoll(token.at(4).data()));
		if (!(validDate(token.at(2), DATE_FORMAT_PT_BR_SHORT) && validDate(token.at(3), DATE_FORMAT_PT_BR_SHORT))) throw CustomException("Erro de formatação");
		docentes.insert(pair<long long, Docente>(atoll(token.at(0).data()), Docente(atoll(token.at(0).data()), token.at(1), parseDate(token.at(2), DATE_FORMAT_PT_BR_SHORT), parseDate(token.at(3), DATE_FORMAT_PT_BR_SHORT), token.at(4).compare("X") == 0 )));
    }
	in.close();
}

void Controller::readVeiculos(string v) {
	using namespace cpp_util;
	using namespace std;
	ifstream in(v);
	string linha;
	Tokenizer *t;
	vector<string> token;

	if (!in.good()) throw CustomException("Erro de I/O");
	getline(in, linha);

	while (getline(in, linha)) {
		t = new Tokenizer(linha, tokenDelimit);
		token = t->remaining();
		delete(t);
		for (string &t1 : token) {
			trim(t1);
		}
		if (veiculos.count(token.at(0)) > 0) throw CustomException("Código repetido para veículo: " + token.at(0));
		if ((token.at(2).compare("C") == 0) || (token.at(2).compare("P") == 0)) {
			veiculos.insert(pair<string, Veiculo>(token.at(0), Veiculo(token.at(0), token.at(1), token.at(2) , parseDouble(token.at(3), LOCALE_PT_BR), token.at(4))));
		}else {
			throw CustomException("Tipo de veículo desconhecido para veículo " + token.at(0) + ": " + token.at(2));
		}
	}
	in.close();
}

void Controller::readPublicacoes(string p) {
	using namespace std;
	using namespace cpp_util;
	string linha;
	ifstream in(p);
	Tokenizer *t;
	vector<string> token, tokenAutores;

	if (!in.good()) throw CustomException("Erro de I/O");
	getline(in, linha);

	while (getline(in, linha)) {
		t = new Tokenizer(linha, tokenDelimit);
		token = t->remaining();
		delete(t);
		for (string &t1 : token) {
			trim(t1);
		}
		t = new Tokenizer(token.at(3), ',');
		tokenAutores = t->remaining();
		delete(t);
		for (string &t1 : tokenAutores) {
			trim(t1);
		}
		vector<Docente> autores;
		for (string autor : tokenAutores) {
			if (docentes.count(atoll(autor.data())) == 0) throw CustomException("Código de docente não definido usado na publicação \"" + token.at(2) + "\": " + autor);
			Docente d1 = docentes.find(atoll(autor.data()))->second;
			autores.insert(autores.end(), d1);
		}
		if (veiculos.count(token.at(1)) == 0) throw CustomException("Sigla de veículo não definida usada na publicação \"" + token.at(2) + "\": " + token.at(1));
		Veiculo v = veiculos.at(token.at(1));

		if (v.getTipo().compare(string("C")) == 0) {
			publicacoes.insert(publicacoes.end(), (Publicacao*)new Conferencia(atoi(token.at(0).data()), token.at(2), atoi(token.at(7).data()), atoi(token.at(8).data()), atoi(token.at(4).data()), v, token.at(6), autores));
		}
		else {
			publicacoes.insert(publicacoes.end(), (Publicacao*)new Periodico(atoi(token.at(0).data()), token.at(2), atoi(token.at(7).data()), atoi(token.at(8).data()), atoi(token.at(4).data()), v, atoi(token.at(5).data()), autores));
		}
	}
	in.close();
}
void Controller::readQualificacoes(string q) {
	using namespace std;
	using namespace cpp_util;
	string linha;
	ifstream in(q);
	Tokenizer *t;
	vector<string> token;

	if (!in.good()) throw CustomException("Erro de I/O");
	getline(in, linha);

	while (getline(in, linha)) {
		t = new Tokenizer(linha, tokenDelimit);
		token = t->remaining();
		delete(t);
		for (string &t1 : token) {
			trim(t1);
		}
		if (qualis.count(token.at(2)) == 0) throw CustomException("Qualis desconhecido para qualificação do veículo " + token.at(1) + " no ano " + token.at(0) + ": " + token.at(2));
		if (veiculos.count(token.at(1)) == 0) throw CustomException("Sigla de veículo não definida usada na qualificação do ano \"" + token.at(0) + "\": " + token.at(1));
		qualificacoes.insert(qualificacoes.end(), Qualificacao(atoi(token.at(0).data()), veiculos.find(token.at(1))->second , qualis.find(token.at(2))->second));
	}
	in.close();
}

void Controller::readRegras(string r) {
	using namespace std;
	using namespace cpp_util;
	string linha;
	ifstream in(r);
	Tokenizer *t;
	vector<string> token;

	if (!in.good()) throw CustomException("Erro de I/O");
	getline(in, linha);

	while (getline(in, linha)) {
		t = new Tokenizer(linha, tokenDelimit);
		token = t->remaining();
		delete(t);
		for (string &t1 : token) {
			trim(t1);
		}
		if (!(validDate(token.at(0), DATE_FORMAT_PT_BR_SHORT) && validDate(token.at(1), DATE_FORMAT_PT_BR_SHORT))) throw CustomException("Erro de formatação");
		//regras.insert(regras.end(), Regras();
	}
	in.close();
}

void Controller::WriteRecredenciamento(){

	//faz uma copia de docentes para docentesOrdem

	ofstream out("recredenciamento.csv");
	if (!out.good) throw CustomException("Erro de I/O");
	out << "Docente;Pontuação;Recredenciado?" << endl;

	for (pair<long long, Docente> d : docentes) {
		double pontuacao = d.second.getPontuacao(anoRecredenciamento, regras);
		//terminar

	}

	out.close();
	/*
		for (Map.Entry<Long, Docente> entry : mapDocentesOrdenado.entrySet()) {

			SimpleDateFormat sdf = new SimpleDateFormat("yyyy");
			Calendar cal = Calendar.getInstance();
			cal.setTime(entry.getValue().getNascimento());
			int yearBirth = cal.get(Calendar.YEAR);
			int AnoIngresso = Integer.parseInt(sdf.format(entry.getValue().getIngresso()));
			int subAno = anoCredenciamento - AnoIngresso;
			int idade = anoCredenciamento - yearBirth;
			String sPonto = String.format("%.1f", pontuacao);

			//Escrita linha por linha segundo regras 
			if (entry.getValue().isCoordenador() == true) {
				fileWriter.append(entry.getValue().getNome());
				fileWriter.append(csvSplitBy);
				fileWriter.append(sPonto);
				fileWriter.append(csvSplitBy);
				fileWriter.append("Coordenador");
				fileWriter.append("\n");

			}
			else if (subAno < 3) {
				fileWriter.append(entry.getValue().getNome());
				fileWriter.append(csvSplitBy);
				fileWriter.append(sPonto);
				fileWriter.append(csvSplitBy);
				fileWriter.append("PPJ");
				fileWriter.append("\n");

			}
			else if (idade > 60) {
				fileWriter.append(entry.getValue().getNome());
				fileWriter.append(csvSplitBy);
				fileWriter.append(sPonto);
				fileWriter.append(csvSplitBy);
				fileWriter.append("PPS");
				fileWriter.append("\n");

			}
			else if (pontuacao >= regras.getPontuacaoMin()) {
				fileWriter.append(entry.getValue().getNome());
				fileWriter.append(csvSplitBy);
				fileWriter.append(sPonto);
				fileWriter.append(csvSplitBy);
				fileWriter.append("Sim");
				fileWriter.append("\n");

			}
			else {
				fileWriter.append(entry.getValue().getNome());
				fileWriter.append(csvSplitBy);
				fileWriter.append(sPonto);
				fileWriter.append(csvSplitBy);
				fileWriter.append("Não");
				fileWriter.append("\n");

			}

		}

	}
	catch (IOException e) {
		throw new CustomException("Erro de I/O");
	}
	finally {
		try {
			fileWriter.close();
		}
		catch (IOException e) {
			throw new CustomException("Erro de I/O");
		}
	}
	*/
}

public void WriteListaPublicacoes() throws CustomException {

	publicacoes.sort((Publicacao p1, Publicacao p2)->p1.getTitulo().compareTo(p2.getTitulo()));

	publicacoes.sort((Publicacao p1, Publicacao p2)->p1.getVeiculo().getSigla().compareTo(p2.getVeiculo().getSigla()));

	publicacoes.sort((Publicacao p1, Publicacao p2)->p2.getAno() - p1.getAno());

	publicacoes.sort((Publicacao p1, Publicacao p2)->p1.getVeiculo().getQualificacoesVeiculo().get(0).getQualis().compareTo(p2.getVeiculo().getQualificacoesVeiculo().get(0).getQualis()));
	try (FileWriter fw = new FileWriter("2-publicacoes.csv")) {
		fw.append("Ano" + csvSplitBy + "Sigla Veículo" + csvSplitBy + "Veículo"
			+ csvSplitBy + "Qualis" + csvSplitBy + "Fator de Impacto" + csvSplitBy
			+ "Título" + csvSplitBy + "Docentes\n");

		for (Publicacao p : publicacoes) {
			String fatorImp = String.format("%.3f", p.getVeiculo().getFatorDeImpacto());
			fw.append(p.getAno() + csvSplitBy + p.getVeiculo().getSigla() + csvSplitBy
				+ p.getVeiculo().getNome() + csvSplitBy + p.getVeiculo().getQualificacoesVeiculo().get(0).getQualis()
				+ csvSplitBy + fatorImp + csvSplitBy + p.getTitulo() + csvSplitBy);

			int tamanho = 0;
			for (Docente d : p.getAutores()) {

				fw.append(d.getNome());
				if (tamanho < (p.getAutores().size() - 1)) {
					fw.append(",");
				}
				tamanho++;

			}
			fw.append("\n");
		}
	}
	catch (IOException ex) {
		throw new CustomException("Erro de I/O");
	}
}

public void WriteStatistics() throws CustomException {
	ArrayList<Publicacao> pArray;

	double ratio;
	try (FileWriter fw = new FileWriter("3-estatisticas.csv")) {

		fw.append("Qualis" + csvSplitBy + "Qtd. Artigos" + csvSplitBy + "Média Artigos / Docente\n");

		for (Qualis q : Qualis.values()) {

			pArray = publicacoes.get(0).getAllByQualis(q, publicacoes);
			ratio = publicacoes.get(0).getRatioByQualis(q, publicacoes);
			String mediaArtigosPorDocente = String.format("%.2f", ratio);
			fw.append(q.getNome() + csvSplitBy + pArray.size() + csvSplitBy + mediaArtigosPorDocente + "\n");

		}

	}
	catch (IOException ex) {
		throw new CustomException("Erro de I/O");
	}
}
