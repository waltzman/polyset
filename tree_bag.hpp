/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_bag.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:29:53 by rlobun            #+#    #+#             */
/*   Updated: 2026/10/19 14:03:50 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_BAG_HPP
# define TREE_BAG_HPP

#include <iostream>
#include "bag.hpp"

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
		
		void print() const {print_node(tree); std::cout << std::endl;}

		void print_node(node *n) const
		{
			if (!n)
				return;
			print_node(n->l);
			std::cout << n->value << " ";
			print_node(n->r);
		}
};
#endif
