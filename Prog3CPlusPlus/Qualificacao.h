/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Qualificacao.h
 * Author: rodri
 *
 * Created on 11 de Julho de 2017, 23:37
 */

#ifndef QUALIFICACAO_H
#define QUALIFICACAO_H
#include "Veiculo.h"
namespace model {

    class Qualificacao {
    public:
        Qualificacao(int ano, Veiculo veiculo);
        virtual ~Qualificacao();
    private:
        int ano;
        Veiculo veiculo;
    };
}
#endif /* QUALIFICACAO_H */

