#include<iostream>
using namespace std;

int partition(int *array, int start, int end){
	int i = start - 1;
	int j = start;
	int value = array[end];
	if (start < end)
	{
		for(j = start; j < end; j++)
		{
			if (array[j] < value)
			{
				int temp = array[++i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
		int temp = array[++i];
		array[i] = array[end];
		array[end] = temp;
	}
	return i;
}

int QuickFind(int *array, int start, int end){
	int result = array[start];
	if (start < end)
	{
		int mid = partition(array, start, end);
		if (mid == 0)
		{
			result = array[0];
			return result;
		}
		result = QuickFind(array, start, mid - 1);
	}
	return result;
}

int QuickFindInLogN(int *array, int start, int end){
	int result = 0;
	bool noFind = false;
	if (array[start] < array[end])
	{
		result = array[start];
		return result;
	}
	while(start < end)
	{
		int mid = (start + end) / 2;
		if (array[mid] == array[start] && array[mid] == array[end])
		{
			noFind = true;
			break;
		}
		if (array[mid] > array[start])
		{
			start = mid;
		}
		else if (array[mid] < array[end])
		{
			end = mid;
		}
		if ((end - start) <= 1)
		{
			result = array[end];
			break;
		}
	}
	if (noFind)
	{
		result = array[start];
		for (int i = start; i < end; i++)
		{
			if (array[i] < result)
			{
				result = array[i];
			}
		}
	}
	return result;
}
int main(){
	int array[5] = {1,1,1,0,1};
	int result = QuickFindInLogN(array, 0, 4);
	getchar();
	return 0;
}