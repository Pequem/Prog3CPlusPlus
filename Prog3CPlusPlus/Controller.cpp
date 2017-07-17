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
    readDocentes(d);
	readVeiculos(v);
}

Controller::~Controller() {
}

void Controller::readDocentes(string d){
    using namespace cpp_util;
	using namespace std;
    ifstream dIn(d);
    string linha;
    Tokenizer *t;
    vector<string> token;
    
    if(!dIn.good()) throw CustomException("Erro de I/O");
    getline(dIn, linha);
    
    while(getline(dIn, linha)){
        t = new Tokenizer(linha, tokenDelimit);
        token = t->remaining();
		if (docentes.count(atol(token.at(0).data()) > 0)) throw CustomException("Código repetido para docente: " + atol(token.at(4).data()));
		if (!(validDate(token.at(2), DATE_FORMAT_PT_BR_SHORT) && validDate(token.at(3), DATE_FORMAT_PT_BR_SHORT))) throw CustomException("Erro de formatação");
		docentes.insert(pair<long, Docente>(atol(token.at(0).data()), Docente(atol(token.at(0).data()), token.at(1), parseDate(token.at(2), DATE_FORMAT_PT_BR_SHORT), parseDate(token.at(3), DATE_FORMAT_PT_BR_SHORT), token.at(4).compare("X") == 0 )));
		delete(t);
    }
}

void Controller::readVeiculos(string v) {
	using namespace cpp_util;
	using namespace std;
	ifstream dIn(v);
	string linha;
	Tokenizer *t;
	vector<string> token;

	if (!dIn.good()) throw CustomException("Erro de I/O");
	getline(dIn, linha);

	while (getline(dIn, linha)) {
		t = new Tokenizer(linha, tokenDelimit);
		token = t->remaining();
		if (veiculos.count(token.at(0)) > 0) throw CustomException("Código repetido para veículo: " + token.at(0));
		if ((token.at(2).compare("C") == 0) || (token.at(2).compare("P") == 0)) {
			veiculos.insert(pair<string, Veiculo>(token.at(0), Veiculo(token.at(0), token.at(1), token.at(2) , parseDouble(token.at(3), LOCALE_PT_BR), token.at(4))));
		}else {
			throw CustomException("Tipo de veículo desconhecido para veículo " + token.at(0) + ": " + token.at(2));
		}
		delete(t);
	}
	return;
}

