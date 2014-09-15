#include <vector>
#include <map>
#include <set>
//#include <tr3/unordered_set>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
float maxConsecProduct(float arr[], int len) {
	float maxPos=1, maxNeg=0, res=0;
	for(int i=0; i<len; i++) {
		if(arr[i] == 0) {
			maxPos=maxNeg=0;
		} else if(arr[i] > 0) {
			maxPos = (maxPos > 1) ? maxPos*arr[i] : arr[i];
			maxNeg = maxNeg * arr[i];
			res= maxPos > res ? maxPos : res;
			cout<<i<<" res= "<<res<<endl;
		} else {
			float prevMaxPos=maxPos;
			maxPos = maxNeg * arr[i];
			maxNeg = (prevMaxPos > 1) ? prevMaxPos * arr[i] : arr[i];
			res= maxPos > res ? maxPos : res;
			cout<<i<<" res= "<<res<<endl;
		}
		
	}
	return res;
}
int main() {
	float arr[]={
		3.1,0.9,-2.7,-0.3,-0.8, 0.3,2.3,-7.5
	};
	cout<<maxConsecProduct(arr, 8);
	//existSubString("")
	return 0;
}