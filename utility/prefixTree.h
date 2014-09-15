#pragma once
#ifndef PREFIXTREE
#define PREFIXTREE
#include <string>
#include <vector>
using namespace std;
// prefixTree for text search
class prefixTree{
private:
	static const unsigned charLen = 256;
	struct Node{
		void *obj;
		bool flag;
		vector<Node*> nexts;
		Node() { 
			obj=NULL; flag=false; 
			nexts.resize(charLen); 
			for(int i=0; i<charLen; i++)
					nexts[i] = NULL;
		}
		~Node() {
			for(int i=0; i<charLen; i++)
					delete nexts[i];
		}
	};
	void recFind(Node *n, string &current, vector<string> &res);
	Node* root;
public:
	prefixTree();
	~prefixTree();
	bool insert(string s);
	bool remove(string s);
	void findAllChildren(Node *n, vector<string> &res);
	vector<string> find(string s); // recursively find based on the prefix
};
#endif