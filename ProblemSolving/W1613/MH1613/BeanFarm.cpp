#include <iostream>

#define _DEBUG_
#ifdef _DEBUG_
#include <cstdio>
#include <time.h>
#endif

#define _USING_ITOR_

using namespace std;
#define MAX 1000
#ifdef _USING_ITOR_
int dx[2] = {-2, 0};
int dy[2] = {0, -2};

bool IsAvail(int x, int y)
{
    if (x < 0 || x >= MAX) return false;
    if (y < 0 || y >= MAX) return false;
    
    return true;
}

#endif

int main(void)
{
#ifdef _DEBUG_
    int begin = clock();
    freopen("sample_input.txt", "r", stdin);
#endif

    int T;
    
    cin >> T;    
    for (int tc=1;tc<=T;tc++)
    {
        int N, M;
        int nCount = 0;
        cin >> N >> M;
        cout << N << " " << M << endl ;
#ifndef _USING_ITOR_
        int LongSide, ShortSide;
        if(N <= M)
        {
            LongSide = M;
            ShortSide = N;
        }
        else
        {
            LongSide = N;
            ShortSide = M;
        }
        
        nCount = (ShortSide / 2) * 4;
        
        if((ShortSide % 2) == 1)
        {
            nCount += ((LongSide - ShortSide) >= 1) ? 2 : 1 ;
        } 
#else
        bool bVisit[MAX][MAX] = {false,};
        
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                int nVisitFlag = 0;
                for(int k=0;k<2;k++)
                {
                    int x, y;
                    x = i + dx[k];
                    y = j + dy[k];
                    
                    if(IsAvail(x, y) == false)
                    {
                        nVisitFlag++;
                        continue;  
                    } 
                    if(bVisit[x][y] == true) 
                    {
                        break;
                    }
                    else
                    {
                        nVisitFlag++;   
                    }
                }
                
                if(nVisitFlag == 2)
                {
                    bVisit[i][j] = true;
                    nCount++;
                }
            }
        }
#endif       
        cout << nCount << endl;
    }
#ifdef _DEBUG_
    cout << (double) (clock() - begin) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}