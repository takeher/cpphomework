#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int c = 0;
        for(const int& num : data)
        {
            if(c == 0)
            {
                if((num >> 5) == 0b110) c = 1;
                else if((num >> 4) == 0b1110) c = 2;
                else if((num >> 3) == 0b11110) c = 3;
                else if((num >> 7)) return false;
            }
            else
            {
                if((num >> 6) != 0b10) return false;
                --c;
            }
        }
        return c == 0;
    }
};
int main(int argc, char *argv[])
{
	vector<int> data {197,130,1};
	Solution sol;
	cout<<"ans is:"<<sol.validUtf8(data)<<endl;
	return 0;
}
