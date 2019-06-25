#include "header.h"

void *f_rand(void *param) {
	//srand(time(NULL));
    int *arr = (int *)param;
	for (int i = 0; i < 90 ; i++) {
	    arr[i] = (rand() % 100 - 2 - 10) + 1;
	}
    return NULL;
}
