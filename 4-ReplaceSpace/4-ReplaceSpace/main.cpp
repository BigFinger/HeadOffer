#include <stdio.h>
#include <cstring>

char* replaceSpace(char* line, int length){
	int newLength = 0;

	for(int i = 0; i < length; i++)
	{
		if (line[i] == ' ')
		{
			newLength++;
		}
	}
	newLength = length + newLength * 2;
	if (newLength <= length)
	{
		return line;
	}
	char* newLine = new char[newLength];
	memset(newLine, 0, newLength);
	strcpy(newLine, line);
	length--;
	newLength--;

	while(length >= 0 && newLength > length)
	{
		if (newLine[length] == ' ')
		{
			newLine[newLength--] = '0';
			newLine[newLength--] = '2';
			newLine[newLength--] = '%';
		}
		else
		{
			newLine[newLength--] = newLine[length];
		}
		length--;
	}
	return newLine;

}

int main(){
	char temp[100] = "We are happy!";
	char* result = replaceSpace(temp, strlen(temp));
	printf("%s\n", result);
	getchar();
	return 0;
}