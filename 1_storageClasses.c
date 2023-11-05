#include <stdio.h>
int a = 20; // global variable
void local()
{
    int i = 10; // local variable
    printf("\nThe value of local variable: %d", i);
}
void stat()
{
    static int j = 0; // static variable
    printf("\nThe value of static variable is: %d ", j++);
}
int main()
{
    printf("\nThe value of global variable is: %d", a);
    local();
    stat();
    stat();
    return 0;
}
