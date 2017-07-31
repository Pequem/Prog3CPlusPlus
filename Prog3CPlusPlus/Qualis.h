/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Qualis.h
 * Author: rodri
 *
 * Created on 17 de Julho de 2017, 00:32
 */

#ifndef QUALIS_H
#define QUALIS_H
#include <string>
#include <vector>
#include "Qualificacao.h"
#include "Publicacao.h"
namespace model {
    using namespace std;
     class Qualis {

    public:
		Qualis();
        Qualis(string nome);
		string getNome();
		void setQualificacao(Qualificacao *q);
		vector<Publicacao*> getPublicacoes();
		double getRatio();
        virtual ~Qualis();
    private:
        string nome;
		vector<Qualificacao*> qualificacoes;
    };
}
#endif /* QUALIS_H */

