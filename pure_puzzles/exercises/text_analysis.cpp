/*
Write a program that reads a line of text, counting 
the number of words, identifying the length of the 
longest word, the greatest number of vowels in a word, 
and/or any other statistics you can think of.

Plan:
    rtp: find total words, longest word, max vowel count in a word
    dtp:
        sht1: take in a line of text
        sht2: diffrentiate from one word to another
        sht3: count each word that appears
        sht4: count number of vowels in a word that appears and keep a max vowel
        sht5: count number of letters in a word and keep max letters
    rdtp:
        sht1: do analysis on one word
    swwyk: rdtp1 > dtp1 > dtp2 > dtp3 > dtp4 > dtp5
    lfa: 
    e: std::string for holding a sentence
*/
#include <string>
#include <iostream>

class TextAnalysis
{
    private:
    bool isALetter(char);
    bool isAVowel(char);
    public:
    void analyze(std::string);
};
bool TextAnalysis::isALetter(char letter)
{
    if(letter >= 65 && letter <= 90 || letter >= 97 && letter <= 122)
    {
        return true;
    }
    return false;
}

bool TextAnalysis::isAVowel(char letter)
{
    switch (letter)
    {
    case 'A':
        return true;
    case 'E':
        return true;
    case 'I':
        return true;
    case 'O':
        return true;
    case 'U':
        return true;
    case 'a':
        return true;
    case 'e':
        return true;
    case 'i':
        return true;
    case 'o':
        return true;
    case 'u':
        return true;
    default:
        return false;
    }
}

void TextAnalysis::analyze(std::string line)
{
    int maxLetters = 0;
    int maxVowels = 0;
    int wordCount = 0;
    std::cout << line.size() << std::endl;
    for(int i=0; i < line.size(); i++)
    {
        char letter=line[i];
        if(isALetter(letter)){
            int vowelCount = 0;
            int letterCount = 0;
            while(isALetter(letter))
            {
                std::cout << letter;
                if(isAVowel(letter))
                {
                    vowelCount++;
                }
                i++;
                letter=line[i];
                letterCount++;
            }
            wordCount++;
            if(maxLetters < letterCount)
            {
                maxLetters = letterCount;
            }
            if(maxVowels < vowelCount)
            {
                maxVowels = vowelCount;
            }
            std::cout << std::endl;
            std::cout << "letterCount: " << letterCount << " vowelCount: " << vowelCount << std::endl;
            std::cout << std::endl;
        }
    }
    std::cout << "TEXT ANALYSIS\n";
    std::cout << "Total Number of Words is: " << wordCount << std::endl;
    std::cout << "Max Number of Letters in A Word is: " << maxLetters << std::endl;
    std::cout << "Max Number of Vowels in A Word is: " << maxVowels << std::endl;
}

int main()
{
    TextAnalysis ta;
    ta.analyze("Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.");
}