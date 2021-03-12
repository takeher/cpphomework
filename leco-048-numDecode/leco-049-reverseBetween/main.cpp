#include <iostream>
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
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode *pre = dummyNode;
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
        ListNode *cur = pre->next;
        ListNode *next;
        for (int i = 0; i < right - left; i++) {
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return dummyNode->next;
    }
};
int main(int argc, char *argv[])
{
	ListNode *l5 = new ListNode(5);
	ListNode *l4 = new ListNode(4,l5);
	ListNode *l3 = new ListNode(3,l4);
	ListNode *l2 = new ListNode(2,l3);
	ListNode *l1 = new ListNode(1,l2);
	Solution sol;
	int left = 2,right = 4;
	sol.reverseBetween(l1, left, right);
	ListNode *l = new ListNode(0,l1);
	cout<<"ans is:";
	while(l->next){
		cout<<(l->next)->val<<" ";
		l=l->next;
	}
	return 0;
}
