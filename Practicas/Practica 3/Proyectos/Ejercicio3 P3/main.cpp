#include <cstdlib>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "BinarySearchTree.h"

using namespace std;


int main() {
    
    int opcio, entero;
    vector<string> options {"1. Insertar al albol valores",
                            "2. Mostrar PreOrdre",
                            "3. Mostrar InOrdre",
                            "4. Mostrar PostOrdre",
                            "5. Mostrar Hojas del Arbol",
                            "6. Eliminar Arbol",
                            "7. Salir"};
                            
    BinarySearchTree<int>* arbre;
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
                cout << "Inserta a l'arbre l'element: ";
                cin >> entero;
                arbre->insert(entero);
                cout << '\n';
                break;
            
            case 2:
            //Mostrar en PreOrdre
                cout << "-> Preordre = {";
                arbre->showPreorder();
                cout << "}" << endl;
                cout << '\n';
                break;      
            case 3:
            //Mostrar en InOrdre
                cout << "-> Inordre = {";
                arbre->showInorder();
                cout << "}" << endl;
                cout << '\n';
                break;
            case 4:
            //Mostrar en PostOrdre
                cout << "-> Postordre = {";
                arbre->showPostorder();
                cout << "}" << endl;
                cout << '\n';
                break;
            case 5:
                cout << "-> Fulles = {";
                arbre->showLeafNodes();
                cout << "}" << endl;
                cout << '\n';
                break;
            case 6:
                //Eliminar Arbol
                cout << "Destruïnt arbre binari" << endl;
                arbre->deleteTree(arbre->root());
                cout << '\n';
                cout << "Abre binari destruït." << endl;
                cout << '\n';
                break;
            case 7:
            //Salir
                cout<<"Hasta la vista"<<endl;
                break;
            default:
            cout << "Escriba un numero dentro de los parametros"<< endl;
        }
    } while(opcio != 7);
    
    return 0;
}

