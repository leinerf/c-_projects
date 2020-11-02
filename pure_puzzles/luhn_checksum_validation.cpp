#include <iostream>

class LuhnCheckSumValidation {
    private:
    int convertCharToInt(char);
    int addDigit(int);
    bool checkValidSum(int);
    int returnDoubleIfModTrue(int,int,int,int);
    void printResult(bool);
    public:
    void simulation();
};

//Private functions
int LuhnCheckSumValidation::convertCharToInt(char c){
    return c - '0';
}

int LuhnCheckSumValidation::addDigit(int num){
    int result = 0;
    if(num > 9){
      result+=1;
    }
    result+=num%10;
    return result;
}

bool LuhnCheckSumValidation::checkValidSum(int num){
    return num%10 == 0;
}

int LuhnCheckSumValidation::returnDoubleIfModTrue(int num, int totalDigits, int moder, int modResult) {
    if(totalDigits%moder == modResult){
        return num * 2;
    }
    return num;
}

void LuhnCheckSumValidation::printResult(bool result){
    if(result) {
        std::cout << "This is a valid number!!!\n";
    }
    else {
        std::cout << "This is not a valid number!!!\n";
    }
}
//Public functions
void LuhnCheckSumValidation::simulation(){
    char digit;
    bool valid = false;
    int oddNumTotal = 0;
    int evenNumTotal = 0;
    int totalDigits = 0;

    while(true){
        //get input
        std::cin >> digit;
        int num = convertCharToInt(digit);
        
        //check if invalid char inputted
        if(num < 0 || num > 9){
            break;
        }
        //calculate total
        totalDigits++;
        oddNumTotal += addDigit(returnDoubleIfModTrue(num,totalDigits,2,1));
        evenNumTotal += addDigit(returnDoubleIfModTrue(num,totalDigits,2,0));

    }
    if(totalDigits%2==0){
        valid = checkValidSum(evenNumTotal); 
    }
    else {
        valid = checkValidSum(oddNumTotal);
    }
    printResult(valid);
}


int main(){
    LuhnCheckSumValidation lcsv;
    lcsv.simulation();
}
