#include <iostream>
#include <cstdio>
#include <stdio.h>

using namespace std;

#define MAX_LEN 50

int main(void)
{
    freopen("sample_input.txt", "r", stdin);
    int T;   
    
    cin >> T;
        
    for(int tc=1;tc<=T;tc++)
    {
        char Mem[MAX_LEN] = {0,};
        char ch = 100;
        int nCount = 0;
		  int nCurBit = 0;
        
        scanf("%s", Mem);
        //cout << Mem << endl;
        
        for(int i=0;i<MAX_LEN;i++)
        {
            if(Mem[i]=='\0')
            {
                break;
            }
            //cout << Mem[i] << " ";
			   if(nCurBit == (Mem[i] - '0')) continue;
			
		      (nCurBit == 0) ? nCurBit = 1 : nCurBit = 0;
			   nCount++;
        }

        //cout << endl;

		  cout << nCount << endl;
    }
    
    return 0;
}
