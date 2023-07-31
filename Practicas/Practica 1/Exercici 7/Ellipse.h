/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ellipse.h
 * Author: arnauquindos
 *
 * Created on 26 de febrero de 2017, 15:07
 */

#ifndef ELLIPSE_H
#define ELLIPSE_H

class Ellipse {
public:
    Ellipse();
    Ellipse(float, float);
    virtual float getArea();
    virtual ~Ellipse();
protected:
    float area;
    float r1, r2;


};

#endif /* ELLIPSE_H */

