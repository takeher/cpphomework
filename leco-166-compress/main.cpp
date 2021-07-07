#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        int rear = -1, l = 0, r = 0;
        while(r < chars.size()){
            l = r;
            while(r < chars.size() && chars[l] == chars[r])r++;
            chars[++rear] = chars[l];
            if(r - l == 1) continue;
            for(const auto& x:to_string(r - l)) chars[++rear] = x;
        }
        return rear + 1;
    }
};
int main(int argc, char *argv[])
{
	vector<char> chars {'a','a','b','b','c','c','c'};	
	Solution sol;
	cout<<"ans is:"<<sol.compress(chars)<<endl;
	return 0;
}
