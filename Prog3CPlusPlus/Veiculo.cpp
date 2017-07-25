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

	string Veiculo::getTipo() {
		return this->tipo;
	}

	void Veiculo::setQualificacao(Qualificacao *q) {
		this->qualificacoes.insert(this->qualificacoes.end(), q);
	}

	void Veiculo::setPublicacao(Publicacao* p) {
		this->publicacoes.insert(this->publicacoes.end(), p);
	}

	vector<Qualificacao*> Veiculo::getQualificacoes() {
		return this->qualificacoes;
	}

	string Veiculo::getSigla() {
		return this->sigla;
	}

	string Veiculo::getNome() {
		return this->nome;
	}

	double Veiculo::getFatorDeImpacto() {
		return this->fatorDeImpactor;
	}

	vector<Publicacao*> Veiculo::getPublicacoes() {
		return this->publicacoes;
	}

    Veiculo::~Veiculo() {
    }

}