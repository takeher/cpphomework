main.cpp:
删除数组中的重复项2，目的是返回删除重复元素后的原地数组。
每个项出现次数不超过2次。
采用覆盖法。
我们使用了两个指针，i 是遍历指针，指向当前遍历的元素；j 指向下一个要覆盖元素的位置。
同样，我们用 count 记录当前数字出现的次数。count 的最小计数始终为 1。
我们从索引 1 开始一次处理一个数组元素。
若当前元素与前一个元素相同，即 nums[i]==nums[i-1]，则 count++。若 count > 2，则说明遇到了多余的重复项。在这种情况下，我们只向前移动 i，而 j 不动。
若count 小于等于2，则我们将i所指向的元素移动到j位置，并同时增加i和j。
若当前元素与前一个元素不相同，即nums[i]!=nums[i - 1]，说明遇到了新元素，则我们更新count=1，
并且将该元素移动到j位置，并同时增加i和j。
当数组遍历完成，则返回j。
