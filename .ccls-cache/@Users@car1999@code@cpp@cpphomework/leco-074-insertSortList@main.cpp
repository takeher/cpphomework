#include <bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* lastSorted = head;
        ListNode* curr = head->next;
        while (curr != nullptr) {
            if (lastSorted->val <= curr->val) {
                lastSorted = lastSorted->next;
            } else {
                ListNode *prev = dummyHead;
                while (prev->next->val <= curr->val) {
                    prev = prev->next;
                }
                lastSorted->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            }
            curr = lastSorted->next;
        }
        return dummyHead->next;
    }
};
int main(int argc, char *argv[])
{
	auto l4 = new ListNode(3);
	auto l3 = new ListNode(1,l4);
	auto l2 = new ListNode(2,l3);
	auto head = new ListNode(4,l2);
	Solution sol;
	auto ans = sol.insertionSortList(head);
	auto l = new ListNode(0,ans);
	cout<<"ans is:";
	while(l->next){
		cout<<(l->next)->val<<" ";
		l = l->next;
	}
	return 0;
}
