/*
PROBLEM: COUNT DOWN BY COUNTING UP
Write a line of code that goes in the designated 
position in the loop in the listing below. The program 
displays the numbers 5 through 1, in that order, with each 
number on a separate line.

for (int row = 1; row <= 5; row++) { 
    cout << expression << "\n";
}
-----------------------------

Plan:
rtp: output the 5, 4, 3, 2, 1 by filling out the expression in the for loop above
dtp:
    sht1: get the right math expression
    sht2: get the right values for the expression
swwyk: dtp:sht1 > dtp:sht2
rdtp:
    sht1: count up from 1, 2, 3, 4, 5
lfa: this is like counting up only down
e: nothing to experiment with
*/
#include <iostream>

int main() {
    for(int row = 1; row <= 5; row++) {
        std::cout << 6 - row << "\n"; 
    }
}