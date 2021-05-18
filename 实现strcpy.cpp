#include<iostream>
#include <stdio.h>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <semaphore.h>
#include <functional>
#include <vector>
#include <unordered_map>
#include <string.h>
#include <cassert>

using namespace std;

char *strcpy1(char *dest, char *src) {
    int i = 0;
    assert((dest != NULL) || (src != NULL));
    char *address = dest;

    int size = strlen(dest) + 1;
    if ((dest > src) && (dest <= src + size - 1)) {
        src = src + size - 1;
        dest = dest + size - 1;
        while (size--) {
            *dest-- = *src--;
        }
        //printf("%s\n", address);
    } else {
        while (size--) {
            *dest++ = *src++;
        }
    }
    return address;
}

int main() {
    char dest[10], src[10];
    sprintf(src, "hello");
    printf("%s\n", strcpy(src + 3, src));
    printf("%s\n", strcpy1(src + 3, src));


    return 0;
}