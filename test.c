#include<stdio.h>


int main() {
    static int a;
    int c = 10;
    a = c;
    printf("a=%d\n", a);


    return 0;
}