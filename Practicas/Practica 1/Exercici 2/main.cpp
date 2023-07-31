/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
Maria Salamó
 * File:   main.cpp
 * Author: aquindsa10.alumnes
 *
 * Created on 16 / de febrer / 2017, 11:46
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * 
 */

int getOpcio(string nom, vector<string> vectorop){
    
    int opcio;
        
    cout << "Hola, " << nom << ", que vols fer?" << endl;
    for (int i=0; i< vectorop.size(); i++){
        cout << i+1 << ". " << vectorop[i] << endl;
    }

    cin >> opcio;
    return opcio;
}

int main(int argc, char** argv) {
    
    string nom;
    string arr_options[] = {"Sortir", "Benvinguda", "Redefinir el nom"};
    int opcio;
    
    //vector<string> vectorop = {"Sortir", "Benvinguda", "Redefinir el nom"};
    
    vector<string> vectorop (arr_options, arr_options + sizeof(arr_options) / sizeof(string));
    
    cout << "Com et dius?" << endl;
    cin >> nom;
    
    opcio = 2;

    do{
        opcio = getOpcio(nom,vectorop);
        
        switch (opcio){
            case 2:
                cout << "Benvingut/da a l'assignatura ESDD, " << nom << endl;
                break;
            case 3:
                cout << "Escriu el teu nom: " << endl;
                cin >> nom;
                break;
            case 1:
                cout << "Fins aviat" << endl;
                break;
            default:
                cout << "ERROR: Opcio no valida" << endl;
                break;
        }
       
    }while(opcio != 1);
            
    return 0;  
}

