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
	/*O contrutor de Qualificação recebe o ano, o veiculo associado e o qualis*/
    Qualificacao::Qualificacao(int ano, Veiculo* veiculo, Qualis* quali) {
        this->ano = ano;
        this->veiculo = veiculo;
		this->quali = quali;
    }
	/*O método getQuali retorna o valor do qualis da qualificação*/
	Qualis* Qualificacao::getQuali() {
		return this->quali;
	}
	/*O método getVeiculo retorna o veiculo  da qualificação*/
	Veiculo* Qualificacao::getVeiculo() {
		return this->veiculo;
	}
	int Qualificacao::getAno() {
		return ano;
	}
	/*O destrutor da qualificaçao destroi o objeto Qualificaçao*/
    Qualificacao::~Qualificacao() {
    }

}