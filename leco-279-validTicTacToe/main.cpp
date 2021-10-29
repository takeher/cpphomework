#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    // 判断X或者O会赢
    bool isWin(const vector<string>& board, char c)
    {
        // 横或者竖满足
        for (int i = 0; i < 3; ++i)
        {
            if ((c == board[i][0] && c == board[i][1] && c == board[i][2])
                    || (c == board[0][i] && c == board[1][i] && c == board[2][i]))
            {
                return true;
            }
        }
        // 对角线满足
        if ((c == board[0][0] && c == board[1][1] && c == board[2][2])
                || (c == board[0][2] && c == board[1][1] && c == board[2][0]))
        {
            return true;
        }

        return false;
    }
public:
    bool validTicTacToe(const vector<string>& board) {
        // 统计数量
        int cntX = 0;
        int cntO = 0;
        for (const string& s : board)
        {
            for (char c : s)
            {
                if (c == 'X')
                {
                    ++cntX;
                }
                else if (c == 'O')
                {
                    ++cntO;
                }
            }
        }

        // 排除数量不对的情况
        if (cntX != cntO && cntX != cntO+1)
        {
            return false;
        }

        // 考虑X或者O获胜，同时满足数量要求，不满足则返回false
        if (isWin(board, 'X') && cntX != cntO+1)
        {
            return false;
        }
        if (isWin(board, 'O') && cntX != cntO)
        {
            return false;
        }
        // 其他情况都是满足的，返回true
        return true;
    }
};
int main(){
  cout << "ans is:"
       << (new Solution())->validTicTacToe(vector<string>{"O  ", "   ", "   "})
       << endl;
  return 0;
}
