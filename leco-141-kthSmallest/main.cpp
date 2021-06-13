#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<vector<int>>& matrix, int mid, int k, int n) {
        int i = n - 1;
        int j = 0;
        int num = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= mid) {
                num += i + 1;
                j++;
            } else {
                i--;
            }
        }
        return num >= k;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (check(matrix, mid, k, n)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
int main(int argc, char *argv[])
{
	//[[1,5,9],[10,11,13],[12,13,15]]
	vector<vector<int>> matrix;
	vector<int> r1 { 1, 5, 9};
	vector<int> r2 {10,11,13};
	vector<int> r3 {12,13,15};
	matrix.push_back(r1);
	matrix.push_back(r2);
	matrix.push_back(r3);
	Solution sol;
	cout<<"ans is:"<<sol.kthSmallest(matrix, 8)<<endl;
	return 0;
}
