#include <iostream>
#include "integrator.h"
#include <random>
#include <iomanip>
using namespace std;

using namespace elma;


void Integrator::update() {
    
    if ( channel("link").nonempty() ) {
        v = channel("link").latest();
    }
    current_integral += delta() * v;
    std::cout << " current_integral: " << current_integral;

}

double Integrator::value() {

    if ( channel("link").nonempty() ) {
        v = channel("link").latest();
    }
    current_integral += delta() * v;

    return current_integral;
}


