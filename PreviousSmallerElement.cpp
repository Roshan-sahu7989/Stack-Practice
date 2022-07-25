#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> PSE(vector<int> &a) {
	stack<int> s;
	vector<int> NSE(a.size());
	int i=0;
	while(i<a.size()) {
		if(s.empty()) {
			NSE[i]=-1;
			s.push(i);
			i++;
		}
		else {
			if(a[s.top()] < a[i]) {
				NSE[i]=s.top();
				s.push(i++);
			}
			else  {
				s.pop();
			}
		}
	}
	return NSE;
}

int main()
 {
 	vector<int> a={4,2,1,5,6,3,2,4,2};
 	vector<int> res=PSE(a);
 	cout<<" orginal array : ";
 	for(int i=0;i<res.size();i++) printf("%3d",a[i]);
 	cout<<endl;
 	cout<<" NSE araay     : ";
 	for(int i=0;i<res.size();i++) {
 		res[i]==-1 ? printf("%2d",res[i]) :   printf("%2d",a[res[i]]);
 		cout<<"  ";
	 }
 }
