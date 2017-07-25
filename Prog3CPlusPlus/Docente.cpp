/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Docente.cpp
 * Author: rodri
 * 
 * Created on 11 de Julho de 2017, 23:39
 */

#include "Docente.h"
#include "Publicacao.h"
#include <ctime>
namespace model {

	Docente::Docente(long long cod,  string nome, time_t nascimento, time_t dataIngresso, bool coordenador) {
		this->cod = cod;
		this->nome = nome;
        this->nascimento = nascimento;
        this->dataIngresso = dataIngresso;
        this->coordenador = coordenador;
    }

	double Docente::getPontuacao(int anoRecredenciamento, Regras* regras) {
		double pontuacao = 0;
		if (publicacoes.size() > 0) {
			int anoInicio = anoRecredenciamento - regras->getQtdAnos();
			for(Publicacao *p: publicacoes){
				if (p->getAno() >= anoInicio && p->getAno() < anoRecredenciamento) {
					pontuacao += p->calcularPontos(anoRecredenciamento, regras);
				}
			}
		}
		return pontuacao;
	}

	void Docente::setPublicacoes(Publicacao *p) {
		this->publicacoes.insert(this->publicacoes.end(), p);
	}
	
	bool Docente::isCoordenador() {
		return this->coordenador;
	}

	string Docente::getNome() {
		return nome;
	}

	int Docente::getAnoIngresso() {
		struct tm *tempo;
		tempo = localtime(&this->dataIngresso);
		return tempo->tm_year;
	}

	int Docente::getIdade(int anoAtual) {
		struct tm *tempo;
		tempo = localtime(&this->nascimento);
		return anoAtual - tempo->tm_year;
	}

    Docente::~Docente() {
    }
}
