//============================================================================
// Name        : W1607.cpp
// Author      : Jae-Hwan, Sim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================
#include <iostream>
#define _DEBUG_

#ifdef _DEBUG_
#include <cstdio>
#include <time.h>
#endif

using namespace std;

int main(void)
{
#ifdef _DEBUG_
	freopen("M1607.txt", "r", stdin);
	int begin = clock();
#endif
	int T;
	scanf("%d", &T);

	for(int tc=0; tc < T; tc++)
	{
		int A, B, C, D;
		scanf("%d %d %d %d", &A, &B, &C, &D);

		if(A*D > B*C) cout << "ALICE" << endl;
		else if(A*D < B*C) cout << "BOB" << endl;
		else cout << "DRAW" << endl;
	}

#ifdef _DEBUG_
	double time = (double) (clock() - begin) / CLOCKS_PER_SEC;
	printf("Spent time : %lf\n", time);
#endif

	return 0;
}
