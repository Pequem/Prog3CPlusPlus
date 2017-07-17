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
#include <exception>
#include "Controller.h"
#include "Tokenizer.h"
#include "DateUtils.h"
#include <ctime>
#include <string>
#include <cstring>
Controller::Controller(string d, string v, string p, string q, string r, string a) {
    readDocentes(d);
    
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
    
    if(!dIn.good()) throw exception();
    getline(dIn, linha);
    
    while(getline(dIn, linha)){
        t = new Tokenizer(linha, tokenDelimit);
        token = t->remaining();

		docentes.insert(docentes.end(), Docente(atoi(token.at(0).data()), token.at(1), parseDate(token.at(2), string("dd/mm/aa")), parseDate(token.at(3), string("dd/mm/aa")), token.at(4).compare("x") == 0 ));
		delete(t);
    }
}

