#include <iostream>

using namespace std;

/*
to run c+r code on macOS so that you can check for memory leak do: clang++ <program>.cpp or clang <program>.c
then run: '''leaks -atExit -- ./a.out | erep LEAK:'''
*/


double *  oil_leak() {
	//allocate 8 bytes from heap
	double *pointer = new double(32.55);
	return pointer;
}

int main() {
	double *p = oil_leak();
	delete p;
}
