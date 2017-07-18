/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Qualificacao.cpp
 * Author: rodri
 * 
 * Created on 11 de Julho de 2017, 23:37
 */

#include "Qualificacao.h"
namespace model {

    Qualificacao::Qualificacao(int ano, Veiculo veiculo, Qualis quali) {
        this->ano = ano;
        this->veiculo = veiculo;
		this->quali = quali;
    }

    Qualificacao::~Qualificacao() {
    }

}