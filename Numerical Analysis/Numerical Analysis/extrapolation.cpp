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

double fDoublePrime(double x){
    return (2.0 * pow(x, 2.0) + 1.0)/(pow(1 - pow(x, 2.0), 5.0/2.0));
}

double absoluteError(double exact, double approx){
    return fabs(exact - approx);
}

double relativeError(double exact, double approx){
    return absoluteError(exact, approx)/exact;
}

std::vector<double> extrapolation(std::vector<double> nodes){
    std::vector<double> extrp;
    for(unsigned i = 0; i < nodes.size(); i+=2){
        extrp.push_back((nodes[i+1] + ((nodes[i+1] - nodes[i])/3.0)));
    }
    
    return extrp;
}

int main(int argc, const char * argv[]) {
    // the integral of 1/sqrt(1-x^2) is arcsin(x)
    double exact = asin(0.99) - asin(0);
    double a = 0.0;
    double b = 0.99;
    std::vector<double> nodes;
    nodes.push_back(101);
    nodes.push_back(201);
    nodes.push_back(1001);
    nodes.push_back(2001);
    
    CompTrapRule ctp(&f, &fDoublePrime, a, b, nodes);
    std::vector<double> results = ctp.getResult();
    std::vector<double> hSteps = ctp.getHStep();
    std::vector<double> errorBounds = ctp.getErrorBound();
    
    std::cout << "Exact Value: " << exact << std::endl;
    for(unsigned i = 0; i < results.size(); i++){
        std::cout << "Composite Trapezoidal Rule approximation: " << std::setprecision(9)
            << results[i] << " with h step of " << hSteps[i] << ", an absolute erorr of "
            << absoluteError(exact, results[i]) << ", and error bound of "
            << errorBounds[i] << '.' << std::endl;
    }
    
    std::vector<double> extrp = extrapolation(results);
    for(unsigned i = 0; i < extrp.size(); i++){
        std::cout << "Richardson's Extrapolation approximation: " << std::setprecision(9)
        << extrp[i] << " with an absolute error of " << absoluteError(exact, extrp[i]) << std::endl;
    }
    return 0;
}
