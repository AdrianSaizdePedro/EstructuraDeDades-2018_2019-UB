/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EllipseContainer.h
 * Author: aquindsa10.alumnes
 *
 * Created on 2 / de març / 2017, 10:36
 */
#include "Ellipse.h"
#include <vector>
using namespace std;

#ifndef ELLIPSECONTAINER_H
#define ELLIPSECONTAINER_H

class EllipseContainer {
public:
    EllipseContainer();
    EllipseContainer(const EllipseContainer& orig);
    virtual ~EllipseContainer();
    void addEllipse (Ellipse *);
    float getAreas();
private:
    int size = 0;
    vector<Ellipse*> container;
    int MAX = 10;
};

#endif /* ELLIPSECONTAINER_H */

