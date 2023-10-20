#include "monty.h"
/**
 * _strcmp - a function that compares two strings.
 * @str1: string one
 * @str2: string two
 * Return: 0 or 1 or -1 of any of the strings compared
 */
int _strcmp(char *str1, char *str2)
{
	int n;

	for (n = 0; str1[n] == str2[n] && str1[n]; n++)
		;

	if (str1[n] > str2[n])
		return (1);
	if (str1[n] < str2[n])
		return (-1);
	return (0);
}

/**
 * _sch - a function that search if a char is in a string
 * @str: the string
 * @ch: the char
 * Return: 1 on sucess and 0 on failure
 */
int _sch(char *str, char ch)
{
	int count = 0;

	while (str[count] != '\0')
	{
		if (str[count] == ch)
		{
			break;
		}
		count++;
	}
	if (str[count] == ch)
		return (1);
	else
		return (0);
}

/**
 * _strtoky - a function that cut a string into tokens using delimiter
 * @str: the string to be cut into parts
 * @delim: delimiters
 * Return: the tokenized string or NULL
 */
char *_strtoky(char *str, char *delim)
{
	static char *ptr;
	int m = 0, n = 0;

	if (!str)
		str = ptr;
	while (str[m] != '\0')
	{
		if (_sch(delim, str[m]) == 0 && str[m + 1] == '\0')
		{
			ptr = str + m + 1;
			*ptr = '\0';
			str = str + n;
			return (str);
		}
		else if (_sch(delim, str[m]) == 0 && _sch(delim, str[m + 1]) == 0)
			m++;
		else if (_sch(delim, str[m]) == 0 && _sch(delim, str[m + 1]) == 1)
		{
			ptr = str + m + 1;
			*ptr = '\0';
			ptr++;
			str = str + n;
			return (str);
		}
		else if (_sch(delim, str[m]) == 1)
		{
			n++;
			m++;
		}
	}
	return (NULL);
}
