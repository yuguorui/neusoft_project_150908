#include "header.h"
#include <time.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return (long long)(((Road*)a)->roadNO) - (long long)(((Road*)b)->roadNO);
}

long quickSort(Road *roads)
{
	int index = 0;
	while (roads[index].lenth != 0)
	{
		index++;
	}

	clock_t start = clock();
	qsort(roads, index, sizeof(Road), cmp);
	clock_t end = clock();
	return end - start;
}

long bubbleSoft(Road *roads)
{
	long index = 0;
	while (roads[index].lenth != 0)
	{
		index++;
	}

	clock_t start = clock();
	long i, j;
	Road temp;
	for (i = 0; i < index - 1; i++)
		for (j = 0; j < index - 1 - i; j++)
			if (roads[j].roadNO > roads[j + 1].roadNO) {
				temp = roads[j];
				roads[j] = roads[j + 1];
				roads[j + 1] = temp;
			}
	clock_t end = clock();

	return end - start;
}