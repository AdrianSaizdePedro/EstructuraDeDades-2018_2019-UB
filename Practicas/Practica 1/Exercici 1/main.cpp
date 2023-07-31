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
    string arr_options[] = {"Sortir", "Benvinguda"};
    int opcio;
    
    cout << "Com et dius?" << endl;
    cin >> nom;
    
    opcio = 2;
    
    do{
        cout << "Hola, " << nom << ", que vols fer?" << endl;
        for (int i=0; i<2; i++){
            cout << i+1 << ". " << arr_options[i] << endl;
        }

        cin >> opcio;
    
        if (opcio == 2)
            cout << "Benvingut/da a l'assignatura ESDD, " << nom;
    }while(opcio != 1);
            
        
    
    
    return 0;
}

