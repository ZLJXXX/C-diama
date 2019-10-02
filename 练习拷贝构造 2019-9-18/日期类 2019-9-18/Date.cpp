#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year = 1900,int month = 1, int day = 1)//���캯��
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//�������쵥��������const����
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//��ֵ��������أ�ʹ��operator
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	void disDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2019, 9, 18);
	d1.disDate();
	Date d2(d1);
	d2.disDate();
	Date d3(2019, 1, 1);
	d3 = d1;
	d3.disDate();
	system("pause");
	return 0;
}