#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(): val(0),next(nullptr){};
  ListNode(int x): val(x),next(nullptr){};
  ListNode(int x, ListNode *next) : val(x), next(next){}
};
class Solution {
public:
  vector<ListNode *> splitListToParts(ListNode *head, int k) {
    int n = 0;
    ListNode *temp = head;
    while (temp != nullptr) {
      n++;
      temp = temp->next;
    }
    int quotient = n / k, remainder = n % k;

    vector<ListNode *> parts(k, nullptr);
    ListNode *curr = head;
    for (int i = 0; i < k && curr != nullptr; i++) {
      parts[i] = curr;
      int partSize = quotient + (i < remainder ? 1 : 0);
      for (int j = 1; j < partSize; j++) {
        curr = curr->next;
      }
      ListNode *next = curr->next;
      curr->next = nullptr;
      curr = next;
    }
    return parts;
  }
};
void printList(ListNode* head){
  auto l = new ListNode(0, head);
  cout<<"[";
  while(l->next){
    cout<<(l->next)->val<<" ";
    l = l->next;
  }
  cout<<"]"<<endl;
};
int main(){
  auto l9 = new ListNode(10);
  auto l8 = new ListNode(9, l9);
  auto l7 = new ListNode(8, l8);
  auto l6 = new ListNode(7, l7);
  auto l5 = new ListNode(6, l6);
  auto l4 = new ListNode(5, l5);
  auto l3 = new ListNode(4, l4);
  auto l2 = new ListNode(3, l3);
  auto l1 = new ListNode(2, l2);
  auto head = new ListNode(1, l1);
  auto ans = (new Solution())->splitListToParts(head, 3);
  cout<<"ans is:"<<endl;
  for_each(ans.begin(), ans.end(), [](ListNode* h){printList(h);});
  return 0;
}
