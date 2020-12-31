/*
make a program that converts from any number base-16 or less to any other number base
Plan:
    rtp: create a number converter that takes a baseX number and change it to baseY number
    dtp:
        sht1: know algorithm for converting baseX to base10
        sht2: implement algorithm for converting baseX to base10
        sht3: know algorithm for converting base10 to baseX
        sht4: implement algorithm for converting base10 to baseX
    rdtp:
        sht1: create a converter alg from binary to decimal vice versa
        sht2: create a converter alg from decimal to hexadecimal vice versa
        sht3: create a converter alg from binary to hexadecimal vice versa
    swwyk: rdtp1 > rdtp2 > rdtp3 > dtp1 dtp2
    lfa:
    e:
*/
#include <iostream>
#include <string>
#include <cmath>

class Base16Converter
{
private:
    int charToNum(char);
    char numToChar(int);
    std::string convertBase10ToBaseX(int, int);
    int convertBaseXToBase10(int, std::string);

public:
    std::string convertBaseToBase(int, int, std::string);
};

int Base16Converter::charToNum(char digit)
{
    switch (digit)
    {
    case 'A':
        return 10; 
    case 'B':
        return 11;
    case 'C':
        return 12;
    case 'D':
        return 13;
    case 'E':
        return 14;
    case 'F':
        return 15;
    default:
        return digit - '0';
    }
}

char Base16Converter::numToChar(int digit)
{
    switch (digit)
    {
        case 10:
            return 'A'; 
        case 11:
            return 'B';
        case 12:
            return 'C';
        case 13:
            return 'D';
        case 14:
            return 'E';
        case 15:
            return 'F';
        default:
            return digit + '0';
    }
}
int Base16Converter::convertBaseXToBase10(int base, std::string digits)
{
    int result = charToNum(digits[0]);
    for (int i = 1; i < digits.size(); i++)
    {
        int multiplier;
        if (base > 10)
        {
            multiplier = std::pow(base, digits.size() - i);
        }
        else
        {
            multiplier = base;
        }
        result = result * multiplier;
        result += charToNum(digits[i]);
    }
    return result;
}

std::string Base16Converter::convertBase10ToBaseX(int base, int num)
{
    int quotient = num;
    int remainder;
    std::string result;
    do
    {
        remainder = quotient%base;
        result = numToChar(remainder) + result;
        quotient = quotient/base;
    } while (quotient != 0);
    return result;
}

std::string Base16Converter::convertBaseToBase(int base1, int base2, std::string digits)
{
    return convertBase10ToBaseX(base2, convertBaseXToBase10(base1, digits));
}

int main()
{
    Base16Converter b16c;
    std::cout << b16c.convertBaseToBase(10, 16, "30") << std::endl;
    std::cout << b16c.convertBaseToBase(10, 14, "30") << std::endl;
    std::cout << b16c.convertBaseToBase(10, 12, "323") << std::endl;
    std::cout << b16c.convertBaseToBase(10, 2, "323") << std::endl;
}
