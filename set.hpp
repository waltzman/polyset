/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 15:10:36 by rlobun            #+#    #+#             */
/*   Updated: 2026/10/19 15:36:08 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

#include "searchable_bag.hpp"
#include <iostream>


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
		void print() const {bag.print();}
		void clear() {bag.clear();}
		searchable_bag& get_bag() const { return bag;}
};

#endif
