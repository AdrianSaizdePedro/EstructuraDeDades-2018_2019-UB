#include <cstdlib>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "HeapMountainFinder.h"
#include "MaxHeap.h"
#include "Mountain.h"
#include "NodeHeap.h"
#include <time.h>
#include <math.h>

using namespace std;
/* Ejercicio 3
 *        | Añadir  |   Encontrar |
 * M.Peque| 10/10   |   47/41     |
 * M.Grand| 25/31   |   94/78     |
 * He de decir que es natural ver como de media tarda más en añadir el fichero de montañas pequeñas.
 * 
 * En cuanto por que tarda más en encontrar las montañas también el documento grande, es debido a
 * que tengo implementado que imprima la montaña si existe y si no imprima que no existe, por lo 
 * que imprimir 1400 veces una montaña, requiere más tiempo de computación.
 */

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
                            
    HeapMountainFinder* heap = new HeapMountainFinder();

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
                    heap->appendMountains("Mountain small");
                    t = clock()-t;
                    cout<<"Tiempo empleado: " << t << endl;
                } else if (g==2){
                    t = clock();
                    heap->appendMountains("Mountain");
                    t = clock()-t;
                    cout<<"Tiempo empleado: " << t << endl;
                }else{
                    cout<<"Error incorrecto"<<endl;
                }
                

                break;
            
            case 2:
            //Mostrar en InOrdre
                try{
                    if(heap->isEmpty()){
                        throw std::invalid_argument("Arbol vacío");
                    }
                    
                    cout<<"HEAP"<<endl;
                    heap->showMountains();
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
                        
                        if (heap->exist(identificador)) {
                            comptador += 1;
                            heap->showMountain(identificador);
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
            // Profunditat
                heap->profunditat();
                
                
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

