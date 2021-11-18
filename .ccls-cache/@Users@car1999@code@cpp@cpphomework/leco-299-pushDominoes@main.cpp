#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int* diff = new int[n];
        memset(diff, 0, sizeof(int)*n);

        // 从左往右
        int weight = 0;
        for (int i = 0; i < n; ++i)
        {
            if (dominoes[i] == 'R')
            {
                weight = n;
            }
            else if (dominoes[i] == 'L')
            {
                weight = 0;
            }
            else
            {
                weight = max(weight-1, 0);
            }
            diff[i] = weight;
        }

        // 从右往左
        weight = 0;
        for (int i = n-1; i >= 0; --i)
        {
            if (dominoes[i] == 'L')
            {
                weight = n;
            }
            else if (dominoes[i] == 'R')
            {
                weight = 0;
            }
            else
            {
                weight = max(weight-1, 0);
            }
            diff[i] -= weight;
        }

        for (int i = 0; i < n; ++i)
        {
            dominoes[i] = diff[i] > 0 ? 'R' : (diff[i] < 0 ? 'L' : '.');
        }

        return dominoes;
    }
};
int main(){
  cout << "ans is:" << (new Solution())->pushDominoes(".L.R...LR..L..") << endl;
  return 0;
}
