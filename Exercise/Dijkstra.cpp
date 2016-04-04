#include <iostream>
#include <cstdio>
#include <stdio.h>

using namespace std;
#define MAX_V   10
#define INF     0xFFFFFFF

int adj[MAX_V][MAX_V] = {INF, };
int Dist[MAX_V] = {INF,};
bool bVisit[MAX_V] = {false,};

void PrintAdj(int V)
{
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(adj[i][j] == INF) 
                printf("INF  ");
            else
                printf("%3d  ", adj[i][j]);   
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
} 

void PrintDist(int V)
{
    for(int i=0;i<V;i++)
    {
        if(Dist[i] == INF)
            printf("INF  ");
        else
            printf("%-3d  ", Dist[i]);
    }
    cout << endl;
    cout << endl;
}

int getShortDist(int VNum)
{
    int min = INF;
    int idx = 0;
    for(int i=1;i<VNum;i++)
    {
        if(bVisit[i]==true) continue;
        
        if(Dist[i] <= min)
        {
            min = Dist[i];
            idx = i;
        }
    }
    return idx;
}

void FindOutGoing(int node, int VNum, int out[], int& nNum)
{
    for(int i=0;i<VNum;i++)
    {
        if(adj[node][i] == INF) continue;
        out[nNum++] = i;
    }
}

int main(void)
{
    freopen("Dijkstra_input.txt", "r", stdin);
    
    int V, E;
    
    cin >> V >> E;
    //초기화 
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
            adj[i][j] = INF;
        Dist[i] = INF;
        bVisit[i] = false;
    }
    
    Dist[0] = 0;
    // 인접 행렬 & dist vector
    for(int i=0;i<E;i++)
    {
        int s, e, cost;
        cin >> s >> e>> cost;
        
        adj[s][e] = cost;
        
        if(s == 0)
            Dist[e] = cost;
    }
    
    bVisit[0] = true;
    
    cout << "Adj Map" << endl;
    PrintAdj(V);
    cout << endl;
    
    //cout << "Dist" << endl;
    //PrintDist(V);
    
    for(int i=0;i<V-1;i++)
    {
        int shortDist = getShortDist(V);
        int outGoing[MAX_V] = {0, };
        int nNum = 0;
        
        bVisit[shortDist] = true;
        
        FindOutGoing(shortDist, V, outGoing, nNum);
        for(int j=0;j<nNum;j++)
        {
            if(Dist[outGoing[j]] >= ( Dist[shortDist] + adj[shortDist][outGoing[j]]))
                Dist[outGoing[j]] = Dist[shortDist] + adj[shortDist][outGoing[j]];
        }
        
    }
    PrintDist(V);
    
    cout << "Hello Dijkstra" << endl;
    return 0;
}