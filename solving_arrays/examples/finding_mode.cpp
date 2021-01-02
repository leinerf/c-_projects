/*
PROBLEM: FINDING THE MODE
In statistics, the mode of a set of values is 
the value that appears most often. Write code 
that processes an array of survey data, where 
survey takers have responded to a question with a 
number in the range 1–10, to determine the mode of 
the data set. For our purpose, if multiple modes 
exist, any may be chosen.
Plan:
    rtp: get the mode of answer response that range from 1-19
    dtp:
        sht1: go through all the answers
        sht2: keep track of the count for user answers
        sht3: get the answer with the highest count
    rdtp:
        sht1: get mode if the answers were grouped
    swwyk: rdtp1 > dtp1 > dtp2 > dtp3;
    lfa: We have to go through all of the numbers
    e: use qsort

Note:
    when solving array problems think if sorting the array is beneficial
    Attr of sorted array
    * it is either sorted in the form least to greatest or greatest to least
    * it groups items that have equal values
    * arrays can also be used to keep track of frequency of integers since 
      indexes are in integers(given a range of possible outputs)
    
    Make it a habit to simulate your code in your mind with small data sample
*/
#include <stdlib.h>     /* qsort */
#include <iostream>

int compareFunc(const void* a,const void* b)
{
    int* intA = (int*) a;
    int* intB = (int*) b;
    return *intA - *intB;
}

int getModeFromSortedArr(int sortedArr[], int arrSize) 
{
    int mode;
    int maxFrequencyCount=1;
    int frequencyCount=1;
    for(int i = 1; i < arrSize; i++) {
        if(sortedArr[i] == sortedArr[i-1]){
            frequencyCount++;
        } else {
            if(frequencyCount > maxFrequencyCount) {
                mode = sortedArr[i-1];
                maxFrequencyCount=frequencyCount;
            }
            frequencyCount=0;
        }
    }
    if(frequencyCount > maxFrequencyCount) {
        mode = sortedArr[arrSize-1];
    }
    return mode;
}

int getModeUsingHistogram(int arr[], int arrSize)
{
    int hist[10]; //Since answer range is 1-10
    for(int i = 0; i < 10; i++)
    {
        hist[i] = 0;
    }
    for(int i = 0; i < arrSize; i++) 
    {
        hist[arr[i] - 1]++;
    }
    
    int mode=0;
    for(int i = 0; i < 10; i++)
    {
        if(hist[i] > hist[mode])
        {
            mode=i;
        }
    }
    return mode+1;
}

int main()
{
    const int ARRAY_SIZE = 12;
    int surveyData[ARRAY_SIZE] = {4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10};
    //Using sorting method
    std::cout << getModeUsingHistogram(surveyData, ARRAY_SIZE) << std::endl;
    qsort(surveyData, ARRAY_SIZE, sizeof(int), compareFunc);
    std::cout << getModeFromSortedArr(surveyData, ARRAY_SIZE) << std::endl;
}