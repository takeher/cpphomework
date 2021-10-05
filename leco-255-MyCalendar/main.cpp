#include <bits/stdc++.h>
using namespace std;

class MyCalendarTwo {
private:
    map<int, int> val2cnt;

public:
    MyCalendarTwo() {}
    bool book(int start, int end) {
        ++val2cnt[start];
        --val2cnt[end];

        int curr = 0;
        for (auto iter = val2cnt.begin(); iter != val2cnt.end(); ++iter)
        {
            // 累加数值
            curr += iter->second;
            if (curr >= 3)
            {
                --val2cnt[start];
                ++val2cnt[end];
                // 如果没有记录了，则清除map来减少后续计算
                if (val2cnt[start] == 0)
                {
                    val2cnt.erase(start);
                }
                if (val2cnt[end] == 0)
                {
                    val2cnt.erase(end);
                }
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
int main(){
  MyCalendarTwo* obj = new MyCalendarTwo();
  cout<<"ans is:"<<obj->book(10, 20)<<endl;
  return 0;
}
