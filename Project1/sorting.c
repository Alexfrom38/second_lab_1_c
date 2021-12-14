#include<stdio.h>
#include<stdlib.h>

void buble_sort(float *array, int size)
{
	float temporary = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size -i -1 ;  j++)
		{
			
			if (array[j] > array[j + 1])
			{
				temporary = array[j];
				array[j] = array[j+1];
				array[j + 1] = temporary;
			}
		}
  }
	

}


void InserSort(float* array, int size)
{
	int i = 0,j = 0;
	float temporary;

	for (i = 0; i < size; i++)
	{
		temporary = array[i];

		for (j = i - 1; j >= 0; j--)
			if (array[j] > temporary)
			{
				array[j + 1] = array[j];
			}
			else
				break;
		
		array[j + 1] = temporary;
	}

}

void qSort(float* array, int low, int up)
{
	int i = low;
	int j = up;
	float tmp = 0;
	float x = array[(int)((low + up) / 2)];

	do
	{
		while (array[i] < x)
			++i;
		while (array[j] > x)
			--j;

		if (i <= j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			i++;
			j--;
		}
	} while (i < j);
	if (low < j)
		qSort(array, low, j);
	if (i < up)
		qSort(array, i, up);
}

void QuickSort( float* array, int size)
{
	qSort(array, 0, size - 1);
}