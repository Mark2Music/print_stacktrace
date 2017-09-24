#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
 
void fun1();
void fun2();
void fun3(int, int);
 
void print_stacktrace();
 
int main()
{
    //print_stacktrace();
    fun3(1,2);
    print_stacktrace();

}
 
void fun1()
{
    printf("stackstrace begin:\n");
   // print_stacktrace();
}
 
void fun2()
{
    fun1();
}
 
void fun3(int a , int b)
{
    fun2();
}
 
void print_stacktrace()
{
    int size = 16;
    void * array[16];
    int stack_num = backtrace(array, size);
    char ** stacktrace = backtrace_symbols(array, stack_num);
    for (int i = 0; i < stack_num; ++i)
    {
            printf("%s\n", stacktrace[i]);
        }
    free(stacktrace);
}
