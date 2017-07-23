/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Regras.h
 * Author: rodri
 *
 * Created on 17 de Julho de 2017, 00:39
 */

#ifndef REGRAS_H
#define REGRAS_H
#include <ctime>
namespace model {

    class Regras {
    public:
        Regras(double fatorMult, time_t dataInicio, time_t dataFim, int qtAno, int pontMin, map<string, int> pontuacoesRegras);
        virtual ~Regras();
    private:
        double fatorMult;
        time_t dataInicio;
        time_t dataFim;
        int qtdAnos;
        int pontMin;
    };
}
#endif /* REGRAS_H */

