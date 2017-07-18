/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Controller.h
 * Author: rodri
 *
 * Created on 17 de Julho de 2017, 01:52
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <string>
#include <vector>
#include <map>
#include "Docente.h"
#include "Veiculo.h"
#include "Publicacao.h"
#include "Conferencia.h"
#include "Periodico.h"
#include "Qualis.h"
#include "CustomException.h"
#include "Tokenizer.h"
#include "DateUtils.h"
#include "NumberUtils.h"
using namespace std;
using namespace model;
class Controller {
public:
    Controller(string d,string v,string p,string q,string r,string a);
    virtual ~Controller();
private:
    const char tokenDelimit = ';';
    map<long long,Docente> docentes;
	map<string, Veiculo> veiculos;
	vector<Publicacao*> publicacoes;
	map<string,Qualis> qualis;
    void readDocentes(string d);
	void readVeiculos(string v);
	void readPublicacoes(string p);
	void readQualis(string q);
};

#endif /* CONTROLLER_H */

