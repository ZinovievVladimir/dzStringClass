#ifndef _STRING
#define _STRING

#include <stdlib.h>

class String
{
	char* str;
	int size;
public:
	template <typename T>
	operator T() const
	{
		return (T)atof(str);
	}
	String();
	String(const char*);
	String(String&);
	~String();
	String& operator=(String&);
	String operator+(String&);
	bool operator>(String&);
	bool operator<(String&);
	bool operator>=(String&);
	bool operator<=(String&);
	bool operator==(String&);
	void output();
};

#endif