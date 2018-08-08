#include <iostream>
using namespace std;

void Selection(int *p,int n)
{
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			if(p[i]>p[j])
				swap(p[i], p[j]);
}

void Bubble(int *p,int n)
{
	for(int i = 0; i < n-1; i++)
		for(int j = n-1; j > i; j--)
			if(p[j] < p[j - 1])
				swap(p[j],p[j-1]);
}

void Insert_1(int * p, int n)
{
	for(int i = 1; i < n; i++)
	{
		int k = i;
		while(p[k] < p[k - 1] && k >= 1)
		{
			swap(p[k], p[k - 1]);
			k--;
		}
	}
}

void Insert_2(int * p, int n)
{
	for(int i = 1; i < n; i++)
	{
		int v = p[i];
		int k = i;
		while(v < p[k - 1] && k>=1)
		{
			p[k] = p[k - 1];
			k--;
		}
		p[k]=v;
	}
}

int partition_1(int *p,int l,int r)
{
	int j = l;
	for(int i = l+1; i <= r; i++)
		if(p[i]<p[l])
		{
			j++;
			swap(p[j],p[i]);
		}
	swap(p[l], p[j]);
	return j;
}

void __Quick_1(int * p, int l,int r)
{
	if(l >= r)
		return;
	int v = partition_1(p, l, r);
	__Quick_1(p, l, v - 1);
	__Quick_1(p, v + 1, r);
}

void Quick_1(int * p, int n)
{
	__Quick_1(p, 0, n - 1);
}


int partition_2(int * p, int l, int r)
{
	int v = p[l];
	int i = l + 1;
	int j = r;
	while( true )
	{
		while( i<=r && p[i] < v)
			i++;
		while( j>=l && p[j] > v)
			j--;
		if(i > j)
			break;
		swap(p[i], p[j]);
		i++;
		j--;
	}
	swap(p[l], p[j]);
	return j;
}

void __Quick_2(int * p, int l,int r)
{
	if(l >= r)
		return;
	int v = partition_2(p, l, r);
	__Quick_2(p, l, v - 1);
	__Quick_2(p, v + 1, r);
}

void Quick_2(int * p, int n)
{
	__Quick_2(p, 0, n - 1);
}

void __Quick_3(int * p, int l, int r)
{
	int v = p[l];
	int lt = l;
	int gt = r + 1;
	int i = l + 1;
	if(l >= r)
		return;
	while(i < gt)
	{
		if(p[i]<v)
		{
			lt++;
			swap(p[lt], p[i]);
			i++;
		}
		else if(p[i]>v)
		{
			gt--;
			swap(p[gt],p[i]);
		}
		else
			i++;
	}
	swap(p[lt], p[l]);

	__Quick_3(p, l, lt - 1);
	__Quick_3(p, gt, r);
}

void Quick_3(int * p, int n)
{
	__Quick_3(p, 0, n - 1);
}

void __mergeSort(int * p, int l, int mid, int r)
{
	int newArray[r - l + 1];
	int i = l;
	int j = mid + 1;
	int k = l;
	for(int i = l; i <= r; i++)
		newArray[i - l]=p[i];
	while( k<=r )
	{
		if(i > mid)
		{
			p[k]=newArray[j - l];
			j++;
			k++;
		}
		else if(j > r)
		{
			p[k]=newArray[i - l];
			i++;
			k++;
		}
		else if(newArray[i - l]>newArray[j - l])
		{
			p[k]=newArray[j - l];
			j++;
			k++;
		}
		else
		{
			p[k]=newArray[i - l];
			i++;
			k++;
		}
	}
}
void __merge(int * p, int l, int r)
{
	int mid=(l + r)/2;
	if(l >= r)
		return;
	__merge(p, l, mid);
	__merge(p, mid+1 , r);
	__mergeSort(p, l, mid,r);
}
void merge(int *p,int n)
{
	__merge(p, 0, n - 1);
}
