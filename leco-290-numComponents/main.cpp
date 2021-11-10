#include <bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    int numComponents(ListNode* head, const vector<int>& nums) {
        // 存储nums帮助快速查找
        int n = nums.size();
        bool exists[10000];
        memset(exists, 0, sizeof(exists));
        for (int num : nums)
        {
            exists[num] = true;
        }

        int res = 0;
        ListNode* curr = head;
        while (curr != nullptr)
        {
            if (exists[curr->val] && (curr->next == nullptr || !exists[curr->next->val]))
            {
                ++res;
            }
            curr = curr->next;
        }

        return res;
    }
};
int main(){
  auto head = new ListNode(0, new ListNode(1, new ListNode(2, new ListNode(3))));
  cout<<"ans is:"<<(new Solution())->numComponents(head, vector<int> {0,1,3})<<endl;
  return 0;
}
