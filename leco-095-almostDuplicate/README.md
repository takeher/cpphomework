main.cpp:
给一个整数数组nums和两个整数k和t。
判断是否存在两个不同下标i和j，使得abs(nums[i]-nums[j])小于等于t ，同时又满足 abs(i - j) 小于等于 k
采用滑动窗口加有序数组的方法。
