#include"PriorityQueue.h.h"



#define EXIT 0              //退出


#define GETHEAD 1           //读取队头(具最小优先权)的值


#define INSERT 2            //将新元素x插入到队尾


#define REMOVEMIN    3      //将队头元素删除


#define ISEMPTY  4          //判断队列是否为空


#define ISFULL 5            //判断队列是否为满


#define MAKEEMPTY 6         //置优先级队列为空


#define GETSIZE 7           //求优先级队列中元素个数


#define OPERATOR_OSTREAM 8  //输出队列元素的重载操作<<


void print_description()
{
	cout << "------------------------------>优先级队列<------------------------------" << endl;
	cout << "功能选项说明：" << endl;
	cout << "#0： 退出" << endl;
	cout << "#1： 读取队头(具最小优先权)的值" << endl;
	cout << "#2： 将新元素x插入到队尾" << endl;
	cout << "#3： 将队头元素删除" << endl;
	cout << "#4： 判断队列是否为空" << endl;
	cout << "#5： 判断队列是否为满" << endl;
	cout << "#6： 置优先级队列为空" << endl;
	cout << "#7： 求优先级队列中元素个数" << endl;
	cout << "#8： 输出队列元素的重载操作<<" << endl;
	cout << "--------------------------------------------------------------------" << endl;
}

//判断输入的字符串每个字符是否都是数值0~9
bool IsNumber(const string& s_num)
{
	for (size_t i = 0; i < s_num.size(); i++)
	{
		if ((s_num[i] < '0') || (s_num[i] > '9'))
		{
			return false;
		}
	}
	return true;
}

//类型转换——将string型转为模板类型T
template <class T>
T StrToTtype(const string& s_num)
{
	T n_num;
	strstream ss_num;
	ss_num << s_num;
	ss_num >> n_num;
	return n_num;
}

//输入数据值
template <class T>
T get_data()
{
	cout << "> 请输入数据值，data = ";
	string s_data;
	cin >> s_data;
	return StrToTtype<T>(s_data);
}

//输入数组的最大长度
template <class T>
int get_maxsize()
{
	cout << "> 请输入数组的最大长度，maxsize = ";
	string s_maxsize;
	cin >> s_maxsize;
	while (false == IsNumber(s_maxsize))
	{
		cout << "* 输入有误，请重新输入：";
		cin >> s_maxsize;
	}
	return atoi(s_maxsize.c_str());
}

//构造优先级队列
template <class T>
PriorityQueue<T>* construct_priorityqueue()
{
	cout << "\n==> 创建优先级队列" << endl;
	int n_maxsize = get_maxsize<T>();
	PriorityQueue<T> *priorityQueue = new PriorityQueue<T>(n_maxsize);
	return priorityQueue;
}

//析构优先级队列
template <class T>
void destory_priorityqueue(PriorityQueue<T>* priorityQueue)
{
	cout << "\n==> 释放优先级队列在堆中申请的空间，并将指向该空间的指针变量置为空" << endl;
	delete priorityQueue;
	priorityQueue = NULL;
}

//读取队头(具最小优先权)的值
template <class T>
void gethead(PriorityQueue<T>* priorityQueue)
{
	cout << "$ 执行读取队头(具最小优先权)的值函数" << endl;
	T data;
	if (false == priorityQueue->getHead(data))
	{
		cout << "* 读取队头元素失败" << endl;
		return;
	}
	cout << "* 读取队头元素成功，data = " << data << endl;
}

//将新元素x插入到队尾
template <class T>
void insert(PriorityQueue<T>* priorityQueue)
{
	cout << "$ 执行将新元素x插入到队尾函数" << endl;
	T data = get_data<T>();
	if (false == priorityQueue->Insert(data))
	{
		cout << "* 入队失败" << endl;
		return;
	}
	cout << "* 入队成功，data = " << data << endl;
}

//将队头元素删除
template <class T>
void removemin(PriorityQueue<T>* priorityQueue)
{
	cout << "$ 执行将队头元素删除函数" << endl;
	T data;
	if (false == priorityQueue->RemoveMin(data))
	{
		cout << "* 出队失败" << endl;
		return;
	}
	cout << "* 出队成功，data = " << data << endl;
}

//判断队列是否为空
template <class T>
void isempty(PriorityQueue<T>* priorityQueue)
{
	cout << "$ 执行判断队列是否为空函数，IsEmpty = " << priorityQueue->IsEmpty() << endl;
}

//判断队列是否为满
template <class T>
void isfull(PriorityQueue<T>* priorityQueue)
{
	cout << "$ 执行判断队列是否为满函数，IsFull = " << priorityQueue->IsFull() << endl;
}

//置优先级队列为空
template <class T>
void makeempty(PriorityQueue<T>* priorityQueue)
{
	cout << "$ 执行置优先级队列为空函数" << endl;
	priorityQueue->MakeEmpty();
}

//求优先级队列中元素个数
template <class T>
void getsize(PriorityQueue<T>* priorityQueue)
{
	cout << "$ 执行求优先级队列中元素个数函数，Size = " << priorityQueue->getSize() << endl;
}

//输出队列元素的重载操作<<
template <class T>
void operator_ostream(PriorityQueue<T>* priorityQueue)
{
	cout << "$ 执行输出队列元素的重载操作<<函数" << endl;
	cout << *priorityQueue;//或operator<<(cout, *priorityQueue);
}

//优先级队列操作选择
template <class T>
void select_operation(PriorityQueue<T>* priorityQueue)
{
	if (NULL == priorityQueue)
	{
		cout << "* 没有构造优先级队列，请先构造优先级队列。" << endl;
		return;
	}

	string s_operation;
	while (s_operation != "0")
	{
		cout << "\n==> 请输入功能选项编号(按\"0\"退出程序)：";
		cin >> s_operation;
		while (false == IsNumber(s_operation))
		{
			cout << "* 输入有误，请重新输入：";
			cin >> s_operation;
		}
		int n_operation = atoi(s_operation.c_str());
		switch (n_operation)
		{
		case EXIT://退出
		{
					  cout << "$ 退出程序" << endl;
					  break;
		}
		case GETHEAD://读取队头(具最小优先权)的值
		{
						 gethead(priorityQueue);
						 break;
		}
		case INSERT://将新元素x插入到队尾
		{
						insert(priorityQueue);
						break;
		}
		case REMOVEMIN://将队头元素删除
		{
						   removemin(priorityQueue);
						   break;
		}
		case ISEMPTY://判断队列是否为空
		{
						 isempty(priorityQueue);
						 break;
		}
		case ISFULL://判断队列是否为满
		{
						isfull(priorityQueue);
						break;
		}
		case MAKEEMPTY://置优先级队列为空
		{
						   makeempty(priorityQueue);
						   break;
		}
		case GETSIZE://求优先级队列中元素个数
		{
						 getsize(priorityQueue);
						 break;
		}
		case OPERATOR_OSTREAM://输出队列元素的重载操作<<
		{
								  operator_ostream(priorityQueue);
								  break;
		}
		default:
		{
				   cout << "* 请输入正确的功能选项编号" << endl;
				   break;
		}
		}
	}
}

int main(int argc, char* argv[])
{
	print_description();
	PriorityQueue<int> *priorityQueue = construct_priorityqueue<int>();
	select_operation(priorityQueue);
	destory_priorityqueue(priorityQueue);
	system("pause");
	return 0;
}