#include "memory.h"

#define ALLOCSIZE          32 /* tamaño del espacio libre  */
#define NULL_PTR_SPACE      0 /* dirección de memoria no valida */

static double allocbuf[ALLOCSIZE] ; /* almacenamiento para allocate */
static double* nextfspc = allocbuf ; /* siguiente posición libre */ 

double* allocate(int nbytes) {
    if (allocbuf + ALLOCSIZE - nextfspc >= nbytes) {
        nextfspc += nbytes ;
        return nextfspc - nbytes ; /* antiguo puntero */
    } else { /* no hay espacio */
        return NULL_PTR_SPACE ;
    }
}

void deallocate(double* ptr) {
    if (ptr >= allocbuf && ptr < allocbuf + ALLOCSIZE) {
        nextfspc = ptr ; /* nuevo espacio libre */
    }
}