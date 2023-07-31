/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MaxHeap.h
 * Author: Adrian
 *
 * Created on 15 de mayo de 2019, 12:59
 */

#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include "NodeHeap.h"
#include <stdexcept>
#include <math.h>
#include <thread>
#include <locale>

using namespace std;
template <class E>
class MaxHeap {
public:
    //Constructores
    MaxHeap();
    MaxHeap(const MaxHeap& orig);
    virtual ~MaxHeap();

    
    //Metodos Consultores
    const int size() const;
    const bool isEmpty() const;
    const int max() const;
    const E& maxValues() const;
    void printHeap();
    int height();
    E search(int key);
    bool exist(int key);
    vector<NodeHeap<E>*>* getVector();


    //Metodos Modificadores
    void insert(const int& key, const E& value);
    void removeMax();
    void deleteHeap();

private:
    vector<NodeHeap<E>*> vectorElements;
    void upHeap();
    void downHeap();
    void swap(int pos1, int pos2);
    

};

/**
 * This is the Constructor of the Max Heap
 *
 */
template <class E>
MaxHeap<E>::MaxHeap() {
}

/**
 * Is the copy Constructor
 * 
 * @param MaxHeap&
 */
template <class E>
MaxHeap<E>::MaxHeap(const MaxHeap& orig) {
    this->vectorElements = orig.vectorElements;
}
/**
 * Destructor para MaxHeap, elimina todos los nodos definidos.
 * Elimina de uno en uno de atras a delante
 * 
 */
template <class E>
MaxHeap<E>::~MaxHeap() {
    int longitud = vectorElements.size() - 1;
    for (longitud ; longitud>=0; longitud--){
        if(vectorElements[longitud] != nullptr)
            delete vectorElements[longitud];
    }
}

/**
 * Devuelve el tamaño que tiene actalmente el MaxHeap
 * 
 * @return size of MaxHeap
 */
template <class E>
const int MaxHeap<E>::size() const{
    return this->vectorElements.size();
}

/**
 * Devuelve true si el vector esta vacio y false si tiene al menos un elemento
 * 
 * @return bool if is Emply
 */
template <class E>
const bool MaxHeap<E>::isEmpty() const{
    return this->vectorElements.empty();
}

/**
 * Devuelve el valor de la key más grande del Heap que coincide con el primer valor del array
 * 
 * @return Int of the max Key
 */
template <class E>
const int MaxHeap<E>::max() const{
    return vectorElements[0]->getKey();
}

/**
 * Devuelve el elemento que guarda el Nodo
 * @return E Element of Node
 */
template <class E>
const E& MaxHeap<E>::maxValues() const{
    return vectorElements[0]->getValue();
}

/**
 * Imprime el Heap de forma ordenada
 * 
 */
