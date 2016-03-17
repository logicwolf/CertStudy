#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

#define SIZE 10
//#define SIMPLE_SOL

void FindMinMaxIndexExceptZero(int arrBookCase[], int nSize, int &nMinIdx, int &nMaxIdx)
{
    int nMin = 0xFFFF; 
    int nMax = -1;
    for(int i=0;i<nSize;i++)
    {
        if( (arrBookCase[i] != 10 ) && ( arrBookCase[i] > nMax ) ) 
        {
            nMax = arrBookCase[i];
            nMaxIdx = i;
        }
        if( (arrBookCase[i] !=  0 ) && ( arrBookCase[i] < nMin ) ) 
        {
            nMin = arrBookCase[i];
            nMinIdx = i;
        }
    }
//cout << "nMinIdx : " << nMinIdx << " nMaxIdx : " << nMaxIdx << endl;
}

void Move(int arrBookCase[], int nMin, int nMax)
{
    arrBookCase[nMin]--;
    arrBookCase[nMax]++;
}

int CheckNumOfEmpty(int arrBookCase[], int nSize)
{
    int nCount = 0;
    for(int i=0;i<nSize;i++)
    {
        if(arrBookCase[i] == 0) nCount++;
    }
    return nCount;
}

void PrintBookCase(int arrBookCase[], int nSize)
{
    for(int i=0;i<nSize;i++)
    {
        cout << arrBookCase[i] << " ";
    }
    cout << endl;
}

void swap(int &a, int &b)
{
    int temp;
    
    temp = a;
    a = b;
    b = temp;
}

void QuickSort(int arr[], int start, int end)
{
    if (start >= end) return;
    
    int pivot = arr[start];
    int l = start + 1;
    int r = end;
    
    while(l <= r)
    {
        while(arr[l] >= pivot && l<=r) l++;
        while(arr[r] <= pivot && l<=r) r--;
        if(l < r)
            swap(arr[l], arr[r]);        
    }
    swap(arr[start], arr[r]);
    QuickSort(arr, start, r-1);
    QuickSort(arr, r+1, end);
}

int main(void)
{
    int begin = clock();
    int arrBookCase[SIZE] = {9, 8, 4, 10, 0, 8, 6, 3, 9, 1};
    int nMove = 5;

#ifdef SIMPLE_SOL
    PrintBookCase(arrBookCase, 10);
    for(int i=0;i<nMove;i++)
    {
        int nMin=0, nMax=0;
        FindMinMaxIndexExceptZero(arrBookCase, SIZE, nMin, nMax);
        Move(arrBookCase, nMin, nMax);
        PrintBookCase(arrBookCase, SIZE);   
    }
    cout << "Result : " << CheckNumOfEmpty(arrBookCase, SIZE) << endl;
#else
    PrintBookCase(arrBookCase, SIZE);
    QuickSort(arrBookCase, 0, SIZE-1);
    PrintBookCase(arrBookCase, SIZE);
    
    for(int i=0;i<nMove;i++)
    {
        int nMin=0, nMax=0;
        FindMinMaxIndexExceptZero(arrBookCase, SIZE, nMin, nMax);
        Move(arrBookCase, nMin, nMax);
        PrintBookCase(arrBookCase, SIZE);
    }
    cout << "Result : " << CheckNumOfEmpty(arrBookCase, SIZE) << endl;
#endif
    
    double spent = (double) (clock() - begin) / CLOCKS_PER_SEC;
    cout.setf(ios::fixed, ios::floatfield);
    cout << "spent time : " << spent << endl; 
    return 0;
}