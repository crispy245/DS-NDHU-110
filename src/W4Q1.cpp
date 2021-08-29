#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int *array, int n)
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(array[j] > array[j+1]){
                swap(array[j],array[j+1]);
            }
        }
    }
}
void selectionSort(int *array, int n)
{
    int min;
	for(int i = 0; i < n; i++){
		min = i;
		for(int j = i+1; j<n; j++){
			if(array[j] < array[min]){
				min = j;
				swap(array[min],array[i]);
			}
		}
	}
}
void insertionSort(int *array, int n)
{
    for(int i = 1; i < n; i++){
        int key = array[i];
        int j = i-1;
        while(j >= 0 && array[j] > key){
            array[j+1] = array[j];
            j -= 1;
        }
        array[j+1] = key;
    }
}

int main()
{
	int array[SIZE];
	int j, k;

	printf("BUBBLE SORT \n");
	srand(time(NULL));
	for(j = 0;j < SIZE;j ++)
		array[j] = rand()%10;
		
	for(j = 0;j < SIZE;j ++)
		printf("%d ", array[j]);
	printf("\n");
	
	bubbleSort(array, SIZE);
		
	for(j = 0;j < SIZE;j ++)
		printf("%d ", array[j]);
	printf("\n");
	
	printf("INSERTION SORT \n");
	for(j = 0;j < SIZE;j ++)
		array[j] = rand()%10;
		
	for(j = 0;j < SIZE;j ++)
		printf("%d ", array[j]);
	printf("\n");
	
	insertionSort(array, SIZE);
		
	for(j = 0;j < SIZE;j ++)
		printf("%d ", array[j]);
	printf("\n");
		
	printf("SELECTION SORT \n");
	for(j = 0;j < SIZE;j ++)
		array[j] = rand()%10    ;
		
	for(j = 0;j < SIZE;j ++)
		printf("%d ", array[j]);
	printf("\n");
	
	selectionSort(array, SIZE);
		
	for(j = 0;j < SIZE;j ++)
		printf("%d ", array[j]);
	printf("\n");
 }
