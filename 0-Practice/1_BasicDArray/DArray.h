#pragma once
#if !defined _DYNAMICARRAY_H_
#define _DYNAMICARRAY_H_
//
//class CDArray
//{
//private:
//	double* m_pData;
//	int m_size;
//	int m_max;//only need to change the function that can change the dynamic array, like pushback,delete,Insert
//
//private:
//	void Init(); //Initilize the Array
//	void Free(); //Free the Array
//	inline int InvalidateIndex(int nIndex);//judge the validate of an Index
//
//public:
//	CDArray(); //default the constructor
//	CDArray(int nSize, double dValue); //set an array with default values
//	//CDArray(const CDArray& arr);//copy constructor
//	~CDArray();
//
//	void	Print();   //display the elements of the array
//	int		GetSize();			//get the size of the array
//	int		SetSize(int nSize);		//reset the size of the array,if nsize < odinary array's size,truncate the first nSize elements 
//									//as the elements of the new array,otherwise the default value of the new element is 0
//
//	double	GetAt(int nIndex);				// get the value of an elements
//	//double 	operator[] (int nIndex) const; 	// ����[]���������Ա���ͳ��������ͨ��a[k]����ȡԪ��ֵ
//	int		SetAt(int nIndex, double dValue);	// set the value of an elements
//
//	int		PushBack(double dValue);		// add an element at the end of the array
//	int		DeleteAt(int nIndex);			// delete an element at some Index
//	int		InsertAt(int nIndex, double dValue);	// Insert a new element at some Index
//
//	//CDArray& CDArray::operator = (const CDArray& array);  	// ���ظ�ֵ��������"="
//};
//
//#endif


class CDArray
{
public:
	CDArray();
	CDArray(int nSize, double dValue);
	CDArray(const CDArray& arr);

	~CDArray();

	void Print(); //�����ʾ��������Ԫ�ص�ֵ
	int GetSize(); //��ȡ�����С
	int SetSize(int nSize); //������������Ĵ�С

	double GetAt(int nIndex);
	double operator[](int nIndex);
	int SetAt(int nIndex, double dValue);
	int PushBack(double dValue);
	int DeleteAt(int nIndex);
	int InsertAt(int nIndex, double dValue);

	CDArray& operator=(const CDArray& array);

private:
	double* m_pData;
	int m_nSize;
	int m_nMax;
	void Init();
	void Free();
	inline int invalidateIndex(int nIndex);
};

#endif