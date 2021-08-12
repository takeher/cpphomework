main.cpp:
TinyURL是一种URL简化服务， 
比如：当输入一个URL https://leetcode.com/problems/design-tinyurl
它将返回一个简化的URL http://tinyurl.com/4e9iAk.
要求：设计一个 TinyURL 的加密 encode 和解密 decode 的方法。
加密和解密算法如何设计和运作是没有限制的，
只需要保证一个URL可以被加密成一个TinyURL，
并且这个TinyURL可以用解密方法恢复成原本的URL。

利用质数构建哈希表。
