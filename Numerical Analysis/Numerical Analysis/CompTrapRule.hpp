//
//  CompTrapRule.hpp
//  Numerical Analysis
//
//  Created by Jeffrey Lima on 5/10/16.
//  Copyright © 2016 Jeffrey Lima. All rights reserved.
//

#ifndef CompTrapRule_hpp
#define CompTrapRule_hpp

#include <iostream>
#include <cmath>
#include <vector>
class CompTrapRule{
public:
    // default constructor
//    CompTrapRule();
    // paramatized constructor
    explicit CompTrapRule(double (*func)(double), double (*fDoublePrime)(double), double a, double b, std::vector<double> nodes);
    // getters
    std::vector<double> getResult();
    std::vector<double> getHStep();
    std::vector<double> getErrorBound();
private:
    double a;
    double b;
    std::vector<double> h;
    std::vector<double> nodes;
    std::vector<double> result;
    std::vector<double> errorBound;
    double (*func)(double);
    double (*fDoublePrime)(double);
    CompTrapRule & calculate();
    double calculateErrorBound(double h);
    double maxValue();
};

#endif /* CompTrapRule_hpp */
