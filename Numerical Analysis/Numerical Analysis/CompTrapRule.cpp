//
//  CompTrapRule.cpp
//  Numerical Analysis
//
//  Created by Jeffrey Lima on 5/10/16.
//  Copyright © 2016 Jeffrey Lima. All rights reserved.
//

#include "CompTrapRule.hpp"

CompTrapRule::CompTrapRule(){}

CompTrapRule::CompTrapRule(double (*func)(double), double a, double b, std::vector<double> nodes){
    this->func = func;
    this->a = a;
    this->b = b;
    this->nodes = nodes;
    result.resize(nodes.size(), 0.0);
    calculate();
}

CompTrapRule & CompTrapRule::calculate(){
    double h;
    double x;
    for(unsigned i = 0; i < nodes.size(); i++){
        h = (b - a)/nodes[i];
    
        for(unsigned j = 1; j < nodes[i]; j++){
            x = a + j * h;
            result[i] += (2.0 * func(x));
        }
        result[i] = (h/2.0)*(func(a) + result[i] + func(b));
    }
    return *this;
}

std::vector<double> CompTrapRule::getResults(){
    return this->result;
}