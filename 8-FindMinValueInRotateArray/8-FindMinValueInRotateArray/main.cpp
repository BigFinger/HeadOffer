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

int main(){
	int array[5] = {1,2,3,4,5};
	int result = QuickFind(array, 0, 4);
	getchar();
	return 0;
}