main.cpp:
一个矩阵中，如果某个元素为0，则把该元素所在的行和列的所有元素都赋为0，
要求使用原地算法，
这里使用了一个简单的节省空间的算法，就是先看第一列和第一行有无0，
用两个标志符记下来，然后把第一列和第一行作为剩余m-1xn-1的标志符，
每当有个元素为0 ，就把这个元素所在这一行和这一列的第一列元素与第一行元素赋0，
然后对第一行/列进行判定，将所有为0元素所在的列/行赋0，
最后对开始的两个标志符判定，如果第一行/列初始有0元素则将第一行/列赋0,
话说这题是不是前面做过。。

