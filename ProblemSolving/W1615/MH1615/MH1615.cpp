#include <iostream>
#include <cstdio>
#include <time.h>
#include <stdio.h>

using namespace std;

int way[200] = {0, };

int main(void)
{
    freopen("sample_input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    int begin = clock();

    for(int tc=1;tc<=T;tc++)
    {
        int N;
        cin >> N;

        for(int i=0;i<200;i++)
        {
            way[i] = 0;
        }

        for(int i=0;i<N;i++)
        {
            int a, b;
            int min, max;
            scanf("%d %d", &a, &b);

            a = (a - 1) / 2;
            b = (b - 1) / 2;

            if(a > b)
            {
                max = a;
                min = b;
            }
            else
            {
                max = b;
                min = a;
            }

            for(int j=min;j<=max;j++)
            {
                way[j]++;
            }
        }

        int max = 0;
        for(int i=0;i<200;i++)
        {
            if(way[i] > max)
                max = way[i];
        }
        cout << max << endl;
    }

    cout << (double) (clock() - begin) / CLOCKS_PER_SEC << endl;;

    return 0;
}
