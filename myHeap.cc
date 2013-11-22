
// simple implementation of heap, assuming minHeap

#include <stdio.h>
#include "myHeap.h"
#include <iostream>
int main() {
	myHeap h;
	h.remove(2);
	h.insert(1);
	h.insert(2);
	h.insert(3);
	h.insert(4);
	h.insert(5);
	h.insert(6);
	h.insert(7);
	h.insert(8);
	h.insert(9);
	h.insert(10);
	h.insert(11);
	h.insert(12);
	cout<<h.peek()<<endl;
	h.removeTop();
	cout<<h.peek()<<endl;
	h.remove(11);
	h.remove(1);
	cout<<h.peek()<<endl;
}
