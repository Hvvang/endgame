#include "header.h"

void *f_rand(void *param) {
    int *arr = (int *)param;
	for (int i = 0; i < 90 ; i++) {
	    arr[i] = (rand() % 86) + 4;
	}
	pthread_exit(NULL);
}
