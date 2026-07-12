/* 个人信息已删除 */
#include <iostream>
#include <conio.h>
#include "7-b6.h"
using namespace std;

/* 给出 Date 类的所有成员函数的体外实现 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
Date::Date()
{
	year = 2000;
	month = 1;
	day = 1;
}

Date::Date(int total_days)
{
	if (total_days < 1) 
		total_days = 1;
	if (total_days > 73049) 
		total_days = 73049;

	int day_cnt = total_days - 1;
	int days_in_month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int year = 1900;
	int month = 1;
	int is_leap;
	int days_in_year;

	while (1)
	{
		is_leap = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
		days_in_year = 365 + is_leap;
		if (day_cnt < days_in_year)
			break;
		day_cnt -= days_in_year;
		year++;
	}
	this->year = year;

	if (is_leap)
		days_in_month[2] = 29;

	while (day_cnt >= days_in_month[month])
	{
		day_cnt -= days_in_month[month];
		month++;
	}
	this->month = month;

	this->day = day_cnt + 1;
}

Date::Date(int year, int month, int day)
{
	if (year >= 1900 && year <= 2099)
		this->year = year;
	else
		this->year = 2000;
	if (month >= 1 && month <= 12)
		this->month = month;
	else
		this->month = 1;

	int days_in_month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int is_leap = ((this->year % 4 == 0 && this->year % 100 != 0) || (this->year % 400 == 0));
	if (is_leap)
		days_in_month[2] = 29;
	int max_days = days_in_month[this->month];

	if (day >= 1 && day <= max_days)
		this->day = day;
	else
		this->day = 1;
}

void Date::set(int year, int month, int day)
{
	if (year != 0)
	{
		if (year >= 1900 && year <= 2099)
			this->year = year;
		else
			this->year = 2000;
	}
	if (month != 0)
	{
		if (month >= 1 && month <= 12)
			this->month = month;
		else
			this->month = 1;
	}

	int days_in_month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int is_leap = ((this->year % 4 == 0 && this->year % 100 != 0) || (this->year % 400 == 0));
	if (is_leap)
		days_in_month[2] = 29;
	int max_days = days_in_month[this->month];

	if (day != 0)
	{
		if (day >= 1 && day <= max_days)
			this->day = day;
		else
			this->day = 1;
	}
	else
	{
		if (this->day > max_days)
			this->day = 1;
	}
}

void Date::get(int &year, int &month, int &day)
{
	year = this->year;
	month = this->month;
	day = this->day;
}

void Date::show()
{
	cout << this->year << "." << this->month << "." << this->day << endl;
}
/* 如果有需要的其它全局函数的实现，可以写于此处 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/


