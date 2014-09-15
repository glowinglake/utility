#ifndef MYHASH
#define MYHASH
#include <iostream>
template <class K, class O>
class Hash {
private:
	struct Node {
		K key;
		O obj;
	};
	int sz;
	unsigned hashFunc(K key);
	static const int PRIME=7919;
	O nullObj;
	Node** nodes;
public:
	Hash() {nodes = new Node*[PRIME]; memset(nodes, 0, PRIME); sz=PRIME;} // choose a large prime
	unsigned size();
	O find(K key);
	bool put(K key, O obj);
	~Hash() {
		for(int i=0; i<PRIME; i++)
			if(nodes[i])
				delete nodes[i];
		delete nodes;
	}
	O end() {return nullObj;}
};
template<class K, class O>
unsigned Hash<K,O>::hashFunc(K key) {
	unsigned kSize=sizeof(K);
	char* ptr=(char*)&key;
	unsigned h=0;
	for(int i=0; i<kSize; i++) {
		h=h*7 + *(ptr+i);
	}
	h=h/sz;
	return h;
}
template<class K, class O>
unsigned Hash<K,O>::size() {
	return sz;
}
template<class K, class O>
O Hash<K,O>::find(K key) {
	unsigned pos=hashFunc(key);
	if(nodes[pos] == NULL)
		return nullObj;
	return nodes[pos]->obj;
}
template<class K, class O>
bool Hash<K,O>::put(K k, O o) {
	unsigned pos=hashFunc(k);
	Node* n = new Node;
	n->key=k; n->obj=o;
	if(nodes[pos] == NULL) {
		nodes[pos] = n;
		std::cout<<"inserted at position "<<pos<<endl;
		return true;
	} else { // linear probing
		return false;
	}
}

#endif