#include <iostream>
#include "CMyString.h"

#define  MAX_PATH 100

int main(){
	char test[MAX_PATH] = "This is Test"; 
	CMyString str(test);

	CMyString str2;
	str2 = str;
	std::cout<< str2.getData() <<std::endl;
	getchar();
}