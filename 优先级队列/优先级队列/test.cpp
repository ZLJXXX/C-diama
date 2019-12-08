#include"PriorityQueue.h.h"



#define EXIT 0              //�˳�


#define GETHEAD 1           //��ȡ��ͷ(����С����Ȩ)��ֵ


#define INSERT 2            //����Ԫ��x���뵽��β


#define REMOVEMIN    3      //����ͷԪ��ɾ��


#define ISEMPTY  4          //�ж϶����Ƿ�Ϊ��


#define ISFULL 5            //�ж϶����Ƿ�Ϊ��


#define MAKEEMPTY 6         //�����ȼ�����Ϊ��


#define GETSIZE 7           //�����ȼ�������Ԫ�ظ���


#define OPERATOR_OSTREAM 8  //�������Ԫ�ص����ز���<<


void print_description()
{
	cout << "------------------------------>���ȼ�����<------------------------------" << endl;
	cout << "����ѡ��˵����" << endl;
	cout << "#0�� �˳�" << endl;
	cout << "#1�� ��ȡ��ͷ(����С����Ȩ)��ֵ" << endl;
	cout << "#2�� ����Ԫ��x���뵽��β" << endl;
	cout << "#3�� ����ͷԪ��ɾ��" << endl;
	cout << "#4�� �ж϶����Ƿ�Ϊ��" << endl;
	cout << "#5�� �ж϶����Ƿ�Ϊ��" << endl;
	cout << "#6�� �����ȼ�����Ϊ��" << endl;
	cout << "#7�� �����ȼ�������Ԫ�ظ���" << endl;
	cout << "#8�� �������Ԫ�ص����ز���<<" << endl;
	cout << "--------------------------------------------------------------------" << endl;
}

//�ж�������ַ���ÿ���ַ��Ƿ�����ֵ0~9
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

//����ת��������string��תΪģ������T
template <class T>
T StrToTtype(const string& s_num)
{
	T n_num;
	strstream ss_num;
	ss_num << s_num;
	ss_num >> n_num;
	return n_num;
}

//��������ֵ
template <class T>
T get_data()
{
	cout << "> ����������ֵ��data = ";
	string s_data;
	cin >> s_data;
	return StrToTtype<T>(s_data);
}

//�����������󳤶�
template <class T>
int get_maxsize()
{
	cout << "> �������������󳤶ȣ�maxsize = ";
	string s_maxsize;
	cin >> s_maxsize;
	while (false == IsNumber(s_maxsize))
	{
		cout << "* �����������������룺";
		cin >> s_maxsize;
	}
	return atoi(s_maxsize.c_str());
}

//�������ȼ�����
template <class T>
PriorityQueue<T>* construct_priorityqueue()
{
	cout << "\n==> �������ȼ�����" << endl;
	int n_maxsize = get_maxsize<T>();
	PriorityQueue<T> *priorityQueue = new PriorityQueue<T>(n_maxsize);
	return priorityQueue;
}

//�������ȼ�����
template <class T>
void destory_priorityqueue(PriorityQueue<T>* priorityQueue)
{
	cout << "\n==> �ͷ����ȼ������ڶ�������Ŀռ䣬����ָ��ÿռ��ָ�������Ϊ��" << endl;
	delete priorityQueue;
	priorityQueue = NULL;
}

//��ȡ��ͷ(����С����Ȩ)��ֵ
template <class T>
void gethead(PriorityQueue<T>* priorityQueue)
{
	cout << "$ ִ�ж�ȡ��ͷ(����С����Ȩ)��ֵ����" << endl;
	T data;
	if (false == priorityQueue->getHead(data))
	{
		cout << "* ��ȡ��ͷԪ��ʧ��" << endl;
		return;
	}
	cout << "* ��ȡ��ͷԪ�سɹ���data = " << data << endl;
}

