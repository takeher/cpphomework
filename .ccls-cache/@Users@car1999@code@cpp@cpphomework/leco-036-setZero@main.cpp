#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
	int r = matrix.size();
	if(!r){return;}
	int c = matrix[0].size();
	int r0 = 1;
	int c0 = 1;
	for(int i = 0;i < r;++i){
		if(!matrix[i][0]){
			r0 = 0;	
			break;
		}
	}
	for(int j = 0;j < c;++j){
		if(!matrix[0][j]){
			c0 = 0;
			break;
		}
	}
	for(int i = 1;i < r;++i){
		for(int j = 1;j < c;++j){
			if(!matrix[i][j]){
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}
	for(int i = 1;i < r;++i){
		if(!matrix[i][0]){
			for(int j = 1;j < c;++j){
				matrix[i][j] = 0;
			}
		}
	}
	for(int i = 1;i < c;++i){
		if(!matrix[0][i]){
			for(int j = 1;j < r;++j){
				matrix[j][i] = 0;
			}
		}
	}
	if(!r0){
		for(int i = 0;i < r;++i){
			matrix[i][0] = 0;
		}
	}
	if(!c0){
		for(int j = 0;j < c;++j){
			matrix[0][j] = 0;
		}
	}
    }
};
int main(int argc, char *argv[])
{
	vector<vector<int>> matrix;
	vector<int> r1 {0,1,2,0};matrix.push_back(r1);
	vector<int> r2 {3,4,5,2};matrix.push_back(r2);
	vector<int> r3 {1,3,1,5};matrix.push_back(r3);
	Solution sol;
	sol.setZeroes(matrix);
	cout<<"ans is:"<<endl;
	for(int i = 0;i < matrix.size();++i){
		for(int j = 0;j < matrix[0].size();++j){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
