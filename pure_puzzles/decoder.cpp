/*
PROBLEM: DECODE A MESSAGE
A message has been encoded as a text stream that is to be read character 
by character. The stream contains a series of comma-delimited integers, 
each a positive number capable of being represented by a C++ int. However, 
the character represented by a particular integer depends on the current decoding 
mode. There are three modes: uppercase, lowercase, and punctuation.

In uppercase mode, each integer represents an uppercase letter: The integer 
modulo 27 indicates the letter of the alphabet (where 1 = A and so on). So an 
input value of 143 in uppercase mode would yield the letter H because 143 modulo 27 
is 8 and H is the eighth letter in the alphabet.

The lowercase mode works the same but with lowercase letters; the remainder of dividing 
the integer by 27 represents the lowercase letter (1 = a and so on). So an input value of 
56 in lowercase mode would yield the letter b because 57 modulo 27 is 2 and b is the second 
letter in the alphabet.

In punctuation mode, the integer is instead considered modulo 9, with the interpretation given 
by Table 2-3 below. So 19 would yield an exclamation point because 19 modulo 9 is 1.

At the beginning of each message, the decoding mode is uppercase letters. Each time the modulo 
operation (by 27 or 9, depending on mode) results in 0, the decoding mode switches. If the 
current mode is uppercase, the mode switches to lowercase letters. If the current mode is 
lowercase, the mode switches to punctuation, and if it is punctuation, it switches back to uppercase.
----------------------------------------------------

Plan:
rtp: decode a message of comma-delimited integers that has punctuation, uppercase, and lowercase mode
dtp:
    sht1: turn a series of char of numbers into a single digit i.e '32' = 32
    sht2: know when to stop decoding because of a , or end of numbers
    sht3: know when to use puncuation mode, uppercase mode, lowercase mode
    sht4: decode message based on mode: puncuation mode, uppercase mode, lowercase mode
swwyk: dtp:sht1 > dtp:sht2 > dtp:sht3 > dtp:sht4
rdtp:
    sht1: decode an array of numbers instead of an array of number chars
    sht2: decode only using one mode
lfa: getting input is similar to the problem about luhn checksum validation
e: know how to use cin.get properly
*/
#include <iostream>

class Decoder {
    private:
        int state; 
        static const int UPPERCASE=0, LOWERCASE=1, PUNCTUATION=2;
        void switchState();
        char uppercaseDecode(int num);
        char lowercaseDecode(int num);
        char punctuationDecode(int num);
        int modCase(int num);
        int modPunctuation(int num);
        int charToInt(char digit);
        void decode(int num);
    public:
        Decoder();
        void decodeMessage();
};

//Private
void Decoder::switchState() {
    if(state == UPPERCASE) {
        state=LOWERCASE;
    }
    else if(state == LOWERCASE) {
        state=PUNCTUATION;
    }
    else if(state == PUNCTUATION) {
        state=UPPERCASE;
    }
}

char Decoder::uppercaseDecode(int num){
    return (char) (num + 64);
}

char Decoder::lowercaseDecode(int num){
    return (char) (num + 96);
}

char Decoder::punctuationDecode(int num){
    if(num == 1) {
        return '!';
    }
    else if(num == 2) {
        return '?';
    }
    else if(num  == 3) {
        return ',';
    }
    else if(num == 4) {
        return '.';
    }
    else if(num == 5) {
        return ' ';
    }
    else if(num == 6) {
        return ';';
    }
    else if(num == 7) {
        return '\"';
    }
    else {
        return '\'';
    }
}

int Decoder::modCase(int num){
    return num % 27;
}

int Decoder::modPunctuation(int num){
    return num % 9;
}

int Decoder::charToInt(char digit){
    return (int) (digit - '0');
}

void Decoder::decode(int num){
    if(state == PUNCTUATION) {
        num = modPunctuation(num);
        if(num == 0) {
            switchState();
        }
        else {
            char character = punctuationDecode(num);
            std::cout << character;
        }
    }
    else {
        num = modCase(num);
        if(num == 0) {
            switchState();
        }
        else if(state == UPPERCASE) {
            char character = uppercaseDecode(num);
            std::cout << character;
        }
        else if(state == LOWERCASE) {
            char character = lowercaseDecode(num);
            std::cout << character;
        }
    }
}
//Public
Decoder::Decoder() {
    state=UPPERCASE;
}

void Decoder::decodeMessage() {
    char charDigit;
    int num=0;
    while(std::cin.get(charDigit)){
        int numDigit = charToInt(charDigit);
        if(charDigit == 44){
            decode(num);
            num=0;
        }
        else if(charDigit == 10){
            decode(num);
            break;
        }
        else {
            num = (num * 10) + numDigit;
        }    
    }
}

int main(){
  Decoder decoder;
  decoder.decodeMessage();
}
