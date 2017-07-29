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
	/*O contrutor de Pontuação recebe um valor e um qualis que será associado*/
    Pontuacao::Pontuacao(int valor, Qualis* quali) {
        this->valor = valor;
        this->quali= quali;
    }
	/*O destrutor de pontuação destroi o objeto Pontuação*/
    Pontuacao::~Pontuacao() {
    }
	/*O método getQuali retorna o valor do qualis*/
	Qualis* Pontuacao::getQuali() {
		return this->quali;
	}
	/*O método getValor retorna o valor da pontuação */
	int Pontuacao::getValor() {
		return this->valor;
	}
	/*O método setValor associa o valor decebido por parametro ao valor da pontuação*/
	void Pontuacao::setValor(int value) {
		this->valor = value;
	}
}
