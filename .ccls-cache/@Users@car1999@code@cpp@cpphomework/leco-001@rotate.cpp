#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
	cout<<'[';
	for(int i =0;i < matrix.size();i++)
	{
		cout<<'[';
		for(int j = matrix.size()-1;j>=0;j--)
		{
			cout<<matrix[j][i];
			if(j != 0)
			{
				cout<<',';
			}
		}
		cout<<']';
		if(i != matrix.size()-1)
		{
			cout<<',';
		}
	}
	cout<<']';
    }
};
vector<vector<int>> read_matrix();
int main(int argc, char *argv[])
{
	vector<vector<int>> matrix = read_matrix();
	Solution sol;
	sol.rotate(matrix);
	return 0;
}
vector<vector<int>> read_matrix()
{
	string s;
	getline(cin, s);
	vector<vector<int>> matrix;
	vector<int> matcol;
	int cnt = 1;
	int col = 0;
	int num = 0;
	while(cnt < s.size()-1)
	{
		if(s[cnt] == '[')
			cnt++;
		else if(s[cnt] == ']')
		{
			cnt++;
			matrix.push_back(matcol);
			matcol.clear();
			col++;
		}
		else if(s[cnt] == ',')
		{
			cnt++;
			int i = cnt;
			if(s[i] != '[')
			{
				while(s[i] != ',' && s[i] != ']')
				{
					i++;
				}
				num = atoi((s.substr(cnt , i - cnt)).c_str());
				matcol.push_back(num);
				cnt = i;
			}
		}
		else 
		{
			int i = cnt;
			while(s[i] != ',' && s[i] != ']')
			{
				i++;
			}
			num = atoi((s.substr(cnt , i - cnt)).c_str());
			matcol.push_back(num);
			cnt = i;
		}
	}
/*
	for(int i = 0; i < matrix.size();i++)
	{
		matcol = matrix[i];
		for(int j = 0; j < matrix.size();j++)
		{
			cout<< matrix[i][j] <<" ";
		}
		cout<<endl;
	}
*/
	return matrix;
}
/*
//solution 1: 
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

//solution 2:
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 水平翻转
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
        // 主对角线翻转
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};


*/
