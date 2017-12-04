#include "Queue.h"
using namespace std;

int main(){
	CQueue<int> queue;
	queue.appendTail(1);
	queue.appendTail(2);
	queue.appendTail(3);
	queue.appendTail(4);
	queue.appendTail(5);

	int head = queue.deleteHead();
	return 0;
}