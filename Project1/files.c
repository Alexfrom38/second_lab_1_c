#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


FILE* write(char* name)
{
	int min = 0, max = 0, count_of_numb = 0;
	float current_rand_numb = 0;

	scanf_s("%d", &min);
	scanf_s("%d", &max);
	scanf_s("%d", &count_of_numb);
	FILE* F2 = fopen(name, "w");

	if (!F2)
	{
		printf("File isn't open");
		return 0;
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
	FILE* F2 = fopen(name, "r");
	if (!F2)
	{
		printf("File isn't open");
		return 0;
	}
	while (fscanf(F2, "%f\n", &current_rand_numb) != EOF)
	{
		//printf("numb = %f \n", current_rand_numb);
		size++;
	}
	fclose(F2);
	/////////////////////////////////////////////////////////
	array = (float*)malloc((size + 1) * sizeof(float));
	/////////////////////////////////////////////////////////
	F2 = fopen(name, "r");
	if (!F2)
	{
		printf("File isn't open");
		return 0;
	}
	while (fscanf(F2, "%f\n", &current_rand_numb) != EOF)
	{

		array[i + 1] = current_rand_numb;
		i++;
	}

	array[0] = (float)size;
	fclose(F2);
	return array;
}



