/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:25:42 by rlobun            #+#    #+#             */
/*   Updated: 2026/10/20 11:47:04 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_ARRAY_BAG_HPP
# define SEARCHABLE_ARRAY_BAG_HPP

#include "searchable_bag.hpp"
#include "array_bag.hpp"

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
#endif
