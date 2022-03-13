#include <iostream>
#include "random_process.h"
#include <random>
#include <iomanip>

using namespace elma;


void RandomProcess::update() {
    
    random_number = (double)(rand()) / ((double)(RAND_MAX/(1 - 0)));
    channel("link").send(random_number);
    std::cout << " random_number: " << random_number ;
    

}
