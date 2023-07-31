/* 
 * File:   Rectangle.h
 * Author: Rubén Ballester Bautista
 * Author: Oriol Rabasseda Alcaide
 * 
 * Created on 25 / febrer / 2016, 12:56
 */

#ifndef RECTANGLE_H
#define	RECTANGLE_H

class Rectangle {
public:
    Rectangle(double baseAux, double alcadaAux);
    virtual ~Rectangle();
    double getArea();
private:
    double base;
    double alcada;
};

#endif	/* RECTANGLE_H */

