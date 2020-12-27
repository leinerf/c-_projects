/*
------------------------
PROBLEM: HALF OF A SQUARE
Write a program that uses only two output statements, 
cout << "#" and cout << "\n", to produce a pattern of 
hash symbols shaped like half of a perfect 5 x 5 square 
(or a right triangle):
#####
####
###
##
#
-------------------------

Plan:
rtp: output half of a square in stars(*) given a length using 
	only two output statements(cout << "#" and cout << "\n")
dtp:
	sht1: print the stars
	sht2: repeatedly print the stars in a row based on length and 
		only using two output statements(cout << "#" and cout << "\n")
	sht3: print the appropriate amount of stars for each row
swwyk: dtp:sht1 > dtp:sht2 > dtp:sht1
rdtp:
	sht1: print a square with any amount of output statements
	sht2: print a square using only two output statements
	sht3: print out the number of stars needed for each row
lfa:
	a1: only using two output statements(cout << "#" and cout << "\n") and given a length
		indicates that we should use a for loop/
	a2: outputing information means needing to use an output function or libarary
e:
	e1: experiment with the input output library
*/
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
