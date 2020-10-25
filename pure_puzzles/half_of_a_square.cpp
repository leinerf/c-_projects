#include <iostream>
#include <string>

std::string create_half_square(int length) {
        std::string result;
        for(int i=0;i < length; i++) {
                int lineCount = length - i;
                for(int j=0; j < lineCount; j++) {
			result+="#";
                }
		result+="\n";
        }
        return result;
}

void create_half_square_without_string(int length) {
	for(int i=0; i < length; i++){
		int lineCount = length - i;
		for(int j=0; j < lineCount; j++) {
			std::cout << '#';
		}
		std::cout << '\n';
	}
}
int main () {
	std::cout << create_half_square(5);
	create_half_square_without_string(5);	
}
