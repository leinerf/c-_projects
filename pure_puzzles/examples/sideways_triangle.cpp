/*
PROBLEM: A SIDEWAYS TRIANGLE
Write a program that uses only two output statements,
cout << "#" and cout << "\n", to produce a pattern of hash
symbols shaped like a sideways triangle:
#
##
###
####
###
##
#

0   7 - 6 
1   7 - 5
2   7 - 4
3   7 - 3
4   7 - 4
5   7 - 5
6   7 - 6

3 - 0 = 3
3 - 1 = 2
3 - 2 = 1
3 - 3 = 0
3 - 4 = -1
3 - 5 = -2
3 - 6 = -3

4 - abs(4 - row)
----------------------

Plan:
rtp: create a sideways triangle like above only using 
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

Absolute values are great if you want to decrease a value to a certain point then increase it again.
Basically the highest value in the example will be when you are subtracting zero
*/
#include <iostream>

void createSidewaysTriangle(){
	int incr=1;
	int i=1;
    while(i > -1){
		if(i == 4) {
			incr = -1;
		}
        for(int j = 0; j < i; j++){
            std::cout << '*';
        }
        std::cout << '\n';
		i+=incr;
    }
}

int main() {
    createSidewaysTriangle();
}
