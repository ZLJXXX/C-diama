
#ifndef PRIORITY_QUEUE_H_


#define PRIORITY_QUEUE_H_



#include <iostream>


#include <string>


#include <strstream>


using namespace std;

const int defaultSize = 50;

template <class T>
class PriorityQueue
{
public:
	PriorityQueue(int sz = defaultSize);        //���캯��
	~PriorityQueue();                           //��������
public:
	bool getHead(T& x) const;       //��ȡ��ͷ(����С����Ȩ)��ֵ
	bool Insert(const T& x);        //����Ԫ��x���뵽��β
	bool RemoveMin(T& x);           //����ͷԪ��ɾ��       
	bool IsEmpty() const;           //�ж϶����Ƿ�Ϊ��
	bool IsFull() const;            //�ж϶����Ƿ�Ϊ��
	void MakeEmpty();               //�����ȼ�����Ϊ��
	int getSize() const;            //�����ȼ�������Ԫ�ظ���
public:
	template <class T>
	friend ostream& operator<<(ostream& os, const PriorityQueue<T>& q); //�������Ԫ�ص����ز���<<
private:
	void adjust();                  //���е���
private:
	T *pqelements;  //��Ŷ���Ԫ�صĶ�������
	int maxSize;    //������������Ԫ�ظ���
	int count;      //��ǰԪ�ظ���(����)
};

//���캯��
template <class T>
PriorityQueue<T>::PriorityQueue(int sz)
{
	cout << "$ ִ�й��캯��" << endl;
	if (sz >= 0)
	{
		maxSize = sz;
		count = 0;
		pqelements = new T[maxSize];
	}
}

//��������
template <class T>
PriorityQueue<T>::~PriorityQueue()
{
	cout << "$ ִ����������" << endl;
	delete[] pqelements;
	pqelements = NULL;
}


//��ȡ��ͷ(����С����Ȩ)��ֵ
template <class T>
bool PriorityQueue<T>::getHead(T& x) const
{
	if (true == IsEmpty())
	{
		return false;
	}
	x = pqelements[0];
	return true;
}

//����Ԫ��x���뵽��β
template <class T>
bool PriorityQueue<T>::Insert(const T& x)
{
	if (true == IsFull())
	{
		return false;
	}
	pqelements[count++] = x;
	adjust();   //������Ȩ���е���
	return true;
}

//����ͷԪ��ɾ��
template <class T>
bool PriorityQueue<T>::RemoveMin(T& x)
{
	if (true == IsEmpty())
	{
		return false;
	}
	x = pqelements[0];
	for (int i = 1; i < count; i++)
	{
		pqelements[i - 1] = pqelements[i];
	}
	count--;
	return true;
}

//�ж϶����Ƿ�Ϊ��
template <class T>
bool PriorityQueue<T>::IsEmpty() const
{
	return (0 == count) ? true : false;
}

//�ж϶����Ƿ�Ϊ��
template <class T>
bool PriorityQueue<T>::IsFull() const
{
	return (maxSize == count) ? true : false;
}

//�����ȼ�����Ϊ��
template <class T>
void PriorityQueue<T>::MakeEmpty()
{
	delete[] pqelements;
	count = 0;
	pqelements = new T[maxSize];
}

//�����ȼ�������Ԫ�ظ���
template <class T>
int PriorityQueue<T>::getSize() const
{
	return count;
}

//�������Ԫ�ص����ز���<<
template <class T>
ostream& operator<<(ostream& os, const PriorityQueue<T>& q)
{
	for (int i = 0; i < q.count; i++)
	{
		os << "[" << i << "]" << " : " << q.pqelements[i] << endl;
	}
	return os;
}

//���е���
template <class T>
void PriorityQueue<T>::adjust()
{
	int i = 0;
	T temp = pqelements[count - 1];
	for (i = count - 2; i >= 0; i--)
	{
		if (pqelements[i] <= temp)
		{
			break;
		}
		pqelements[i + 1] = pqelements[i];
	}
	pqelements[i + 1] = temp;
}


#endif /* PRIORITY_QUEUE_H_ */
