#include "main.h"

/**
 * print_line - draws a straight line in the terminal
 * @n: number of times the character _ should be printed
 */
void print_line(int n)
{
    if (n <= 0)
    {
        _putchar('\n');
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            putchar('');
        }
        _putchar('\n');
    }
}
