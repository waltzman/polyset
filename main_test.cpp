/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:51:13 by rlobun            #+#    #+#             */
/*   Updated: 2026/10/19 15:24:41 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree_bag.hpp"

#include "array_bag.hpp"


int main()
{	

	array_bag* ab = new array_bag();
	ab->insert(5);
	ab->print();
	int ar1[] = {3, 6, 76, 54, 23};
	ab->insert(ar1,  5);
	ab->print();
	tree_bag* tb = new tree_bag();
	int arr[] = {4, 6, 3, 1, 39};
	b->insert(43536);
	tb->insert(arr, 5);
	tb->insert(arr, 5);
	tb->print();
	return (0);
}
