/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

char removeSpaces(char *str) {

	int i, newIndex = 0;
	if (str&&str[0])
	{
		for (i = 0; str[i] != '\0'; i++)
		if (str[i] != ' ')
			str[newIndex++] = str[i];

		str[newIndex] = '\0';
	}
	else
		return '\0';
}