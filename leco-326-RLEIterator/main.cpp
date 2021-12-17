#include<bits/stdc++.h>
using namespace std;

/*

*/
class RLEIterator {
private:
    // 编码的引用
    vector<int>& e;
    // 表示当前指向的元素
    int i = 0;
    // 表示当前i里已经删除的次数
    int q = 0;
    // e的大小
    int en;
public:
    RLEIterator(vector<int>& encoding) : e(encoding){
        en = e.size();
    }
    
    int next(int n) {
        // 循环直到删除了足够n的元素
        while (i < en)
        {
            // 考虑当前i的元素不够减
            if (q + n > e[i])
            {
                // 更新还没删够的次数
                n -= e[i] - q;
             // 指向下一个后，自然要重置为0
                q = 0;
                // 偶数所以是+2
                i += 2; 
            }
            else
            {
                // 考虑当前i的元素可以减
                q += n;
                // 满足条件，并返回i+1的元素
                return e[i+1];
            }
        }

        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
int main(){
  auto encoding = vector<int> {3,8,0,9,2,5};
  RLEIterator* obj = new RLEIterator(encoding);
  cout<<"ans is:"<<(obj->next(2))<<endl;
  return 0;
}
