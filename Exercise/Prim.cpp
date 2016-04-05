#include <iostream>

using namespace std;

#define INF 0xFFFFFFF
#define VERTICES 7

int adj_mat[VERTICES][VERTICES] = {
    {0, 32, 31, INF, INF, 60, 51},
    {32, 0, 21, INF, INF, INF, INF},
    {31, 21, 0, INF, 46, INF, 25},
    {INF, INF, INF, 0, 34, 18, INF},
    {INF, INF, 46, 34, 0, 40, 51},
    {60, INF, INF, 18, 40, 0, INF},
    {51, INF, 25, INF, 51, INF, 0}
};

int Dist[VERTICES] = {INF, };
bool bVisit[VERTICES] = {false,};

int getMinNode(int n)
{
    int v;
    for(int i=0;i<n;i++)
    {
        if(bVisit[i] == false)
        {
            v = i;
            break;   
        } 
    }
    
    for(int i=0;i<n;i++)
    {
        if(bVisit[i] ==false && Dist[i] < Dist[v]) v = i;
    }
    return v;
}

void prim(int s, int n)
{
    for(int i=0;i<n;i++)
    {
        Dist[i] = INF;
        bVisit[i] = false;
    }
    
    Dist[s] = 0;
    
    for(int i=0;i<n;i++)
    {
        int u = getMinNode(n);
        bVisit[u] = true;
        cout << "Selected Node : " << u << endl;
        for(int v=0;v<n;v++)
        {
            if(adj_mat[u][v] == INF) continue;
            
            if(bVisit[v] == true) continue;
            
            if( adj_mat[u][v] < Dist[v] )
                Dist[v] = adj_mat[u][v];
        }
    }
    
    for(int i=0;i<n;i++)
    {
        cout << Dist[i] << " ";
    }
    cout << endl;
}


int main(void)
{
    prim(0, VERTICES);
    return 0;
}