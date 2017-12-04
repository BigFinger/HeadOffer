#pragma once
#include <iostream>
#include <stack>

template<typename T>
class CQueue{
public:
	CQueue(void);
	~CQueue(void);

	void appendTail(const T& node);
	T deleteHead();

private:
	std::stack<T> stack1;
	std::stack<T> stack2;
};

#include "Queue.h"

template<typename T>
CQueue<T>::CQueue(){
	
}
template<typename T>
CQueue<T>::~CQueue(){
	while(stack1.empty()==false)stack1.pop();
	while(stack2.empty()==false)stack2.pop();
}

template<typename T>
void CQueue<T>::appendTail(const T& node){
	while(!stack2.empty())
	{
		T stackNode = stack2.top();
		stack1.push(stackNode);
		stack2.pop();
	}
	stack1.push(node);
	while(!stack1.empty())
	{
		T stackNode = stack1.top();
		stack2.push(stackNode);
		stack1.pop();
	}
}

template<typename T>
T CQueue<T>::deleteHead(){
	T node;
	if (!stack2.empty())
	{
		node = stack2.top();
		stack2.pop();
	}
	return node;
}