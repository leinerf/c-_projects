/*
Using the same rule as the shapes programs from earlier in the chapter 
(only two output statements—one that outputs the hash mark and one that outputs an end-of-line), 
write a program that produces the following shapes:
*/
#include <iostream>

/*
2-1
########
 ###### 
  ####  
   ##   

Plan:
    rtp: Create a L(8) * H(4) triangle pointing down using 2 output statements
    dtp:
        sht1: output 4 rows of stars with 2 output statement
        sht2: output proper proper amount of white space and stars
        sht3: output formatted to look like a triangle pointing down
    swwyk:
        sht1 > sht2 > sht3
    rdtp:
        sht1: output number of white space and stars for each row
    lfa: it requires two for loops and math calculation using index like the half-square problem
    e: libraries used is cin & cout
*/
void trianglePointingDown() {
    for(int i=0; i < 4; i++) {
        int whiteSpace = i * 2;
        int numStars = 8 - whiteSpace;
        for(int j = 0; j < 8; j++) {
            char outputValue;
            if(j < (whiteSpace/2) || j >= numStars +  (whiteSpace/2)) {
                outputValue = ' ';
            }
            else {
                outputValue = '#';
            }
            std::cout << outputValue;
        }
        std::cout << "\n";
    }
}

/*
2-2
   ##
  ####
 ######
########
########
 ######
  ####
   ##
index   white   stars
0       6       2
1       4       4
2       2       6
3       0       8
4       0       8
5       2       6
6       4       4
7       6       6

Plan:
    rtp: Create a L(8) * H(8) diamond pointing down using 2 output statements
    dtp:
        sht1: output 4 rows of stars with 2 output statement
        sht2: output proper proper amount of white space and stars
        sht3: output formatted to look like a diamond
    swwyk:
        sht1 > sht2 > sht3
    rdtp:
        sht1: output number of white space and stars for each row
    lfa: it requires two for loops and math calculation using index
        absolute value like the sideways triangle problem 
    e: libraries used is cin & cout
*/
void diamond() {
    int incr=1;
    int i=0;
    while(i > -1) {
        if(i == 4) {
            i = 3;
            incr = -1;
        }
        int whiteSpace = 6 - (i * 2);
        int numStars = 8 - whiteSpace;

        for(int j = 0; j < 8; j++) {
            char outputValue;
            if(j < (whiteSpace/2) || j >= numStars +  (whiteSpace/2)) {
                outputValue = ' ';
            }
            else {
                outputValue = '#';
            }
            std::cout << outputValue;
        }
        std::cout << "\n";
        i+=incr;
    }
}

/*
2-3
#            # 
 ##        ## 
  ###    ### 
   ########
   ########
  ###    ### 
 ##        ## 
#            #

index   outWhite    inWhite     stars
0       0           12          2
1       2           8           4
2       4           4           6
3       6           0           8
4       6           0           8
5       4           4           6
6       2           8           4
7       0           12          2
Plan:
    rtp: Create a L(12) * H(8) cross using 2 output statements
    dtp:
        sht1: output 8 rows of stars with 2 output statement
        sht2: output proper proper amount of white space and stars
        sht3: output formatted to look like a cross
    swwyk:
        sht1 > sht2 > sht3
    rdtp:
        sht1: output number of white space and stars for each row
    lfa: it requires two loops and math calculation using index
        and going forward and backwards
    e: libraries used is cin & cout
*/
void xshape() {
    int incr=1;
    int i=0;
    while(i > -1) {
        if(i == 4) {
            i = 3;
            incr = -1;
        }
        int outWhiteSpace = i * 2;
        int inWhiteSpace = 12 - (i * 4);
        int numStars = 14 -(inWhiteSpace + outWhiteSpace);
        for(int j = 0; j < 14; j++) {
            char outputValue;
            //in range of inner whitespace or outerwhitespace
            if(j < outWhiteSpace/2 || 
            j >= numStars + inWhiteSpace + outWhiteSpace/2 || 
            j >= (numStars + outWhiteSpace)/2 && j < (numStars + outWhiteSpace)/2 + inWhiteSpace) {
                outputValue = ' ';
            }
            else {
                outputValue = '#';
            }
            std::cout << outputValue;
        }
        std::cout << "\n";
        i+=incr;
    }
}

/*
2-4
########
 ######
  ####
   ##
   ##
  ####
 ######
########
Plan:
    rtp: Create a L(8) * H(8) hourglass using 2 output statements
    dtp:
        sht1: output 4 rows of stars with 2 output statement
        sht2: output proper proper amount of white space and stars
        sht3: output formatted to look like a hourglass
    swwyk:
        sht1 > sht2 > sht3
    rdtp:
        sht1: output number of white space and stars for each row
    lfa: it requires two for loops and math calculation using index
        absolute value like the sideways triangle problem 
    e: libraries used is cin & cout
*/
void hourglass() {
    int incr=1;
    int i=0;
    while(i > -1) {
        if(i == 4) {
            i = 3;
            incr = -1;
        }
        int whiteSpace = (i * 2);
        int numStars = 8 - whiteSpace;

        for(int j = 0; j < 8; j++) {
            char outputValue;
            if(j < (whiteSpace/2) || j >= numStars +  (whiteSpace/2)) {
                outputValue = ' ';
            }
            else {
                outputValue = '#';
            }
            std::cout << outputValue;
        }
        std::cout << "\n";
        i+=incr;
    }
}
int main() {
    trianglePointingDown();
    std::cout << std::endl;
    diamond();
    std::cout << std::endl;
    xshape();
    std::cout << std::endl;
    hourglass();
}