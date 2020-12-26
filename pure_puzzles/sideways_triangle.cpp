#include <iostream>

void createSidewaysTriangle(){
    int poundCount=1;
    int switcher=1;
    for(int i=0;i < 7;i++){
        for(int j=0;j < poundCount ; j++){
            std::cout << '#';
        }
        if(i == 3) {
            switcher= -1;
        }
        poundCount = poundCount + (switcher * 1);
        std::cout << '\n';
    }
}

int main() {
    createSidewaysTriangle();
}
