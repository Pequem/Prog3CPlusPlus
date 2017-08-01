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
#include "Publicacao.h"
#include "Docente.h"
#include "Veiculo.h"
#include "Conferencia.h"
#include "Periodico.h"
#include "Qualis.h"
#include "Qualificacao.h"
#include "Regras.h"
#include "CustomException.h"
#include "Tokenizer.h"
#include "DateUtils.h"
#include "NumberUtils.h"
#include "StringUtils.h"
using namespace std;
using namespace model;
class Controller {
public:
    Controller(string d,string v,string p,string q,string r,string a);
    virtual ~Controller();
private:
    const char tokenDelimit = ';';
    map<long long,Docente*> docentes;
	map<string, Veiculo*> veiculos;
	vector<Publicacao*> publicacoes;
	vector<Pontuacao*> pont2;
	map<string,Qualis*> qualis;
	vector<Qualificacao*> qualificacoes;
	Regras* regras;
	int anoRecredenciamento;
    void readDocentes(string d);
	void readVeiculos(string v);
	void readPublicacoes(string p);
	void readQualificacoes(string q);
	void readRegras(string r);
	void WriteRecredenciamento();
	void WriteListaPublicacoes();
	void WriteStatistics();
};

#endif /* CONTROLLER_H */

