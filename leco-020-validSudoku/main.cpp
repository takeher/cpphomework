#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> wow(9,0);
        int mux1;
        int mux2;
        int mux3;
        int box_index;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    continue;
                }
                mux1 = 0x01 << (board[i][j] - '1');
                mux2 = 0x01 << 9 << (board[i][j] - '1');
                mux3 = 0x01 << 9 << 9 << (board[i][j] - '1');
                box_index = (i/3) * 3 + j/3;
                if((wow[i]&mux1) != mux1 && (wow[j]&mux2) != mux2 && (wow[box_index]&mux3) != mux3){
                    wow[i] = wow[i]|mux1;
                    wow[j] = wow[j]|mux2;
                    wow[box_index] = wow[box_index]|mux3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
int main(int argc, char *argv[])
{
	vector<vector<char>> board;
	vector<char> row1 =  {'5','3','.','.','7','.','.','.','.'};board.push_back(row1);
	vector<char> row2 =  {'6','.','.','1','9','5','.','.','.'};board.push_back(row2);
	vector<char> row3 =  {'.','9','8','.','.','.','.','6','.'};board.push_back(row3);
	vector<char> row4 =  {'8','.','.','.','6','.','.','.','3'};board.push_back(row4);
	vector<char> row5 =  {'4','.','.','8','.','3','.','.','1'};board.push_back(row5);
	vector<char> row6 =  {'7','.','.','.','2','.','.','.','6'};board.push_back(row6);
	vector<char> row7 =  {'.','6','.','.','.','.','2','8','.'};board.push_back(row7);
	vector<char> row8 =  {'.','.','.','4','1','9','.','.','5'};board.push_back(row8);
	vector<char> row9 =  {'.','.','.','.','8','.','.','7','9'};board.push_back(row9);
	Solution sol;
	bool ans = sol.isValidSudoku(board);
	for(int i = 0;i < board.size();++i){
		for(int j = 0;j < board[i].size();++j){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"ans is:"<<ans<<endl;
	return 0;
}
/*
 *['5','3','.','.','7','.','.','.','.'],
  ['6','.','.','1','9','5','.','.','.'],
  ['.','9','8','.','.','.','.','6','.'],
  ['8','.','.','.','6','.','.','.','3'],
  ['4','.','.','8','.','3','.','.','1'],
  ['7','.','.','.','2','.','.','.','6'],
  ['.','6','.','.','.','.','2','8','.'],
  ['.','.','.','4','1','9','.','.','5'],
  ['.','.','.','.','8','.','.','7','9']
*/
