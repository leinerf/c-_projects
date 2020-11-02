#include <iostream>

class LuhnCheckSumValidation {
  public:
    void simulation();
};

void LuhnCheckSumValidation::simulation(){
    char number;
    while(std::cin.get(number)){
        std::cout << number;
    }
}

int main(){
    LuhnCheckSumValidation lcsv;
    lcsv.simulation();
}
