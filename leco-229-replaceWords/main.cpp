#include <bits/stdc++.h>
using namespace std;
struct TrieNode
{
	bool isEnd;
	unordered_map<char, TrieNode*> next;
};

class RootTree {
public:
	TrieNode*root;
	/** Initialize your data structure here. */
	RootTree() {
		root = new TrieNode();
		root->isEnd = false;
	}

	void insert(string key) {
		TrieNode* p = root;
		for (int i = 0; i < key.length(); i++)
		{
			if ((p->next).count(key[i]) <= 0)
			{
				(p->next).insert(make_pair(key[i], new TrieNode()));
			}
			p = (p->next)[key[i]];
		}
		p->isEnd = true;
	}

	string findx(string &word)
	{
		TrieNode*p = root;
		if ((p->next).count(word[0]) <= 0) return word;
		string ans = word;
		for (int i = 0; i < word.length(); ++i)
		{
			if ((p->next).count(word[i]) > 0)
			{
				p = (p->next)[word[i]];
				if (p->isEnd)
				{
					ans = word.substr(0, i + 1);
					break;
				}
			}
			else
			{
				break;
			}
		}
		return ans;
	}
};

class Solution {
public:
	string replaceWords(const vector<string>& dictionary, string sentence) {
		//将词根插入到前缀树中
		RootTree roottree;
		for (int i = 0; i < dictionary.size(); ++i)
		{
			roottree.insert(dictionary[i]);
		}

		stringstream ss(sentence);
		string w;
		string ans = "";
		while (ss >> w)
		{
			string temp = roottree.findx(w);
			ans = ans + temp + " ";
		}
		ans.pop_back();
		return ans;
	}
};
int main(){
  cout << "ans is:"
       << (new Solution())->replaceWords(vector<string>{"cat", "bat", "rat"}, "the cattle was rattled by the battery")
       << endl;
  return 0;
}
