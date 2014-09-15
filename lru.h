//  LRU
#ifndef myLRU
#define myLRU
#include <iostream>
#include <map>
using namespace std;

template<class K, class V>
class LRU {
	struct Node {
		K key;
		V value;
		Node* left;
		Node* right;
		Node() {left=right=NULL;}
	};
	public:
	LRU(unsigned c) {cap = c; curSize=0; 
		head=new Node; tail =new Node;
		head->right = tail; tail->left=head;}
	~LRU() {
		Node *t=head;
		while(t) {
			Node* nextT=t->right;
			delete t;
			t=nextT;
		}
	}
	V find(K key, bool &found) {
		if(index.find(key) != index.end()) {
			Node* n = index[key];
			remove(n);
			prepend(n);
			found=true;
			return n->value;
		} else {
			found = false;
			return *(new V);
		}
	}
	void insert(K key, V value) {
		if(index.find(key) != index.end()) { // update the value
			Node *n = index[key];
			remove(n);
			prepend(n);
			n->value = value;
			index[key] = n;
		} else if(curSize < cap) {
			Node *n = new Node;
			n->key = key; n->value = value;
			prepend(n);
			index[key] = n;
			curSize++;
		} else {
			Node *change = tail->left;
			remove(change);
			index.erase(change->key);
			change->key = key;
			change->value = value;
			prepend(change);
			index[key]=change;
		}
	}
	void reportStat() {
		cout<<"current size="<<curSize<<" of capacity "<<cap<<endl;
	}
	private:
	void prepend(Node* n) {
		n->left=head;
		n->right=head->right;
		head->right=n;
		n->right->left=n;
	}
	void remove(Node* n) {
		n->left->right=n->right;
		n->right->left=n->left;
		n->left=NULL; n->right=NULL;
	}
	unsigned curSize;
	unsigned cap;
	Node* head;
	Node* tail;
	map<K, Node*> index;
};
#endif
