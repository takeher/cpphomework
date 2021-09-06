#include <bits/stdc++.h>
using namespace std;
class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        head=0,tail=0,count=0,capacity=k;
        vec.resize(k);
    }
    bool insertFront(int value) {
        if(isFull())return false;
        head=(head+capacity-1)%capacity;
        vec[head]=value;
        count++;
        return true;
    }
    bool insertLast(int value) {
        if(isFull())return false;
        vec[tail]=value;
        tail=(tail+1)%capacity;
        count++;
        return true;
    }
    bool deleteFront() {
        if(isEmpty())return false;
        head=(head+1)%capacity;
        count--;
        return true;
    }
    bool deleteLast() {
        if(isEmpty())return false;
        tail=(tail+capacity-1)%capacity;
        count--;
        return true;
    }
    int getFront() {
        if(isEmpty())return -1;
        return vec[head];
    }
    int getRear() {
        if(isEmpty())return -1;
        return vec[(tail+capacity-1)%capacity];
    }
    bool isEmpty() {
        return count==0;
    }
    bool isFull() {
        return count==capacity;
    }
private:
    vector<int>vec;
    int head;
    int tail;
    int count;
    int capacity;
};
int main(){
  MyCircularDeque* circularDeque = new MyCircularDeque(3); // 设置容量大小为3
  cout<<"ans is:";
  cout<<circularDeque->insertLast(1)<<" "                            // 返回 true
      <<circularDeque->insertLast(2)<<" "                            // 返回 true
      <<circularDeque->insertFront(3)<<" "                           // 返回 true
      <<circularDeque->insertFront(4)<<" " // 已经满了，返回 false
      <<circularDeque->getRear()<<" "      // 返回 2
      <<circularDeque->isFull()<<" "       // 返回 true
      <<circularDeque->deleteLast()<<" "   // 返回 true
      <<circularDeque->insertFront(4)<<" " // 返回 true
      <<circularDeque->getFront()<<endl;     // 返回 4
  return 0;
}
