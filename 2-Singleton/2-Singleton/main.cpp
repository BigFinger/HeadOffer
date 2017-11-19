#include "Singleton.h"
#include <stdio.h>
#include "windows.h"

extern CRITICAL_SECTION g_csThreadCode;

int main(){
	InitializeCriticalSection(&g_csThreadCode);
	Singleton* s1 = Singleton::getInstance();
	Singleton* s2 = Singleton::getInstance();

	s1->setWhich(2);
	printf("%d,%d", s1->getWhich(), s2->getWhich());
}