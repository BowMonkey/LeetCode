
#include"head.h"
//Ï£¶ûÅÅĞò
void sort(int *array, int size)
{
	int h = 1;
	int i, j, temp;
	while (h < size / 3)
	{
		h = 3 * h + 1;
	}
	while (h >= 1)
	{
		for (i = h; i < size; i++)
		{
			for (j = i; j >= h && array[j] <= array[j - h]; j -= h)
			{
				temp = array[j];
				array[j] = array[j - h];
				array[j - h] = temp;
			}
		}
		h = h / 3;
	}
}
