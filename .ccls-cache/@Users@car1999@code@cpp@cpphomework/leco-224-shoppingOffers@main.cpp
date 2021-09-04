#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    map<vector<int>, int> needs2num;

    // 注意这里needs是按值传递来避免修改后对之前递归的影响
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int> needs)
    {
        if (needs2num.find(needs) != needs2num.end())
        {
            return needs2num[needs];
        }
        // 初始化的结果
        int res = 0;
        // 直接购买的数量
        for (int i = 0; i < needs.size(); ++i)
        {
            res += needs[i] * price[i];
        }

        // 遍历每个礼包，对于满足needs的继续递归遍历
        int n = needs.size();
        for (const vector<int>& s : special)
        {
            vector<int> currNeeds = needs;
            int j = 0;
            for (; j < n; ++j)
            {
                // 减去礼包后剩下的数量
                int after = currNeeds[j] - s[j];
                // 不足说明礼包超过需要了，该情况忽略
                if (after < 0)
                {
                    break;
                }
                // 更新数量
                currNeeds[j] = after;
            }

            if (j == n)
            {
                res = min(res, s[n] + dfs(price, special, currNeeds));
            }
        }
        return res;
    }

public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dfs(price, special, needs);
    }
};
int main(){
  // price = [2,3,4], special = [[1,1,0,4],[2,2,1,9]], needs = [1,2,1]
  vector<int> price {2,3,4};
  vector<vector<int>> special {vector<int> {1,1,0,4}, vector<int> {2,2,1,9}};
  vector<int> needs {1,2,1};
  cout<<"ans is:"<<(new Solution())->shoppingOffers(price, special, needs)<<endl;
  return 0;
}
