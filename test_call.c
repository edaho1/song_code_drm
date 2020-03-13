#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int func(int num, char str)
{
    printf("%s\t%d", str, num);
}

int main()
{
    char str = "this is a string";
    int num = 20;
    func (num, str);

    return 0;
}