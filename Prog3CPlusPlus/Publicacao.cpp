/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Publicacao.cpp
 * Author: rodri
 * 
 * Created on 11 de Julho de 2017, 23:16
 */

#include "Publicacao.h"

namespace model {

    Publicacao::Publicacao(int ano, string titulo, int pagInicial, int pagFinal, int numero, Veiculo veiculo, vector<Docente> autores) {
        this->ano = ano;
        this->titulo = titulo;
        this->pagInicial = pagInicial;
        this->pagFinal = pagFinal;
        this->numero = numero;
        this->veiculo = veiculo;
		for (Docente d : autores) {
			this->autores.insert(this->autores.end(), d);
		}
    }

    Publicacao::~Publicacao() {
    }
}
