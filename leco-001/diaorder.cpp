#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> diaorder(vector<vector<int>>& matrix) {
	vector<int> num;
	if(matrix.size() != 0)
	{
	int div = (matrix.size()>matrix[0].size()?matrix.size():matrix[0].size());
	for(int i = 0;i < 2 * div - 1;i++)
	{
		for(int j = 0; j <= (i < div?i:(2*div - 2 - i));j++)
		{
			if (i < div)
			{
				if( ((i%2 != 0?j:(i - j)) < matrix.size()) && ( (i%2 != 0?(i - j):j) < matrix[0].size())) 
				{	
					num.push_back(matrix[(i%2 != 0?j:(i - j))][(i%2 != 0?(i - j):j)]);
				}
			}
			else 
			{ 
				if( ((i%2 != 0?(i - div + 1 + j):(div - 1 - j)) < matrix.size()) && ( (i%2 != 0?(div - 1 - j):(i - div + 1 + j)) < matrix[0].size()) )
				{
					num.push_back(matrix[(i%2 != 0?(i - div + 1 + j):(div - 1 - j))][(i%2 != 0?(div - 1 - j):(i - div + 1 + j))]);
				}
			}
		}
	}
	}
	return num;
    }
};
vector<vector<int>> read_matrix();
void print_matrix(vector<int>& matrix);
int main(int argc, char *argv[])
{
	vector<vector<int>> matrix = read_matrix();
	Solution sol;
	vector<int> num = sol.diaorder(matrix);
	print_matrix(num);
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
void print_matrix(vector<int>& matrix)
{
	for(int i = 0; i < matrix.size();i++)
	{
		cout<< matrix[i] <<" ";
	}

}

