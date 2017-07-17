/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Publicacao.h
 * Author: rodri
 *
 * Created on 11 de Julho de 2017, 23:16
 */

#ifndef PUBLICACAO_H
#define PUBLICACAO_H
#include <string>
#include "Veiculo.h"
namespace model {
    using namespace std;

    class Publicacao {
    public:
        Publicacao(int ano, string titulo, int pagInicial, int pagFinal, int numero, Veiculo veiculo);
        virtual ~Publicacao();
    private:
        int ano;
        string titulo;
        int pagInicial;
        int pagFinal;
        int numero;
        Veiculo veiculo;
    };
}
#endif /* PUBLICACAO_H */

