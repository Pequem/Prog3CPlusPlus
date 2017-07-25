/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pontuacao.cpp
 * Author: rodri
 * 
 * Created on 17 de Julho de 2017, 00:35
 */

#include "Pontuacao.h"

namespace model {

    Pontuacao::Pontuacao(int valor, Qualis* quali) {
        this->valor = valor;
        this->quali= quali;
    }

    Pontuacao::~Pontuacao() {
    }

	Qualis* Pontuacao::getQuali() {
		return this->quali;
	}

	int Pontuacao::getValor() {
		return this->valor;
	}

	void Pontuacao::setValor(int value) {
		this->valor = value;
	}
}
