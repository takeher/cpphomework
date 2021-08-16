#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0, B = 0;
        unordered_map<char, int> cows;
        string left;
        for(int i = 0; i < secret.size(); ++i)
        {
            if(secret[i] == guess[i])
                ++A;
            else
            {
                ++cows[secret[i]];
                left += guess[i];
            }
        }
        for(char ch : left)
        {
            if(cows[ch])
            {
                ++B;
                --cows[ch];
            }
        }

        string ans = to_string(A) + "A" + to_string(B) + "B";
        return ans;
    }
};
int main(int argc, char *argv[])
{
	string secret = "1807";
	string guess = "7810";
	Solution sol;
	cout<<"ans is:"<<sol.getHint(secret, guess)<<endl;
	return 0;
}
