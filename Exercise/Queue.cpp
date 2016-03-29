#include <iostream>

using namespace std;

#define Q_SIZE 5

typedef struct _Queue
{
    int Q[Q_SIZE];
    int front;
    int rear;
} Queue;

Queue gQueue;

void CreateQueue()
{
    for(int i=0;i<Q_SIZE;i++)
    {
        gQueue.Q[i] = 0;
    }
    gQueue.front = -1;
    gQueue.rear = -1;
}

bool IsFull()
{
    if(gQueue.rear == Q_SIZE - 1) return true;
    return false;
}

bool IsEmpty()
{
    if(gQueue.rear == gQueue.front) return true;
    return false;
}

void enQueue(int item)
{
    if(IsFull() == true)
    {
        cout << "Queue is Full" << endl;
        return;
    }
    
    gQueue.rear++;
    gQueue.Q[gQueue.rear] = item;
}

int deQueue()
{
    if(IsEmpty() == true)
    {
        cout << "Queue is Empty" << endl;
        return -1;
    }
    
    gQueue.front++;
    return gQueue.Q[gQueue.front];
}

int main(void)
{
    int nVal = -1;
    CreateQueue();
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);
    enQueue(6);
    
    for (int i=0;i<6;i++)
    {
        nVal = deQueue();
        cout << "nVal : " << nVal << endl;
    }
    
    return 0;
}