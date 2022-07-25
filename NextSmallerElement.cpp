#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> NSE(vector<int> &a) {
	stack<int> s;
	vector<int> res(a.size());
	int i=0;
	while(i<a.size()) {
		if(s.empty()) {
			s.push(i++);
		}
		else {
			if(a[i]  < a[s.top()]) {
				res[s.top()]=i;
				s.pop();
			}
			else { 
				s.push(i++);
			}
		}
	}
	while(!s.empty()) {
		res[s.top()]=-1;
		s.pop();
	}
	return res;
}

int main()
 {
 	vector<int> a={4,2,1,5,6,3,2,4,2};
 	vector<int> res=NSE(a);
 	cout<<" orginal array : ";
 	for(int i=0;i<res.size();i++) printf("%3d",a[i]);
 	cout<<endl;
 	cout<<" NSE araay     : ";
 	for(int i=0;i<res.size();i++) {
 		res[i]==-1 ? printf("%2d",a.size()) :   printf("%2d",a[res[i]]);
 		cout<<"  ";
	 }
 }
