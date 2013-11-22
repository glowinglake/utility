#ifndef MYSTRING
#define MYSTRING

// simple implementation of string

#include <stdio.h>
#include <string.h>
using namespace std;
class myString {
	public:
		myString() {
			str=NULL;
			len=0;
		}
		myString(const char * s) {
			if(!s) {
				len=0;
			} else {
				len=strlen(s);
				str=new char[len+1];
				str[len]='\0';
				memcpy(str, s, len);
			}
		}
		~myString() {
			//printf("deleting myString %s\n", str);
			delete [] str;
		}
		const unsigned int length() {
			return len;
		}
		const bool empty() {
			return (len==0);
		}
		const char * value() {
			return str;
		}
		myString & operator=(myString & string) {
			// handle self assignment
			if(&string == this)
				return *this;
			this->len = string.length();
			if(len > 0) {
				str = new char[len+1];
				memcpy(str, string.value(), len);
			}
		}
		char & operator[](unsigned int i) {
			if(i>=len)
				return *str;
			return str[i];
		}
		myString operator+(myString &string) {
			unsigned int newLen = this->len + string.length();
			char *newStr = new char[newLen+1];
			memcpy(newStr, str, len);
			memcpy(newStr+len, string.value(), string.length());
			newStr[newLen]='\0';
			myString res;
			res.str = newStr;
			res.len = newLen;
			return res;
		}
		myString & operator+=(myString &string) {
			unsigned int newLen = this->len + string.length();
			char *newStr = new char[newLen+1];
			memcpy(newStr, str, len);
			memcpy(newStr+len, string.value(), string.length());
			newStr[newLen]='\0';
			delete [] str;
			str = newStr;
			len = newLen;
			return *this;
		}
		myString &push_back(const char c) {
			char *newStr = new char[len+2];
			memcpy(newStr, str, len);
			newStr[len]=c;
			newStr[len+1]='\0';
			len=len+1;
			delete [] str;
			str=newStr;
			return *this;
		}
		
	private:
		char *str;
		unsigned int len;
};

#endif