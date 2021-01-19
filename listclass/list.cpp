#include<iostream> 
using namespace std;
class list_t
{
	struct node_d
	{
		node_d* next;
		node_d* prev;
		double data;
	};
public:
	list_t (){(*node).next = node;(*node).prev = node;}
	list_t (const list_t& x);
	virtual ~list_t ();
	class iterator;
	void push_front(const double& x);
	void push_back(const double& x);
	void pop_front();
	void pop_back();
	iterator insert(iterator pos, const double& x);
	void erase(iterator pos, const double& x);
	void erase(iterator first, iterator last);
	iterator begin();
	iterator end();
	void splice(iterator pos, list_t& x);
	unsigned size() const;
	bool empty() const;
	void sort();
	list_t& operator=(const list_t& x);

protected:
	node_d* node;
	unsigned int length;

};
class list_t::iterator 
{
public:
	iterator(){}
	iterator(node_d* x):node_t(x){}
	double operator*() const
	{
		return (*node_t).data;
	}
	iterator& operator++()
	{
		node_t = (*node_t).next;
		return *this;
	}
	iterator operator++(int)
	{
		iterator tmp = *this;
		++*this;
		return tmp;
	}
	bool operator==(const iterator& x)
	{
		if(this == &x)
			return true;
		else 
			return false;
	}
protected:
	node_d* node_t;
};
