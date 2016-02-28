#include <iostream>
using namespace std;

#define _DEBUG_

#ifdef _DEBUG_
#include <cstdio>
#include <time.h>
#endif

#define MAXNUM 1000000

bool bChecked[MAXNUM] = {false, };
bool bCorrectNum[MAXNUM] = {false, };


bool CheckCorrectNum(int num)
{
	if((num % 4) != 1)
	{
		return false;
	}

	// check whether num is prime or not
	if(num == 1)
	{
		return false;
	}

	for(int i=2;i<=num/2;i++)
	{
		if((num % i) == 0)
		{
			return false;
		}
	}
	return true;
}


int main(void)
{
#ifdef _DEBUG_
	freopen("MH1607.txt", "r", stdin);
	int begin = clock();
#endif

	int T;
	cin >> T;

	for(int tc = 0;tc < T; tc++)
	{
		int L, R, nCount = 0;
		scanf("%d %d", &L, &R);

		for(int idx = L;idx<=R;idx++)
		{
			if(bChecked[idx] == true)
			{
				if(bCorrectNum[idx] == true)
				{
					nCount++;
				}
			}
			else
			{
				bChecked[idx] = true;
				bCorrectNum[idx] = CheckCorrectNum(idx);
				if(bCorrectNum[idx] == true)
				{
					nCount++;
				}
			}
		}
		cout << nCount << endl;
	}

#ifdef _DEBUG_
	double time = (double) (clock() - begin) / CLOCKS_PER_SEC;
	printf("Spent time : %lf", time);
#endif
	return 0;
}
