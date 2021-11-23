#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int len = hand.size();
        // 两种特例
        if(len % groupSize != 0) return false; // 不能整除 直接返回false
        if(groupSize == 1) return true; // groupSize为1 直接返回true

        // 排序
        sort(hand.begin(),hand.end());

        // 记录数组元素是否被用过
        vector<int> used(len,false);
        // i为第一个指针 遍历hand数组 
        for(int i=0;i<len;i++){
            // 元素已被使用则跳过
            if(used[i]) continue;
            // 剩下的牌数量不足以构成一个新的W
            if(i>len-groupSize) return false;
            // 取use[i]为这一手牌中的第一张牌 并记录该牌已被使用
            int cur = hand[i];            
            used[i] = true;

            int tar = cur + 1; // tar为下一张需要找到的牌
            int end = cur + groupSize - 1;// end为这一手牌中的最后一张牌
            for(int j=i+1;j<len;j++){
                if(used[j]) continue; // 若已被用过 则跳过
                if(hand[j]>tar) return false;// hand[j]>tar 说明缺少需要的牌
                else if(hand[j]==tar){
                    // hand[j]==tar 说明已找到下一张需要的牌
                    used[j] = true;
 
                    if(hand[j]==end)break; // 已找到end这张牌 跳出循环 重新开始找新的一组牌
                    // 还未到end 继续找下一个tar
                    else tar++;
                }
            }
        }
        return true;
    }
};
int main(){
  vector<int> hand{1,2,3,6,2,3,4,7,8};
  cout << "ans is:"<< (new Solution())->isNStraightHand(hand, 3)<< endl;
  return 0;
}
