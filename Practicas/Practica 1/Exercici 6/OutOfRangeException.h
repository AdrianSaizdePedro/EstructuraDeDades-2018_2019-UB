/* CIRCLE_H */
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   outofrangeexception.h
 * Author: amirmonc7.alumnes
 *
 * Created on 23 / de febrer / 2017, 10:49
 */

#ifndef OUTOFRANGEEXCEPTION_H
#define OUTOFRANGEEXCEPTION_H
#include <stdexcept>
using std::runtime_error;

class OutOfRangeException: public runtime_error {
public:
  OutOfRangeException();
};

#endif /* OUTOFRANGEEXCEPTION_H */