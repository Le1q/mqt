#include "businesslogic.h"

BusinessLogic::BusinessLogic(){
    std::cout << "BusinessLogic constructor" << std::endl;
}
BusinessLogic::~BusinessLogic(){
    std::cout << "BusinessLogic destructor" << std::endl;
}

void BusinessLogic::doSomething(){
    std::cout << "BusinessLogic::doSomething()" << std::endl;
}


