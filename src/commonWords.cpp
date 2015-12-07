/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31

int exists(char *s1, int beginning, int end, char *s2, int wordLength)
{
	int index, count = 0, temp = beginning;
	for (index = 0; s2[index] != '\0'; index++)
	{
		if (s2[index] == ' ')
		{
			count = 0;
			temp = beginning;
			continue;
		}
		if (s1[temp] == s2[index])
		{
			count++;
			temp++;
		}
		if (count == wordLength)
			return(1);
	}
	return(0);
}

char ** commonWords(char *str1, char *str2)
{
	if (str1 == '\0' || str2 == '\0')
		return(NULL);
	int index, k = 0, count = 1, index1, resindex = 0, j = 0, flag = 0;
	char **result = (char **)malloc(SIZE * sizeof(int *));
	for (index = 0; index < SIZE; index++)
		result[index] = (char *)malloc(SIZE * sizeof(char));
	for (index = 0; str1[index] != '\0'; index++)
	{
		if (str1[index] == ' ')
		{
			k = index + 1;
			count = 1;
			continue;
		}
		if (str1[index + 1] == ' ' || str1[index + 1] == '\0')
		{
			if (exists(str1, k, index, str2, count))
			{
				flag = 1;
				for (index1 = k; index1 <= index; index1++)
				{
					result[resindex][j++] = str1[index1];
				}
				result[resindex][j] = '\0';
				resindex++;
				j = 0;
			}
		}
		count++;
	}
	if (!flag)
		return(NULL);
	return(result);
}