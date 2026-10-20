/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_bag.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 11:45:49 by rlobun            #+#    #+#             */
/*   Updated: 2026/10/19 11:51:07 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_BAG_HPP
# define SEARCHABLE_BAG_HPP

#include "bag.hpp"

class searchable_bag : virtual public bag
{

	public:
		virtual bool has(int value) const = 0;
};

#endif
