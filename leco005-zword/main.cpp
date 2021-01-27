#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
	string ans = "";
	int l = s.size();
	int step = 2*numRows - 2;
	if(l <= numRows){return s;}
	if(numRows == 1){return s;}
	for (int i = 0; i < numRows; ++i) {
		int j = 0;
		if( i == 0 || i == numRows - 1){
			while(j < (l / step)){
				ans+=s[i + j*step];
				++j;
			}
			if( (i + j*step) < l){ans += s[i + j*step];}
		}
		else{
			while(j < (l / step)){
				ans+=s[i + j*step];
				ans+=s[i + j*step + step - 2*i];
				++j;
			}
			if( (i + j*step) < l){ans += s[i + j*step];}
			if( (i + j*step + step -2*i) < l){ans += s[i + j*step + step - 2*i];}
		}
	}
	return ans;
    }
};
int main(int argc, char *argv[])
{
	string s, ans;
	int numRows;
	numRows = 4;
	s = "PAYPALISHIRING";
	Solution sol;
	ans = sol.convert(s,  numRows);
	cout<<"ans is :"<< ans <<endl;
	return 0;
}
