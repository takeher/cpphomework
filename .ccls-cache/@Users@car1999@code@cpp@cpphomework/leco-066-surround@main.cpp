#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n, m;

    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O') {
            return;
        }
        board[x][y] = 'A';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        if (n == 0) {
            return;
        }
        m = board[0].size();
        for (int i = 0; i < n; i++) {
            dfs(board, i, 0);
            dfs(board, i, m - 1);
        }
        for (int i = 1; i < m - 1; i++) {
            dfs(board, 0, i);
            dfs(board, n - 1, i);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
int main(int argc, char *argv[])
{
	vector<vector<char>> board;
	vector<char> l1 {'X','X','X','X'};board.push_back(l1);
	vector<char> l2 {'X','O','O','X'};board.push_back(l2);
	vector<char> l3 {'X','X','O','X'};board.push_back(l3);
	vector<char> l4 {'X','O','X','X'};board.push_back(l4);
	Solution sol;
	sol.solve(board);
	for(int i = 0;i < board.size();++i){
		for(int j = 0;j < board[i].size();++j){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
