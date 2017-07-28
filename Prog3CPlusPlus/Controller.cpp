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
#include <iomanip>
#include <cstring>
#include "Controller.h"
Controller::Controller(string d, string v, string p, string q, string r, string a) {
	string qualiVector[8] = { string("A1"), string("A2"), string("B1"), string("B2"), string("B3"), string("B4"), string("B5"), string("C") };
	for (string s : qualiVector) {
		qualis.insert(pair<string, Qualis*>(s, new Qualis(s)));
	}
	readDocentes(d);
	readVeiculos(v);
	readPublicacoes(p);
	readQualificacoes(q);
	readRegras(r);
	anoRecredenciamento = atoi(a.data());
	cout << "Leitura Concluida" << endl;
	WriteRecredenciamento();
	//WriteListaPublicacoes();
	//WriteStatistics();
	//cout << "Escrita Concluida" << endl;
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
		docentes.insert(pair<long long, Docente*>(atoll(token.at(0).data()), new Docente(atoll(token.at(0).data()), token.at(1), parseDate(token.at(2), DATE_FORMAT_PT_BR_SHORT), parseDate(token.at(3), DATE_FORMAT_PT_BR_SHORT), token.at(4).compare("X") == 0 )));
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
			veiculos.insert(pair<string, Veiculo*>(token.at(0), new Veiculo(token.at(0), token.at(1), token.at(2) , parseDouble(token.at(3), LOCALE_PT_BR), token.at(4))));
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
	Publicacao *pObj;

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
		vector<Docente*> autores;
		for (string autor : tokenAutores) {
			if (docentes.count(atoll(autor.data())) == 0) throw CustomException("Código de docente não definido usado na publicação \"" + token.at(2) + "\": " + autor);
			Docente *d1 = docentes.find(atoll(autor.data()))->second;
			autores.insert(autores.end(), d1);
		}
		if (veiculos.count(token.at(1)) == 0) throw CustomException("Sigla de veículo não definida usada na publicação \"" + token.at(2) + "\": " + token.at(1));
		Veiculo *v = veiculos.at(token.at(1));

		if (v->getTipo().compare(string("C")) == 0) {
			pObj =(Publicacao*) new Conferencia(atoi(token.at(0).data()), token.at(2), atoi(token.at(7).data()), atoi(token.at(8).data()), atoi(token.at(4).data()), v, token.at(6), autores);
		}
		else {
			pObj = (Publicacao*)new Periodico(atoi(token.at(0).data()), token.at(2), atoi(token.at(7).data()), atoi(token.at(8).data()), atoi(token.at(4).data()), v, atoi(token.at(5).data()), autores);
		}
			for (Docente *d : autores) {
				d->setPublicacoes(pObj);
			}
			v->setPublicacao(pObj);
			publicacoes.insert(publicacoes.end(), pObj);
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
		Veiculo *v = veiculos.find(token.at(1))->second;
		Qualificacao *q = new Qualificacao(atoi(token.at(0).data()), v, qualis.find(token.at(2))->second);
		v->setQualificacao(q);
		qualis.find(token.at(2))->second->setQualificacao(q);
		qualificacoes.insert(qualificacoes.end(), q);
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
	vector<string> token1;
	vector<Pontuacao*> pontuacoes;

	if (!in.good()) throw CustomException("Erro de I/O");
	getline(in, linha);
	getline(in, linha);
	t = new Tokenizer(linha, tokenDelimit);
	token = t->remaining();
	delete(t);
	for (string &t1 : token) {
		trim(t1);
	}
	t = new Tokenizer(token.at(2), ',');
	token1 = t->remaining();
	delete(t);
	for (string &t1 : token1) {
		trim(t1);
		Pontuacao *p = new Pontuacao(0, qualis.find(t1)->second);
		pontuacoes.insert(pontuacoes.end(), p);
	}
	t = new Tokenizer(token.at(3), ',');
	token1 = t->remaining();
	delete(t);
	for (unsigned int _i = 0; _i < pontuacoes.size(); _i++) {
		token1[_i] = trim(token1[_i]);
		pontuacoes[_i]->setValor(atoi(token1[_i].data()));
	}
	if (!(validDate(token.at(0), DATE_FORMAT_PT_BR_SHORT) && validDate(token.at(1), DATE_FORMAT_PT_BR_SHORT))) throw CustomException("Erro de formatação");
	this->regras = new Regras(atof(token.at(4).data()), parseDate(token.at(0), DATE_FORMAT_PT_BR_SHORT), parseDate(token.at(1), DATE_FORMAT_PT_BR_SHORT), atoi(token.at(5).data()), atoi(token.at(6).data()), pontuacoes);
	in.close();
}

