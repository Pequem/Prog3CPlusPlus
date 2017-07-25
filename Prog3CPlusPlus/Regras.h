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
#include "classMap.h"
#include <ctime>
#include <vector>
#include "Pontuacao.h"
#include "Qualis.h"
namespace model {
	using namespace std;
    class Regras {
    public:
        Regras(double fatorMult, time_t dataInicio, time_t dataFim, int qtAno, int pontMin, vector<Pontuacao*> pontuacoesRegras);
        virtual ~Regras();
		int getQtdAnos();
		double getFatorMult();
		int getPontMin();
		Pontuacao* getPontuacoesRegraByQuali(Qualis *q);
    private:
        double fatorMult;
        time_t dataInicio;
        time_t dataFim;
        int qtdAnos;
        int pontMin;
		vector<Pontuacao*> pontuacoesRegras;
    };
}
#endif /* REGRAS_H */

