#include<stdio.h>
#include<stdlib.h>
#include"files.h"
#include"sorting.h"
#include<time.h>

void print(float* array, int size)
{
	printf("\n");

	for (int q = 0; q < size; q++)
		printf("%f ", array[q]);

	printf("\n");

}

int get_size(float* array)
{
	int size = 0; 
	size = (int)array[0];
	return size;
}

int main(void)
{
	clock_t t1 = 0, t2 = 0;
	int size = 0;
	char* name = "C:\\Users\\Alex\\source\\repos\\second_lab_1_c\\second_lab_1_c\\test123.txt";
	int q = 999; 
	float* current_array = NULL;
	float* temporary_array = NULL;


	while (q != 0)
	{
		printf("0 - exit \n");
	//	printf("1 - input random array in file \n");
		//printf("2 - input array from keyboard \n");
		printf("1 - read array from file \n");
	//	printf("4 - get random array \n");
		printf("2 - show array \n");
		printf("3 - reset array value \n");
		printf("4 - sort array  \n");
		printf("5 -  current_array = temporary_array(random array without sorting) \n");

		scanf_s("%d",&q);
		switch (q)
		{
		case 0:            
			return 0;
			break;
			///////////////////////////////////////////////////////////////////////////////////////////
		case 1:
			//temporary_array = read(name);
			current_array = read(name);
			if (current_array == 0) return 0;
			size = get_size(current_array);
			temporary_array = (float*)malloc(size * sizeof(float));
			for (int i = 0; i < size; i++)
			{
				temporary_array[i] = current_array[i + 1];
			}
			current_array = (float*)malloc(size * sizeof(float));
			
			for (int i = 0; i < size; i++)
			{
				 current_array[i] = temporary_array[i];
			}
		
			break;
			///////////////////////////////////////////////////////////////////////////////////////////
		case 2:

			print(current_array,size);
			break;
			///////////////////////////////////////////////////////////////////////////////////////////
		case 3:
			for (int i = 0; i < size; i++)
			{
				current_array[i] = 0;
			}
			break;

		case 4:
			t1 = clock();
			buble_sort(current_array, size);
			t2 = clock();
			printf("time for buble_sort: %lf", (((double)(t2 - t1)) / CLOCKS_PER_SEC));

			for (int i = 0; i < size; i++)
			{
				current_array[i] = temporary_array[i];
			}

			t1 = clock();
			InserSort(current_array, size);
			t2 = clock();
			printf("time for insert_sort: %lf", (((double)(t2 - t1)) / CLOCKS_PER_SEC));

			for (int i = 0; i < size; i++)
			{
				current_array[i] = temporary_array[i];
			}

			t1 = clock();
			QuickSort(current_array, size);
		
			t2 = clock();
			printf("time for buble_sort: %lf", (((double)(t2 - t1)) / CLOCKS_PER_SEC));

			break;
			///////////////////////////////////////////////////////////////////////////////////////////
		case 5:

			for (int i = 0; i < size; i++)
			{
				current_array[i] = temporary_array[i];
			}
			break;

		default:
			printf("invalid input \n");

		}

	}

	return 0;
	
}

