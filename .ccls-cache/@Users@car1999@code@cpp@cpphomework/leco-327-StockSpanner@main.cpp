#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
private:
  // 单调递增的栈
  stack<int> prices;
  // 记录对应的连续日数，方便后面快速计算
  stack<int> days;

public:
  StockSpanner() {}

  int next(int price) {
    int day = 1;
    while (!prices.empty() && prices.top() <= price) {
      prices.pop();
      day += days.top();
      days.pop();
    }

    prices.push(price);
    days.push(day);

    return day;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
int main(){
  StockSpanner *obj = new StockSpanner();
  cout<<"ans is:"<<obj->next(100)<<endl;
  return 0;
}
