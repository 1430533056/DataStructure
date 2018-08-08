#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

namespace sortHelper
{
	int * GenerateTestArray(int n,int l,int r) //[l,r]
	{
		if(l > r)
			return NULL;
		srand(time(NULL));
		int * p = new int [n];
		for(int i = 0; i < n; i++)
			p[i] = rand() % (r - l + 1) + l;
		return p;
	}
	int * GenerateTestArray_NearlyOrdered(int n,int swapTimes)
	{
		int * p = new int[n];
		for(int i = 0; i < n; i++)
			p[i]=i;
		srand(time(NULL));
		for(int i = 0; i < swapTimes; i++)
		{
			int posx = rand()%n;
			int posy = rand()%n;
			swap(p[posx], p[posy]);
		}
		return p;
	}
	void printArray(int * p, int n)
	{
		for(int i = 0; i < n; i++)
			cout << p[i]<<" ";
		cout<<endl;
	}
	bool isSorted(int * p,int n)
	{
		for(int i = 0; i < n-1; i++)
			if(p[i]>p[i + 1])
				return false;
		return true;
	}
	void TestSort(string sortName,void(*func)(int *,int),int *arr,int n)
	{
		clock_t startTime = clock();
		func(arr, n);
		clock_t endTime = clock();
		if(isSorted(arr,n))
			cout << sortName<<": "<<double(endTime - startTime)/CLOCKS_PER_SEC<<"s"<<endl;
		else
			cout<<"sort error!"<<endl;
	}
	int * copyArray(int* p,int n)
	{
		int * arr = new int[n];
		for(int i = 0; i < n; i++)
			arr[i]=p[i];
		return arr;
	}
};
