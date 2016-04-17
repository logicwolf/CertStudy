#include <iostream>
#include <cstdio>
#include <time.h>

// N : num of city, M : num of road, D : Destination
// V : velocity, L : Length
#define MAX_V 500
#define MAX_L 500
#define MAX_N 150

#define INF 1000.0
#define NOT_DECIDED 600.0
#define MAX_M (MAX_N)*(MAX_N-1)/2

using namespace std;

typedef struct _EDGE
{
    int start;
    int end;
    int vel;
    int len;
    double Time;
} Edge;

int N, M, D;

Edge edge[MAX_M];
double adj[MAX_N][MAX_N] = {0,};
double Time[MAX_N] = {INF, };
int path[MAX_N] = {0,};
bool bVisit[MAX_N] = {false,};

void print_adj()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}
void Init()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(i==j)
                adj[i][j] = 0 ;
            else
                adj[i][j] = INF;
        }
        Time[i] = INF;
    }
}

int getNear(int selCity)
{
    double MinTime = INF;
    int near = 0;
    for(int i=0;i<N;i++)
    {
        double dTime = adj[selCity][i];
        if(selCity == i) continue;
        if(dTime == INF) continue;

        if(dTime == NOT_DECIDED)
        {
            for(int j=0;j<M;j++)
            {
                if(edge[j].start == selCity && edge[j].end == i)
                {
                    dTime = (double) edge[j].len / edge[j].vel;
                    break;
                }
            }
        }
        if(MinTime > dTime)
        {
            MinTime = dTime;
            near = i;
        }
    }
    return near;
}

int main(void)
{
    freopen("sample_input.txt", "r", stdin);
    int begin = clock();
    int T;

    cin >> T;

    for(int tc=1;tc<=1;tc++)
    {
        cin >> N >> M >> D;
        //cout << N << " " << M << " " << D << endl;
        Init();
        for(int i=0;i<M;i++)
        {
            // Input Processing
            int start, end, vel, len;
            cin >> start >> end >> vel >> len;
            //cout << start << " " << end << " " << vel << " " << len << endl;
            edge[i].start = start;
            edge[i].end = end;
            edge[i].vel = vel;
            edge[i].len = len;
            edge[i].Time = (vel == 0) ? NOT_DECIDED : (double) len / vel;

            adj[start][end] = edge[i].Time;
        }
        print_adj();

        int selCity = 0;
        bVisit[selCity] = true;
        Time[selCity] = 0;

        //cout << endl;

        //for(int i=0;i<N-1;i++)
        {
            int near = getNear(selCity);
            cout << "near : " << near << endl;
        }
    }

    cout << (double) (clock() - begin) / CLOCKS_PER_SEC << endl;
    return 0;
}
