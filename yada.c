#include <stdio.h>
 /* count characters in input; 2nd version */
 int main()
 { int c, nl;

    nl = 0;
    while((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            ++nl;
        }
    }
    printf("%d\n", nl);
 }