void Controller::WriteRecredenciamento() {

	ofstream out("1-recredenciamento.csv");
	if (!out.good()) throw CustomException("Erro de I/O");
	out << "Docente;Pontuação;Recredenciado?" << endl;

	for (pair<long long, Docente*> d : docentes) {
		double pontuacao = d.second->getPontuacao(anoRecredenciamento, regras);

		if (d.second->isCoordenador()) {
			out << d.second->getNome() << tokenDelimit << pontuacao << tokenDelimit << "Coordenador" << endl;
		}
		else if ((anoRecredenciamento - d.second->getAnoIngresso()) < 3) {
			out << d.second->getNome() << tokenDelimit << pontuacao << "PPJ" << endl;
		}
		else if (d.second->getIdade(anoRecredenciamento) > 60) {
			out << d.second->getNome() << tokenDelimit << pontuacao << tokenDelimit << "PPS" << endl;
		}
		else if (pontuacao >= regras->getPontMin()) {
			out << d.second->getNome() << tokenDelimit << pontuacao << tokenDelimit << "Sim" << endl;
		}
		else {
			out << d.second->getNome() << tokenDelimit << pontuacao << tokenDelimit << "Não" << endl;
		}
	}

	out.close();
}

void Controller::WriteListaPublicacoes() {
	ofstream out("2-publicacoes.csv");
	if (!out.good()) throw CustomException("Erro de I/O");

	sort(publicacoes.begin(), publicacoes.end(), [](Publicacao *p1, Publicacao *p2) {
		return p1->getTitulo().compare(p2->getTitulo());
	});

	sort(publicacoes.begin(), publicacoes.end(), [](Publicacao *p1, Publicacao *p2) {
		return p1->getVeiculo()->getSigla().compare(p2->getVeiculo()->getSigla());
	});

	sort(publicacoes.begin(), publicacoes.end(), [](Publicacao *p1, Publicacao *p2) {
		return p2->getAno() - p1->getAno();
	});

	sort(publicacoes.begin(), publicacoes.end(), [](Publicacao *p1, Publicacao *p2) {
		return p1->getVeiculo()->getQualificacoes().at(0)->getQuali()->getNome().compare(p2->getVeiculo()->getQualificacoes().at(0)->getQuali()->getNome());
	});

	out << "Ano;Sigla Veículo;Veículo;Qualis;Fator de Impacto;Título;Docentes" << endl;
	
	for (Publicacao *p : publicacoes) {
		out << p->getAno() << tokenDelimit << p->getVeiculo()->getSigla() << tokenDelimit << p->getVeiculo()->getNome() <<
			tokenDelimit << p->getVeiculo()->getQualificacoes().at(0)->getQuali()->getNome() << tokenDelimit <<
			p->getVeiculo()->getFatorDeImpacto() << tokenDelimit << p->getTitulo() << tokenDelimit;

		unsigned int tam = 0;
		for (Docente *d : p->getAutores()) {
			out << d->getNome();
			if (tam < (p->getAutores().size() - 1)) {
				out << ',';
			}
		}
		out << endl;
	}

	out.close();
}

void Controller::WriteStatistics() {
	ofstream out("3-estatisticas.csv");
	if (!out.good()) throw CustomException("Erro de I/O");

	out << "Qualis;Qtd. Artigos;Média Artigos / Docentes" << endl;

	for (pair<string, Qualis*> pq : qualis) {
		out << pq.second->getNome() << tokenDelimit << pq.second->getPublicacoes().size() << tokenDelimit <<
			std::setprecision(2) << std::fixed << cpp_util::formatDouble(pq.second->getRatio(), cpp_util::LOCALE_PT_BR)  << endl;
	}
	out.close();
}
