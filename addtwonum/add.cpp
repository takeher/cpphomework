#include<iostream>
using namespace std;
/*
 * Definition for singly-linked list.
*/ 
struct ListNode {
	int val;
	ListNode *next;
     	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
     	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void print_list(ListNode* l);
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	//链表l1和l2每个节点从低位到高位存每一位数字
	//例如l1[7,8,9],l2[4,5,6],987与654相加等于1641
	int i = 0, c = 0, num = 1;
	while(1)
	{
		num = (l1 + i)->val + l2->val + c;
		(l1 + i)->val = num%10;
		c = num>=10?1:0;
		if(l2->next != nullptr && (l1 + i)->next != nullptr)
		{	
			l2 = l2->next;
		}
		else if(l2->next == nullptr && (l1 + i)->next != nullptr)
		{	
			l2->val = 0;
			if(c == 0)
				break;
		}
		else if(l2->next != nullptr && (l1 + i)->next == nullptr)
		{
			(l1 + i)->next = l2->next;
			l2->next = nullptr;
		}
		else 
		{
			if( c != 0)
			{
				(l1 + i)->next = new ListNode;
				break;
			}
			else 
			{
				break;
			}
		}
		i++;
	}
	if(c != 0)
	{
		(l1 + i + 1)->val = 1;
		(l1 + i + 1)->next = nullptr;

	}
	return l1;
    }
};
int main(int argc, char *argv[])
{
	Solution sol;
	ListNode* l11 = new ListNode(2);
	ListNode* l12 = new ListNode(4);
	ListNode* l13 = new ListNode(3);
	ListNode* l21 = new ListNode(5);
	ListNode* l22 = new ListNode(6);
	ListNode* l23 = new ListNode(4);
	l12->next = l13;
	l11->next = l12;
	l22->next = l23;
	l21->next = l22;
	print_list(l11);
	print_list(l21);
	ListNode* l = sol.addTwoNumbers(l11, l21);
	cout<<"list is:"<<endl;
	print_list(l);
	return 0;
}
void print_list(ListNode* l)
{
	int i = 0;
	while((l + i)->next != nullptr)
	{
		cout<<(l + i)->val<<" ";
		i++;
	}
	cout<< ((l +i)->val) <<endl;
}
