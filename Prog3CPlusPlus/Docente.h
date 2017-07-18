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
using namespace std;
namespace model {
	
    class Docente {
    public:
		Docente(long cod, string nome, time_t nascimento, time_t dataIngresso, bool coordenador);
        virtual ~Docente();
    private:
		long cod;
        string nome;
        std::time_t nascimento;
        std::time_t dataIngresso;
        bool coordenador;
    };
}
#endif /* DOCENTE_H */

