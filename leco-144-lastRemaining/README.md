main.cpp:
消除游戏。
给定一个从1 到 n 排序的整数列表。
首先，从左到右，从第一个数字开始，每隔一个数字进行删除，直到列表的末尾。
第二步，在剩下的数字中，从右到左，从倒数第一个数字开始，每隔一个数字进行删除，直到列表开头。
我们不断重复这两步，从左到右和从右到左交替进行，直到只剩下一个数字。
返回长度为 n 的列表中，最后剩下的数字。
算法：
不论奇偶数，最后一个消除的就是从左往右的点，这个恰好也是我们起点
从左往右消除，起点肯定会改变
从右往左消除，偶数时候起点不改变，奇数时候会改变
而最后一个数字即最后起点就是结果
剩下就是模拟直接去求解了