#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
	vector<int> col;
	vector<int> row;
    	for(int i = 0;i < matrix.size();i++)
	{
		for(int j = 0;j < matrix[0].size();j++)
		{
			if(matrix[i][j] == 0)
			{
				col.push_back(j);
				row.push_back(i);
			}
		}
	}
	for(int i = 0;i < row.size();i++)
	{	
		for(int j = 0;j < matrix[0].size();j++)
		{
			matrix[row[i]][j] = 0;
		}
	}

	for(int i = 0;i < matrix.size();i++)
	{	
		for(int j = 0;j < col.size();j++)
		{
			matrix[i][col[j]] = 0;
		}
	}
    }
};
vector<vector<int>> read_matrix();
void print_matrix(vector<vector<int>>& matrix);
int main(int argc, char *argv[])
{
	vector<vector<int>> matrix = read_matrix();
	print_matrix(matrix);
	Solution sol;
	sol.setZeroes(matrix);
	print_matrix(matrix);
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
	return matrix;
}
void print_matrix(vector<vector<int>>& matrix)
{
	for(int i = 0; i < matrix.size();i++)
	{
		for(int j = 0; j < matrix[0].size();j++)
		{
			cout<< matrix[i][j] <<" ";
		}
		cout<<endl;
	}

}
/*
class Solution {
    public void setZeroes(int[][] matrix) {
        boolean isFirstRowHaveZero = false;
        boolean isFirstColHaveZero = false;
        for(int i = 0; i < matrix.length; i++) {
            if (matrix[i][0] == 0) {
                isFirstColHaveZero = true;
            }
        }

        for(int j = 0; j < matrix[0].length; j++) {
            if (matrix[0][j] == 0) {
                isFirstRowHaveZero = true;
            }
        }

        for(int i = 1; i < matrix.length; i++) {
            for(int j = 1; j < matrix[i].length; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                } 
            }
        }
        
        for(int i = 1; i < matrix.length; i++) {
            for(int j = 1; j < matrix[i].length; j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                } 
            }
        }

        for(int i = 0; i < matrix.length; i++) {
            if (isFirstColHaveZero) {
                matrix[i][0] = 0;
            }
        }

        for(int j = 0; j < matrix[0].length; j++) {
            if (isFirstRowHaveZero) {
                matrix[0][j] = 0;
            }
        }

    }
}
*/
