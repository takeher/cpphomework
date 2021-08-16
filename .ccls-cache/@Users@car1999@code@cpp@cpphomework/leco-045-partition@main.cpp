#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
    public:
	ListNode* partition(ListNode* head, int x)
	{
		ListNode* small = new ListNode(0);
		ListNode* smallHead = small;
		ListNode* large = new ListNode(0);
		ListNode* largeHead = large;
		while (head != nullptr) {
			if (head->val < x) {
				small->next = head;
				small = small->next;
			}
			else {
				large->next = head;
				large = large->next;
			}
			head = head->next;
		}
		large->next = nullptr;
		small->next = largeHead->next;
		return smallHead->next;
	}
};
int main(int argc, char *argv[])
{
	ListNode* h6 = new ListNode(2,nullptr);
	ListNode* h5 = new ListNode(5,h6);
	ListNode* h4 = new ListNode(2,h5);
	ListNode* h3 = new ListNode(3,h4);
	ListNode* h2 = new ListNode(4,h3);
	ListNode* h1 = new ListNode(1,h2);
	Solution sol;
	int x = 3;
	auto ans = sol.partition(h1, x);
	ListNode* l = new ListNode(0,ans);
	cout<<"ans is: ";
	while(l->next){
		cout<<(l->next)->val<<" ";
		l=l->next;
	}
	cout<<endl;
	return 0;
}
