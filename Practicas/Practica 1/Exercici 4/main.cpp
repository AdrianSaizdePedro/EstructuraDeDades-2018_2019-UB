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
#include"Ellipse.h"
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
void crearFigura(int &countC, int &countE){
                float r1, r2;
                char type;
                cout << "Introdueix les dades de la figura: "<<endl;
                cin >> type;
                if (type == 'C' || type == 'c'){
                    cin >> r1;
                    Circle cerc(r1);
                    try{
                        cout << "L'area del cercle és: " << cerc.getArea()<<endl;
                    }catch(OutOfRangeException &OutOfRangeException){
                        cout << OutOfRangeException.what() <<endl;
                    }
                    countC++;
                }else{
                    cin >> r1;
                    cin >> r2;
                    Ellipse ellipse(r1,r2);
                    try{
                        cout << "L'area de l'el·lipse és: " << ellipse.getArea()<<endl;
                    }catch(OutOfRangeException &OutOfRangeException){
                        cout << OutOfRangeException.what() <<endl;
                    }
                    countE++;
                }
}

int main() {
    string st;
    int opcio;
    int countC, countE;
    vector<string> vectorop = {"Sortir","Afegir una figura","Glossari de figures"};
    
    cout << "Hola, com et dius?" << endl;
    cin >> st;
    do{
        opcio = getOpcio(st, vectorop);
        switch (opcio){
            case 1:
                cout << "Fins aviat" << endl;
                break;
            case 2:
                crearFigura(countC, countE);
                break;
            case 3:
                cout << "Has creat " << countE << " ellipses i " << countC << " cercles."  << endl;
                break;
            default:
                cout << "Error: Opció no vàlida.";
                break;
        }
    }while(opcio != 1);
    return 0;
}
