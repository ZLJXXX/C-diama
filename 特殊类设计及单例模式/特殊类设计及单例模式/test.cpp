#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<thread>
#include<mutex>
using namespace std;
class ordinary{
public:
	ordinary()
	{
		cout << "ordinary" << endl;
	}
};
//int main(){
//	ordinary hp1;				// ջ
//	static ordinary hp2;		// ���ݶ�(��̬��)
//	ordinary* p = new ordinary; // ��
//	system("pause");
//	return 0;
//}
// ֻ���ڶ���
class HeapOnly
{
public:
	static HeapOnly* GetHeapObj()
	{
		HeapOnly* p = new HeapOnly;
		return p;
	}

private:
	HeapOnly()
	{
		cout << "HeapOnly()" << endl;
	}
	//��������˽�л�
	//C++98��ֻ������������
	//HeapOnly(const HeapOnly&);
	//C++11
	HeapOnly(const HeapOnly&) = delete;//ɾ����������
};
class StackOnly
{
public:
	static StackOnly CreateObject()
	{
		return StackOnly();
	}
private:
	StackOnly()
	{}
	/*void* operator new(size_t size);
	void operator delete(void* p);*/
};
//class NonInherit final
//{
//public:
//	NonInherit()
//	{}
//};
//
//class Inherit : public NonInherit  // �������๹�캯�����趨
//{};
//int main()
//{
////	//HeapOnly hp1;				// ջ
////	//static HeapOnly hp2;		// ���ݶ�(��̬��)
////	HeapOnly* p = HeapOnly::GetHeapObj(); // ��
////	//HeapOnly copy1(*p); //ջ��������
////	//static HeapOnly copy(*p); //���ݶο�������
//
//	//StackOnly so = StackOnly::CreateObject();
//	////static StackOnly so1(so);
//	////StackOnly* p2 = new StackOnly; // operator new + ���캯��
//
//	/*Inherit p1;*/
//	system("pause");
//	return 0;
//}

//����:
//���� --> һ�����ͳ�ʼ����main������ʼ֮���ʵ��������
class Singleton
{
public:
	static Singleton& GetInstance()
	{ 
		//˫�ؼ�����Ч��
		if (_sInst == nullptr)
		{
		    _stx.lock();
			if (_sInst == nullptr)
			{
				_sInst = new Singleton;
			}
			_stx.unlock();
			
		}
		return *_sInst;
	}
private:
	//���캯��˽�л�
	Singleton()
	{}
	//�������캯��˽�л�
	Singleton(const Singleton&) = delete;
	static Singleton* _sInst;//���� 
	static mutex _stx;
};
Singleton* Singleton::_sInst = nullptr;
mutex Singleton::_stx;
int main()
{
	/*cout << &Singleton::GetInstance() << endl;
	cout << &Singleton::GetInstance() << endl;
	cout << &Singleton::GetInstance() << endl;
	cout << &Singleton::GetInstance() << endl;*/

	// ���߳�������Singleton::GetInstance()����û���̰߳�ȫ�����⣿
	// 
	vector<thread> vthreads;
	for (size_t i = 0; i < 100; ++i)
	{
		vthreads.push_back(thread([]()
		{
			this_thread::sleep_for(std::chrono::seconds(1));
			for (size_t i = 0; i < 10; ++i)
			{
				cout << &Singleton::GetInstance() << endl;
			}
		}));
	}
	for (auto& e : vthreads)
	{
		e.join();
	}
	system("pause");
	return 0;
}
