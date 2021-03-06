#include <iostream>
#include <cstdio>
#include <time.h>
#include <stdio.h>

#define INF 1000
#define NOT_DECIDE 999

#define MAX_V 500
#define MAX_L 500
#define MAX_N 10*500

using namespace std;

bool bVisit[MAX_N] = {false, };
double adj[MAX_N][MAX_N][3];      // 0 : V, 1 : L, 2 : time
double spent_time[MAX_N] = {INF, };
int ShortLoc[MAX_N] = {0, };

void print_adj(int N, int opt)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%-lf ", adj[i][j][opt]);
        }
        cout << endl;
    }
    cout << endl;
}

void print_time(int N)
{
    for(int i=0;i<N;i++)
    {
        printf("%lf ", spent_time[i]);
    }
    cout << endl << endl;
}

void init(int N)
{
    for(int i=0;i<N;i++)
    {
        bVisit[i] = false;
        spent_time[i] = INF;
        ShortLoc[i] = 0;
        for(int j=0;j<N;j++)
        {
            if(i == j)
            {
                adj[i][j][0] = 0;
                adj[i][j][1] = 0;
                adj[i][j][2] = 0;
            }
            else
            {
                adj[i][j][0] = 0;
                adj[i][j][1] = 0;
                adj[i][j][2] = INF;
            }
        }
    }
}

int GetNear(int N)
{
    double MinTime = INF;
    int near = -1;
    for(int i=0;i<N;i++)
    {
        if(bVisit[i] == true) continue;

        if(spent_time[i] < MinTime)
        {
            MinTime = spent_time[i];
            near = i;
            //cout << MinTime << endl;
        }
    }
    return near;
}

void GetOutGoing(int CurLoc, int& nNumOfOut, int OutLoc[], int N)
{
    for(int i=0;i<N;i++)
    {
        if(adj[CurLoc][i][1] != 0)
        {
            OutLoc[nNumOfOut++] = i;
        }
    }
}

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

        //cout << N << " " << M << " " << D << " " << endl;
        //init(N);

        for(int i=0;i<M;i++)
        {
            int S, E, V, L; // S : start city, E : End city, V : Velocity, L : Length
            cin >> S >> E >> V >> L;
            //cout << S << " " << E << " " << V << " " << L << endl;

            if(S == 0 && V == 0) V = 70;
            if(V != 0)
            {
                adj[S][E][0] = V;
                adj[S][E][1] = L;
                adj[S][E][2] = (double) L / V;
            }
            else
            {
                adj[S][E][0] = 0;
                adj[S][E][1] = L;
                adj[S][E][2] = NOT_DECIDE;
            }
        }
        //print_adj(N, 2);

        // make new loc and edge

#if 0
        int CurrentLocation = 0;
        spent_time[0] = 0;
        bVisit[0] = true;
        ShortLoc[0] = 0;

        for(int i=0;i<N;i++)
        {
            int near;
            if(i==0) near = 0;
            else near = GetNear(N);
            cout << "near : " << near << endl;
            CurrentLocation = near;
            bVisit[CurrentLocation] = true;
            //ShortLoc[near] = CurrentLocation;
            //bVisit[near] = true;

            int nNumOfOut = 0;
            int OutArr[MAX_N];
            GetOutGoing(CurrentLocation, nNumOfOut, OutArr, N);

            for(int j=0;j<nNumOfOut;j++)
            {
                double time;
                if(adj[CurrentLocation][OutArr[j]] == NOT_DECIDE)
                {
                    int V;
                    if(CurrentLocation == 0) V=70;
                    else V = edge[ShortLoc[CurrentLocation]][CurrentLocation].V;
                    time = (double) edge[CurrentLocation][OutArr[j]].L / V;
                }
                else
                {
                    time = adj[CurrentLocation][OutArr[j]];
                }

                if(spent_time[OutArr[j]] > (spent_time[CurrentLocation] + time))
                {
                    spent_time[OutArr[j]] = spent_time[CurrentLocation] + time;
                    ShortLoc[OutArr[j]] = CurrentLocation;
                }
            }
            print_time(N);
        }
        int loc = D;
        int nTrace = 0;
        int Trace[MAX_N];
        Trace[nTrace++] = loc;
        while(loc != 0)
        {
            loc = ShortLoc[loc];
            Trace[nTrace++] = loc;

        }

        for(int i=0;i<nTrace;i++)
        {
            printf("%d ", Trace[nTrace - i - 1]);
        }
        cout << endl;
#endif
    }

    cout << (double) (clock() - begin) / CLOCKS_PER_SEC << endl;

    return 0;
}
