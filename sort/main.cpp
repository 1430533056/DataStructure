#include <iostream>
#include "sortHelper.h"
#include "sort.h"
using namespace std;
int main()
{
	int * p1;
	int * p2;
	int n=20;
	// p1 = sortHelper::GenerateTestArray_NearlyOrdered(n, 10);
	p1 = sortHelper::GenerateTestArray(n,1,n);
	p2 = sortHelper::copyArray(p1, n);
	// sortHelper::printArray(p1, n);
	// sortHelper::printArray(p2, n);
	sortHelper::TestSort("Selection", Selection, p1, n);
	sortHelper::TestSort("merge", merge, p2, n);
	sortHelper::printArray(p2, n);
	delete[] p1;
	delete[] p2;
	return 0;
}
