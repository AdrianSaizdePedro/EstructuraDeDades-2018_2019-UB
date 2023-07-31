/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circle.h
 * Author: amirmonc7.alumnes
 *
 * Created on 23 / de febrer / 2017, 10:20
 */

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
public:
    Circle(float);
    float getArea();
    virtual ~Circle();
private:
    float area;
    float radi;
};

#endif 




