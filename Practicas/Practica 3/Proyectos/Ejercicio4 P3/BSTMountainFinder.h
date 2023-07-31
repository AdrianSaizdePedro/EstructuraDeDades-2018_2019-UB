/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BSTMountainFinder.h
 * Author: Adrian
 *
 * Created on 28 de abril de 2019, 20:01
 */

#ifndef BSTMOUNTAINFINDER_H
#define BSTMOUNTAINFINDER_H
#include "BinarySearchTree.h"
#include "Mountain.h"
#include <string>
#include <regex>
#include <iostream>
#include <fstream>
#include <exception>


using namespace std;

class BSTMountainFinder {
public:
    //Constructores
    BSTMountainFinder();
    BSTMountainFinder(const BSTMountainFinder& orig);
    virtual ~BSTMountainFinder();
    
    //Consultores
    BinarySearchTree<Mountain>* getArbre();
    void showMountain(int IdMountain);
    void showMountains();
    Mountain findMountain(int IdMountain);
    void profunditat();
    bool isMountain(int IdMountain);
    void printInorder(NodeTree<Mountain>* elem, int *contador, bool *stop);
    
    //Modificadores
    void setArbre(BinarySearchTree<Mountain>* arbre);
    void appendMountains(std::string filename);
    void insertMountain(int mountainID, std::string name, int height);
private:
    BinarySearchTree<Mountain>* bst;
};

//Constructores
BSTMountainFinder::BSTMountainFinder() {
    this->bst = new BinarySearchTree<Mountain>();
}

BSTMountainFinder::BSTMountainFinder(const BSTMountainFinder& orig) {
    
}

BSTMountainFinder::~BSTMountainFinder() {
}



//Consultores
BinarySearchTree<Mountain>* BSTMountainFinder::getArbre(){
    return this->bst;
}

void BSTMountainFinder::showMountain(int IdMountain){
    findMountain(IdMountain).toString();
}

void BSTMountainFinder::printInorder(NodeTree<Mountain>* elem, int *contador, bool *stop){
    int resposta;
 
    if (*contador == 40){
        cout << "Vols continuar mostrant les muntanyes? (Si//No)" << endl;
        cout << " 1) Si" << endl;
        cout << " 2) No" << endl;
        cin >> resposta;
        if(resposta == 1){
            *contador = 0;
        }
        else if (resposta == 2){
            *stop = true;
            *contador = 41;
            cout <<  "   E N D   " << endl;
        }

    }
    
    if(!*stop){
        if(!elem->isExternal() && elem->left() != 0) {
            printInorder(elem->left(), contador, stop);
        } 
        if(!*stop){
            
            cout<<"Identificador: "<<elem->getValue().getID()<<endl;
            cout<<"Nombre: "<<elem->getValue().getNom()<<endl;
            cout<<"Altura: "<<elem->getValue().getAltura()<<endl;
            cout<<endl;
            
            (*contador) += 1;
        }
        
        
        
        if (!elem->isExternal() && elem->right() != 0) {
            printInorder(elem->right(), contador, stop);    
        } 
    } 
}

void BSTMountainFinder::showMountains(){
    int contador = 0;
    bool stop = false;
    printInorder(bst->root(), &contador, &stop);
}

bool BSTMountainFinder::isMountain(int IdMountain){
    NodeTree <Mountain>* guia = this->bst->root();
    bool trobat = false;
    bool end = false;
        while(!trobat && !end) {
            //Si les muntanyes coinciden
            if (guia->getKey() == IdMountain) {
                trobat = true;
            }
            //Si el nodo es mayor que el elemento a comparar
            else if(guia->getKey() > IdMountain) {
                if (!guia->left() == 0) {
                    guia = guia->left(); 
                }
                else {
                    end = true;
                }
            }
            //Si el nodo es menor que el elemento a comparar
            else {
                if (!guia->right() == 0) {
                    guia = guia->right(); 
                }
                else {
                    end = true;
                }
            }
        }
    return trobat;
}


Mountain BSTMountainFinder::findMountain(int IdMountain){
    NodeTree <Mountain>* guia = this->bst->root();
    bool trobat = false;
    bool final = false;
    
        while(!trobat && !final) {
            //Si les muntanyes coinciden
            if (guia->getKey() == IdMountain) {
                trobat = true;
                return guia->getValue();
            }
            //Si el nodo es mayor que el elemento a comparar
            else if(guia->getKey() > IdMountain) {
                if (!guia->left() == 0) {
                    guia = guia->left(); 
                }
                else {
                    final = true;
                }
            }
            //Si el nodo es menor que el elemento a comparar
            else {
                if (!guia->right() == 0) {
                    guia = guia->right(); 
                }
                else {
                    final = true;
                }
            }
        }
}

// Metode per saber la profunditat d'un arbre
void BSTMountainFinder::profunditat(){
    cout << " Profunditat maxima  de l'arbre: ";
    cout<<this->bst->heightMax()<<endl;
    cout << '\n';
    cout << " Profunditat minima de l'arbre: ";
    cout<< this->bst->heightMin()<<endl;
    cout << '\n';
}





//*****Modificadores*******
void BSTMountainFinder::setArbre(BinarySearchTree<Mountain>* arbre){
    this->bst = arbre;
}

void BSTMountainFinder::appendMountains(string filename){
    string line,name;
    int id, altura;
    
    string prueba;
    
    
    fstream file(filename);
    if(file.is_open()){
        while(getline(file, line)){
            //file>>prueba; 
            prueba = line;
            
            id = stoi(prueba.substr(0,prueba.find(":")));
            prueba = prueba.substr(prueba.find(":")+2,prueba.length());
            
            name = prueba.substr(0,prueba.find(":"));
            prueba = prueba.substr(prueba.find(":")+2,prueba.length());
            
            altura = stoi(prueba.substr(0,prueba.find(":")));
            
            insertMountain(id,name,altura);
            
        }
        file.close();
    } else
        cout<<"No existe el archivo txt"<<endl;
}

void BSTMountainFinder::insertMountain(int mountainID, std::string name, int height){
    
    Mountain mountain ;
    mountain.setID(mountainID);
    mountain.setNom(name);
    mountain.setAltura(height);
    
    this->bst->insert(mountain, mountain.getID());

}


#endif /* BSTMOUNTAINFINDER_H */

