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
#include <iostream>
namespace model {
	/*O construtor de docente recebe o codigo, nome, data de nascimento, data de ingresso como parametro e se é ou nao um
coordenador*/
	Docente::Docente(long long cod,  string nome, time_t nascimento, time_t dataIngresso, bool coordenador) {
		this->cod = cod;
		this->nome = nome;
        this->nascimento = nascimento;
        this->dataIngresso = dataIngresso;
        this->coordenador = coordenador;
    }
/*O método getPontuaçao verifica o numeros de publicaçoes do docente para calcular a sua pontuação, se maior que zero, será verificado quais anos devem ser considerados de acordo com as regras e roda uma lista de publicaçoes somando de acordo*/
	double Docente::getPontuacao(int anoRecredenciamento, Regras* regras) {
		double pontuacao = 0;
		if (publicacoes.size() > 0) {
			int anoInicio = anoRecredenciamento - regras->getQtdAnos();
			for(Publicacao *p: publicacoes){
				if ((p->getAno() >= anoInicio) && (p->getAno() < anoRecredenciamento)) {
					pontuacao += p->calcularPontos(anoRecredenciamento, regras);
				}
			}
		}
		return pontuacao;
	}
/*O método setPublicacoes coloca uma devida publicaçao ao docente referido*/
	void Docente::setPublicacoes(Publicacao *p) {
		this->publicacoes.insert(this->publicacoes.end(), p);
	}
	/*Verifica se é ou nao coordenador*/
	bool Docente::isCoordenador() {
		return this->coordenador;
	}
/*O método getNome retorna o nome do docente*/
	string Docente::getNome() {
		return nome;
	}
/*O método getAnoIngresso retorna o ano de ingresso do docente */
	int Docente::getAnoIngresso() {
		struct tm *tempo;
		tempo = localtime(&this->dataIngresso);
		
		return(tempo->tm_year + 1900);
	}
/*O método getIdade retorna a idade do docente*/
	int Docente::getIdade(int anoAtual) {
		struct tm *tempo;
		tempo = localtime(&this->nascimento);
	
		return (anoAtual - (tempo->tm_year + 1900));
	}
/*O destrutor de Docente destroi o Objeto Docente*/
    Docente::~Docente() {
    }
}
