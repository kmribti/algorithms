/*******************************************
 * DANIEL'S PRIVATE ALGORITHM IMPLEMENTAIONS
 * Random-Select Algorithm
 * Features:
 * 1. select the smallest k-th element
 * 2. will modify orignal list
 *******************************************/

#ifndef __RANDOM_SELECT_H__
#define __RANDOM_SELECT_H__

/**
 * the random_select partition routine
 */
inline int partition(int list[],int begin, int end)
{
	int pivot_idx = choose_pivot(begin,end);
    int pivot = list[pivot_idx];
	swap(list[begin],list[pivot_idx]);

	int i = begin + 1;
	int j = end;
  
	while(i <= j)
	{
		while((i <= end) && (list[i] <= pivot))
			i++;
		while((j >= begin) && (list[j] > pivot))
			j--;
		if(i < j)
			swap(list[i],list[j]);
	}
      
	swap(list[begin],list[j]);
	return j; // final pivot position
}

/**
 * select the k-th smallest number in 'list' of range [begin, end]
 */
inline int random_select(int list[], int begin, int end, int k)
{
	if(begin == end)
		return begin;
   
	int pivot_idx = partition(list, begin, end);
	int human_idx = pivot_idx - begin + 1;

	if(k == human_idx)
		return pivot_idx;
	if(k < human_idx)
		return random_select(list, begin, pivot_idx - 1, k);
	if(k > human_idx)
		return random_select(list, pivot_idx+1, end, k - human_idx);
}

#endif //