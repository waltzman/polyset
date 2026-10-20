/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bag.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 11:33:42 by rlobun            #+#    #+#             */
/*   Updated: 2026/10/20 12:34:09 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BAG_HPP
# define BAG_HPP

class bag
{
	public:
		virtual void insert(int val) = 0;
		virtual void insert(int* array, int size) = 0;
		virtual void print() const = 0;
		virtual void clear() = 0;
		
};

#endif
