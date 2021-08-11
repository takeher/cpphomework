#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dir_x[8] = {0, 1, 0, -1, 1, 1, -1, -1};
    int dir_y[8] = {1, 0, -1, 0, 1, -1, 1, -1};

    void bfs(vector<vector<char>>& board, int sx, int sy) {
        queue<pair<int, int>> Q;
        vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), 0));
        Q.push({sx, sy});
        vis[sx][sy] = true;
        while (!Q.empty()) {
            auto pos = Q.front();
            Q.pop();
            int cnt = 0, x = pos.first, y = pos.second;
            for (int i = 0; i < 8; ++i) {
                int tx = x + dir_x[i];
                int ty = y + dir_y[i];
                if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size()) {
                    continue;
                }
                // 不用判断 M，因为如果有 M 的话游戏已经结束了
                cnt += board[tx][ty] == 'M';
            }
            if (cnt > 0) {
                // 规则 3
                board[x][y] = cnt + '0';
            } else {
                // 规则 2
                board[x][y] = 'B';
                for (int i = 0; i < 8; ++i) {
                    int tx = x + dir_x[i];
                    int ty = y + dir_y[i];
                    // 这里不需要在存在 B 的时候继续扩展，因为 B 之前被点击的时候已经被扩展过了
                    if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size() || board[tx][ty] != 'E' || vis[tx][ty]) {
                        continue;
                    }
                    Q.push(make_pair(tx, ty));
                    vis[tx][ty] = true;
                }
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, const vector<int>& click) {
        int x = click[0], y = click[1];
        if (board[x][y] == 'M') {
            // 规则 1
            board[x][y] = 'X';
        } else {
            bfs(board, x, y);
        }
        return board;
    }
};
int main(int argc, char *argv[])
{
	char b[4][5] = {
		{'B', '1', 'E', '1', 'B'},
		{'B', '1', 'M', '1', 'B'},
		{'B', '1', '1', '1', 'B'},
		{'B', 'B', 'B', 'B', 'B'}
	};
	vector<vector<char>> board(4, vector<char>(5, 'B'));
	int i = 0;for_each(board.begin(),board.end(),[&i, b](vector<char>& bb)->void{for(int j = 0;j < bb.size();++j)bb[j]=b[i][j];i++;});
	board = (new Solution)->updateBoard(board, vector<int>{1,2});
	cout<<"ans is:"<<endl;
	for_each(board.begin(),board.end(),[](vector<char>& bb)->void{for_each(bb.begin(),bb.end(),[](char b_)->void{cout<<b_<<" ";});cout<<endl;});
	return 0;
}
