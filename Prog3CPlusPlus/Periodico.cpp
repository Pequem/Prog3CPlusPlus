/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Periodico.cpp
 * Author: rodri
 * 
 * Created on 11 de Julho de 2017, 23:27
 */

#include "Periodico.h"
namespace model {

    Periodico::Periodico(int ano, string titulo, int pagInicial, int pagFinal, int numero, Veiculo veiculo, int volume):
    Publicacao(ano, titulo, pagInicial, pagFinal, numero, veiculo){
        this->volume = volume;
    }

    Periodico::~Periodico() {
    }
}
