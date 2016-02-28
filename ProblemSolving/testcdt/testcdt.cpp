//============================================================================
// Name        : testcdt.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <iostream>
#include <time.h>

using namespace std;

int main(void)
{
	int a = 9;
	int begin = clock();
	cout << "Hello cpp test world!!! : " << a + 1 + 1 << endl;

	double spent = (double) (clock() - begin) / CLOCKS_PER_SEC;

	cout << "Spent Time : " << spent << endl;

	return 0;
}
