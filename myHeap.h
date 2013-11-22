#ifndef MYHEAP
#define MYHEAP

// simple implementation of heap, assuming minHeap

#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
class myHeap {
	public:
		myHeap() {
			data.push_back(0); // dummy, for index matching, now x's children 2x, 2x+1, y's parent y/2
		}
		//~myHeap();
		bool empty() {return data.size() <= 1;}
		int size() {return data.size() - 1;}
		int peek() {
			if(empty())
				return 0;
			return data[1];
		}
		void insert(int n) {
			data.push_back(n);
			int in=data.size()-1;
			while(in > 1 && data[in/2] > data[in]) {
				swap(data[in/2], data[in]);
				in=in/2;
			}
		}
		void removeTop() {
			if(empty()) {
				printf("empty heap for removeTop\n");
				return;
			}
			remove(1);
		}
		void remove(int index) {
			if(index < 1 || index >= data.size()) {
				printf("invalid index %d for removal\n", index);
				return;
			}
			int last=data.size()-1;
			swap(data[index], data[last]);
			data.pop_back();
			while(1) {
				if(index*2+1 < data.size()) { // both children exist
					int swapElement;
					if(data[index*2] < data[index*2+1])
						swapElement=index*2;
					else
						swapElement=index*2+1;
					if(data[swapElement] < data[index]) {
						swap(data[swapElement], data[index]); index=swapElement;
					}
					else
						break;
				} else if(index*2 < data.size()) { // only left child exists
					if(data[index*2] < data[index]) {
						swap(data[index*2], data[index]); index=index*2;
					} else
						break;
				} else
					break;
			}
		}
	private:
		vector<int> data;
};
#endif