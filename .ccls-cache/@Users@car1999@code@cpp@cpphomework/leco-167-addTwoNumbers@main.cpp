#include<bits/stdc++.h>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1 -> val);
            l1 = l1 -> next;
        }
        while (l2) {
            s2.push(l2 -> val);
            l2 = l2 -> next;
        }
        int carry = 0;
        ListNode* ans = nullptr;
        while (!s1.empty() or !s2.empty() or carry != 0) {
            int a = s1.empty() ? 0 : s1.top();
            int b = s2.empty() ? 0 : s2.top();
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();
            int cur = a + b + carry;
            carry = cur / 10;
            cur %= 10;
            auto curnode = new ListNode(cur);
            curnode -> next = ans;
            ans = curnode;
        }
        return ans;
    }
};
int main(int argc, char *argv[])
{
	auto l14 = new ListNode(3);
	auto l13 = new ListNode(4, l14);
	auto l12 = new ListNode(2,l13);
	auto l1  = new ListNode(7,l12);
	auto l23 = new ListNode(4);
	auto l22 = new ListNode(6,l23);
	auto l2  = new ListNode(5,l22);
	Solution sol;
	auto ans = sol.addTwoNumbers(l1, l2);
	cout<<"ans is";
	auto l = new ListNode(0, ans);
	while(l->next){
		cout<<(l->next)->val;
		l=l->next;
	}

	return 0;
}
