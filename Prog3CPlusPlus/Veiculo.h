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
namespace model {
    using namespace std;
    class Veiculo {
    public:
        Veiculo();
        Veiculo(string sigla, string nome, string tipo, double fatorDeImpacto, string issn);
        virtual ~Veiculo();
    private:
        string sigla;
        string nome;
		string tipo;
        double fatorDeImpactor;
        string issn;
    };
}
#endif /* VEICULO_H */

