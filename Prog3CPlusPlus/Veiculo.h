/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Veiculo.h
 * Author: rodri
 *
 * Created on 11 de Julho de 2017, 23:18
 */

#ifndef VEICULO_H
#define VEICULO_H
#include <string>
#include "classMap.h"
#include "Publicacao.h"
#include "Qualificacao.h"
namespace model {
    using namespace std;
    class Veiculo {
    public:
        Veiculo();
        Veiculo(string sigla, string nome, string tipo, double fatorDeImpacto, string issn);
		string getTipo();
		void setQualificacao(Qualificacao *q);
		void setPublicacao(Publicacao *p);
		vector<Qualificacao*> getQualificacoes();
		string getSigla();
		string getNome();
		double getFatorDeImpacto();
		vector<Publicacao*> getPublicacoes();
        virtual ~Veiculo();
    private:
        string sigla;
        string nome;
		string tipo;
        double fatorDeImpactor;
        string issn;
		vector<Publicacao*> publicacoes;
		vector<Qualificacao*> qualificacoes;
    };
}
#endif /* VEICULO_H */

