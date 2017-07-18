/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conferencia.cpp
 * Author: rodri
 * 
 * Created on 11 de Julho de 2017, 23:15
 */

#include "Conferencia.h"
namespace model {
    using namespace std;
    Conferencia::Conferencia(int ano, string titulo, int pagInicial, int pagFinal, int numero, Veiculo veiculo, string local, vector<Docente> autores):
    Publicacao::Publicacao(ano, titulo, pagInicial, pagFinal, numero, veiculo, autores)
    {
        this->local = local;
    }

    Conferencia::~Conferencia() {
    }
}
