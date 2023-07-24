#include "../deck.h"


/**
 * is_letter - a function that returns wheter the
 * input character is a letter
 * @a: the input character
 * Return: int
 **/
int is_letter(char a)
{
	if (!(a >= 65 && a <= 90) && !(a >= 97 && a <= 122))
		return (0);
	return (1);
}

/**
 * is_digit - a function that returns whether
 * a character is a digit
 * @a: the character to check
 * Return: int
 **/
int is_digit(char a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}
