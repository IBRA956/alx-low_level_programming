#include "main.h"

/**
 * print_line - draws a straight line in the terminal
 * @n: number of times the character _ should be printed
 */
void print_line(int n)
{
    if (n <= 0)
    {
        _putchar('\n'); // Assuming _putchar is a function to print a character
    }
    else
    {
        int i;

        for (i = 1; i <= n; i++)
        {
            _putchar('_'); // Print underscores ('_') n times
        }
        _putchar('\n'); // Move to the next line after printing the line of underscores
    }
}

