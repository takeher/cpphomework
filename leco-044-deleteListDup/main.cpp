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
   ListNode* deleteDuplicates(ListNode* head) {
        ListNode* PCUR=new ListNode(0);
        PCUR->next=head;
        head=PCUR;
        ListNode *L,*R;
        while(PCUR->next != NULL)
        {
            L=PCUR->next;
            R=PCUR->next;
            while(R->next && R->next->val==L->val)
                R=R->next;
            //如果循环后，L与R节点相同，说明不重复
            if(L == R) PCUR=PCUR->next;
            //L与R节点不相同，将PCUR的next指向R->next,继续重复上述操作
            else 
            {
                PCUR->next=R->next;
                //C++没有内存回收机制，应该释放这些指针，虽然不释放能通过，但是应该养成好习惯
                while(L!=R)
                {
                    ListNode*tmp=L;
                    L=L->next;
                    delete tmp;
                }
                delete L;
            }
        }
        return head->next;
    }
};
int main(int argc, char *argv[])
{
	ListNode* h7 = new ListNode(5);
	ListNode* h6 = new ListNode(4,h7);
	ListNode* h5 = new ListNode(4,h6);
	ListNode* h4 = new ListNode(3,h5);
	ListNode* h3 = new ListNode(3,h4);
	ListNode* h2 = new ListNode(2,h3);
	ListNode* h1 = new ListNode(1,h2);
	Solution sol;
	auto ans = sol.deleteDuplicates(h1);
	ListNode* l = new ListNode(0,ans);
	cout<<"ans is: ";
	while(l->next){
		cout<<(l->next)->val<<" ";
		l = l->next;
	}
	return 0;
}
