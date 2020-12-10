#include"queue.h"

int main(){
	Deque *dq=createDeque();
	push_back(dq,80);
	push_front(dq,90);
	push_back(dq,70);
	push_front(dq,60);
	pop_back(dq);
	size(dq);
	print(dq);
	return 0;
}
