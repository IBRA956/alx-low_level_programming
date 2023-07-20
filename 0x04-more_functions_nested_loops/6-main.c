#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    print_line(0);    // Will print an empty line because n is 0.
    print_line(2);    // Will print "__" (two underscores) in a new line.
    print_line(10);   // Will print "__________" (ten underscores) in a new line.
    print_line(-4);   // Will print an empty line because n is less than or equal to 0.
    return (0);
}

