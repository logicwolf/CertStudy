#include <iostream>

#define MAX 4

using namespace std;

bool Check(int Arr[], int i, int k)
{
    for(int idx=1;idx<k;idx++)
    {
        if(i == Arr[idx]) return true;
    }
    return false;
}

void PrintArr(int Arr[], int k)
{
    for(int i=1;i<=k;i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;
}

void Permut(int Arr[], int k, int input)
{
    if( k == input )
    {
        PrintArr(Arr, k);
    }
    else
    {
        k++;
        for(int i=1;i<=input;i++)
        {
            if(Check(Arr, i, k)) continue;
            Arr[k] = i;
            Permut(Arr, k, input);
        }
    }
}

int main(void)
{
    int Arr[MAX] = {0, };
    Permut(Arr, 0, 3);        
    return 0;
}