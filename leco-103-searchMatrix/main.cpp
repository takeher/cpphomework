#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col = 0, row = matrix[0].size()-1;
        while(1)
        {
            if(matrix[col][row] > target)
                --row;
            else if(matrix[col][row] < target)
                ++ col;
            else
                return true;
            if(col == matrix.size() || row < 0)
                break;
        }
        return false;
    }
};
int main(int argc, char *argv[])
{
	//matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
	vector<vector<int>> matrix;
	vector<int> r1 { 1, 4, 7,11,15};matrix.push_back(r1);
	vector<int> r2 { 2, 5, 8,12,19};matrix.push_back(r2);
	vector<int> r3 { 3, 6, 9,16,22};matrix.push_back(r3);
	vector<int> r4 {10,13,14,17,24};matrix.push_back(r4);
	vector<int> r5 {18,21,23,26,30};matrix.push_back(r5);
	Solution sol;
	bool ans = sol.searchMatrix(matrix, 5);
	cout<<"ans is:"<<ans;
	return 0;
}
