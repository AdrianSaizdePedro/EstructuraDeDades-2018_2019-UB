/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: aquindsa10.alumnes
 *
 * Created on 16 / de febrer / 2017, 11:20
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main() {
    
    string nom;
    int a;
    
    cout << "Com et dius?" << endl;
    cin >> nom;
    
    a = 2;
    
    do{
        cout << "Hola, " << nom << ", que vols fer?" << endl;
        cout << "1. Sortir"  << endl;
        cout << "2. Benvinguda" << endl;
        cin >> a;
    
        if (a == 2)
            cout << "Benvingut/da a l'assignatura ESDD, " << nom;
    }while(a != 1);
            
        
    
    
    return 0;
}

