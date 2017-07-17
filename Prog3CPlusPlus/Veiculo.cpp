/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Veiculo.cpp
 * Author: rodri
 * 
 * Created on 11 de Julho de 2017, 23:18
 */

#include "Veiculo.h"
namespace model {
    Veiculo::Veiculo(){
        
    }
    Veiculo::Veiculo(string sigla, string nome, string tipo, double fatorDeImpacto, string issn){
        this->sigla = sigla;
        this->nome = nome;
		this->tipo = tipo;
        this->fatorDeImpactor = fatorDeImpacto;
        this->issn = issn;
    }

    Veiculo::~Veiculo() {
    }

}