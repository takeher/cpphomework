#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int nCount = 0;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'X') {
                    if ( (i > 0 && board[i - 1][j] == 'X') ||( j > 0 && board[i][j - 1] == 'X'))
                        continue;
                    ++nCount;
                }
            }
        }
        return nCount;
    }
};
int main(int argc, char *argv[])
{
	vector<vector<char>> board;
	vector<char> b1 {'X','.','.','X'};board.push_back(b1);
	vector<char> b2 {'.','.','.','X'};board.push_back(b2);
	vector<char> b3 {'.','.','.','X'};board.push_back(b3);
	Solution sol;
	cout<<"ans is:"<<sol.countBattleships(board)<<endl;
	return 0;
}
