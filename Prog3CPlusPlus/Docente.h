/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Docente.h
 * Author: rodri
 *
 * Created on 11 de Julho de 2017, 23:39
 */

#ifndef DOCENTE_H
#define DOCENTE_H
#include <list>
#include <ctime>
#include <string>
#include <vector>
#include "Regras.h"
#include "Publicacao.h"
using namespace std;
namespace model {
	class Publicacao;
    class Docente {
    public:
		Docente(long long cod, string nome, time_t nascimento, time_t dataIngresso, bool coordenador);
        virtual ~Docente();
		double getPontuacao(int ano, Regras* regras);
		bool isCoordenador();
		string getNome();
		int getAnoIngresso();
		int getIdade(int anoAtual);
		void setPublicacoes(Publicacao* p);
    private:
		long long cod;
        string nome;
        std::time_t nascimento;
        std::time_t dataIngresso;
        bool coordenador;
		vector<Publicacao*> publicacoes;
    };
}
#endif /* DOCENTE_H */

