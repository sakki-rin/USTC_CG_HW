//#include <iostream>
//#include "DArray.h"
//
//#define SAFEDELETES(p) if(p){delete []p;p=NULL;}
//#define TRUE  1
//#define FALSE 0
//
//using namespace std;
//
//CDArray::CDArray()
//{
//	Init();
//}
//
//CDArray::CDArray(int nSize, double dValue)
//{
//	m_pData = new double[nSize];
//	for (int i = 0; i < nSize; i++)
//	{
//		m_pData[i] = dValue;
//	}
//	m_size = nSize;
//	m_max = nSize;
//}
//
//void CDArray::Init()
//{
//	m_max = 0;
//	m_size = 0;
//	m_pData = NULL;
//}
//
//CDArray::~CDArray()
//{
//	Free();
//}
//
//void CDArray::Free()
//{
//	SAFEDELETES(m_pData);
//	m_size = 0;
//	m_max = 0;
//}
//
//int CDArray::GetSize()
//{
//	return m_size;
//}
//
//inline int CDArray::InvalidateIndex(int nIndex) //内联函数，在每个调用点上展开，减少函数调用的开销
//{
//	if (nIndex<0 || nIndex> m_size)
//	{
//		return TRUE;
//	}
//	return FALSE;
//}
//
//double CDArray::GetAt(int nIndex)
//{
//	if (InvalidateIndex(nIndex))
//	{
//		cout << "the Index is invalidate in GetAt()!\n" << endl;
//		return FALSE;
//	}
//	return m_pData[nIndex];
//}
//
//int CDArray::SetAt(int nIndex, double dValue)
//{
//	if (InvalidateIndex(nIndex))
//	{
//		cout << "the Index is invalidate in SetAt()!\n" << endl;
//		return FALSE;
//	}
//	m_pData[nIndex] = dValue;
//	return TRUE;
//}
//
//int CDArray::PushBack(double dValue)
//{
//	if (m_size < m_max)
//	{
//		m_pData[m_size] = dValue;
//		m_size++;
//	}
//	else
//	{
//		if (m_max == 0)
//		{
//			m_max = 1;
//		}
//		else
//		{
//			m_max *= 2;
//		}
//		double* pTemp = NULL;
//		pTemp = new double[m_max];
//		if (pTemp == NULL)
//		{
//			cout << "can not alloc memory in PushBack()" << endl;
//			return FALSE;
//		}
//		for (int i = 0; i < m_size; i++)
//		{
//			pTemp[i] = m_pData[i];
//		}
//		pTemp[m_size] = dValue;
//		SAFEDELETES(m_pData);
//
//		m_pData = pTemp;
//		m_size++;
//	}
//
//	return TRUE;
//}
//
//int CDArray::DeleteAt(int nIndex)
//{
//	if (InvalidateIndex(nIndex))
//	{
//		cout << "the Index is invalidate in DeleteAt()!\n" << endl;
//		return FALSE;
//	}
//	/*double* pTemp = NULL;
//	pTemp = new double[m_size - 1];
//	if (pTemp == NULL)
//	{
//		cout << "can not alloc memory in DeleteAt()!\n" << endl;
//		return FALSE;
//	}
//	for (int i = 0; i < nIndex; i++)
//	{
//		pTemp[i] = m_pData[i];
//	}
//	for (int i = nIndex; i < m_size - 1; i++)
//	{
//		pTemp[i] = m_pData[i + 1];
//	}
//
//	SAFEDELETES(m_pData);
//	m_pData = pTemp;
//	m_size--;
//
//	return TRUE;*/
//	else
//	{
//		for (int i = nIndex; i < m_size-1; i++)
//		{
//			m_pData[i] = m_pData[i + 1];
//		}
//		m_size--;
//	}
//	return TRUE;
//}
//
//int CDArray::InsertAt(int nIndex, double dValue)
//{
//	if (InvalidateIndex(nIndex))
//	{
//		cout << "the Index is validate in InsertAt()!" << endl;
//		return FALSE;
//	}
//	else
//	{
//		if (m_size < m_max)
//		{
//			for (int i = m_size; i > nIndex; i--)
//			{
//				m_pData[i] = m_pData[i - 1];
//			}
//			m_pData[nIndex] = dValue;
//			m_size++;
//		}
//		else
//		{
//			if (m_max == 0)
//			{
//				m_max = 1;
//			}
//			else
//			{
//				m_max *= 2;
//			}
//
//			double* pTemp = NULL;
//			pTemp = new double[m_max];
//			if (pTemp == NULL)
//			{
//				cout << "can not alloc memory in InsertAt()!\n" << endl;
//				return FALSE;
//			}
//
//			for (int i = 0; i < nIndex; i++)
//			{
//				pTemp[i] = m_pData[i];
//			}
//			pTemp[nIndex] = dValue;
//
//			for (int i = nIndex; i < m_size; i++)
//			{
//				pTemp[i + 1] = m_pData[i];
//			}
//			SAFEDELETES(m_pData);
//			m_pData = pTemp;
//			m_size++;
//		}
//	}
//	return TRUE;
//}
//
//int CDArray::SetSize(int nSize)
//{
//	if (m_pData == NULL)
//	{
//		m_pData = new double[nSize];
//		if (m_pData == NULL)
//		{
//			cout << "can not alloc memory in SetSize()!\n" << endl;
//			return FALSE;
//		}
//
//		for (int i = 0; i < nSize; i++)
//		{
//			m_pData[i] = 0;
//		}
//		m_size = nSize;
//		m_size = nSize;
//	}
//	else if (m_size == nSize)
//	{
//		return TRUE;
//	}
//	else
//	{
//		double* pTemp = NULL;
//		pTemp = new double[nSize];
//		if (pTemp == NULL)
//		{
//			cout << "can not alloc memory in SetSize()!\n" << endl;
//			return FALSE;
//		}
//		if (m_size > nSize)
//		{
//			for (int i = 0; i < nSize; i++)
//			{
//				pTemp[i] = m_pData[i];
//			}
//		}
//		else if (m_size < nSize)
//		{
//			for (int i = 0; i < m_size; i++)
//			{
//				pTemp[i] = m_pData[i];
//			}
//			for (int i = m_size; i < nSize; i++)
//			{
//				pTemp[i] = 0;
//			}
//		}
//		SAFEDELETES(m_pData);
//		m_pData = pTemp;
//		m_size = nSize;
//		m_max = nSize;
//	}
//	return TRUE;
//}
//
//void CDArray::Print()
//{
//	cout<<"max= "<<m_max << " size = " << m_size << ":";
//	for (int i = 0; i < GetSize(); i++)
//	{
//		cout << " " << GetAt(i);
//	}
//	cout << endl;
//}

