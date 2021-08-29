#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#define size 100000
int farray[size];

void initialize(int farray[]) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		farray[i] = rand() % 100000 + 1;
	}
}
void insertionsort(int* array, int length) {
	for (int i = 1; i < length; i++) {
		int key = array[i];
		int j = i - 1;
		while (j >= 0 && array[j] > key) {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
	printf("The array is sorted using insertion sort in %u seconds\n", clock());
}


void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


void quicksort(int start, int end) {
	if (start >= end)return;
	int key = start, i = start + 1, j = end;
	while (i <= j) {
		while (i <= end && farray[i] <= farray[key]) i++;
		while (j > start && farray[j] >= farray[key])j--;
		if (i > j) swap(&farray[key], &farray[j]);
		else swap(&farray[i], &farray[j]);
	}
	quicksort(start, j - 1);
	quicksort(j + 1, end);

}


int main() {
	int array[size];
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 100000 + 1;
	}
	printf("Array of 100000 random numbers is initialized\n");
	insertionsort(array, size);
	initialize(farray);
	quicksort(0, size - 1);
	printf("The array is sorted using quick sort in %u seconds\n", clock());
	system("pause");
	return 0;
	
}
