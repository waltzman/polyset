/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:48:57 by rlobun            #+#    #+#             */
/*   Updated: 2026/10/19 15:50:25 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_TREE_BAG_HPP
# define SEARCHABLE_TREE_BAG_HPP

#include "tree_bag.hpp"
#include "searchable_bag.hpp"

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

#endif
