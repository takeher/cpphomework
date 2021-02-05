#include<iostream>
#include<vector> 
using namespace std;
class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
	if(n == 1){
		ans.push_back("()");
		return ans;
	}
	getParenthesis("",n,n);
	return ans;
    }
    void getParenthesis(string str,int left, int right){
	if( (left == 0 ) && (right == 0) ){
		ans.push_back(str); 
	} else if(left == right){
		getParenthesis(str+"(",left-1,right);
	} else{
		if(left > 0){
                    getParenthesis(str+"(",left-1,right);
                }
                getParenthesis(str+")",left,right-1);
	}

    }
};
int main(int argc, char *argv[])
{
	int n = 3;
	Solution sol;
	vector<string> ans = sol.generateParenthesis(n);
	for(int i = 0;i < ans.size();++i){ cout<<ans[i]<<" ";}
	return 0;
}
/*
 ()
 ()() (())
 ()()() (())() (()()) ((())) ()(())



 */
