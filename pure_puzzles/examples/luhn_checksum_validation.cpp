/*
PROBLEM: LUHN CHECKSUM VALIDATION
The Luhn formula is a widely used system for validating identification 
numbers. Using the original number, double the value of every other digit. 
Then add the values of the individual digits together (if a doubled value 
now has two digits, add the digits indi- vidually). The identification number 
is valid if the sum is divisible by 10.

Write a program that takes an identification number of arbitrary length and 
determines whether the number is valid under the Luhn formula. The program must 
process each character before reading the next one.
-------------------------------------

Plan:
rtp: A person will input of a series of numbers one by one and you have to check if is a valid using checksum
dtp:
    sht1: Know which digits to double
    sht2: Treat doubled numbers 10 and greater according to their individual
        digits
    sht3: Know we’ve reached the end of the number
    sht4: Reading each digit separately also char to decimal
swwyk: dtp:sht4 > dtp:sht3 > dtp:sht1 > dtp:sht2
rdtp:
    sht1: dipslay positive count or negative count
    sht2: checksum validation with fixed length
lfa: this is similar to counting the number of positive and negative numbers
e: learn how to use cin.get()
*/

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

    while(std::cin.get(digit)){
        //get input
        int num = convertCharToInt(digit);
        
        //check if invalid char inputted
        if(num < 0 || num > 9){
            break;
        }
        //calculate total
        totalDigits++;
        oddNumTotal += addDigit(returnDoubleIfModTrue(num,totalDigits,2,0));
        evenNumTotal += addDigit(returnDoubleIfModTrue(num,totalDigits,2,1));

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
