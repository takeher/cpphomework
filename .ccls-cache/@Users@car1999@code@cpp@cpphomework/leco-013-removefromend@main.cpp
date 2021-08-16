#include<iostream> 
using namespace std;

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
	int size = 0;
	ListNode* l = new ListNode(0,head);
	while(l->next != nullptr){
		++size;
		l = l->next;
	}
	l = new ListNode(0,head);
	for(int i = 0;i < size;++i){
		if(i == size - n){
			l->next = (l->next)->next;
			break;
		}
		l = l->next;
	}
	return head;
    }
};
int main(int argc, char *argv[])
{
	ListNode* h5 = new ListNode(5);
	ListNode* h4 = new ListNode(4,h5);
	ListNode* h3 = new ListNode(3,h4);
	ListNode* h2 = new ListNode(2,h3);
	ListNode* h1 = new ListNode(1,h2);
	Solution sol;
	h1 = sol.removeNthFromEnd(h1, 2);
	ListNode* l = new ListNode(0,h1);
	cout<<"list is:";
	while(l->next != nullptr){
		cout<<(l->next)->val<<" ";
		l = l -> next;
	}
	delete l;
	return 0;
}
/*
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = head;
        ListNode* second = dummy;
        for (int i = 0; i < n; ++i) {
            first = first->next;
        }
        while (first) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
*/
