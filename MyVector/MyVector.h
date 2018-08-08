#ifndef __MYVECTOR_H__
#define __MYVECTOR_H__

template <typename T>
class MyVector
{
private:
	T * m_p;
	int m_len;
public:
	MyVector(int size);
	MyVector(const MyVector & v1);
	~MyVector();
public:
	T & operator[](int index);
	MyVector & operator=(const MyVector & v1);
	int getLen()
	{
		return m_len;
	}
public:
 	friend ostream & operator<< (ostream & out,MyVector & v1)
	{
		for(int i = 0; i < v1.getLen(); i++)
		{
			out<<v1.m_p[i]<<" ";
		}
		return out;
	};
};

#endif


