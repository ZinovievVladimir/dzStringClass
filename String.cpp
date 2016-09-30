#include "String.h"
#include <stdio.h>


String::String() {
	str= new char(0);
	size=0;
}

String::String(const char* str1)
{
	size=0;
	for (;str1[size]!=0;size++);
	str= new char[size+1];
	for (int i=0; i<=size; i++)
	{
		str[i]=str1[i];
	}
}

String::String(String& a)
{
	size=a.size;
	str= new char[size+1];
	for (int i=0; i<=size; i++)
	{
		str[i]=a.str[i];
	}
}

String::~String()
{
	delete []str;
}

void String::output()
{
	printf("%s", str);	
}

String& String::operator=(String& a)
{
	if (str!=a.str)
	{
		if (size!=a.size)
		{
			size=a.size;
			delete []str;
			str= new char[size+1];
		}
		for (int i=0; i<=size; i++)
		{
			str[i]=a.str[i];
		}
	}
	return *this;
}

String String::operator+(String& a)
{
	String sum;
	sum.size=size+a.size;
	sum.str=new char[sum.size+1];
	for (int i=0; i<size; i++)
	{
		sum.str[i]=str[i];
	}
	for (int i=size, j=0; i<=sum.size;i++, j++)
	{
		sum.str[i]=a.str[j];
	}
	return sum;
}

bool String::operator==(String& a)
{
	if (size!=a.size)
		return 0;
	else
		for (int i=0; i<size; i++)
			if(str[i]!=a.str[i])
				return 0;
	return 1;
}

bool String::operator>(String& a)
{
	int minlen=(size<a.size)?size:a.size;
	if (a==*this)
		return 0;
	for(int i=0; i<minlen; i++)
	{
		if(str[i]>a.str[i])
			return 1;
		if(str[i]<a.str[i])
			return 0;
	}
	return (minlen<a.size)?0:1;
}

bool String::operator<(String& a)
{
	int minlen=(size<a.size)?size:a.size;
	if (a==*this)
		return 0;
	for(int i=0; i<minlen; i++)
	{
		if(str[i]<a.str[i])
			return 1;
		if(str[i]>a.str[i])
			return 0;
	}
	return (minlen<a.size)?1:0;
}

bool String::operator<=(String& a)
{
	if (*this>a)
		return 0;
	else
		return 1;
}

bool String::operator>=(String& a)
{
	if (*this<a)
		return 0;
	else
		return 1;
}