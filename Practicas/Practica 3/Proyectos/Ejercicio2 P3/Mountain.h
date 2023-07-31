/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mountain.h
 * Author: Adrian
 *
 * Created on 28 de abril de 2019, 19:05
 */

#ifndef MOUNTAIN_H
#define MOUNTAIN_H
#include <string>

using namespace std;
        
class Mountain {
public:
    //Constructores
    Mountain();
    Mountain(int identificador, std::string nom, int altura);
    Mountain(const Mountain& orig);
    virtual ~Mountain();
    
    //Consultores
    const int getID() const;
    const string getNom() const;
    const int getAltura() const;
    
    //Modificadores
    void setID(const int id);
    void setNom(const string nom);
    void setAltura(const int altura);
    void toString();

private:
    int identificador;
    string nom;
    int altura;
};

#endif /* MOUNTAIN_H */

