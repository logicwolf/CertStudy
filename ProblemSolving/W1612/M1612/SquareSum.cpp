#include <iostream>
#include <cstdio>

using namespace std;

#define MAX_N 10
#define VERY_LARGE_NUM 1000000000000000

int main(void)
{
    freopen("sample_input.txt", "r", stdin);
    
    int T;
    cin >> T;
    
    for(int tc=1;tc<=T;tc++)
    {
        int N;
        cin >> N;
        
        int input[MAX_N] = {0, };
        unsigned long long nSum[2] = {0,0};
        
        for(int i=0;i<N;i++)
        {
            unsigned long long nLocalSum[2] = {1, 0};
            int base, exp;
            cin >> input[i];
            
            base = input[i]/10;
            exp = input[i]%10;
            
            for(int j=0;j<exp;j++)
            {
                nLocalSum[0] *= base;
                nLocalSum[1] *= base;
                if(nLocalSum[0] > VERY_LARGE_NUM)
                {
                    nLocalSum[1] += nLocalSum[0] / VERY_LARGE_NUM;
                    nLocalSum[0] = nLocalSum[0] % VERY_LARGE_NUM;
                }
            }
            nSum[0] += nLocalSum[0];
            nSum[1] += nLocalSum[1];
            if(nSum[0] > VERY_LARGE_NUM) 
            {
                nSum[1] += nSum[0] / VERY_LARGE_NUM;
                nSum[0] = nSum[0] % VERY_LARGE_NUM;
            }  
        } 
        if(nSum[1] > 0) cout << nSum[1];
        cout << nSum[0] << endl;
    }    
    
    return 0;
}