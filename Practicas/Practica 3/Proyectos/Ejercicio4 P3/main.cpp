#include <cstdlib>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "BinarySearchTree.h"
#include "BSTMountainFinder.h"
#include <time.h>
#include <math.h>

using namespace std;


int main() {
    
    int opcio, identificador, altura;
    string nom;
    clock_t t;
    
    vector<string> options {
        "1. Insertar un fichero",
        "2. Mostrar Arbre",
        "3. Cercar Mountanyes",
        "4. Profunditat",
        "5. Sortir"};
                            
    BSTMountainFinder* arbre = new BSTMountainFinder();

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
                int g;
                cout<<"Que fichero quieres leer: \n 1. Montañas (pequeño) \n 2. Montañas Grande"<<endl;
                cout<<"Elige opcion: ";
                cin>>g;
                if(g==1){
                    t = clock();
                    arbre->appendMountains("Mountain small");
                    t = clock()-t;
                    cout<<"Tiempo empleado: " << t << endl;
                } else if (g==2){
                    t = clock();
                    arbre->appendMountains("Mountain");
                    t = clock()-t;
                    cout<<"Tiempo empleado: " << t << endl;
                }else{
                    cout<<"Error incorrecto"<<endl;
                }
                

                break;
            
            case 2:
            //Mostrar en InOrdre
                try{
                    if(arbre->getArbre()->isEmpty()){
                        throw std::invalid_argument("Arbol vacío");
                    }
                    
                    cout<<"ÁRBOL"<<endl;
                    arbre->showMountains();
                    cout<<endl;
                } catch(std::invalid_argument e){
                    cout << e.what() <<endl;
                    cout<<endl;
                }
                break;     
            case 3:{
                
                fstream cerca("cercaMuntanyes.txt");
                string text = " ";
                int comptador;
                
                if (cerca.is_open()) {
                    t = clock();
                    while (getline(cerca, text)) {
                        
                        identificador = stoi(text);
                        
                        if (arbre->isMountain(identificador)) {
                            comptador += 1;
                            arbre->showMountain(identificador);
                            cout << '\n';
                            
                        } else {
                            cout << "No existeix una muntanya amb l'ID " << identificador << "." << endl;
                            cout << '\n';
                        }   
                    }
                    cerca.close();
                    cout << "Total de muntanyes trobades: " << comptador << endl;
                    t = clock()-t;
                    cout<<"Tiempo empleado: " << t << endl;
                    cout<<"*************************"<<endl;
                    cout<<endl;
                } else {
                    cout << "Fitxer incorrecte." << endl;
                }
                break;
            }
            case 4:
            // Profunditat maxima i minima de l'arbre
                arbre->profunditat();
                
                
                break;
            case 5:
                cout << "Hasta la vista, guapo"<<endl;
                break;
            default:
            cout << "Escriba un numero dentro de los parametros"<< endl;
        }
    } while(opcio != 5);
    
    return 0;
}

