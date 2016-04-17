#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
    freopen("sample_input.txt", "r", stdin);
        
    int T;
    int baseD = 11, baseH = 11, baseM = 11;
    cin >> T;
    
    for(int i=0;i<T;i++)
    {
        int D, H, M;
        int diffD, diffH, diffM;
        int total;
        bool bCarry = false;
        cin >> D >> H >> M;
        
        diffM = M - baseM;
        if(diffM < 0)
        {
            diffM += 60;
            bCarry = true;
        }
        
        if(bCarry == true) 
        {
            H -= 1;
            bCarry = false;
        }
        
        diffH = H - baseH;
        
        if(diffH < 0)
        {
            diffH += 24;
            bCarry = true;
        }
        
        if(bCarry == true)
        {
            D -= 1;
            bCarry = false;
        }
        
        diffD = D - baseD;
        
        if(diffD < 0)
        {
            cout << "-1" << endl;;
        }
        else
        {
            cout << diffD*24*60 + diffH*60 + diffM << endl;
        }
    }
    
    return 0;
}