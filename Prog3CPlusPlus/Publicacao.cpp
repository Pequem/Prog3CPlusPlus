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
	/*O contrustor de Publicação recebe como parametros, ano, titulo, paginas inicial e final, numero, veiculo em que se encontra e 
	lista de docentes que são os autores*/
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
	/*O destrutor de Publicação destroi o objeto Publicação*/
	Publicacao::~Publicacao() {
	}
	/*O método getAno retorna o valor do ano da publicação*/
	int Publicacao::getAno() {
		return this->ano;
	}
	/*O método calcularPontos calcula os pontos da publicaçao aplicando um fator multiplicador dependendo do seu tipo e seguindo determinadas
	regras dependendo do ano*/
	double Publicacao::calcularPontos(int ano, Regras* regras) {
		double pontuacao = 0.0;

		for (Qualificacao *q : this->veiculo->getQualificacoes()) {
			if (regras->getPontuacoesRegraByQuali(q->getQuali()) == NULL) continue;
			if (this->veiculo->getTipo().compare(string("P")) == 0) {
				pontuacao += (regras->getFatorMult() * (regras->getPontuacoesRegraByQuali(q->getQuali())->getValor()));
			}
			else if (this->veiculo->getTipo().compare(string("C")) == 0){
				pontuacao += regras->getPontuacoesRegraByQuali(q->getQuali())->getValor();
			}
		}

		return pontuacao;
	}
	/*O método getTitulo retorna o titulo da publicação */
	string Publicacao::getTitulo() {
		return this->titulo;
	}
	/*O método getAutores retorna a lista de docentes da publicação */
	vector<Docente*> Publicacao::getAutores() {
		return this->autores;
	}
	/*O método getVeiculo retorna o veiculo da publicação */
	Veiculo* Publicacao::getVeiculo(){
		return this->veiculo;
	}
}
