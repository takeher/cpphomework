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
	list_t (){(*node).next = node;(*node).prev = node;length = 0;}
	list_t (const list_t& x);
	~list_t ();
	class iterator;
	void push_front(const double& x);
	void push_back(const double& x);
	void pop_front();
	void pop_back();
	iterator insert(iterator pos, const double& x);
	void erase(iterator pos);
	void erase(iterator first, iterator last);
	iterator begin();
	iterator end();
	void splice(iterator pos, list_t& x);
	unsigned size() const;
	bool empty() const;
	void show();
	void inverse();
	//void sort();
	list_t& operator=(const list_t& x);

protected:
	node_d* node = new node_d;
	unsigned length = 0;

};
class list_t::iterator 
{
public:
	iterator(){}
	//iterator(node_d* x):node(x){}
	double operator*() const
	{
		return (*node).data;
	}
	iterator& operator++()
	{
		node = (*node).next;
		return *this;
	}
	iterator operator++(int)
	{
		iterator tmp = *this;
		++*this;
		return tmp;
	}
	iterator& operator--()
	{
		node = (*node).prev;
		return *this;
	}
	iterator operator--(int)
	{
		iterator tmp = *this;
		--*this;
		return tmp;
	}

	bool operator==(const iterator& x)
	{
		if(this->node == x.node)
			return true;
		else 
			return false;
	}
	bool operator!=(const iterator& x)
	{
		if(x.node == this->node)
			return false;
		else 
			return true;
	}
//protected:
	node_d* node;
	iterator(node_d*x):node(x){}
};
list_t::~list_t()
{
	delete node;
	cout<<"~"<<endl;
}
bool list_t::empty() const
{
	if((*node).next==node and (*node).prev==node)
		return true;
	else 
		return false;
}
list_t::iterator list_t::begin()
{
	return (*node).next;
}
list_t::iterator list_t::end()
{
	return node;
}
list_t::iterator list_t::insert(iterator pos, const double &x)
{
	node_d* p = new node_d;
	p->data = x;
	p->next = pos.node;
	p->prev = (*pos.node).prev;
	(*(*pos.node).prev).next = p;
	(*pos.node).prev = p;
	++length;
	return p;
}
void list_t::push_front(const double &x)
{
	insert(begin(), x);
}
void list_t::push_back(const double &x)
{
	insert(end(), x);
}
void list_t::erase(iterator pos)
{
	node_d* p = new node_d;
	p = pos.node;
	(p->prev)->next = p->next;
	(p->next)->prev = p->prev;
	delete p;
	--length;
}
void list_t::erase(iterator first,iterator last)
{
	for(iterator itr = first;itr != last;++itr)
	{	
		erase(itr);
	}
}
void list_t::pop_front()
{	
	if(!empty())
		erase(begin());
	else 
		cout<<"nothing to pop"<<endl;
}
void list_t::pop_back()
{
	if(!empty())
		erase(--end());
	else 
		cout<<"nothing to pop"<<endl;
}
unsigned list_t::size() const
{
	return length;
}
void list_t::splice(iterator pos, list_t &x)
{
	for(auto itr = x.begin();itr != x.end();++itr)
	{	
		insert(++pos,*itr);
		++length;
	}
}
list_t& list_t::operator=(const list_t& x)
{
	this->node = x.node;
	return *this;
}
void list_t::show()
{
	for(iterator itr = begin();itr != end();++itr)
	{	
		cout<<*itr<<" ";
	}
	cout<<endl;
}
void list_t::inverse()
{
	node_d pd = *node;
	(*node).next = (*node).prev;
	(*node).prev = pd.next;
	for(iterator itr = begin();itr != end();++itr)
	{	
		pd = *(itr.node);
		(*itr.node).next = (*itr.node).prev;
		(*itr.node).prev = pd.next;
	}
}
int main(int argc, char *argv[])
{
	list_t list1;
	cout<<"a list class"<<endl;
	cout<<"Is list empty?:";
	cout<<(int)list1.empty()<<endl;
	list1.push_front(12.0);
	auto itr = list1.begin();
	cout<<"push:";
	cout<<*itr<<endl;
	list1.push_back(13);
	list1.push_back(14);
	list1.push_back(15);
	list1.push_front(11);
	cout<<"list1 is:";
	list1.show();
	list1.inverse();
	cout<<"inverse is:";
	list1.show();
	list1.pop_back();
	cout<<"now list1 is:";
	list1.show();
	list1.pop_front();
	cout<<"now list1 is:";
	list1.show();

	cin.get();
	return 0;
}
