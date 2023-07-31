/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HeapMountainFinder.h
 * Author: Adrian
 *
 * Created on 19 de mayo de 2019, 18:10
 */

#ifndef HEAPMOUNTAINFINDER_H
#define HEAPMOUNTAINFINDER_H

#include <string>
#include "MaxHeap.h"
#include "Mountain.h"
#include "NodeHeap.h"
#include <iostream>
#include <fstream>
#include <exception>

class HeapMountainFinder {
public:
    //Constructores
    HeapMountainFinder();
    virtual ~HeapMountainFinder();
    
    //Consultores
    void showMountain(int IdMountain);
    void showMountains();
    bool isEmpty();
    bool exist(int key);
    //Modificadores
    void insertMountain(int mountainID, std::string name, int height);
    void appendMountains(std::string filename);
    Mountain findMountain(int IdMountain);
    void profunditat();
    
private:
    MaxHeap<Mountain>* heap;
    

};

HeapMountainFinder::HeapMountainFinder() {
    this->heap = new MaxHeap<Mountain>();
}

HeapMountainFinder::~HeapMountainFinder() {
}






/************ CONSULTORES *************/
void HeapMountainFinder::showMountain(int IdMountain){
    findMountain(IdMountain).toString();
}

void HeapMountainFinder::showMountains(){
    int respuesta;
    
    int contador = 0;
    for(int i = 0;i<heap->size() && contador<40; i++){

        cout<<i+1<<"."<<endl;
        Mountain mon = this->heap->getVector()->at(i)->getValue();
        mon.toString();
        cout<<endl; 
        
        contador++;
        if(contador == 40){
            cout<<"Deseas continuar imprimiendo montañas? (Escriba 1 para SI y 2 para NO"<<endl;
            cin>>respuesta;
            if(respuesta == 1)
                contador = 0;
            else{
                contador = 50;
            }
        }
    }
    
}

bool HeapMountainFinder::isEmpty(){
    return heap->isEmpty();
}
bool HeapMountainFinder::exist(int key){
    return heap->exist(key);
}




/************ MODIFICADORES *************/
void HeapMountainFinder::insertMountain(int mountainID, std::string name, int height){
    Mountain mountain ;
    mountain.setID(mountainID);
    mountain.setNom(name);
    mountain.setAltura(height);
    
    this->heap->insert(mountainID, mountain);
}

void HeapMountainFinder::appendMountains(std::string filename){
    string line, name;
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

Mountain HeapMountainFinder::findMountain(int IdMountain){
    return heap->search(IdMountain);
}

void HeapMountainFinder::profunditat(){
    cout<<"La profuncidad es de: "<<this->heap->height()<<endl;
    cout<<endl;
}

    
    
#endif /* HEAPMOUNTAINFINDER_H */

