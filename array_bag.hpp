/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_bag.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 11:54:42 by rlobun            #+#    #+#             */
/*   Updated: 2026/10/20 11:49:25 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_BAG_HPP
# define ARRAY_BAG_HPP

#include "bag.hpp"
#include <iostream>

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
			delete data;
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
			for (int i = 0; i < size; ++i)
				std::cout << data[i] << " ";
			std::cout << std::endl;
		}

		void  clear() 
		{
			delete data;
			data = 0;
			size = 0;
		}
};

#endif
