/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pontuacao.h
 * Author: rodri
 *
 * Created on 17 de Julho de 2017, 00:35
 */

#ifndef PONTUACAO_H
#define PONTUACAO_H
#include "Qualis.h"
#include <vector>
#include "Regras.h"
namespace model {
    using namespace std;
    class Pontuacao {
    public:
        Pontuacao(int valor, Qualis* quali);
        virtual ~Pontuacao();
		void setValor(int value);
		int getValor();
		Qualis* getQuali();
    private:
        int valor;
        Qualis* quali;
		Regras* regra;
    };
}
#endif /* PONTUACAO_H */

