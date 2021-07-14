#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> countAB;
        for (int u: A) {
            for (int v: B) {
                ++countAB[u + v];
            }
        }
        int ans = 0;
        for (int u: C) {
            for (int v: D) {
                if (countAB.count(-u - v)) {
                    ans += countAB[-u - v];
                }
            }
        }
        return ans;
    }
};
int main(int argc, char *argv[])
{
	vector<int> A { 1, 2};
	vector<int> B {-2,-1};
	vector<int> C {-1, 2};
	vector<int> D { 0, 2};
	Solution sol;
	cout<<"ans is:"<<sol.fourSumCount(A, B, C, D)<<endl;
	return 0;
}
