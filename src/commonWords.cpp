/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

int subString(char *array, char *str2);
#include <malloc.h>

#define SIZE 31
char ** commonWords(char *str1, char *str2) {
	int i, k = 0;
	int flag = -1, m = 0, n;
	char array[20];
	char **result = (char **)malloc(SIZE * sizeof(char *));

	if ((str1&&str1[0]) || (str2&&str2[0])){

		for (i = 0; i<SIZE; i++)
			result[i] = (char *)malloc(30 * sizeof(char *));
		for (i = 0; str1[i] != '\0'; i++)
		{
			if (str1[i] != ' ')
				array[k++] = str1[i];
			if (str1[i] == ' ' || str1[i + 1] == '\0')
			{
				array[k++] = '\0';
				flag = subString(array, str2);
				if (flag == 1)
				{
					for (n = 0; array[n] != '\0'; n++)
					{
						result[m][n] = array[n];
					}
					result[m][n] = '\0';
					m++;
					printf("\n");
				}
				k = 0;
			} //sub string if close

		}  //for close  
		if (m>0)
			return result;
	}
	return NULL;
}
int subString(char *array, char *str2)
{
	int count1 = 0, count2 = 0, flag = -1, i, j;
	while (str2[count1] != '\0')
		count1++;

	while (array[count2] != '\0')
		count2++;

	for (i = 0; i <= count1 - count2; i++)
	{
		for (j = i; j<i + count2; j++)
		{
			flag = 1;
			if (str2[j] != array[j - i])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			break;
	}
	return flag;
}
