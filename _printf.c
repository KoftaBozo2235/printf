#include "main.h"

void print_buffer(char hamdy[], int *hamdy1);

/**
 * _printf - Printf function
 * @hamdy2: format.
 * Return: Printed chars.
 */
int _printf(const char *hamdy2, ...)
{
    int hamdy3, hamdy4 = 0, hamdy5 = 0;
    int hamdy6, hamdy7, hamdy8, hamdy9, hamdy1 = 0;
    va_list hamdy10;
    char hamdy[BUFF_SIZE];

    if (hamdy2 == NULL)
        return (-1);

    va_start(hamdy10, hamdy2);

    for (hamdy3 = 0; hamdy2 && hamdy2[hamdy3] != '\0'; hamdy3++)
    {
        if (hamdy2[hamdy3] != '%')
        {
            hamdy[hamdy1++] = hamdy2[hamdy3];
            if (hamdy1 == BUFF_SIZE)
                print_buffer(hamdy, &hamdy1);
            /* write(1, &hamdy2[hamdy3], 1);*/
            hamdy5++;
        }
        else
        {
            print_buffer(hamdy, &hamdy1);
            hamdy6 = get_flags(hamdy2, &hamdy3);
            hamdy7 = get_width(hamdy2, &hamdy3, hamdy10);
            hamdy8 = get_precision(hamdy2, &hamdy3, hamdy10);
            hamdy9 = get_size(hamdy2, &hamdy3);
            ++hamdy3;
            hamdy4 = handle_print(hamdy2, &hamdy3, hamdy10, hamdy,
                hamdy6, hamdy7, hamdy8, hamdy9);
            if (hamdy4 == -1)
                return (-1);
            hamdy5 += hamdy4;
        }
    }

    print_buffer(hamdy, &hamdy1);

    va_end(hamdy10);

    return (hamdy5);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @hamdy: Array of chars
 * @hamdy1: Index at which to add next char, represents the length.
 */
void print_buffer(char hamdy[], int *hamdy1)
{
    if (*hamdy1 > 0)
        write(1, &hamdy[0], *hamdy1);

    *hamdy1 = 0;
}
