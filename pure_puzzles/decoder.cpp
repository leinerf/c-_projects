#include <iostream>

/*
 * Don't need map since ascii key is already a map from int to char
 * Diff between capital and lowercase is 32
 * Diff 1 - 65, diff between 1-27 and 65-90 is 64
 * (x * 10) + newNum
 * Use switch statements for punctuation or if statement
 */

class Decoder {
    private:
        int state,  UPPERCASE=0, LOWERCASE=1, PUNCTUATION=2;
        void switchState();
        char uppercaseDecode(int num);
        char lowercaseDecode(int num);
        char punctuationDecode(int num);
        int modCase(int num);
        int modPunctuation(int num);
        int modNumber(int num);
        int charToInt(char digit);
        char decode(int num);
        void decodeLetter(int num);
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
        state==UPPERCASE;
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
        if(numDigit == 44){
            //decode num;
            //decide whether decode or switchState
            decodeLetter(num);
            num=0;
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
