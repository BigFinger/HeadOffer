#include "Singleton.h"
#include "windows.h"

CRITICAL_SECTION g_csThreadCode;
/* 饿汉模式 */
Singleton* Singleton::singleton = NULL;
/* 懒汉模式 */
//Singleton* Singleton::singleton = new Singleton();

Singleton::Singleton(){
	which = 1;
}

Singleton* Singleton::getInstance(){
	EnterCriticalSection(&g_csThreadCode);
	if (singleton == NULL)
	{
		singleton = new Singleton();
	}
	LeaveCriticalSection(&g_csThreadCode);
	return singleton;
}

void Singleton::setWhich(int which){
	this->which = which;
}

int Singleton::getWhich(){
	return which;
}