#include <iostream>
#include "DArray.h"

#define TRUE 1
#define FALSE 0
#define SAFEDELETE(p) if(p){delete []p;p=NULL;}

using namespace std;

CDArray::CDArray()
{
	Init();
}

void CDArray::Init()
{
	m_nMax = 0;
	m_nSize = 0;
	m_pData = NULL;
}

CDArray::CDArray(int nSize, double dValue = 0)
{
	m_pData = new double[nSize];
	for (int i = 0; i < nSize; i++)
	{
		m_pData[i] = dValue;
	}
	m_nSize = nSize;
	m_nMax = m_nSize;
}

CDArray::~CDArray()
{
	Free();
}

void CDArray::Free()
{
	SAFEDELETE(m_pData);
	m_nSize = 0;
	m_nMax = 0;
}

int CDArray::GetSize()
{
	return m_nSize;
}

inline int CDArray::invalidateIndex(int nIndex)
{
	if (nIndex<0 || nIndex>m_nSize)
	{
		return FALSE;
	}
	return TRUE;
}

double CDArray::GetAt(int nIndex)
{
	if (!invalidateIndex(nIndex))
	{
		cout << "the nIndex is invalidate in GetAt()" << endl;
		return FALSE;
	}
	return m_pData[nIndex];
}

int CDArray::SetAt(int nIndex, double dValue)
{
	if (!invalidateIndex(nIndex))
	{
		cout << "the nIndex is invalidate in SetAt()" << endl;
		return FALSE;
	}
	m_pData[nIndex] = dValue;
	return TRUE;
}

int CDArray::PushBack(double dValue)
{
	if (m_nSize < m_nMax)
	{
		m_pData[m_nSize] = dValue;
	}
	else {
		if (m_nMax == 0)
		{
			m_nMax = 1;
		}
		else
		{
			m_nMax *= 2;
		}
		double* pTemp = NULL;
		pTemp = new double[m_nMax];
		if (pTemp == NULL)
		{
			cout << "Can not allocate enough memory for PushBack()" << endl;
			return FALSE;
		}
		for (int i = 0; i < m_nSize; i++)
		{
			pTemp[i] = m_pData[i];
		}
		pTemp[m_nSize] = dValue;
		SAFEDELETE(m_pData);
		m_pData = pTemp;
		m_nSize++;

		//这样写就没有在堆区开辟内存，不能将值存储进去，m_nSize值变大，但是数组个数并没增加
		//m_nSize++;
		//m_pData[m_nSize-1] = dValue;
		//return TRUE;
	}
	return TRUE;
}

