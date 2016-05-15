//
//  CompTrapRule.cpp
//  Numerical Analysis
//
//  Created by Jeffrey Lima on 5/10/16.
//  Copyright © 2016 Jeffrey Lima. All rights reserved.
//

#include "CompTrapRule.hpp"

//No need for it at the moment
//CompTrapRule::CompTrapRule(){}

CompTrapRule::CompTrapRule(double (*func)(double), double (*fDoublePrime)(double), double a, double b, std::vector<double> nodes){
    this->func = func;
    this->fDoublePrime = fDoublePrime;
    this->a = a;
    this->b = b;
    this->nodes = nodes;
    h.resize(nodes.size());
    result.resize(nodes.size(), 0.0);
    errorBound.resize(nodes.size());
    calculate();
}

CompTrapRule & CompTrapRule::calculate(){
    double x;
    for(unsigned i = 0; i < nodes.size(); i++){
        h[i] = (b - a)/nodes[i];
    
        for(unsigned j = 1; j < nodes[i]; j++){
            x = a + j * h[i];
            result[i] += (2.0 * func(x));
        }
        result[i] = (h[i]/2.0)*(func(a) + result[i] + func(b));
        errorBound[i] = calculateErrorBound(h[i]);
    }
    return *this;
}

double CompTrapRule::maxValue(){
    // In the works, trying to find an optimal/reasonable implementation.
//    double max = fDoublePrime(a), temp;
//    for(unsigned i = 0; i < 100; i++){
//        if(max > (temp = fDoublePrime(b)))
//            max = temp;
//    }
//    return max;
    return (fDoublePrime(a) > fDoublePrime(b)) ? fDoublePrime(a) : fDoublePrime(b);
}

double CompTrapRule::calculateErrorBound(double h){
    return ((b - a)/12.0)*pow(h, 2.0)*maxValue();
}


std::vector<double> CompTrapRule::getResult(){
    return this->result;
}

std::vector<double> CompTrapRule::getHStep(){
    return this->h;
}

std::vector<double> CompTrapRule::getErrorBound(){
    return this->errorBound;
}