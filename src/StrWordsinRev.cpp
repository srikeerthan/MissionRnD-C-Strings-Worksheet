/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void reverse(char *str, int first, int last)
{
	int i,j,temp;
	for (i = first, j = last - 1; i < j; i++, j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}
void str_words_in_rev(char *input, int len){
	int i,first=0,count=0;
	for (i = 0; input[i]; i++)
	{
		if (input[i] == ' '){
			if (count == 1){
				reverse(input, first, i);
				count = 0;
			}
		}
		else
		{
			if (count == 0)
				first = i;
			count = 1;
		}
	}
	reverse(input, first, i);
	reverse(input, 0, len);
}
