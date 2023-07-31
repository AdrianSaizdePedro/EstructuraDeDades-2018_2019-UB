/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EllipseContainer.cpp
 * Author: aquindsa10.alumnes
 * 
 * Created on 2 / de març / 2017, 10:36
 */

#include "EllipseContainer.h"
#include "Ellipse.h"
#include "Circle.h"
#include <vector>
using namespace std;

EllipseContainer::EllipseContainer() {
}

EllipseContainer::EllipseContainer(const EllipseContainer& orig) {
}

EllipseContainer::~EllipseContainer() {
    vector<Ellipse*>::iterator it;
    for (it=container.begin();it!=container.end();++it){
        if (dynamic_cast<Circle*>(*it)){
            delete (Circle*)(*it);
        }else{
            delete (Ellipse*)(*it);
        }
    }
}

void EllipseContainer::addEllipse (Ellipse * e){
    if (size < 10){
        container[size] = e;
        size++;
    }
}
float EllipseContainer::getAreas(){

    vector<Ellipse*>::iterator it;
    float suma= 0;
    for (it=container.begin();it!=container.end();++it){
        suma +=(*it)->getArea();
    }
    return suma;
}