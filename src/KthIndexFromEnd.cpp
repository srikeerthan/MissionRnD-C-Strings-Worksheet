/*
OVERVIEW: Given a string, return the Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/

#include<stdio.h>
char KthIndexFromEnd(char *str, int K) {
	int len = 0;
	if (str == NULL)
		return '\0';
	for (len = 0; str[len]; len++);
	if (K<0||K>len||len==0)
		return '\0';
	if (K == len-1)
		return str[0];
	else if (K == 0)
		return str[len - 1];
	else
		return str[(len-1) - K];

}