/*
If you like the Luhn formula problem, try 
writing a program for a different check-digit system, 
like the 13-digit ISBN system. The program could take 
an identification number and verify it or take a number 
without its check digit and generate the check digit.

Algorithm
1) Take the first 12 digits of the 13-digit ISBN
2) Multiply each number in turn, from left to right by a number. 
    The first digit is multiplied by 1, the second by 3, the third 
    by 1 gain, the fourth by 3 again, and so on to the eleventh which 
    is multiplied by 1 and the twelfth by 3.
3) Add all of the 12 answers.
4) Do a modulo 10 division on the result from step 3. Take that 
    remainder result from step 4. If it's a zero, then the check digit is zero. 
    If the remainders isn't zero then subtract the remainder from 10. The 
    answer to that is your check digit.

No storage system(i.e arrays, hashmaps etc)
Plan:
    rtp: Create an ISBN system using the algorithm above to 
        create check num if 12 digits given or validate ISBN series if 13 digits given
    dtp:
        sht1: take a series of numbers as input "203948208101(2)" 
        sht2: convert each digit to integer
        sht3: check if 12 digit or 13 digit then use ISBNValidator or ISBNCreateCheckDigit
        sht4: create algorithm for ISBNValidator
        sht5: create algorithm for ISBNCreateCheckDigit
    rdtp:
        sht1: program only deals with Validating Digit
        sht2: program only deals with Creating Check Digit
    swwyk: dtp1 > dtp2 > rdtp1 > dtp4 > rdtp2 > dtp5 > dtp3 
    lfa: similar to needing to take char and converting to int like LuhnCheckSum and Decoder
    e: cin.get() is pretty useful
*/
#include <iostream>

class ISBNSystem {
    private:
    int charToInt(char);
    bool validateNumberSimulator(int, int);
    int createCheckDigitNumberSimulator(int);
    public:
    void simulator();
};

int ISBNSystem::charToInt(char charNum) {
    return charNum - '0';
}

int ISBNSystem::createCheckDigitNumberSimulator(int total) {
    return 10 - (total % 10);
}

bool ISBNSystem::validateNumberSimulator(int total, int checkDigit) {
    return checkDigit == createCheckDigitNumberSimulator(total);
}

void ISBNSystem::simulator() {
    char charNum;
    int checkDigit;
    int digitCount = 0;
    int total = 0;
    int testVar;
    while((charNum = std::cin.get()) != 10) {
        digitCount++;
        int num = charToInt(charNum);
        if(digitCount == 13) {
            checkDigit=num;
            break;
        }
        if(digitCount % 2 == 1) {
            total += num;
        } else {
            total += num * 3;
        }
    }
    if(digitCount == 13 && validateNumberSimulator(total, checkDigit)){
        std::cout << "valid ISBN number\n"; 
    }
    else if(digitCount == 12){
        std::cout << "check digit is: " << createCheckDigitNumberSimulator(total) << std::endl;
    }
    else {
        std::cout << "Invalid ISBN number\n";
    }
}

int main() {
    ISBNSystem isbnSystem;
    isbnSystem.simulator();
}