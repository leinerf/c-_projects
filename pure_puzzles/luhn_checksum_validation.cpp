#include <iostream>
#include <typeinfo>

//<TODO: do this with cin.get()>> and convert character to number
int main() {
    int total=0;
    int round=1;
    int number;
    while(std::cin >> number){
        if(round%2==0) {
            number=number*2;
            if(number > 10){
                total+=1;
                total+=number%10;
            }
            else {
                total+=number;
            }
        }
        else {
            total+=number;
        }

        round++;
    } 
    
    if(total%10 == 0){
        std::cout << total << " valid number" << std::endl;
    }
    else {
        std::cout << total << "invalid number" << std::endl;
    }
}
