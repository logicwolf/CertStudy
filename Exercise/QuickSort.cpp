//============================================================================
// Name        : QuickSort.cpp
// Author      : Jae-Hwan, Sim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <iostream>
#include <string>

using namespace std;

//#define _INT_SORT_
#define _STRUCTURE_SORT_

#if defined(_INT_SORT_)
void print_arr(int arr[], int nSize)
{
	for(int i=0;i<nSize;i++)
	{
		std::cout << arr[i] << " ";
	}
	cout << endl;
}

void Swap(int &a, int &b)
{
	int temp;

	temp =a;
	a = b;
	b = temp;
}

void QuickSort(int arr[], int start, int end)
{
	int p = arr[start];
	int l = start+1;
	int r = end;

	if(start >= end) return;

	while(l<=r)
	{
		while(arr[l] <= p && l <= r) l++;
		while(arr[r] >= p && l <= r) r--;

		if(l < r)
			Swap(arr[l], arr[r]);
	}

	Swap(arr[start], arr[r]);

	QuickSort(arr, start, r-1);
	QuickSort(arr, r+1, end);
}

void SortArray(int arr[], int nSize)
{
	QuickSort(arr, 0, nSize-1);
}
#elif defined(_STRUCTURE_SORT_)

typedef struct _Person
{
	int age;
	string name;
	int height;
} Person;

#define MAX_PERSON 5

Person per[MAX_PERSON];

void print_structure()
{
	for(int i=0;i<MAX_PERSON;i++)
	{
		cout << i << ": " << "age[" << per[i].age << "], name[" << per[i].name << "], height[" << per[i].height << "]" << endl;
	}
	cout << endl;
}

void make_structure()
{
	per[0].age = 24;
	per[0].name = "Sim";
	per[0].height = 182;

	per[1].age = 20;
	per[1].name = "kim";
	per[1].height = 162;

	per[2].age = 31;
	per[2].name = "gil";
	per[2].height = 182;

	per[3].age = 29;
	per[3].name = "lee";
	per[3].height = 172;

	per[4].age = 24;
	per[4].name = "park";
	per[4].height = 185;

}

void Swap(Person& a, Person& b)
{
	Person temp;

	temp.age = a.age;
	temp.name = a.name;
	temp.height = a.height;

	a.age = b.age;
	a.name = b.name;
	a.height = b.height;

	b.age = temp.age;
	b.name = temp.name;
	b.height = temp.height;
}

bool CompareAge(const Person& left, const Person& right)
{
	if(left.height <= right.height) return true;
	return false;
}


void QuickSort(Person perArr[], int start, int end)
{
	if (start >= end) return;

	Person p = perArr[start];
	int i = start+1;
	int j = end;

	while(i <= j)
	{
		while(CompareAge(perArr[i], p) && i <= j) i++;
		while(CompareAge(p, perArr[j]) && i <= j) j--;

		if(i < j)
			Swap(perArr[i], perArr[j]);
	}

	Swap(perArr[start], perArr[j]);

	QuickSort(perArr, start, j-1);
	QuickSort(perArr, j+1, end);
}


#else
#endif


int main(void)
{
#if defined(_INT_SORT_)
	cout << "Integer QuickSort Test" << endl;
	int arr[] = {10, 2, 5, 8, 9, 2, 3, 4, 1, 11, 3, 7, 4, 6, 12};

	print_arr(arr, 15);
	SortArray(arr, 15);
	print_arr(arr, 15);

#elif defined(_STRUCTURE_SORT_)
	cout << "Structure QuickSort Test" << endl;
	make_structure();
	print_structure();
	cout << "Sort by age" << endl;

	QuickSort(per, 0, 4);
	print_structure();

	cout << "End of Quick Sort" << endl;

#else
#endif

	return 0;
}
