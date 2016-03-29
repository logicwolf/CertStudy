#include <iostream>

using namespace std;

//#define _USE_RECURSIVE_
#define _USE_STACK_

typedef struct _Point{
    int x;
    int y;
} Point;

Point pt[100];

int map[5][5] = {1, 1, 1, 1, 1,
                 1, 0, 1, 0, 2,
                 1, 0, 1, 0, 0,
                 1, 0, 1, 0, 1,
                 1, 0, 1, 1, 1
                 };
                 
bool visited[5][5] = {false, };
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int path = 0;

void PrintStep(int step)
{
    for(int i=0;i<step+1;i++)
    {
        cout << pt[i].x << " " << pt[i].y << endl;
    }
    cout << endl << endl;
}

void DFS_Recursive(int x, int y, int step)
{
    pt[step].x = x;
    pt[step].y = y;
    if(map[x][y] == 2)
    {
        cout << "Find Route : " << step << endl;
        //path = 1;
        PrintStep(step);
        return;
    }
    
    visited[x][y] = true;
    for(int i=0;i<4;i++)
    {
        if((x+dx[i] < 0) || (x+dx[i] > 4)) continue;
        if((y+dy[i] < 0) || (y+dy[i] > 4)) continue;
        if(visited[x+dx[i]][y+dy[i]] == true) continue;
        if(map[x+dx[i]][y+dy[i]] == 0) continue;
        DFS_Recursive(x+dx[i], y+dy[i], step+1);
    }
}

int main(void)
{
#ifdef _USE_RECURSIVE_
    DFS_Recursive(0, 0, 0);
#endif

#ifdef _USE_STACK_
#endif
    return 0;
}