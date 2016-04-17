#include <iostream>
#include <cstdio>
#include <time.h>
#include <stdio.h>

#define MAX_N 1000000

long long array[MAX_N] = {0,};

using namespace std;

int main(void)
{
    freopen("input.txt", "r", stdin);
    int T;
    //scanf("%d", &T);
    cin >> T;
    int begin = clock();

    for(int tc=1;tc<=T;tc++)
    {
        int N;
        scanf("%d", &N);
        //cin >> N;
        for(int i=0;i<N;i++)
        {
            scanf("%lld", &array[i]);
        }
        long long sum = 0;
        long long max = array[N-1];
        for(int j=N-2;j>=0;j--)
        {
            if(array[j] < max)
            {
                sum += (max - array[j]);
            }
            else
            {
                max = array[j];
            }
        }
        cout << sum << endl;
    }

    cout << (double) (clock() - begin) / CLOCKS_PER_SEC << endl;;

    return 0;
}
