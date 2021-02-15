#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
 	int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < (n + 1) / 2; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
	}
    }
};
int main(int argc, char *argv[])
{
	//[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]
	vector<vector<int>> matrix;
	vector<int> r1{5,1,9,11};matrix.push_back(r1);
	vector<int> r2{2,4,8,10};matrix.push_back(r2);
	vector<int> r3{13,3,6,7};matrix.push_back(r3);
	vector<int> r4{15,14,12,16};matrix.push_back(r4);
	Solution sol;
	sol.rotate(matrix);
	for(int i = 0;i < matrix.size();++i){
		for(int j = 0;j < matrix[i].size();++j){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
