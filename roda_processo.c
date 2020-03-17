#include <stdio.h>
void print_all(FILE *stream)
{
    int c;
    while ((c = getc(stream)) != EOF)
putchar(c);
}
int main(void)
{
    FILE *stream;

    if ((stream = popen("ping www.google.com -c 3", "r")) == NULL)
        return 1;
    print_all(stream);
    pclose(stream);
    return 0;
}