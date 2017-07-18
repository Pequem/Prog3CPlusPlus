/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Periodico.h
 * Author: rodri
 *
 * Created on 11 de Julho de 2017, 23:27
 */

#ifndef PERIODICO_H
#define PERIODICO_H


#include <vector>
#include "Docente.h"
#include "Publicacao.h"

namespace model {

    class Periodico:Publicacao {
    public:
        Periodico(int ano, string titulo, int pagInicial, int pagFinal, int numero, Veiculo veiculo, int volume, vector<Docente> autores);
        virtual ~Periodico();
    private:
        int volume;
    };
}
#endif /* PERIODICO_H */

