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
	readQualis(q);
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
		if (docentes.count(atoll(token.at(0).data()) > 0)) throw CustomException("Código repetido para docente: " + atoll(token.at(4).data()));
		if (!(validDate(token.at(2), DATE_FORMAT_PT_BR_SHORT) && validDate(token.at(3), DATE_FORMAT_PT_BR_SHORT))) throw CustomException("Erro de formatação");
		docentes.insert(pair<long long, Docente>(atoll(token.at(0).data()), Docente(atoll(token.at(0).data()), token.at(1), parseDate(token.at(2), DATE_FORMAT_PT_BR_SHORT), parseDate(token.at(3), DATE_FORMAT_PT_BR_SHORT), token.at(4).compare("X") == 0 )));
    }
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
		if (veiculos.count(token.at(0)) > 0) throw CustomException("Código repetido para veículo: " + token.at(0));
		if ((token.at(2).compare("C") == 0) || (token.at(2).compare("P") == 0)) {
			veiculos.insert(pair<string, Veiculo>(token.at(0), Veiculo(token.at(0), token.at(1), token.at(2) , parseDouble(token.at(3), LOCALE_PT_BR), token.at(4))));
		}else {
			throw CustomException("Tipo de veículo desconhecido para veículo " + token.at(0) + ": " + token.at(2));
		}
	}
	return;
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
		t = new Tokenizer(token.at(3), ',');
		tokenAutores = t->remaining();
		delete(t);
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
}
void Controller::readQualis(string q) {
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
	}
}

