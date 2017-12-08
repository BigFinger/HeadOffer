#include <iostream>
using namespace std;

int FibonacciRecursion(int a){
	if (a <= 0)
	{
		return 0;
	}
	else if (a == 1)
	{
		return 1;
	}
	return FibonacciRecursion(a - 1) + FibonacciRecursion(a - 2);
}

int FibonacciCycle(int a){
	int result = 0;
	int *array = new int[a + 1];
	for (int i = 0; i < a + 1; i++)
	{
		if (i == 0)
		{
			array[i] = 0;
		}
		else if (i == 1)
		{
			array[i] = 1;
		}
		else
		{
			array[i] = array[i - 1] + array[i - 2];
		}
	}
	result = array[a];
	delete[] array;
	array = NULL;
	return result;
}

int main(){
	int a = 3;
	int result = FibonacciRecursion(a);
	result = FibonacciCycle(a);
	getchar();
	return 0;
}