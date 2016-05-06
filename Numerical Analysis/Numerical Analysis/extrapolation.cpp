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

double f(double x){
    return pow(pow(1 - pow(x, 2.0), 1.0/2.0), -1.0);
//    return x * log(x);
}

double compTrap(double (*func)(double), double a, double b, unsigned n){
    double result = 0.0;
    double h = (b - a)/n;
    double x;
    std::cout << "h = " << h << std::endl;
    for(unsigned j = 1; j < n; j++){
        x = a + j * h;
        result += (2.0 * func(x));
    }
    
    return (h/2.0)*(func(a) + result + func(b));
}

int main(int argc, const char * argv[]) {
    double a = 0.0;
    double b = 0.99;
    unsigned n = 2001;
    
    std::cout << "Composite Trapezoidal Rule approximation: " << std::setprecision(9) << compTrap(&f, a, b, n) << std::endl;
    return 0;
}
