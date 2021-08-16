#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        int maxFreq = 0;
        for (auto &ch : s) {
            maxFreq = max(maxFreq, ++mp[ch]);
        }
        vector<string> buckets(maxFreq + 1);
        for (auto &[ch, num] : mp) {
            buckets[num].push_back(ch);
        }
        string ret;
        for (int i = maxFreq; i > 0; i--) {
            string &bucket = buckets[i];
            for (auto &ch : bucket) {
                for (int k = 0; k < i; k++) {
                    ret.push_back(ch);
                }
            }
        }
        return ret;
    }
};
int main(int argc, char *argv[])
{
	string s = "tree";
	Solution sol;
	cout<<"ans is:"<<sol.frequencySort(s)<<endl;
	return 0;
}
