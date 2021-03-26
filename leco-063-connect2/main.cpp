#include<bits/stdc++.h> 
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public:
    void handle(Node* &last, Node* &p, Node* &nextStart) {
        if (last) {
            last->next = p;
        }
        if (!nextStart) {
            nextStart = p;
        }
        last = p;
    }

    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }
        Node *start = root;
        while (start) {
            Node *last = nullptr, *nextStart = nullptr;
            for (Node *p = start; p != nullptr; p = p->next) {
                if (p->left) {
                    handle(last, p->left, nextStart);
                }
                if (p->right) {
                    handle(last, p->right, nextStart);
                }
            }
            start = nextStart;
        }
        return root;
    }
};
int main(int argc, char *argv[])
{
	auto r1 = new Node(3);
	auto l1 = new Node(2);
	auto root = new Node(1,l1,r1,nullptr);
	Solution sol;
	auto ans = sol.connect(root);
	cout<<ans->val<<" ";
	if(!ans->next) cout<<"#"<<" ";
	cout<<(ans->left)->val<<" ";
	cout<<( (ans->left)->next)->val<<" ";
	cout<<"#"<<endl;
	return 0;
}

