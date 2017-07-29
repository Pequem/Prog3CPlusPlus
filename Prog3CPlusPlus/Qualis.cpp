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
	/*construtor default*/
	Qualis::Qualis() {

	}
	/*O construtor de Qualis recebe o nome do qualis que segue só pode ser alguns valor (A1-C1)*/
    Qualis::Qualis(string nome) {
		this->nome = nome;
	}
	/*O método getNome retorna o nome do qualis*/
	string Qualis::getNome() {
		return this->nome;
	}
	/*O método setQualificacao associa a qualificaçao ao Qualis*/
	void Qualis::setQualificacao(Qualificacao *q) {
		this->qualificacoes.insert(this->qualificacoes.end(), q);
	}
	/*O método getPublicacoes retorna as publicaçoes com determinada qualificação*/
	vector<Publicacao*> Qualis::getPublicacoes() {
		vector<Publicacao*> publicacoes;
		
		for (Qualificacao *q: qualificacoes) {
			for (Publicacao *p: q->getVeiculo()->getPublicacoes()) {
				publicacoes.insert(publicacoes.end(), p);
			}
		}
		return publicacoes;
	}
	/*O metodo getRatio retorna a razão de qualis por numero de autores*/
	double Qualis::getRatio() {
		double soma = 0;
		for (Publicacao *p : getPublicacoes()) {
			soma += 1.0 / p->getAutores().size();
		}
		return soma;
	}
	/*O destrutor do Qualis destroi o objeto Qualis*/
    Qualis::~Qualis() {
    }
}