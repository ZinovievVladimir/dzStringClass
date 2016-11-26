#include "String.h"
#include <stdio.h>

void sravn(String a, String b)
{
	if(a > b)
	{
		a.output();
		printf (" > ");
		b.output();
	}
	else
	{
		if (a == b)
		{
			a.output();
			printf (" = ");
			b.output();
		}
		else
		{
			a.output();
			printf (" < ");
			b.output();
		}
	}
	printf("\n");
}



void main()
{
	String str("234"), str1("134"), str2("9964"), str3("2247");
	String str4;
	

	printf("str: ");
	str.output();

	str4=str+str;
	printf("\n\nstr+str: ");
	str4.output();

	printf("\n\nstr(int): %i\n", (int)str);
	printf("str(double): %f\n", (double)str);
	printf("str(float): %f\n\n", (float)str);

	sravn(str,str1);
	sravn(str1,str2);
	sravn(str3,str1);
	sravn(str,str3);
	sravn(str,str);
}