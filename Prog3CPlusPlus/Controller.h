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
#include "Docente.h"
using namespace std;
using namespace model;
class Controller {
public:
    Controller(string d,string v,string p,string q,string r,string a);
    virtual ~Controller();
private:
    const char tokenDelimit = ';';
    vector<Docente> docentes;
    void readDocentes(string d);
};

#endif /* CONTROLLER_H */

