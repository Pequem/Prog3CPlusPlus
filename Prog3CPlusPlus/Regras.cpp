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
	/*O contrutor de Regras recebe um fator multiplicador, uma data de inicio e uma data de fim,  quantos anos deve ser considerado
	uma pontuação minima, uma lista de pontuações*/
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
	/*O destrutor de Regras destroi o objeto Regras*/
    Regras::~Regras() {
    }
	/*O método getFatorMult retorna o valor do fator multiplicador*/
	double Regras::getFatorMult() {
		return this->fatorMult;
	}
	/*O método getPontuacoesRegraByQuali retorna a pontuação de acordo com o qualis*/
	Pontuacao* Regras::getPontuacoesRegraByQuali(Qualis *q) {
		for (Pontuacao *p : this->pontuacoesRegras) {
			if (p->getQuali()->getNome().compare(q->getNome()) == 0) {
				return p;
			}
		}
	}
	/*O método getPontMin retorna o valor da pontuação minima*/
	int Regras::getPontMin() {
		return this->pontMin;
	}
	/*O método getQtdAnos retorna o valor da quantidade de anos que deve ser considerada para essa regra*/
	int Regras::getQtdAnos(){ 
		return qtdAnos; 
	}
}
