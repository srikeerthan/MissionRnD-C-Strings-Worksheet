/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

#include<stdio.h>
char removeSpaces(char *str) {
	int i, j,count=0;
	if (str==NULL)
		return '\0';
	for (i = 0, j = 0; str[i]; i++)
	{
		if (str[i] == ' '){
			count = 1;
			continue;
		}
		else
		{
			if (count == 0)
				j++;
			else
			{
				str[j] = str[i];
				j++;
			}
		}
	}
	str[j] = '\0';
}