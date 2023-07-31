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
#include "Circle.h"
#include "OutOfRangeException.h"
Circle::Circle(float r) {
    radi = r;
}
float Circle::getArea(){
    if(radi<0){
        throw OutOfRangeException();
    }else{
    return radi*radi*3.14;}
}

Circle::~Circle() {
}