int CDArray::DeleteAt(int nIndex)
{
	if (!invalidateIndex(nIndex))
	{
		cout << "the nIndex is invalidate in DeleteAt()" << endl;
		return FALSE;
	}
	double* pTemp = new double[m_nSize - 1];
	if (pTemp == NULL)
	{
		cout << "Can not allocate enough memory for DeleteAt()" << endl;
		return FALSE;
	}
	for (int i = 0; i < nIndex; i++)
	{
		pTemp[i] = m_pData[i];
	}
	for (int i = nIndex; i < m_nSize - 1; i++)
	{
		pTemp[i] = m_pData[i + 1];
	}
	SAFEDELETE(m_pData);
	m_pData = pTemp;
	m_nSize--;
	return TRUE;
}

int CDArray::InsertAt(int nIndex, double dValue)
{
	if (!invalidateIndex(nIndex))
	{
		cout << "the nIndex is invalidate in InsertAt()" << endl;
		return FALSE;
	}
	else {
		if (m_nSize < m_nMax)
		{
			for (int i = m_nSize; i > nIndex; i--)
			{
				m_pData[i] = m_pData[i - 1];
			}
			m_pData[nIndex] = dValue;
			m_nSize++;
		}
		else {
			if (m_nMax == 0)
			{
				m_nMax = 1;
			}
			else
			{
				m_nMax *= 2;
			}
			double* pTemp = new double[m_nMax];
			if (pTemp == NULL)
			{
				cout << "Can not allocate enough memory for InsertAt()" << endl;
				return FALSE;
			}
			for (int i = 0; i < nIndex; i++)
			{
				pTemp[i] = m_pData[i];
			}
			pTemp[nIndex] = dValue;
			for (int i = nIndex + 1; i < m_nSize + 1; i++)
			{
				pTemp[i] = m_pData[i - 1];
			}
			SAFEDELETE(m_pData);
			m_pData = pTemp;
			m_nSize++;
		}
		return TRUE;
	}
}

int CDArray::SetSize(int nSize)
{
	if (m_pData == NULL)
	{
		m_pData = new double[nSize];
		if (m_pData == NULL)
		{
			cout << "Can not alloc memory in SetSize()!" << endl;
			return FALSE;
		}
		for (int i = 0; i < nSize; i++)
		{
			m_pData[i] = 0;
		}
		m_nSize = nSize;
		m_nMax = nSize;
	}
	else if (m_nSize == nSize)
	{
		return TRUE;
	}
	else
	{
		double* pTemp = new double[nSize];
		if (pTemp == NULL)
		{
			cout << "Can not alloc memory in SetSize()!" << endl;
			return FALSE;
		}
		if (m_nSize < nSize)
		{
			for (int i = 0; i < m_nSize; i++)
			{
				pTemp[i] = m_pData[i];
			}
			for (int i = m_nSize; i < nSize; i++)
			{
				pTemp[i] = 0;
			}
		}
		else
		{
			for (int i = 0; i < nSize; i++)
			{
				pTemp[i] = m_pData[i];
			}
		}
		SAFEDELETE(m_pData);
		m_pData = pTemp;
		m_nSize = nSize;
		m_nMax = nSize;
	}
	return TRUE;
}

void CDArray::Print()
{
	cout <<"max="<<m_nMax<< "size= " << m_nSize << ":";
	for (int i = 0; i < GetSize(); i++)
	{
		cout << " " << GetAt(i);
	}
	cout << endl;
}

double CDArray::operator[](int nIndex)
{
	return GetAt(nIndex);
}

CDArray& CDArray::operator=(const CDArray& array)
{
	if (array.m_pData == NULL)
	{
		SAFEDELETE(m_pData);
		m_pData = NULL;
		m_nSize = 0;
	}
	if (m_pData == NULL)
	{
		m_pData = new double(*array.m_pData);
		m_nSize = array.m_nSize;
	}
	else
	{
		SAFEDELETE(m_pData);//堆区属性需要先释放干净
		m_nSize = array.m_nSize;
		m_pData = new double[m_nSize];//堆区需要开辟数据，不是直接赋值
		for (int i = 0; i < m_nSize;i++ )
		{
			m_pData[i] = array.m_pData[i];
		}
		//m_pData = array.m_pData;
	}
	return *this;
}
