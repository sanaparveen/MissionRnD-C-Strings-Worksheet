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
#include<cmath>

void reverseString(char *str, int len)
{
	int i = 0, j = len - 1;
	while (i<j)
	{
		str[i] = str[i] + str[j];
		str[j] = str[i] - str[j];
		str[i] = str[i] - str[j];
		i++; j--;
	}
}

int toString(int num, char str[], int len)
{
	int i = 0;
	while (num)
	{
		str[i++] = (num % 10) + '0';
		num = num / 10;
	}
	while (i < len)
		str[i++] = '0';
	reverseString(str, i);
	str[i] = '\0';
	return i;
}

void number_to_str(float number, char *str,int afterdecimal){

	int beforePoint, len;
	float afterPoint;
	if (number<0)
	{
		number = -1 * number;
		str[0] = '-';
	}
	beforePoint = (int)number;
	if (str[0] != '-')
		len = toString(beforePoint, str, 0);
	else
	{
		len = toString(beforePoint, str + 1, 0);
		len++;
	}
	afterPoint = number - (float)beforePoint;

	if (afterdecimal != 0)
	{
		str[len] = '.';
		afterPoint = afterPoint * pow(10, afterdecimal);
		toString((int)afterPoint, str + len + 1, afterdecimal);
	}
	
}
