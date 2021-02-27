#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		int m = matrix.size();
		if (m == 0) return false;
		int n = matrix[0].size();
		// 二分查找
		int left = 0, right = m * n - 1;
		int pivotIdx, pivotElement;
		while (left <= right) {
			pivotIdx = (left + right) / 2;
			pivotElement = matrix[pivotIdx / n][pivotIdx % n];
			if (target == pivotElement)
				return true;
			else {
				if (target < pivotElement)
					right = pivotIdx - 1;
				else
					left = pivotIdx + 1;
			}
		}
		return false;
	}
};
int main(int argc, char* argv[])
{
	vector<vector<int>> matrix;
	int target = 3;
	vector<int> r1{1, 3, 5, 7};
	matrix.push_back(r1);
	vector<int> r2{10, 11, 16, 20};
	matrix.push_back(r2);
	vector<int> r3{23, 30, 34, 60};
	matrix.push_back(r3);
	Solution sol;
	bool ans = sol.searchMatrix(matrix, target);
	cout << "ans is:" << ans << endl;
	return 0;
}
