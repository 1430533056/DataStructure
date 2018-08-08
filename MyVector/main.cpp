#include <iostream>
#include <cstring>
using namespace std;
#include "MyVector.cpp"

class Teacher
{
private:
	int age;
	char name[32];
public:
	Teacher()
	{
		age = 0;
		strcpy(name,"a");
	}
	Teacher(const char *pname,int _age)
	{
		age = _age;
		strcpy(name, pname);
	}
	void Print()
	{
		cout << name<<":\t"<<age << endl;
	}
};

int main()
{
	Teacher t1("liu", 31), t2("li", 32), t3("zhang", 33);
	MyVector < Teacher > tArray(3);
	tArray[0]=t1;
	tArray[1]=t2;
	tArray[2]=t3;

	for(int i=0;i<tArray.getLen();i++)
		tArray[i].Print();

	return 0;
}

int main01()
{
	MyVector < int > v1(10), v2(1);
	MyVector < char > v3(5);

	for(int i = 0; i < v1.getLen(); i++)
	{
		v1[i]=i + 1;
		cout<<v1[i]<<" ";
	}
	cout<<endl;
	v2 = v1;
	for(int i = 0; i < v2.getLen(); i++)
		cout << v2[i]<<" ";

	cout << endl;
	for(int i = 0; i < v3.getLen(); i++)
	{
		v3[i]=i + 97;
		cout<<v3[i]<<" ";
	}

	cout << endl;
	cout<<v3;
	return 0;
}
