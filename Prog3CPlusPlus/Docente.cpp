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
namespace model {

    Docente::Docente(string nome, Date nascimento, Date dataIngresso, bool coordenador, list<Publicacao> publicacoes) {
        this->nome = nome;
        this->nascimento = nascimento;
        this->dataIngresso = dataIngresso;
        this->coordenador = coordenador;
        this->publicacoes = publicacoes;
    }

    Docente::~Docente() {
    }
}
