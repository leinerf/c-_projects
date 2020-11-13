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
