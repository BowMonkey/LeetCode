

#include"head.h"


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
	//lo为nums最左端，hi为nums最右端
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

