#include "prefixTree.h"


prefixTree::prefixTree(void)
{
	root=new Node;
}


prefixTree::~prefixTree(void)
{
	delete root; // will recursively delete all children
}

bool prefixTree::insert(string s) {
	if(s.empty() || s.length() == 0)
		return false;
	int i=0;
	Node *cur = root;
	for(i=0; i<s.length(); i++) {
		char c = s[i];
		if(cur->nexts[c])
			cur = cur->nexts[c];
		else {
			cur->nexts[c] = new Node;
			cur = cur->nexts[c];
		}
	}
	if(!cur->flag)
		cur->flag = true;
	return true;
}

bool prefixTree::remove(string s) {
	if(s.empty() || s.length() == 0)
		return false;
	int i=0;
	Node *cur = root;
	for(i=0; i<s.length(); i++) {
		char c = s[i];
		if(cur->nexts[c])
			cur = cur->nexts[c];
		else {
			return false;
		}
	}
	if(cur->flag)
		cur->flag = false;
	return true;
}

vector<string> prefixTree::find(string s) {
	vector<string> res;
	int i=0;
	Node *cur = root;
	//first find the base of "s"
	for(i=0; i<s.length(); i++) {
		char c = s[i];
		if(cur->nexts[c])
			cur = cur->nexts[c];
		else {
			//no string with given prefix
			return res;
		}
	}
	//then recursively search for all children
	findAllChildren(cur, res);
	return res;
}
void prefixTree::recFind(Node *n, string &current, vector<string> &res) {
	if(n->flag)
			res.push_back(current);
	for(int i=0; i < charLen; i++) {
			if(n->nexts[i]) {
				current.push_back(i);
				recFind(n->nexts[i], current, res);
				current.pop_back();
			}
	}
}
void prefixTree::findAllChildren(Node *n, vector<string> &res) {
	string current;
	recFind(n, current, res);
}