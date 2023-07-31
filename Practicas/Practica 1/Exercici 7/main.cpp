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
#include <fstream>
#include <vector>
#include"Circle.h"
#include"Ellipse.h"
#include "OutOfRangeException.h"
#include "EllipseContainer.h"
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
Ellipse * crearFigura(int &countC, int &countE){
                float r1, r2;
                string type;
                cout << "Introdueix les dades de la figura: "<<endl;
                cin >> type;
                if (type == "C" || type == "c"){
                    cin >> r1;
                    Circle *cerc;
                    cerc = new Circle(r1);
                    try{
                        cout << "L'area del cercle és: " << cerc->getArea()<<endl;
                    }catch(OutOfRangeException &OutOfRangeException){
                        cout << OutOfRangeException.what() <<endl;
                    }
                    countC++;
                    return cerc;
                }else{
                    cin >> r1;
                    cin >> r2;
                    Ellipse *ellipse;
                    ellipse = new Ellipse(r1,r2);
                    try{
                        cout << "L'area de l'el·lipse és: " << ellipse->getArea()<<endl;
                    }catch(OutOfRangeException &OutOfRangeException){
                        cout << OutOfRangeException.what() <<endl;
                    }
                    countE++;
                    return ellipse;
                }
                
}

Ellipse crearFiguraFitxer(int &countC, int &countE, char type, float r1, float r2){
                if (type == 'C' || type == 'c'){
                    Circle cerc(r1);
                    try{
                        cout << "L'area del cercle és: " << cerc.getArea()<<endl;
                    }catch(OutOfRangeException &OutOfRangeException){
                        cout << OutOfRangeException.what() <<endl;
                    }
                    countC++;
                    return cerc;
                }else{
                    Ellipse ellipse(r1,r2);
                    try{
                        cout << "L'area de l'el·lipse és: " << ellipse.getArea()<<endl;
                    }catch(OutOfRangeException &OutOfRangeException){
                        cout << OutOfRangeException.what() <<endl;
                    }
                    countE++;
                    return ellipse;
                }
}        

int main() {
    string st;
    int opcio;
    int countC=0;
    int countE=0;
    string arr_options[] = {"Sortir", "Afegir figura", "Glossari de figures","Afegir fitxer","Arees totals"};
    vector<string> vectorop (arr_options, arr_options + sizeof(arr_options) / sizeof(string));
    
    EllipseContainer *cont;
    cont = new EllipseContainer;
    
    cout << "Hola, com et dius?" << endl;
    cin >> st;
    do{
        opcio = getOpcio(st, vectorop);
        switch (opcio){
            case 1:
                cout << "Fins aviat" << endl;
                break;
            case 2:
                Ellipse* e;
                e= crearFigura(countC, countE);
                cont->addEllipse(e);
                break;
            case 3:
                cout << "Has creat " << countE << " ellipses i " << countC << " cercles."  << endl;
                break;
            case 4:{
                ifstream meu_fitxer("Figures.txt");
                char tipus;
                float r1, r2;
                while (!meu_fitxer.eof()) {
                    meu_fitxer >> tipus;
                    if (tipus == 'C' || tipus == 'c'){
                        meu_fitxer >> r1;
                        Ellipse* e;
                        *e = crearFiguraFitxer(countC, countE, tipus, r1, 0);
                        cont->addEllipse(e);
                    }else{
                        meu_fitxer >> r1 >> r2;
                        Ellipse* e;
                        *e = crearFiguraFitxer(countC, countE, tipus, r1, r2);
                        cont->addEllipse(e);
                    }                 
                }
                meu_fitxer.close();
                break;
            }
            case 5:
                cout << cont->getAreas() << endl;
                break;
            default:
                cout << "Error: Opció no vàlida.";
                break;
        }
    
    }while(opcio != 1);
    return 0;
}

