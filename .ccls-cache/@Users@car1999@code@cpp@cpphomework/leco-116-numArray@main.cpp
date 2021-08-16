#include<bits/stdc++.h>
using namespace std;
class SegTree
{
public:
    vector<int> nums;
    vector<int> treesum;
    int n;

    SegTree(vector<int>  nums)
    {
        this->nums = nums;
        this->n = nums.size();
        treesum.resize(4 * n, 0);
        if (n > 0)
            _build(0, 0, n - 1);
    }

    void update(int ID, int newValue)
    {
        _update(0, 0, n - 1, ID, newValue);
    }

    int query(int ql, int qr)
    {
        return _query(0, 0, n - 1, ql, qr);
    }

    void _build(int root, int l, int r)
    {
        if (l == r)
        {
            treesum[root] = nums[r];
            return ;
        }
        int left = 2 * root + 1;
        int right = 2 * root + 2;
        int mid = (l + r) >> 1;
        _build(left, l, mid);
        _build(right, mid + 1, r);
        treesum[root] = treesum[left] + treesum[right];
    }

    void _update(int root, int l, int r, int ID, int newValue)
    {
        if (l == ID && r == ID)
        {
            treesum[root] = newValue;
            return;
        }
        int left = 2 * root + 1;
        int right = 2 * root + 2;
        int mid = (l + r) >> 1;
        if (ID <= mid)
            _update(left, l, mid, ID, newValue);
        else
            _update(right, mid + 1, r, ID, newValue);
        treesum[root] = treesum[left] + treesum[right];
    }

    int _query(int root, int l, int r, int ql, int qr)
    {
        if (l == ql && r == qr)
            return treesum[root];
        int left = 2 * root + 1;
        int right = 2 * root + 2;
        int mid = (l + r) >> 1;
        if (qr <= mid)
            return _query(left, l, mid, ql, qr);
        else if (mid + 1 <= ql)
            return _query(right, mid + 1, r, ql, qr);
        return _query(left, l, mid, ql, mid) + _query(right, mid + 1, r, mid + 1, qr);
    }

};


class NumArray
{
public:
    SegTree * ST;

    NumArray(vector<int>& nums)
    {
        ST = new SegTree(nums);
    }

    void update(int index, int val)
    {
        ST->update(index, val);
    }

    int sumRange(int left, int right)
    {
        return ST->query(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
int main(int argc, char *argv[])
{
	vector<int> nums {1,3,5};
	NumArray array(nums);
	cout<<"ans1 is:"<<array.sumRange(0,2)<<endl;
	array.update(1,2);
	cout<<"ans2 is:"<<array.sumRange(0,2)<<endl;
	return 0;
}
