main.cpp:
给定一个非负整数 c ，
判断是否存在两个整数a和b，使得a2+b2=c。

费马平方和定理告诉我们：
一个非负整数c
如果能够表示为两个整数的平方和，
当且仅当 c 的所有形如 4k+3 的质因子的幂均为偶数。
因此我们需要对 c 进行质因数分解，
再判断所有形如 4k+3 的质因子的幂是否均为偶数即可。


