
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
	PriorityQueue(int sz = defaultSize);        //构造函数
	~PriorityQueue();                           //析构函数
public:
	bool getHead(T& x) const;       //读取队头(具最小优先权)的值
	bool Insert(const T& x);        //将新元素x插入到队尾
	bool RemoveMin(T& x);           //将队头元素删除       
	bool IsEmpty() const;           //判断队列是否为空
	bool IsFull() const;            //判断队列是否为满
	void MakeEmpty();               //置优先级队列为空
	int getSize() const;            //求优先级队列中元素个数
public:
	template <class T>
	friend ostream& operator<<(ostream& os, const PriorityQueue<T>& q); //输出队列元素的重载操作<<
private:
	void adjust();                  //队列调整
private:
	T *pqelements;  //存放队列元素的队列数组
	int maxSize;    //队列最大可容纳元素个数
	int count;      //当前元素个数(长度)
};

//构造函数
template <class T>
PriorityQueue<T>::PriorityQueue(int sz)
{
	cout << "$ 执行构造函数" << endl;
	if (sz >= 0)
	{
		maxSize = sz;
		count = 0;
		pqelements = new T[maxSize];
	}
}

//析构函数
template <class T>
PriorityQueue<T>::~PriorityQueue()
{
	cout << "$ 执行析构函数" << endl;
	delete[] pqelements;
	pqelements = NULL;
}


//读取队头(具最小优先权)的值
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

//将新元素x插入到队尾
template <class T>
bool PriorityQueue<T>::Insert(const T& x)
{
	if (true == IsFull())
	{
		return false;
	}
	pqelements[count++] = x;
	adjust();   //按优先权进行调整
	return true;
}

//将队头元素删除
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

//判断队列是否为空
template <class T>
bool PriorityQueue<T>::IsEmpty() const
{
	return (0 == count) ? true : false;
}

//判断队列是否为满
template <class T>
bool PriorityQueue<T>::IsFull() const
{
	return (maxSize == count) ? true : false;
}

//置优先级队列为空
template <class T>
void PriorityQueue<T>::MakeEmpty()
{
	delete[] pqelements;
	count = 0;
	pqelements = new T[maxSize];
}

//求优先级队列中元素个数
template <class T>
int PriorityQueue<T>::getSize() const
{
	return count;
}

//输出队列元素的重载操作<<
template <class T>
ostream& operator<<(ostream& os, const PriorityQueue<T>& q)
{
	for (int i = 0; i < q.count; i++)
	{
		os << "[" << i << "]" << " : " << q.pqelements[i] << endl;
	}
	return os;
}

//队列调整
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
