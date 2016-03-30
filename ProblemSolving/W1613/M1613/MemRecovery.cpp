#include <iostream>
#include <cstdio>
#include <stdio.h>

using namespace std;

#define MAX_LEN 50

void PrintMem(int arr[], int nCount)
{
    for(int i=0;i<nCount;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(void)
{
    freopen("sample_input.txt", "r", stdin);
    int T;   
    
    cin >> T;
        
    for(int tc=1;tc<=1;tc++)
    {
        char Mem[MAX_LEN] = {0,};
        char ch = 100;
        int nCount = 0;
        
        scanf("%s", Mem);
        //cout << Mem << endl;
        
        for(int i=0;i<MAX_LEN;i++)
        {
            if(Mem[i]=='\0')
            {
                break;
            }
            cout << Mem[i] << " ";
        }
        
        //PrintMem(Mem, nCount);
        //cout <<"nCount : " <<  nCount << endl;
    }
    
    return 0;
}