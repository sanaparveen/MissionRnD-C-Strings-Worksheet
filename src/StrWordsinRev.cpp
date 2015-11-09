/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void reverse(char *i, char *j);
void str_words_in_rev(char *input, int len){

	char *start = input;
	char *temp = input;
	while (*temp)
	{
		temp++;
		if (*temp == '\0')
		{
			reverse(start, temp - 1);
		}
		else if (*temp == ' ')
		{
			reverse(start, temp - 1);
			start = temp + 1;
		}
	}
	reverse(input, temp - 1);
	
}
void reverse(char *i, char *j)
{
	char temp;
	while (i < j)
	{
		temp = *i;
		*i++ = *j;
		*j-- = temp;
	}
}
