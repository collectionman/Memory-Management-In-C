#include <stdio.h>
#include "memory.h"

int main(int argc, char* argv[]) {
    double* double_ptr ;
    double value = 0.54369 ;
    while ((double_ptr = allocate(sizeof(double)))) {
        printf("Allocating... memory location: %d\n", double_ptr) ;

        value += 14.1529 ;
        *double_ptr = value ;

        printf("Value in that space is %f\n", *double_ptr) ;       
    }
    printf("There is no more free space to allocate char\n") ;

    return 0 ;
}