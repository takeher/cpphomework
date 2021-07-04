main.cpp:
给你一个区间数组intervals，其中 intervals[i]=[starti,endi]，且每个 starti都不同。
区间i的右侧区间可以记作区间j，并满足startj >=endi，且startj最小化。
返回一个由每个区间i的右侧区间的最小起始位置组成的数组。如果某个区间i不存在对应的右侧区间，则下标i处的值设为-1。

使用一个二分法。
