#include <iostream>
#include <cstdio>
#include <time.h>

#define INF 1000
#define NOT_DECIDE 999

#define MAX_N 150
#define MAX_V 500
#define MAX_L 500

using namespace std;

typedef struct _Edge{
    int V;
    int L;
} Edge;

Edge edge[MAX_N][MAX_N];
bool bVisit[MAX_N] = {false, };
double adj[MAX_N][MAX_N] = {0, };
double spent_time[MAX_N] = {INF, };
int ShortLoc[MAX_N] = {0, };

void print_adj(int N)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%-.lf ", adj[i][j]);
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
                adj[i][j] = 0;
            }
            else
            {
                adj[i][j] = INF;
            }
        }
    }
}

int GetNear(int CurLoc, int N)
{
    double MinTime = INF;
    int near = -1;
    for(int i=0;i<N;i++)
    {
        if(bVisit[i] == true) continue;
        if(CurLoc == i) continue;
        if(adj[CurLoc][i] == INF) continue;

        if(adj[CurLoc][i] < MinTime)
        {
            MinTime = adj[CurLoc][i];
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
        if(adj[CurLoc][i] != 0 && adj[CurLoc][i] != INF)
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

    for(int tc=1;tc<=2;tc++)
    {
        int N, M, D; // N : num of city, M : num of road, D : Target city
        cin >> N >> M >> D;

        //cout << N << " " << M << " " << D << " " << endl;
        init(N);

        for(int i=0;i<M;i++)
        {
            int S, E, V, L; // S : start city, E : End city, V : Velocity, L : Length
            cin >> S >> E >> V >> L;
            //cout << S << " " << E << " " << V << " " << L << endl;

            if(S == 0 && V == 0) V = 70;
            if(V != 0)
            {
                adj[S][E] = (double) L / V;
            }
            else
            {
                adj[S][E] = NOT_DECIDE;
            }
            edge[S][E].V = V;
            edge[S][E].L = L;
        }
        //print_adj(N);

        int CurrentLocation = 0;
        spent_time[0] = 0;
        bVisit[0] = true;
        ShortLoc[0] = 0;

        for(int i=0;i<N-2;i++)
        {
            int nNumOfOut = 0;
            int OutArr[MAX_N];
            GetOutGoing(CurrentLocation, nNumOfOut, OutArr, N);

            for(int j=0;j<nNumOfOut;j++)
            {
                double time;
                if(adj[CurrentLocation][OutArr[j]] == NOT_DECIDE)
                {
                    time = (double) edge[CurrentLocation][OutArr[j]].L / edge[ShortLoc[ShortLoc[CurrentLocation]]][CurrentLocation].V;
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

            int near = GetNear(CurrentLocation, N);
            //cout << "near : " << near << endl;
            CurrentLocation = near;
            bVisit[CurrentLocation] = true;
            //ShortLoc[near] = CurrentLocation;
            //bVisit[near] = true;

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
    }

    cout << (double) (clock() - begin) / CLOCKS_PER_SEC << endl;

    return 0;
}
