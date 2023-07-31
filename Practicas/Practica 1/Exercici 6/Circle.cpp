/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circle.cpp
 * Author: amirmonc7.alumnes
 * 
 * Created on 23 / de febrer / 2017, 10:20
 */
#include "Ellipse.h"
#include "Circle.h"
#include "OutOfRangeException.h"
#include <iostream>


Circle::Circle(float r):Ellipse() {
    std::cout << "Soc el constructor de la classe Cercle." << std::endl;
    r1 = r;
    r2 = r;
}

float Circle::getArea(){
    if(r1<0 || r2<0){
        throw OutOfRangeException();
    }else{
    return r1*r2*3.14;}
}

Circle::~Circle() {
}

