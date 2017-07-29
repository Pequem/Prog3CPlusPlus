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
    /*O construtor de Periodico (que é uma publicação) recebe o ano, o titulo, as paginas inical e final, o veiculo onde se encontra, o volume
    uma lista de docentes que sao os autores */
    Periodico::Periodico(int ano, string titulo, int pagInicial, int pagFinal, int numero, Veiculo* veiculo, int volume, vector<Docente*> autores):
    Publicacao(ano, titulo, pagInicial, pagFinal, numero, veiculo, autores){
        this->volume = volume;
    }
    /* O destrutor de Periodico destroi o objeto Periodico*/
    Periodico::~Periodico() {
    }
}
