#include <iostream>
using namespace std;
//  Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head){ return nullptr;}
        ListNode *p = head;
        int len = 1;
        for(; p->next; p=p->next){ len++;}
        p->next = head;
        k %= len;
        for(p = head; --len != k; p = p->next);
        head = p->next;
        p->next = nullptr;
        return head;
    }
};
int main(int argc, char *argv[])
{
	auto l5 = new ListNode(5);
	auto l4 = new ListNode(4,l5);
	auto l3 = new ListNode(3,l4);
	auto l2 = new ListNode(2,l3);
	auto l1 = new ListNode(1,l2);
	cout<<"list is :1 2 3 4 5, k = 2"<<endl;
	int k = 2;
	Solution sol;
	ListNode* ans = new ListNode(0,sol.rotateRight(l1, k));
	cout<<"ans is:";
	while(ans->next){
		cout<<(ans->next)->val<<" ";
		ans = ans->next;
	}
	return 0;
}
