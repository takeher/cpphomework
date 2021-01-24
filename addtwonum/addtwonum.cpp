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
	int num1 = 0, num2 = 0, i = 0;
	while((l1 + i)->next != nullptr)
	{
		num1 = num1 + ((l1 + i)->val) * pow(10,i);
		i++;
	}
	num1 = num1 + ((l1 + i)->val) * pow(10,i);//计算l1里的数
	i = 0;
	while((l2 + i)->next != nullptr)
	{
		num2 = num2 + ((l2 + i)->val) * pow(10,i);
		i++;
	}
	num2 = num2 + ((l2 + i)->val) * pow(10,i);//计算l2里的数
	i = 0;
	num1 = num1 + num2;
	while(num1 != 0)
	{
		(l2 + i)->val = num1%10;//得到个位上的数
		num1 = num1/10;//小数点左移
		if( (l2 + i)->next == nullptr && num1 > 0)
		{
			//如果下一位不是0，并且l2的next为空，就加一个新节点
			(l2 + i)->next = new ListNode();
		}
		i++;
	}
	return l2;
    }
};
int main(int argc, char *argv[])
{
	Solution sol;
	ListNode* l11 = new ListNode(7);
	ListNode* l12 = new ListNode(8);
	ListNode* l13 = new ListNode(9);
	ListNode* l21 = new ListNode(4);
	ListNode* l22 = new ListNode(5);
	ListNode* l23 = new ListNode(6);
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
