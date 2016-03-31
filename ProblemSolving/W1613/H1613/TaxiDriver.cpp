#include <iostream>
#include <cstdio>
#include <time.h>

using namespace std;

int main(void)
{
    freopen("sample_input.txt", "r", stdin);
    int begin = clock();
    
    int T;
    cin >> T;
    
    for(int tc=1;tc<=1;tc++)
    {
        int N, M, D; // N : num of city, M : num of road, D : Target city
        
        cin >> N >> M >> D;
        cout << N << " " << M << " " << D << " " << endl;
        
        for(int i=0;i<M;i++)
        {
            int S, E, V, L; // S : start city, E : End city, V : Velocity, L : Length
            cin >> S >> E >> V >> L;
            cout << S << " " << E << " " << V << " " << L << endl;
        }
    }
    
    cout << (double) (clock() - begin) / CLOCKS_PER_SEC << endl;
    
    return 0;
}