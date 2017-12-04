#include "Queue.h"

template<typename T>
CQueue<T>::CQueue(){
	stack1.clear();
	stack2.clear();
}
template<typename T>
CQueue<T>::~CQueue(){
	stack1.clear();
	stack2.clear();
}

template<typename T>
void CQueue<T>::appendTail(const T& node){
	while(!stack2.empty())
	{
		T stackNode = stack2.pop();
		stack1.push(stackNode);
	}
	stack1.push(node);
	while(stack1.empty())
	{
		T stackNode = stack1.pop();
		stack2.push(stackNode);
	}
}

template<typename T>
T CQueue<T>::deleteHead(){
	T node;
	if (!stack2.empty())
	{
		node = stack2.pop();
	}
	return node;
}