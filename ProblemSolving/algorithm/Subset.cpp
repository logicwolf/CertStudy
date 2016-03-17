#include <iostream>

#define MAX 5

using namespace std;

void PrintSubSet(bool bArray[])
{
    for(int i=0;i<MAX;i++)
    {
        if(bArray[i] == true)
        {
            cout << i+1 << " ";
        }
    }
    cout << endl;
}

void SubSet(bool bArray[], int k, int input)
{
    if( k == input )
    {
        PrintSubSet(bArray);
    }
    else
    {
        bArray[k] = true;
        SubSet(bArray, k+1, input);
        bArray[k] = false;
        SubSet(bArray, k+1, input);    
    }
}

int main(void)
{
    bool bBinArray[MAX] = {false,};
    SubSet(bBinArray, 0, MAX);
    return 0;
}