template <class E>
void MaxHeap<E>::printHeap(){
    NodeHeap<E>* aux;
    int respuesta;
    
    int contador = 0;
    for(int i = 0;i<size() && contador<40; i++){
        aux = vectorElements[i];

        cout<<i<<"."<<endl;
        cout<<"El nodo con key: "<<aux->getKey()<<endl;
        cout<<"El valor es: "<<aux->getValue()<<endl;
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

template <class E>
int MaxHeap<E>::height(){
    return ((int)(log2(vectorElements.size())) +1);
}

template <class E>
E MaxHeap<E>::search(int key){
    bool trobat = false;
    int pos = 0;
    for (int i=0;i<this->vectorElements.size() && !trobat;i++){
        
        if(this->vectorElements[i]->getKey() == key){
            trobat = true;
        }
        pos++;
    }
    if(trobat){
        return vectorElements[pos-1]->getValue();
    }else {
        cout<<"No existe ningun nodo con la clau: "<<key<<endl;
        cout<<endl;
    }
    
}

template <class E>
bool MaxHeap<E>::exist(int key){
    bool trobat = false;
    for (int i=0;i<this->vectorElements.size() && !trobat;i++){
        
        if(this->vectorElements[i]->getKey() == key){
            trobat = true;
        }
    }
    return trobat;
    
}

template <class E>
vector<NodeHeap<E>*>* MaxHeap<E>::getVector(){
    return &this->vectorElements;
}




/**
 * Inserta el nodo que representa el Elemeto dado. Como curiosidad, observar que
 * no puede haber dos nodos (co el mismo key) y se añaden de forma ordenada
 * 
 * @param key
 * @param value
 */
template <class E>
void MaxHeap<E>::insert(const int& key, const E& value){
    if(isEmpty()){
        NodeHeap<E>* nodo = new NodeHeap<E>(value,key);
        vectorElements.push_back(nodo);
    } else{

        bool found = false;
        int i = 0;
        while(!found && i<this->size()){
            found = vectorElements.at(i)->getKey()==key;
            i++;
        }

        if(!found){
            NodeHeap<E>* nodo = new NodeHeap<E>(value,key);
            vectorElements.push_back(nodo);
            upHeap();
        } else{
            vectorElements[i-1]->setValue(value);
        }

    }
}
/**
 * Elimina el elemento con la key más grande
 * 
 */
template <class E>
void MaxHeap<E>::removeMax(){
    if(isEmpty())
        throw new invalid_argument("Heap esta vacío");
    
    swap(0, size()-1);
    vectorElements.pop_back();
    downHeap();
}

template <class E>
void MaxHeap<E>::deleteHeap(){
    this->vectorElements.clear();
}


/*********** METODOS PRIVADOS *************/

/**
 * Intercambia el nodo añadido a su posición idonea dentro del vector, para que sus hijo simre sean menores que él.
 */
template <class E>
void MaxHeap<E>::upHeap(){
    bool trobat = false;
    int positionToUpHeap = vectorElements.size()-1;
    while(positionToUpHeap != 0 && !trobat){
        if(vectorElements[(positionToUpHeap-1)/2]->getKey() < vectorElements[positionToUpHeap]->getKey()){
            swap((positionToUpHeap -1)/2, positionToUpHeap);
            positionToUpHeap = (positionToUpHeap -1)/2;
        } else {
            trobat = true;
        }
    }
}

template <class E>
void MaxHeap<E>::downHeap(){
    int i = 0;
    bool found = false;
    
    int hijoDr;
    int hijoIz;
    
    while(i < vectorElements.size() && !found){
        hijoIz = 2*i + 1;
        hijoDr = 2*i + 2;
        
        if(hijoDr>=size() && hijoIz>=size()){
            found = true;
        } else if (hijoDr >= size()){
            if (vectorElements[i]->getKey() < vectorElements[hijoIz]->getKey()){
                swap(i, hijoIz);
                i = hijoIz;
            } else{
                found = true;
            }
        } else if (hijoIz>= size()){
            if(vectorElements[i]->getKey() < vectorElements[hijoDr]->getKey()){
                swap(i, hijoDr);
                i = hijoDr;
            } else{
                found = true;
            }
        } else{
            if(vectorElements[hijoDr]->getKey() < vectorElements[hijoIz]->getKey()){
                if(vectorElements[i]->getKey() < vectorElements[hijoIz]->getKey()){
                    swap(i, hijoIz);
                    i = hijoIz;
                } else{
                    found = true;
                }
            } else{
                if(vectorElements[i]->getKey() < vectorElements[hijoDr]->getKey()){
                    swap (i, hijoDr);
                    i = hijoDr;
                } else {
                    found = true;
                }
            }
            
        }
        
        
    }
}


/**
 * Intercambia el orden de dos nodos passando por parametro la posición que ocupa en el vector
 * 
 * @param pos1
 * @param pos2
 */
template <class E>
void MaxHeap<E>::swap(int pos1, int pos2){
    NodeHeap<E>* nodo = vectorElements[pos1];
    vectorElements[pos1] = vectorElements[pos2];
    vectorElements[pos2] = nodo;
}

#endif /* MAXHEAP_H */

