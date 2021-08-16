#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* evenHead = head->next;
        ListNode* odd = head;
        ListNode* even = evenHead;
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
int main(int argc, char *argv[])
{
	auto l5 = new ListNode(5);
	auto l4 = new ListNode(4,l5);
	auto l3 = new ListNode(3,l4);
	auto l2 = new ListNode(2,l3);
	auto head = new ListNode(1,l2);
	Solution sol;
	head = sol.oddEvenList(head);
	auto l = new ListNode(0,head);
	cout<<"ans is:"<<endl;
	while(l->next){
		cout<<(l->next)->val<<" ";
		l = l->next;
	}
	return 0;
}
