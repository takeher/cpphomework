#include<bits/stdc++.h>
using namespace std;

class ExamRoom {
  int n;
  set<int> s;

public:
  ExamRoom(int N) : n(N) {}

  int seat() {
    // 没有人的时候直接坐第一个位置
    if (s.empty()) {
      s.insert(0);
      return 0;
    }

    int res = 0;
    // 上一个点的位置
    int pre = -1;
    // 当前最大距离
    int maxDist = 0;
    for (int cur : s) {
      // 取相邻结点的中点位置
      int dist = (cur - pre) >> 1;
      if (dist > maxDist) {
        res = pre == -1 ? 0 : pre + dist;
        maxDist = dist;
      }
      pre = cur;
    }
    // 考虑最后一个位置的特殊情况
    if (n - 1 - pre > maxDist) {
      res = n - 1;
    }
    s.insert(res);

    return res;
  }

  // 离开就是删除，而无需重排
  void leave(int p) { s.erase(p); }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
int main(){
  ExamRoom *obj = new ExamRoom(10);
  int param_1 = obj->seat();
  obj->leave(4);
  cout<<"ans is:"<<obj->seat()<<endl;
  return 0;
}
