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

	Publicacao::Publicacao(int ano, string titulo, int pagInicial, int pagFinal, int numero, Veiculo* veiculo, vector<Docente*> autores) {
		this->ano = ano;
		this->titulo = titulo;
		this->pagInicial = pagInicial;
		this->pagFinal = pagFinal;
		this->numero = numero;
		this->veiculo = veiculo;
		for (Docente* d : autores) {
			this->autores.insert(this->autores.end(), d);
		}
	}

	Publicacao::~Publicacao() {
	}

	int Publicacao::getAno() {
		return this->ano;
	}

	double Publicacao::calcularPontos(int ano, Regras* regras) {
		double pontuacao = 0;

		for (Qualificacao *q : this->veiculo->getQualificacoes()) {
			if (regras->getPontuacoesRegraByQuali(q->getQuali()) == NULL) continue;
			if (this->veiculo->getTipo().compare(string("P")) == 0) {
				pontuacao += (regras->getFatorMult() * regras->getPontuacoesRegraByQuali(q->getQuali())->getValor());
			}
			else {
				pontuacao += regras->getPontuacoesRegraByQuali(q->getQuali())->getValor();
			}
		}

		return pontuacao;
	}

	string Publicacao::getTitulo() {
		return this->titulo;
	}

	vector<Docente*> Publicacao::getAutores() {
		return this->autores;
	}

	Veiculo* Publicacao::getVeiculo(){
		return this->veiculo;
	}
}
