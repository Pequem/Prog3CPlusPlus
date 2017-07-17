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
#include "Date.h"
#include "Publicacao.h"
#include <list>
namespace model {

    class Docente {
    public:
        Docente(string nome, Date nascimento, Date dataIngresso, bool coordenador, list<Publicacao> publicacoes);
        virtual ~Docente();
    private:
        string nome;
        Date nascimento;
        Date dataIngresso;
        bool coordenador;
        list<Publicacao> publicacoes;
    };
}
#endif /* DOCENTE_H */