//����Ԫ��x���뵽��β
template <class T>
void insert(PriorityQueue<T>* priorityQueue)
{
	cout << "$ ִ�н���Ԫ��x���뵽��β����" << endl;
	T data = get_data<T>();
	if (false == priorityQueue->Insert(data))
	{
		cout << "* ���ʧ��" << endl;
		return;
	}
	cout << "* ��ӳɹ���data = " << data << endl;
}

//����ͷԪ��ɾ��
template <class T>
void removemin(PriorityQueue<T>* priorityQueue)
{
	cout << "$ ִ�н���ͷԪ��ɾ������" << endl;
	T data;
	if (false == priorityQueue->RemoveMin(data))
	{
		cout << "* ����ʧ��" << endl;
		return;
	}
	cout << "* ���ӳɹ���data = " << data << endl;
}

//�ж϶����Ƿ�Ϊ��
template <class T>
void isempty(PriorityQueue<T>* priorityQueue)
{
	cout << "$ ִ���ж϶����Ƿ�Ϊ�պ�����IsEmpty = " << priorityQueue->IsEmpty() << endl;
}

//�ж϶����Ƿ�Ϊ��
template <class T>
void isfull(PriorityQueue<T>* priorityQueue)
{
	cout << "$ ִ���ж϶����Ƿ�Ϊ��������IsFull = " << priorityQueue->IsFull() << endl;
}

//�����ȼ�����Ϊ��
template <class T>
void makeempty(PriorityQueue<T>* priorityQueue)
{
	cout << "$ ִ�������ȼ�����Ϊ�պ���" << endl;
	priorityQueue->MakeEmpty();
}

//�����ȼ�������Ԫ�ظ���
template <class T>
void getsize(PriorityQueue<T>* priorityQueue)
{
	cout << "$ ִ�������ȼ�������Ԫ�ظ���������Size = " << priorityQueue->getSize() << endl;
}

//�������Ԫ�ص����ز���<<
template <class T>
void operator_ostream(PriorityQueue<T>* priorityQueue)
{
	cout << "$ ִ���������Ԫ�ص����ز���<<����" << endl;
	cout << *priorityQueue;//��operator<<(cout, *priorityQueue);
}

//���ȼ����в���ѡ��
template <class T>
void select_operation(PriorityQueue<T>* priorityQueue)
{
	if (NULL == priorityQueue)
	{
		cout << "* û�й������ȼ����У����ȹ������ȼ����С�" << endl;
		return;
	}

	string s_operation;
	while (s_operation != "0")
	{
		cout << "\n==> �����빦��ѡ����(��\"0\"�˳�����)��";
		cin >> s_operation;
		while (false == IsNumber(s_operation))
		{
			cout << "* �����������������룺";
			cin >> s_operation;
		}
		int n_operation = atoi(s_operation.c_str());
		switch (n_operation)
		{
		case EXIT://�˳�
		{
					  cout << "$ �˳�����" << endl;
					  break;
		}
		case GETHEAD://��ȡ��ͷ(����С����Ȩ)��ֵ
		{
						 gethead(priorityQueue);
						 break;
		}
		case INSERT://����Ԫ��x���뵽��β
		{
						insert(priorityQueue);
						break;
		}
		case REMOVEMIN://����ͷԪ��ɾ��
		{
						   removemin(priorityQueue);
						   break;
		}
		case ISEMPTY://�ж϶����Ƿ�Ϊ��
		{
						 isempty(priorityQueue);
						 break;
		}
		case ISFULL://�ж϶����Ƿ�Ϊ��
		{
						isfull(priorityQueue);
						break;
		}
		case MAKEEMPTY://�����ȼ�����Ϊ��
		{
						   makeempty(priorityQueue);
						   break;
		}
		case GETSIZE://�����ȼ�������Ԫ�ظ���
		{
						 getsize(priorityQueue);
						 break;
		}
		case OPERATOR_OSTREAM://�������Ԫ�ص����ز���<<
		{
								  operator_ostream(priorityQueue);
								  break;
		}
		default:
		{
				   cout << "* ��������ȷ�Ĺ���ѡ����" << endl;
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