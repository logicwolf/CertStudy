#include <iostream>
#include <cstdio>

using namespace std;
#define MAX_E 30
typedef struct _Edge{
    int u;
    int v;
    int dist;
} Edge;

Edge edge[MAX_E];
bool bSelected[MAX_E];
int p[MAX_E];

int numV;
int numEdge;

int find_set(int x)
{
    if(p[x] == x) return x;
    else find_set(p[x]);
} 

void union_set(int u, int v)
{
    p[find_set(v)] = find_set(u);
}

void make_set(int x)
{
    p[x] = x;
}

void SWAP(Edge& l, Edge& r)
{
    Edge temp;
    
    temp.u = l.u;
    temp.v = l.v;
    temp.dist = l.dist;
    
    l.u = r.u;
    l.v = r.v;
    l.dist = r.dist;
    
    r.u = temp.u;
    r.v = temp.v;
    r.dist = temp.dist;
}

void QuickSort(int start, int end)
{
    if(start >= end) return;
    
    int l = start + 1;
    int r = end;
    int pivot = start;
    
    while(l <= r)
    {
        while(edge[l].dist <= edge[pivot].dist  && l <= r) l++;
        while(edge[r].dist >= edge[pivot].dist  && l <= r) r--;
        
        if(l < r)
            SWAP(edge[l], edge[r]);
    }
    SWAP(edge[start], edge[r]);
    
    QuickSort(start, r-1);
    QuickSort(r+1, end);
}

void PrintEdge(int num)
{
    for(int i=0;i<num;i++)
    {
        cout << "(" << edge[i].u << ", " << edge[i].v << ") : " << edge[i].dist << endl;
    }
    cout << endl;
}

int main(void)
{
    freopen("mst_input.txt", "r", stdin);
    
    cin >> numV >> numEdge;
    
    for(int i=0;i<=numEdge;i++)
    {
        cin >> edge[i].u >> edge[i].v >> edge[i].dist;
    }
#if 0    
    make_set(1);
    make_set(2);
    make_set(3);
    
    cout << find_set(1) << " " << find_set(2) << " " << find_set(3) << endl;
    
    union_set(2, 3);
    cout << find_set(1) << " " << find_set(2) << " " << find_set(3) << endl;
    union_set(1, 2);
    cout << find_set(1) << " " << find_set(2) << " " << find_set(3) << endl;
#endif
   
    for(int i=0;i<numV;i++) 
    {
        make_set(i);
        bSelected[i] = false;
    }

    // 정렬
    //PrintEdge(numEdge);
    QuickSort(0, numEdge-1);
    //PrintEdge(numEdge);
    
    for(int i=0;i<numEdge;i++)
    {
        if(find_set(edge[i].u) != find_set(edge[i].v))
        {
            bSelected[i]=true;
            union_set(edge[i].u, edge[i].v);
        }
    }
    
    // Print MST
    for(int i=0;i<numEdge;i++)
    {
        if(bSelected[i] == false) continue;
      
        cout << "(" << edge[i].u << ", " << edge[i].v << ") : " << edge[i].dist << endl;
    }
    
    return 0;
}