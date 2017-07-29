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
	/*Construtor default*/
    Veiculo::Veiculo(){
        
    }
	/*O contrutor de Veiculo recebe uma sigla, um nome, um tipo, um fator de impacto e um issn*/
    Veiculo::Veiculo(string sigla, string nome, string tipo, double fatorDeImpacto, string issn){
        this->sigla = sigla;
        this->nome = nome;
		this->tipo = tipo;
        this->fatorDeImpactor = fatorDeImpacto;
        this->issn = issn;
    }
	/*O método getTipo retorna o tipo de Veiculo*/
	string Veiculo::getTipo() {
		return this->tipo;
	}
	/*O método setQualificacao associa uma qualificaçao ao veiculo*/
	void Veiculo::setQualificacao(Qualificacao *q) {
		this->qualificacoes.insert(this->qualificacoes.end(), q);
	}
	/*O método setPublicação associa uma publicaçao a ao veiculo*/
	void Veiculo::setPublicacao(Publicacao* p) {
		this->publicacoes.insert(this->publicacoes.end(), p);
	}
	/*O método getQualificacao retorna uma lista de qualificaçoes asoociada ao veiculo*/
	vector<Qualificacao*> Veiculo::getQualificacoes() {
		return this->qualificacoes;
	}
	/*O método getSigla retorna a sigla do veiculo*/
	string Veiculo::getSigla() {
		return this->sigla;
	}
	/*O método getNome retorna o nome do veiculo*/
	string Veiculo::getNome() {
		return this->nome;
	}
	/*O método getFatorDeImpacto retorna o valor de impacto do veiculo*/
	double Veiculo::getFatorDeImpacto() {
		return this->fatorDeImpactor;
	}
	/*O método getPublicacoes retorna uma lista de publicaçoes associadas ao veiculo*/
	vector<Publicacao*> Veiculo::getPublicacoes() {
		return this->publicacoes;
	}
	/*O destrutor de veiculo destroi o objeto Veiculo*/
    Veiculo::~Veiculo() {
    }

}