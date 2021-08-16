#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.length();
        int i = 0;
        int slots = 1;
        while (i < n) {
            if (slots == 0) {
                return false;
            }
            if (preorder[i] == ',') {
                i++;
            } else if (preorder[i] == '#'){
                slots--;
                i++;
            } else {
                // 读一个数字
                while (i < n && preorder[i] != ',') {
                    i++;
                }
                slots++; // slots = slots - 1 + 2
            }
        }
        return slots == 0;
    }
};
int main(int argc, char *argv[])
{
	string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
	Solution sol;
	cout<<"ans is:"<<sol.isValidSerialization(preorder);
	return 0;
}
