#include <iostream>
#include <time.h>
#define MAX 10
using namespace std;

//int arr[MAX] = {-1, 3, 9, 6, 7, -6, 1, 5, 4, -2};
int arr[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void PrintSubSet(bool bSelect[])
{
    for(int i=0;i<MAX;i++)
    {
        if(bSelect[i]==true)
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

void subSet(bool bSelect[], int k, int input, int sum)
{
    if(k == input)
    {
        if(sum == 10)
            PrintSubSet(bSelect);
    }
    else
    {
        bSelect[k] = true;
        subSet(bSelect, k+1, input, sum+arr[k]);
        bSelect[k] = false;
        subSet(bSelect, k+1, input, sum);
    }
}

int main(void)
{
    bool bSelect[MAX] = {false, };
    int begin = clock();

    subSet(bSelect, 0, MAX, 0);

    cout.setf(ios::fixed, ios::floatfield);
    cout << "Spent Time : " << (double) (clock() - begin) / CLOCKS_PER_SEC << endl;

    return 0;
}
