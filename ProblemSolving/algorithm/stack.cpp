#include <iostream>

using namespace std;
#define STACK_SIZE 100

typedef struct _Stack
{
    int stack[STACK_SIZE];
    int sp;
} Stack;

void CreateStack(Stack& s)
{
    s.sp = -1;
    for(int i=0;i<STACK_SIZE;i++)
    {
        s.stack[i] = 0;
    }
}

void push(Stack& s, int x)
{
    s.sp++;
    if(s.sp > STACK_SIZE)
        cout << "Stack Overflow occurs" << endl;
    else
        s.stack[s.sp] = x;
}

int pop(Stack& s)
{
    int res = 0xFFFFFFFF;
    if(s.sp < 0)
        cout << "Stack Underflow occurs" << endl;
    else
    {
        res = s.stack[s.sp];
        s.sp--;
    }
    return res;
}

int main(void)
{
    int pop_val;
    Stack s;
    CreateStack(s);

    push(s, 3);
    push(s, -1);
    push(s, 21);

    pop_val = pop(s);
    cout << "pop : " << pop_val << endl;

    pop_val = pop(s);
    cout << "pop : " << pop_val << endl;

    pop_val = pop(s);
    cout << "pop : " << pop_val << endl;

    return 0;
}
