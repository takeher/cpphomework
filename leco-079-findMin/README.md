main.cpp:
查找旋转排序数组中的最小元素。
我们考虑数组中的最后一个元素 x：
在最小值右侧的元素（不包括最后一个元素本身），
它们的值一定都严格小于x；
而在最小值左侧的元素，它们的值一定都严格大于x。
因此，我们可以根据这一条性质，通过二分查找的方法找出最小值。
在二分查找的每一步中，左边界为low，右边界为high，
区间的中点为pivot，最小值就在该区间内。
我们将中轴元素nums[pivot]与右边界元素nums[high] 进行比较。