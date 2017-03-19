
#include<stdio.h>
#include<stdlib.h>

int *twoSum(int *nums, int numsSize, int target);
void sort(int *array, int size);


int main(void)
{
	int *p;
	int target = 200;
	int nums[] = { 150,24,79,50,88,345,3};
	p = twoSum(nums, sizeof(nums) / sizeof(nums[0]), target);
	return 0;
}

int *twoSum(int *nums, int numsSize, int target)
{
	int lo, hi, i, j, id1, id2;
	int n = 1;
	int *answer = NULL;
	int *array = (int *)malloc(sizeof(int) * numsSize);
	for (i = 0; i < numsSize; i++)
	{
		array[i] = nums[i];
	}
	//loÎªnums×î×ó¶Ë£¬hiÎªnums×îÓÒ¶Ë
	lo = 0;
	hi = numsSize - 1;
	sort(array, numsSize);
	for ( i = 0; i < numsSize; i++)
	{
		printf("%d ", array[i]);
	}
	while (hi > lo)
	{
		if (array[lo] + array[hi] < target)
			lo++;
		else if (array[lo] + array[hi] > target)
			hi--;
		else
		{
			answer = (int *)realloc(answer, 2 * n);
			for (i = 0; i < numsSize; i++)
			{
				if (array[lo] == nums[i])
				{
					id1 = i;
					break;
				}

			}
			for (j = numsSize - 1; j >= 0; j--)
			{
				if (array[hi] == nums[j])
				{
					id2 = j;
					break;
				}
			}
			answer[2 * n - 2] = id1;
			answer[2 * n - 1] = id2;
			n++;
			hi--;
		}
	}
	return answer;
}

//Ï£¶ûÅÅÐò
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
