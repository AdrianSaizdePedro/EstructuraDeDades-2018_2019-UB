/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Adrian
 *
 * Created on 15 de mayo de 2019, 12:59
 */

#include <cstdlib>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "MaxHeap.h"
#include "NodeHeap.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
int opcio, key;
string elemento;
    vector<string> options {"1. Insertar al Heap valores",
                            "2. Eliminar el Nodo mas grande",
                            "3. Mostrar Heap",
                            "4. Imprime la Key más grande",
                            "5. Imprime el elemento con la key más grande",
                            "6. Tamaño",
                            "7. Eliminar Heap",
                            "8. Salir"};
                            
MaxHeap<string>* heap;
    do {  
        
        for(vector<string>::const_iterator it = options.begin(); it != options.end(); ++it){
            cout << ' ' << *it;
            cout << '\n';  
        }
        
        cout << "Opcio: ";
        cin >> opcio;
        cout << '\n';
        
        switch(opcio){
            case 1:
                cout << "Inserta al heap la key: ";
                cin >> key;
                cout<<"Inserte aqui el elemento que desea guardar: ";
                cin >> elemento;
                heap->insert(key, elemento);
                cout << '\n';
                break;
            
            case 2:
            //Eliminar
                if(heap->isEmpty()){
                    cout<<"EXCEPTION: El heap está Vacío"<<endl;
                    cout<<"------------------------------"<<endl;
                    cout<<endl;
                }
                else{

                        cout << "Eliminamos el Heap...";
                        heap->removeMax();
                        cout << '\n';
                }
                break;      
            case 3:
            //Mostrar el Heap
                if(heap->isEmpty()){
                    cout<<"EXCEPTION: El heap está Vacío"<<endl;
                    cout<<"------------------------------"<<endl;
                    cout<<endl;
                }
                else{
                        cout << "Imprimir el Heap: "<<endl;
                        heap->printHeap();
                        cout << '\n';
                    
                }
                break;
            case 4:
            //Imprimir la key más grande
                if(heap->isEmpty()){
                    cout<<"EXCEPTION: El heap está Vacío"<<endl;
                    cout<<"------------------------------"<<endl;
                    cout<<endl;
                }
                else{
                        cout << "La key más grande es: "<< heap->max() <<endl;
                        cout << '\n';
                    
                }
                break;
            case 5:
            //Imprime el elemento con la key más grande
                if(heap->isEmpty()){
                    cout<<"EXCEPTION: El heap está Vacío"<<endl;
                    cout<<"------------------------------"<<endl;
                    cout<<endl;
                }
                else{ 
                        cout << "Elemento de la key "<< heap->max()<<" es: "<< heap->maxValues()<< endl;
                        cout << '\n';
                    
                }
                break;
            case 6:
            //Tamaño
                cout << "El tamaño del heap es: " << heap->size() << endl;
                cout << '\n';
                break;
            case 7:
            //Eliminar Heap
                heap->deleteHeap();
                break;
            case 8:
            //Salir
                cout<<"Hasta la vista"<<endl;
                break;
            default:
            cout << "Escriba un numero dentro de los parametros"<< endl;
        }
    } while(opcio != 8);
    
    return 0;
}

