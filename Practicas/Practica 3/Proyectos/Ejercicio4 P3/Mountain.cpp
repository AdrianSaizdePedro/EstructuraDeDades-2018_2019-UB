/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mountain.cpp
 * Author: Adrian
 * 
 * Created on 28 de abril de 2019, 19:05
 */

#include "Mountain.h"
#include <iostream>
#include <string>

using namespace std;
//Construtores
Mountain::Mountain() {
}

Mountain::Mountain(const Mountain& orig) {
    this->identificador = orig.getID();
    this->nom = orig.getNom();
    this->altura = orig.getAltura();
}

Mountain::~Mountain() {
}

Mountain::Mountain(int identificador, string nom, int altura){
    this->identificador = identificador;
    this->nom = nom;
    this->altura = altura;
}




//Consultores
const int Mountain::getID() const{
    return this->identificador;
}

const string Mountain::getNom() const{
    return this->nom;
}

const int Mountain::getAltura() const{
    return this->altura;
}




//Modificadores
void Mountain::setID(const int id){
    this->identificador = id;
}

void Mountain::setNom(const string nom){
    this->nom = nom;
}

void Mountain::setAltura(const int altura){
    this->altura = altura;
}



//ToString
void Mountain::toString(){
    cout<<"Identificador: "<<this->identificador<<endl;
    cout<<"Nombre: "<<this->nom<<endl;
    cout<<"Altura: "<<this->altura<<endl;
}