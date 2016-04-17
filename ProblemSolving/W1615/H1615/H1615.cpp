#include <iostream>
#include <cstdio>
#include <time.h>
#include <stdio.h>

using namespace std;
#define MAX_N 10000
int height[MAX_N] = {0, };

void Swap(int &a, int &b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}

void quick_sort(int arr[], int s, int e)
{
    if(s >= e) return;

    int pivot = arr[s];
    int l = s+1;
    int r = e;

    while(l<=r)
    {
        while(arr[l] <= pivot && l <= r) l++;
        while(arr[r] >= pivot && l <= r) r--;

        if(l < r)
            Swap(arr[l], arr[r]);
    }
    Swap(arr[s], arr[r]);

    quick_sort(arr, s, r - 1);
    quick_sort(arr, r + 1, e);
}

int main(void)
{
    freopen("sample_input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    int begin = clock();

    for(int tc=1;tc<=T;tc++)
    {
        int MaxDiff = 0;
        int N;
        cin >> N;

        for(int i=0;i<N;i++)
        {
            scanf("%d", &height[i]);
        }
        quick_sort(height, 0, N-1);

#if 0
        for(int i=0;i<N;i++) printf("%d ", height[i]);
        cout << endl;
#endif
        for(int i=0; i < N-2 ;i++)
        {
            if( ( height[i+2] - height[i] ) > MaxDiff ) MaxDiff = height[i+2] - height[i];
        }

        if( ( height[N-1] - height[N-2] ) > MaxDiff ) MaxDiff = height[N-1] - height[N-2];
        if( ( height[1] - height[0] ) > MaxDiff ) MaxDiff = height[1] - height[0];

        cout << MaxDiff << endl;
    }

    cout << (double) (clock() - begin) / CLOCKS_PER_SEC << endl;;

    return 0;
}
