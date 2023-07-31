/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: amirmonc7.alumnes
 *
 * Created on 16 / de febrer / 2017, 11:23
 */

#include <iostream>
#include <vector>
#include"Circle.h"
#include "OutOfRangeException.h"
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
void crearCercle(int &count){
                float radi;
                cout << "Escriu l'area del cercle"<<endl;
                count++;
                cin >> radi;
                Circle cerc(radi);
                try{
                    cout << "L'area del cercle és: " << cerc.getArea()<<endl;
                }catch(OutOfRangeException &OutOfRangeException){
                    cout << OutOfRangeException.what() <<endl;
                }
                
    
}
int main() {
    string st;
    int opcio;
    int count;
    vector<string> vectorop = {"Sortir","Afegir un cercle"};
    
    cout << "Hola, com et dius?" << endl;
    cin >> st;
    do{
        opcio = getOpcio(st, vectorop);
        switch (opcio){
            case 1:
                cout << "Fins aviat" << endl;
                break;
            case 2:
                crearCercle(count);
                break;
            default:
                cout << "Error: Opció no vàlida.";
                break;
        }
    }while(opcio != 1);
    return 0;
}

