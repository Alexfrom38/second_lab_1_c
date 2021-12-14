#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>



FILE* write(char* name)
{
	int min = 0, max = 0, count_of_numb = 0;
	float current_rand_numb = 0;

	printf("\n input min: ");
	scanf_s("%d", &min);

	printf("\n input max: ");
	scanf_s("%d", &max);

	printf("\n input count: ");
	scanf_s("%d", &count_of_numb);

	if (min > max)
	{
		printf("\n  min > max - err ");
		return 0;
	}
	FILE* F2 = fopen(name, "w");

	if (!F2)
	{
		printf("File isn't open");
		exit(0);
	}
		
		
		
	for (int i = 0; i < count_of_numb; i++)
	{
		current_rand_numb = (((float)rand()) / RAND_MAX) * ((float)max - (float)min) + min;
		
		fprintf(F2, "%f\n", current_rand_numb);
	}
		
		
	fclose(F2);
		
	return F2;
}
float* read(char* name)
{
	int size = 0, i = 0; float* array = NULL;
	float current_rand_numb = 0;
	FILE *F2 = fopen(name, "r");
	if (!F2)
	{
		printf("File isn't open");
		return 0;
	}
	while (fscanf(F2, "%f\n", &current_rand_numb) != EOF)
	{
		printf("numb = %f \n", current_rand_numb);
		size++;
	}
	fclose(F2);
	/////////////////////////////////////////////////////////
	array = (float*)malloc((size+1) * sizeof(float));
	/////////////////////////////////////////////////////////
	F2 = fopen(name, "r");
	if (!F2)
	{
		printf("File isn't open");
		return 0;
	}
	while (fscanf(F2, "%f\n", &current_rand_numb) != EOF)
	{
		
		array[i+1] = current_rand_numb;
		i++;
	}
	
	array[0] = (float)size;
	fclose(F2);
	return array;
}

FILE* hand_write(char* name)
{
	int count_of_numb = 0; float tmp = 0;

	printf("input count of numbs\n");
	scanf_s("%d", &count_of_numb);

	FILE* F2 = fopen(name, "w");

	if (!F2)
	{
		printf("File isn't open");
		return 0;
	}

	for (int q = 0; q < count_of_numb; q++)
	{
		printf("inpt number\n");
		scanf_s("%f", &tmp);
		fprintf(F2, "%f\n", tmp);
	}
	fclose(F2);
	return F2;
}

int main(void)
{ 
	float* array;
	int q = 999;
	float current_rand_numb = 0;
	int min = 0, max = 0, count_of_numb = 0;
	char* name = NULL;
	name = "test123.txt";
	FILE* F2 = NULL;

	printf("q - 1 rand\n");
	printf("q - 2 hand_write\n");

	scanf_s("%d", &q);

	if (q == 1)
		F2 = write(name);
	else if (q == 2)
		F2 = hand_write(name);

	array = read(name);
	for (int i = 0; i <= array[0]; i++)
	{
		printf("%f  ", array[i]);
	}
	free(F2); free(array);
	


	return 0;
}


