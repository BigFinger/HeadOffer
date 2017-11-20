#include <stdio.h>


bool findNum(int **array, int find, int row, int column){
	int columnIndex = column - 1;
	int rowIndex = 0;
	if (array == NULL || row <= 0 || column <= 0)
	{
		return false;
	}
	while(columnIndex >= 0 && rowIndex < row)
	{
		if (array[rowIndex][columnIndex] == find)
		{
			return true;
		}
		else if (array[rowIndex][columnIndex] > find)
		{
			columnIndex--;
		}
		else
		{
			rowIndex++;
		}
	}
	return false;
}


int main(){
	int length, width;
	int find;
	scanf("%d", &length);
	scanf("%d", &width);
	scanf("%d", &find);
	int **num = new int*[length];

	for (int i = 0; i < length; i++)
	{
		num[i] = new int[width];
		for (int j = 0; j < width; j++)
		{
			scanf("%d", &num[i][j]);
		}
	}
	bool ret = findNum(num, find, length, width);
	getchar();
	return 0;
}