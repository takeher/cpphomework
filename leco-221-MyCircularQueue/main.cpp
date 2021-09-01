#include <bits/stdc++.h>
using namespace std;
class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        vec.resize(k);
        head=0;
        tail=0;
        count=0;
        capacity=k;
    }
    bool enQueue(int value) {
        if(isFull())return false;
        vec[tail]=value;
        tail=(tail+1)%capacity;
        count++;
        return true;
    }
    bool deQueue() {
        if(isEmpty())return false;
        head=(head+1)%capacity;
        count--;
        return true;
    }
    int Front() {
        if(isEmpty())return -1;
        return vec[head];
    }
    int Rear() {
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
  MyCircularQueue* circularQueue = new MyCircularQueue(3);
  cout<<circularQueue->enQueue(1)<<endl;
  cout<<circularQueue->enQueue(2)<<endl;
  cout<<circularQueue->enQueue(3)<<endl;
  cout<<circularQueue->enQueue(4)<<endl;
  cout<<circularQueue->Rear()<<endl;
  cout<<circularQueue->isFull()<<endl;
  cout<<circularQueue->deQueue()<<endl;
  cout<<circularQueue->enQueue(4)<<endl;
  cout<<circularQueue->Rear()<<endl;
  return 0;
}
