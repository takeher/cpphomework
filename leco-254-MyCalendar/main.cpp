#include<bits/stdc++.h>
using namespace std;

class MyCalendar {
public:
  vector<vector<int>> arr;
  MyCalendar() {}

  bool book(int start, int end) {
    int l = 0, r = arr.size() - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (arr[mid][0] >= end)
        r = mid;
      else
        l = mid + 1;
    }
    if (l == arr.size() - 1 && arr[l][0] < end) {
      if (start >= arr[l][1]) {
        arr.push_back({start, end});
        return 1;
      } else
        return 0;
    }
    if (!l || start >= arr[l - 1][1]) {
      arr.insert(arr.begin() + l, {start, end});
      return 1;
    } else
      return 0;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
int main(){
  cout<<"ans is:"<<(new MyCalendar())->book(10, 20)<<endl;
  return 0;
}
