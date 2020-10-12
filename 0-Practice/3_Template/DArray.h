#pragma once

#include <iostream>
#include <assert.h>

using namespace std;

template<class DataType>
class DArray
{
public:
	DArray();
	DArray(int nSize, const DataType& dValue);
	DArray(const DArray& arr);
	~DArray();

	void Print() const;

	int GetSize() const;
	void SetSize(int nSize);
	const DataType& GetAt(int nIndex) const;
	void SetAt(int nIndex, const DataType& dValue);

	void Pushback(const DataType& dValue);
	void DeleteAt(int nIndex);
	void InsertAt(int nIndex, const DataType& dValue);

    const DataType& operator[](int nIndex) const;
	DArray& operator=(const DArray& arr);

private:
	DataType* m_pData;
	int m_nSize;
	int m_nMax;

private:
	void Init();
	void Free();
};

//default constructor
template<class DataType>
DArray<DataType>::DArray()
{
	Init();
}

//set an array with default values
template<class DataType>
DArray<DataType>::DArray(int nSize, const DataType& dValue)//ªÚ’ﬂ: m_pData(new T[nSize]), m_nSize(nSize), m_nMax(nSize)∏≥÷µ
{
	m_pData = new DataType[nSize];
	m_nSize = nSize;
	m_nMax = nSize;
	for (int i = 0; i < nSize; i++)
	{
		m_pData[i] = dValue;
	}
}

template<class DataType>
DArray<DataType>::DArray(const DArray& arr)
{
	m_pData = new DataType[arr.m_nSize];
	m_nSize = arr.m_nSize;
	m_nMax = arr.m_nMax;
	for (int i = 0; i < m_nSize; i++)
	{
		m_pData[i] = arr[i];
	}
}

template<class DataType>
DArray<DataType>::~DArray()
{
	Free();
}

template<class DataType>
void DArray<DataType>::Init()
{
	m_pData = nullptr;
	m_nSize = 0;
	m_nMax = 0;
}

template<class DataType>
void DArray<DataType>::Free()
{
	delete[]m_pData;
	m_pData = nullptr;
	m_nSize = 0;
	m_nMax = 0;
}

template<class DataType>
void DArray<DataType>::Print() const
{
	cout << "max= " << m_nMax << " ;size= " << m_nSize << ":";
	for (int i = 0; i < m_nSize; i++)
		cout << " " << GetAt(i);

	cout << std::endl;
	//for (int i = 0; i < m_nSize; i++)
	//{
	//	cout << m_pData[i] << endl;
	//}
}

template<class DataType>
int DArray<DataType>::GetSize() const
{
	return m_nSize;
}

template<class DataType>
void DArray<DataType>::SetSize(int nSize)
{

}

template<class DataType>
const DataType& DArray<DataType>::GetAt(int nIndex) const
{
	assert(nIndex >= 0);
	assert(nIndex < m_nSize);
	return m_pData[nIndex];
}

template<class DataType>
void DArray<DataType>::SetAt(int nIndex, const DataType& dValue)
{
	assert(nIndex >= 0);
	assert(nIndex < m_nSize);
	m_pData[nIndex] = dValue;
}

template<class DataType>
void DArray<DataType>::Pushback(const DataType& dValue)
{
	if (m_nSize < m_nMax)
	{
		m_pData[m_nSize] = dValue;
	}
	if (m_nMax == 0)
	{
		m_nMax = 1;
	}
	else
	{
		m_nMax *= 2;
	}
	DataType* pTemp = NULL;
	pTemp = new DataType[m_nMax];
	if (pTemp == NULL)
	{
		cout << "no memory" << endl;
		return;
	}
	for (int i = 0; i < m_nSize; i++)
	{
		pTemp[i] = m_pData[i];
	}
	pTemp[m_nSize] = dValue;
	delete[]m_pData;
	m_pData = pTemp;
	m_nSize++;
}

template<class DataType>
void DArray<DataType>::DeleteAt(int nIndex)
{
	assert(nIndex >= 0);
	assert(nIndex < m_nSize);
	for (int i = nIndex + 1; i < m_nSize; i++)
	{
		m_pData[i - 1] = m_pData[i];
	}
	m_nSize--;
}

template<class DataType>
void DArray<DataType>::InsertAt(int nIndex, const DataType& dValue)
{
	assert(nIndex >= 0);
	assert(nIndex <= m_nSize);
	if (m_nSize < m_nMax)
	{
		for (int i = m_nSize; i > nIndex; i--)
		{
			m_pData[i] = m_pData[i - 1];
		}
		m_pData[nIndex] = dValue;
		m_nSize++;
	}
	else
	{
		if (m_nMax == 0)
		{
			m_nMax = 1;
		}
		else
		{
			m_nMax *= 2;
		}
		DataType* pTemp = new DataType[m_nMax];
		for (int i = 0; i < nIndex; i++)
		{
			pTemp[i] = m_pData[i];
		}
		pTemp[nIndex] = dValue;
		for (int i = nIndex + 1; i < m_nSize + 1; i++)
		{
			pTemp[i] = m_pData[i - 1];
		}
		delete[]m_pData;
		m_pData = pTemp;
		m_nSize++;
	}
}

template<class DataType>
const DataType& DArray<DataType>::operator[](int nIndex) const
{
	assert(nIndex >= 0);
	assert(nIndex < m_nSize);
	return GetAt(nIndex);
}

template<class DataType>
DArray<DataType>& DArray<DataType>::operator=(const DArray& arr)
{
	DataType* pTemp = new DataType[arr.m_nMax];
	for (int i = 0; i < arr.m_nSize; i++)
	{
		pTemp[i] = arr[i];
	}
	delete[]m_pData;
	m_pData = pTemp;
	m_nSize = arr.m_nSize;
	m_nMax = arr.m_nMax;

	return *this;
}