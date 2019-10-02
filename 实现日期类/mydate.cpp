#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#pragma once
using namespace std;

class Date
{
public:
	
	//���캯������ʼ��
	Date(int year = 2018, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
		{
	
		}
		//��������
		~Date()
		{
		}
		//�������캯��
		Date(const Date& d)//���봫���ã������������޵ݹ�
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		//��ֵ���������
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


	//�ж�ƽ������
	bool IsLeapyear(int year)//�ж��Ƿ�Ϊƽ��
	{
		return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
	}
	//ȷ��ÿ���µ�����
	int GetmonthDay(int year, int month)
	{
		static int monthday[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (IsLeapyear(year) && month == 2)
		{
			return 29;
		}
		else
		{
			return monthday[month];
		}
	}
		//���������
		bool operator==(const Date& d)
		{
			return _year == d._year
				&&_month == d._month
				&&_day == d._day;
		}
		Date& operator+=(int day)
		{
			_day += day;
			while (_day > GetmonthDay(_year, _month))
			{
				_day = _day - GetmonthDay(_year, _month);
				_month += 1;
				if (_month > 12)
				{
					++_year;
					_month = 1;
				}
			}
			return *this;
		}
		Date operator+(int day)//����ı�ԭ������ֵ�����ڼ�������
		{
			Date ret = *this;//����thisָ��
			return ret += day;

		}
		Date& operator-=(int day)
		{
			if (day < 0)
			{
				return *this += (-day);
			}

			_day = _day - day;
			while (_day < 1)
			{
				_month -= 1;
				if (_month == 0)
				{
					_month = 12;
					--_year;
				}

				_day += GetmonthDay(_year, _month);
			}

			return *this;
		}

		Date operator-(int day)
		{
			Date ret = *this;
			return ret -= day;
		}
		void PrintDate1()
		{
			cout << "ԭ��������" << _year << "-" << _month << "-" << _day << endl;
		}

		void PrintDate2()
		{
			cout << "�����ں������" << _year << "-" << _month << "-" << _day << endl;
		}

		void PrintDate3()
		{
			cout << "�����ں������" << _year << "-" << _month << "-" << _day << endl;
		}

		void PrintDate4()
		{
			cout << "�������ں������" << _year << "-" << _month << "-" << _day << endl;
		}


	private:
		int _year;
		int _month;
		int _day;
	};


	int main()
	{
		Date d1(2019, 9, 18);
		d1.PrintDate1();
		Date d2;
		d2 = d1 + 66;
		d2.PrintDate2();

		Date d3;
		d3 += 66;
		d3.PrintDate3();

		Date d4 = d1 - 66;
		d4.PrintDate4();


		system("pause");
		return 0;
	}