#include <cstdlib>
#include <iostream>
#include "bag2.hpp"

int main(int ac, char **av)
{
	if (ac == 1)
		return 1;
	searchable_bag *t = new searchable_tree_bag;
	searchable_bag *a = new searchable_array_bag;
	for (int i = 1; i < ac; i++)
	{
		t->insert(atoi(av[i]));
		a->insert(atoi(av[i]));
	}
	t->print();
	a->print();
	for (int i = 1; i < ac; i++)
	{
		std::cout << t->has(atoi(av[i])) << " ";
		std::cout << a->has(atoi(av[i])) << " ";
		std::cout << t->has(atoi(av[i]) - 1) << " ";
		std::cout << a->has(atoi(av[i]) - 1) << " ";
		std::cout << std::endl;
	}

	t->clear();
	std::cout << "\n ************************************************** \n" << std::endl;
	/*std::cout << "\nPRINTING A BEFORE CLEAR:" << std::endl;
	a->print();
	a->clear();
	std::cout << "\nPRINTING A CLEARED:" << std::endl;
	a->print();*/
	const searchable_array_bag tmp(static_cast<searchable_array_bag &>(*a));
	std::cout << "\n  * * * * * * * * * * * * * * * * * * tmp.print();" << std::endl;
	tmp.print();
	std::cout << (tmp.has(1)? "\nHAS 1" : "\nDOES NOT HAVE 1") << std::endl;
	set sa(*a);
	set st(*t);
	for (int i = 1; i < ac; i++)
	{
		st.insert(atoi(av[i]));
		sa.insert(atoi(av[i]));
	}
	std::cout << "sa.has(" << atoi(av[1])  << ")? :";
	std::cout << (sa.has(atoi(av[1])) ? "YES" : "NOOOO") << std::endl;
	std::cout << "\n ----------------------------- sa.print(); \n" << std::endl;
	sa.print();
	std::cout << "\n ----------------------------- sa.get_bag().print(); \n" << std::endl;
	sa.get_bag().print();
	std::cout << "\n ----------------------------- st.print(); \n" << std::endl;
	st.print();
	std::cout << "\n ----------------------------- st.get_bag().print(); \n" << std::endl;
	st.get_bag().print();
	sa.clear();
 	int arr[] = {1, 2, 3, 4,};
	sa.insert(arr, 4);
	sa.print();
	std::cout << std::endl;
}
