/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
void reverse(char *str, int len)
{
	int j, temp,i;
	for (j = 0, i = len- 1; j < i; i--, j++)
	{
		temp = str[j];
		str[j] = str[i];
		str[i] = temp;
	}
}
int string(int n, char *str,int d)
{
	int i = 0;
	while (n)
	{
		str[i++] = (n % 10)+'0';
		n = n / 10;
	}
	while (i < d)
		str[i++] = '0';
	reverse(str,i);
	str[i] = '\0';
	return i;
}
int power(int i, int adec)
{
	int j;
	for (j = 1; j < adec; j++)
		i = i*i;
	return i;
}
void number_to_str(float number, char *str, int afterdecimal){
	int i,count=0,j,k=0;
	if (number < 0){
		number *= -1;
		count = 1;
	}
	int n = (int)number;
	float dec = number - (float)n;
	i=string(n, str,0);
	if (afterdecimal != 0)
	{
		str[i] = '.';
		dec = dec*power(10, afterdecimal);
		k = string((int)dec, str + i + 1, afterdecimal);
	}
	if (count == 1)
	{
		i = i + k+2;
		for (j = i; j > 0; j--)
		{
			str[j] = str[j - 1];
		}
		str[0] = '-';
	}
}
