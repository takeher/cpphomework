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
    ListNode* swapPairs(ListNode* head) {
	if(head == nullptr){return head;}
	if(head->next == nullptr){return head;}
	ListNode* l = new ListNode(0,head);
	ListNode* l1 = new ListNode(0,head->next);
	ListNode* t = new ListNode(0,l);
	for(int i =0;l->next;++i){
		(l->next)->next = (l1->next)->next;
		if(i == 0){
			head = l1->next;
		}else{
			(t->next)->next = l1->next;
		}
		t->next = l->next;
		(l1->next)->next = l->next;
		if( (l->next)->next){
			(l->next) = (l->next)->next;
			(l1->next) = (l->next)->next;
		}else{ break;}
	}
	return head;
    }
};
int main(int argc, char *argv[])
{
	ListNode* h8 = new ListNode(8,nullptr);
	ListNode* h7 = new ListNode(7,h8);
	ListNode* h6 = new ListNode(6,h7);
	ListNode* h5 = new ListNode(5,h6);
	ListNode* h4 = new ListNode(4,h5);
	ListNode* h3 = new ListNode(3,h4);
	ListNode* h2 = new ListNode(2,h3);
	ListNode* h1 = new ListNode(1,h2);
	Solution sol;
	h1 = sol.swapPairs(h1);
	ListNode* l = new ListNode(0,h1);
	while(l->next){
		cout<<(l->next)->val<<" ";
		l = l->next;
	}
	return 0;
}
/*class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        return newHead;
    }
};

*/
