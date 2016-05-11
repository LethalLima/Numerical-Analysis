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
    CompTrapRule();
    // paramatized constructor
    CompTrapRule(double (*func)(double), double a, double b, std::vector<double> nodes);
    std::vector<double> getResults();
private:
    double a;
    double b;
    std::vector<double> nodes;
    std::vector<double> result;
    double (*func)(double);
    CompTrapRule & calculate();
};

#endif /* CompTrapRule_hpp */
