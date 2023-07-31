/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ellipse.cpp
 * Author: arnauquindos
 * 
 * Created on 26 de febrero de 2017, 15:07
 */

#include "Ellipse.h"
#include "OutOfRangeException.h"
#include <iostream>


Ellipse::Ellipse() {
    std::cout << "Soc el constructor de la classe Ellipse." << std::endl;
    r1 = 0;
    r2 = 0;
}

Ellipse::Ellipse(float radi1, float radi2) {
    std::cout << "Soc el constructor de la classe Ellipse." << std::endl;
    r1 = radi1;
    r2 = radi2;
}

float Ellipse::getArea(){
    if(r1<0 || r2<0){
        throw OutOfRangeException();
    }else{
        return r1*r2*3.14;
    }
}

Ellipse::~Ellipse() {
}

