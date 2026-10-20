#pragma once

#include <iostream>

class bag
{
	public:
		virtual void insert(int val) = 0;
		virtual void insert(int* array, int size) = 0;
		virtual void print() const = 0;
		virtual void clear() = 0;
		
};


class array_bag: virtual public bag
{
	protected:
		int* data;
		int	size;
	public:
		array_bag(): data(0), size(0) {}
		array_bag(const array_bag& o) 
		{
			size = o.size;
			data = new int[size];
			for (int i = 0; i < size; i++)
				data[i] = o.data[i];
		}
		array_bag& operator=(const array_bag& o)
		{
			if (this != &o)
			{
				this->clear();
				size = o.size;
				data = new int[size];
				for (int i = 0; i < size; i++)
					data[i] = o.data[i];

			}
			return *this;
		}
		~array_bag() 
		{
			delete[] data;
		}

		void insert(int v)
		{	
			int* tmp = new int[size + 1];
			for (int i = 0; i < size; i++)
				tmp[i] = data[i];
			tmp[size] = v;
			delete data;
			data = tmp;
			size++;
		}

		void insert(int *a, int sz)
		{
			for (int i = 0; i < sz; ++i)
				insert(a[i]);
		}

		void print() const
		{
			std::cout << "\n[ARRAY BAG PRINT()]" << std::endl;
			if (size == 0)
			{
				std::cout << " 0000000 EMPTY!!!! 0000000000000" << std::endl;
				return ;
			}
			//std::cout << "\n[ARRAY BAG PRINT()]" << std::endl;
			for (int i = 0; i < size; ++i)
				std::cout << data[i] << " ";
			std::cout << std::endl;
		}

		void  clear() 
		{
			delete[] data;
			data = 0;
			size = 0;
		}
};
class tree_bag: virtual public bag
{
	protected:
		struct node
		{
			node* l;
			node* r;
			int value;

			node(node* l, node *r, int v) : l(l), r(r), value(v) {}
		};
		node* tree;
	public:
		tree_bag(): tree(0) {}
		tree_bag(const tree_bag& o) {tree = copy_node(o.tree);}
		tree_bag& operator=(const tree_bag& o)
		{
			if (this != &o)
			{
				this->clear();
				tree = copy_node(o.tree);
			}
			return *this;
		}
		~tree_bag() {destroy_tree(tree);}

		void destroy_tree(node* n)
		{
			if (!n)
				return;
			destroy_tree(n->l);
			destroy_tree(n->r);
			delete n;
		}

		void clear() { destroy_tree(tree); tree = 0;}

		node* copy_node(node* n)
		{
			if (!n)
				return 0;
			node* cp= new node(0, 0, n->value);
			cp->l = copy_node(n->l);
			cp->r = copy_node(n->r);
			return cp;

			// return new node(copy_node->l, copy_node->r, n->value);

		}

		node* extract_tree(node* n)
		{
			node* tmp = n;
			destroy_tree(n);
			return tmp;
		}

		void set_tree(node* n)
		{
			destroy_tree(tree);
			tree = n;
		}

		void insert(int val)
		{
			node** n = &tree;
			while (*n)
			{
				if (val < (*n)->value)
					n = &(*n)->l;
				else
					n = &(*n)->r;
			}
			*n = new node(0,0,val);
		}

		void insert(int* arr, int size)
		{
			for (int i = 0; i < size; ++i)
				insert(arr[i]);
		}
		
		void print() const 
		{
			std::cout << "\n[TREE BAG PRINT()]" << std::endl;
			print_node(tree); std::cout << std::endl;}

		void print_node(node *n) const
		{
			if (!n)
				return;
			print_node(n->l);
			std::cout << n->value << " ";
			print_node(n->r);
		}
};

class searchable_bag : virtual public bag
{

	public:
		virtual bool has(int value) const = 0;
};

class searchable_array_bag : public searchable_bag, public array_bag

{
	public:
		searchable_array_bag() {}
		searchable_array_bag(const searchable_array_bag& o) : array_bag(o) {}
		searchable_array_bag& operator=(const searchable_array_bag& o) {if (this != &o) array_bag::operator=(o); return (*this);}
		~searchable_array_bag() {}
		bool has(int val) const 
		{
			for (int i = 0; i < size; ++i)
			if (data[i] == val)
				return true;
			return false;
		}
};

class searchable_tree_bag: public searchable_bag, public tree_bag

{
	public:
		searchable_tree_bag() {}
		searchable_tree_bag(const searchable_tree_bag& o) : tree_bag(o) {}
		searchable_tree_bag& operator=(const searchable_tree_bag& o) {if (this != &o) tree_bag::operator=(o); return (*this);}
		~searchable_tree_bag() {}

		bool has(int val) const
		{
			for (node* n = tree; n; n = val < n->value ? n->l : n->r)
				if (val == n->value)
					return true;
			return false;
		}
};

class set
{
	searchable_bag& bag;
	public:
		set(searchable_bag &b) : bag(b) {}
		set(const set& o) : bag(o.bag) {}
		set& operator=(const set& o) { bag = o.bag; return *this;}
		~set() {}
		void insert(int v) { if (!bag.has(v)) bag.insert(v);}
		void insert(int *a, int sz) {for (int i = 0; i < sz; ++i) bag.insert(a[i]);}
		bool has(int v) {return bag.has(v);}
		void print() const 
		{
			std::cout << "\n[SEARCHABLE BAG  FROM SET PRINT()]" << std::endl;
			bag.print();
		}
		void clear() {bag.clear();}
		searchable_bag& get_bag() const { return bag;}
};


