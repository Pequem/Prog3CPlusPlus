/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conferencia.h
 * Author: rodri
 *
 * Created on 11 de Julho de 2017, 23:15
 */

#ifndef CONFERENCIA_H
#define CONFERENCIA_H
#include <string>
#include "Publicacao.h"
namespace model {

    class Conferencia:Publicacao {
    public:
        Conferencia(int ano, string titulo, int pagInicial, int pagFinal, int numero, Veiculo veiculo, string local);
        virtual ~Conferencia();
    private:
        string local;
    };
}
#endif /* CONFERENCIA_H */

