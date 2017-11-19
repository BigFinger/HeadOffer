#pragma once
#define NULL 0



class Singleton{
public:
	static Singleton* getInstance();
	void setWhich(int which);
	int getWhich();
private:
	Singleton();
private:
	static Singleton* singleton;
private:
	int which;
};