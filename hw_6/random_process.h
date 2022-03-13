#ifndef _RANDOMPROCESS_H
#define _RANDOMPROCESS_H

#include "elma/elma.h"

using namespace elma;

class RandomProcess : public Process {

    public:

    RandomProcess(std::string name) : Process(name) {}
    void init() {};
    void start(){};
    void update();
    void stop() {};

    private:
    
    double random_number;


};  

#endif