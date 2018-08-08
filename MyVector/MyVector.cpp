#include <iostream>
using namespace std;
#include "MyVector.h"

template <typename T>
MyVector <T>::MyVector(int size)
{
	m_len = size;
	m_p = new T[m_len];
}
template <typename T>
MyVector <T>::MyVector(const MyVector<T> & v1)
{
	m_len = v1.m_len;
	m_p = new T[m_len];
	for(int i = 0; i < m_len; i++)
		m_p[i] = v1.m_p[i];
}
template <typename T>
MyVector <T>::~MyVector()
{
	if(m_p != NULL)
	{
		delete[] m_p;
		m_p = NULL;
		m_len = 0;
	}
}

template <typename T>
T& MyVector<T>::operator[](int index)
{
	return m_p[index];
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T> & v1)
{
	if(m_p != NULL)
		delete[] m_p;
	m_len = v1.m_len;
	m_p = new T[m_len];
	for(int i = 0; i < m_len; i++)
		m_p[i] = v1.m_p[i];
	return *this;
}

// template <typename T>
// ostream & operator<< (ostream & out,MyVector<T> & v1)
// {
// 	for(int i = 0; i < v1.getLen(); i++)
// 	{
// 		out<<v1.m_p[i]<<" ";
// 	}
// 	return out;
// };
