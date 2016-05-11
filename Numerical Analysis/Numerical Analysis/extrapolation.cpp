//
//  extrapolation.cpp
//  Project 3: Richardson Extrapolation
//
//  Created by Jeffrey Lima on 5/5/16.
//  Copyright © 2016 Jeffrey Lima. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include "CompTrapRule.hpp"

double f(double x){
    return pow(pow(1 - pow(x, 2.0), 1.0/2.0), -1.0);
//    return x * log(x);
}

int main(int argc, const char * argv[]) {
    
    double a = 0.0;
    double b = 0.99;
    std::vector<double> nodes;
    nodes.push_back(101);
    nodes.push_back(201);
    nodes.push_back(1001);
    nodes.push_back(2001);
    CompTrapRule ctp(&f, a, b, nodes);
    std::vector<double> results = ctp.getResults();
    for(unsigned i = 0; i < results.size(); i++){
        std::cout << "Composite Trapezoidal Rule approximation: " << std::setprecision(9) << results[i] << std::endl;
    }
    
    return 0;
}
