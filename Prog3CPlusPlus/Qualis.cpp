/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Qualis.cpp
 * Author: rodri
 * 
 * Created on 17 de Julho de 2017, 00:32
 */

#include "Qualis.h"

namespace model {
	Qualis::Qualis() {

	}

    Qualis::Qualis(string nome) {
		this->nome = nome;
	}

	string Qualis::getNome() {
		return this->nome;
	}

	void Qualis::setQualificacao(Qualificacao *q) {
		this->qualificacoes.insert(this->qualificacoes.end(), q);
	}

	vector<Publicacao*> Qualis::getPublicacoes() {
		vector<Publicacao*> publicacoes;
		
		for (Qualificacao *q: qualificacoes) {
			for (Publicacao *p: q->getVeiculo()->getPublicacoes()) {
				publicacoes.insert(publicacoes.end(), p);
			}
		}
		return publicacoes;
	}

	double Qualis::getRatio() {
		double soma = 0;
		for (Publicacao *p : getPublicacoes()) {
			soma += 1.0 / p->getAutores().size();
		}
		return soma;
	}

    Qualis::~Qualis() {
    }
}