#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//class person
//{
//public:
//	virtual person* BuyTicket()
//	{
//		  cout << "ѧ��-���" << endl;
//		  return nullptr;
//	}
//};
//class student : public person
//{
//public:
//	virtual student* BuyTicket()
//	{
//		  cout << "ѧ��-ȫ��" << endl;
//		  return nullptr;
//	}
//};
//void func(person& p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	person p;
//	student s;
//	func(p);
//	func(s);
//	system("pause");
//	return 0;
//}
//class Person {
//public:
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual ~Student() { cout << "~Student()" << endl; }
//};
//
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	delete p1;
//	delete p2;
//	system("pause");
//	return 0;
//}

//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//	virtual void Func4()
//	{
//		cout << "Derive::Func4()" << endl;
//	}
//private:
//	int _d = 2;
//};
//int main()
//{
//	Base b;
//	Derive d;
//	cout << sizeof(b) << endl;
//	cout << sizeof(d) << endl;
//	system("pause");
//	return 0;
//}
//class Base {
//public:
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "Base::func2" << endl; }
//private:
//	int a;
//};
//class Derive :public Base {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//	virtual void func4() { cout << "Derive::func4" << endl; }
//private:
//	int b;
//};
//
//typedef void(*VFPTR) ();
//void PrintVTable(VFPTR vTable[])
//{
//	// ����ȡ����е��麯��ָ���ӡ�����á����þͿ��Կ���������ĸ�����
//	cout << " ����ַ>" << vTable << endl;
//	for (int i = 0; vTable[i] != 0; ++i)
//	{
//		printf(" ��%d���麯����ַ :0X%x,->", i, vTable[i]);
//		VFPTR f = vTable[i];
//		f();
//	}
//	cout << endl;
//}
//int main()
//{
//	Base b;
//	Derive d;
//	// ˼·��ȡ��b��d�����ͷ4bytes����������ָ�룬ǰ������˵���麯��������һ�����麯��ָ
//		// 1.��ȡb�ĵ�ַ��ǿת��һ��int*��ָ��
//		// 2.�ٽ�����ȡֵ����ȡ����b����ͷ4bytes��ֵ�����ֵ����ָ������ָ��
//		// 3.��ǿת��VFPTR*����Ϊ������һ����VFPTR����(�麯��ָ������)�����顣
//		// 4.���ָ�봫�ݸ�PrintVTable���д�ӡ���
//		// 5.��Ҫ˵�����������ӡ���Ĵ��뾭�����������Ϊ��������ʱ�����Ĵ����ɾ�����������
//		//û�з�nullptr������Խ�磬���Ǳ����������⡣����ֻ��Ҫ��Ŀ¼���� - ���� - �������������ٱ���ͺ��ˡ�
//	VFPTR* vTableb = (VFPTR*)(*(int*)&b);
//	PrintVTable(vTableb);
//	VFPTR* vTabled = (VFPTR*)(*(int*)&d);
//	PrintVTable(vTabled);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	Base b;
//	Derive d;
//	return 0;
//}
class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};
class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};
class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};
typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
	cout << " ����ַ>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" ��%d���麯����ַ :0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}
int main()
{
	Derive d;
	VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);
	PrintVTable(vTableb1);
	VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1)));
	PrintVTable(vTableb2);
	return 0;
}

