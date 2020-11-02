#include <iostream>

class LuhnCheckSumValidation {
    private:
    int convertCharToInt(char);
    public:
    void simulation();
};

int LuhnCheckSumValidation::convertCharToInt(char c){
  return c - '0';
}

void LuhnCheckSumValidation::simulation(){
    char digit;
    bool done = false;
    while(!done){
        std::cin >> digit;
        int num = convertCharToInt(digit);
        if(num < 0 || num > 9){
            done=true;
        }
    }
}


int main(){
    LuhnCheckSumValidation lcsv;
    lcsv.simulation();
}
