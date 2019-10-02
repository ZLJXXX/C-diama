#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#pragma once
using namespace std;

class Date
{
public:
	
	//构造函数并初始化
	Date(int year = 2018, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
		{
	
		}
		//析构函数
		~Date()
		{
		}
		//拷贝构造函数
		Date(const Date& d)//必须传引用，否则会出现无限递归
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		//赋值运算符重载
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


	//判断平年闰年
	bool IsLeapyear(int year)//判断是否为平年
	{
		return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
	}
	//确定每个月的天数
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
		//运算符重载
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
		Date operator+(int day)//不会改变原来日期值，日期加上天数
		{
			Date ret = *this;//拷贝this指针
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
			cout << "原来的日期" << _year << "-" << _month << "-" << _day << endl;
		}

		void PrintDate2()
		{
			cout << "加日期后的日期" << _year << "-" << _month << "-" << _day << endl;
		}

		void PrintDate3()
		{
			cout << "加日期后的日期" << _year << "-" << _month << "-" << _day << endl;
		}

		void PrintDate4()
		{
			cout << "减掉日期后的日期" << _year << "-" << _month << "-" << _day << endl;
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