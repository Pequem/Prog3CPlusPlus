/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Regras.cpp
 * Author: rodri
 * 
 * Created on 17 de Julho de 2017, 00:39
 */

#include "Regras.h"
namespace model {

	Regras::Regras(double fatorMult, time_t dataInicio, time_t dataFim, int qtAnos, int pontMin, vector<Pontuacao*> pontuacoesRegras) {
		this->fatorMult = fatorMult;
		this->dataInicio = dataInicio;
		this->dataFim = dataFim;
		this->qtdAnos = qtAnos;
		this->pontMin = pontMin;
		for (Pontuacao* p : pontuacoesRegras) {
			this->pontuacoesRegras.insert(this->pontuacoesRegras.end(), p);
		}
	}

    Regras::~Regras() {
    }

	double Regras::getFatorMult() {
		return this->fatorMult;
	}

	Pontuacao* Regras::getPontuacoesRegraByQuali(Qualis *q) {
		for (Pontuacao *p : this->pontuacoesRegras) {
			if (p->getQuali()->getNome().compare(q->getNome()) == 0) {
				return p;
			}
		}
	}

	int Regras::getPontMin() {
		return this->pontMin;
	}

	int Regras::getQtdAnos(){ 
		return qtdAnos; 
	}
}
