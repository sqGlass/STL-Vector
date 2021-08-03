/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:04:17 by sglass            #+#    #+#             */
/*   Updated: 2021/05/29 12:14:02 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stack>
#include <vector>
#include <exception>
#include "vector.hpp"
#include "iterator.hpp"
// #include "const_iterator.hpp"
#include "reverse_iterator.hpp"
// #include "const_reverse_iterator.hpp"
// #include <vector>

void    const_reverse_iter_test()
{
    std::vector<int> real(5, 100);
    std::vector<int>::const_reverse_iterator it_r = real.rbegin();
    std::vector<int>::const_reverse_iterator it2_r;
    it2_r = it_r;
    std::cout << it_r - real.rend() << std::endl;
    std::cout << "real contains:\n";
    while (it2_r != real.rend())
        std::cout << *it2_r++ << std::endl;
    ft::vector<int> my(5, 100);
    ft::vector<int>::const_reverse_iterator it_m = my.rbegin();
    ft::vector<int>::const_reverse_iterator it2_m;
    it2_m = it_m;
    std::cout << it_m - my.rend() << std::endl;
    std::cout << "my contains:\n";
    while (it2_m != my.rend())
        std::cout << *it2_m++ << std::endl;
}

void    const_iter_test(void)
{
    std::vector<int> real(5, 100);
    std::vector<int>::const_iterator it_r = real.begin();
    std::vector<int>::const_iterator it2_r;
    it2_r = it_r;
    std::cout << "real contains:\n";
    while (it2_r != real.end())
        std::cout << *it2_r++ << std::endl;
	////
    ft::vector<int> my(5, 100);
    ft::vector<int>::const_iterator it_m = my.begin();
    ft::vector<int>::const_iterator it2_m;
    it2_m = it_m;
    std::cout << "my contains:\n";
    while (it2_m != my.end())
        std::cout << *it2_m++ << std::endl;
    return;
}


void swap2_test()
{
	unsigned int i;
	std::vector<int> foo(3, 100); // three ints with a value of 100
	std::vector<int> bar(5, 200); // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo contains:";
	for (std::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "bar contains:";
	for (std::vector<int>::iterator it = bar.begin(); it != bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	////////////////////////////////////////////////////////////
	unsigned int my_i;
	ft::vector<int> my_foo(3, 100); // three ints with a value of 100
	ft::vector<int> my_bar(5, 200); // five ints with a value of 200

	my_foo.swap(my_bar);

	std::cout << "foo contains:";
	for (ft::vector<int>::iterator my_it = my_foo.begin(); my_it != my_foo.end(); ++my_it)
		std::cout << ' ' << *my_it;
	std::cout << '\n';

	std::cout << "bar contains:";
	for (ft::vector<int>::iterator my_it = my_bar.begin(); my_it != my_bar.end(); ++my_it)
		std::cout << ' ' << *my_it;
	std::cout << '\n';
}

void relation_oper_test()
{
	std::vector<int> foo(3, 100); // three ints with a value of 100
	std::vector<int> bar(2, 200); // two ints with a value of 200

	if (foo == bar)
		std::cout << "foo and bar are equal\n";
	if (foo != bar)
		std::cout << "foo and bar are not equal\n";
	if (foo < bar)
		std::cout << "foo is less than bar\n";
	if (foo > bar)
		std::cout << "foo is greater than bar\n";
	if (foo <= bar)
		std::cout << "foo is less than or equal to bar\n";
	if (foo >= bar)
		std::cout << "foo is greater than or equal to bar\n";
	std::cout << std::endl;
		////////////////////////////////////////////////////////
	ft::vector<int> my_foo(3, 100); // three ints with a value of 100
	ft::vector<int> my_bar(2, 200); // two ints with a value of 200

	if (my_foo == my_bar)
		std::cout << "foo and bar are equal\n";
	if (my_foo != my_bar)
		std::cout << "foo and bar are not equal\n";
	if (my_foo < my_bar)
		std::cout << "foo is less than bar\n";
	if (my_foo > my_bar)
		std::cout << "foo is greater than bar\n";
	if (my_foo <= my_bar)
		std::cout << "foo is less than or equal to bar\n";
	if (my_foo >= my_bar)
		std::cout << "foo is greater than or equal to bar\n";
}

void swap_test()
{
	std::vector<int> foo(3, 100); // three ints with a value of 100
	std::vector<int> bar(5, 200); // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo contains:";
	for (unsigned i = 0; i < foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << '\n';

	std::cout << "bar contains:";
	for (unsigned i = 0; i < bar.size(); i++)
		std::cout << ' ' << bar[i];
	std::cout << '\n';
	/////////////////////////////////////////////////////////
	ft::vector<int> my_foo(3, 100); // three ints with a value of 100
	ft::vector<int> my_bar(5, 200); // five ints with a value of 200

	my_foo.swap(my_bar);

	std::cout << "foo contains:";
	for (unsigned i = 0; i < my_foo.size(); i++)
		std::cout << ' ' << my_foo[i];
	std::cout << '\n';

	std::cout << "bar contains:";
	for (unsigned i = 0; i < my_bar.size(); i++)
		std::cout << ' ' << my_bar[i];
	std::cout << '\n';
}

void size_test()
{
	std::vector<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i = 0; i < 10; i++)
		myints.push_back(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.insert(myints.end(), 10, 100);
	std::cout << "2. size: " << myints.size() << '\n';

	myints.pop_back();
	std::cout << "3. size: " << myints.size() << '\n';
	///////////////////////////////////////////////////////
	ft::vector<int> my_myints;
	std::cout << "0. size: " << my_myints.size() << '\n';

	for (int i = 0; i < 10; i++)
		my_myints.push_back(i);
	std::cout << "1. size: " << my_myints.size() << '\n';

	my_myints.insert(my_myints.end(), 10, 100);
	std::cout << "2. size: " << my_myints.size() << '\n';

	my_myints.pop_back();
	std::cout << "3. size: " << my_myints.size() << '\n';
}

void resize_test()
{
	std::vector<int> myvector;

	// set some initial content:
	for (int i = 1; i < 10; i++)
		myvector.push_back(i);

	myvector.resize(5);
	myvector.resize(8, 100);
	myvector.resize(12);

	std::cout << "myvector contains:";
	for (int i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	///////////////////////////////////////////////////
	ft::vector<int> my_myvector;

	// set some initial content:
	for (int i = 1; i < 10; i++)
		my_myvector.push_back(i);

	my_myvector.resize(5);
	my_myvector.resize(8, 100);
	my_myvector.resize(12);

	std::cout << "My myvector contains:";
	for (int i = 0; i < my_myvector.size(); i++)
		std::cout << ' ' << my_myvector[i];
	std::cout << '\n';
}

void reserve_test()
{
	std::vector<int>::size_type sz;

	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		foo.push_back(i);
		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	std::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100); // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		bar.push_back(i);
		if (sz != bar.capacity())
		{
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	std::cout << std::endl;
	///////////////////////////////////////////////////////////////////////
	std::vector<int>::size_type my_sz;

	ft::vector<int> my_foo;
	my_sz = my_foo.capacity();
	std::cout << "My making foo grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		my_foo.push_back(i);
		if (my_sz != my_foo.capacity())
		{
			my_sz = my_foo.capacity();
			std::cout << "My capacity changed: " << my_sz << '\n';
		}
	}

	ft::vector<int> my_bar;
	my_sz = my_bar.capacity();
	my_bar.reserve(100); // this is the only difference with foo above
	std::cout << "My making bar grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		my_bar.push_back(i);
		if (my_sz != my_bar.capacity())
		{
			my_sz = my_bar.capacity();
			std::cout << "My capacity changed: " << my_sz << '\n';
		}
	}
}

void rend_test()
{
	std::vector<int> myvector(5); // 5 default-constructed ints

	int i = 0;

	std::vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit != myvector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	/////////////////////////////////////////////////////////////////
	ft::vector<int> my_myvector(5); // 5 default-constructed ints

	int my_i = 0;

	ft::vector<int>::reverse_iterator my_rit = my_myvector.rbegin();
	for (; my_rit != my_myvector.rend(); ++my_rit)
		*my_rit = ++my_i;

	std::cout << "My myvector contains:";
	for (ft::vector<int>::iterator my_it = my_myvector.begin(); my_it != my_myvector.end(); ++my_it)
		std::cout << ' ' << *my_it;
	std::cout << '\n';
}

void rbegin_test()
{
	std::vector<int> myvector(5); // 5 default-constructed ints

	int i = 0;

	std::vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit != myvector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	/////////////////////////////////////////////////////////////////
	ft::vector<int> my_myvector(5); // 5 default-constructed ints

	int my_i = 0;

	ft::vector<int>::reverse_iterator my_rit = my_myvector.rbegin();
	for (; my_rit != my_myvector.rend(); ++my_rit)
		*my_rit = ++my_i;

	std::cout << "My myvector contains:";
	for (ft::vector<int>::iterator my_it = my_myvector.begin(); my_it != my_myvector.end(); ++my_it)
		std::cout << ' ' << *my_it;
	std::cout << '\n';
}

void push_back_test()
{
	std::vector<int> myvector;
	int myint;

	std::cout << "Please enter some integers (enter 0 to end):\n";

	do
	{
		std::cin >> myint;
		myvector.push_back(myint);
	} while (myint);

	std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
	/////////////////////////////////////////////////////////////////////////
	
	ft::vector<int> my_myvector;
	int my_myint;

	std::cout << "Please enter some integers (enter 0 to end):\n";
	do
	{
		std::cin >> my_myint;
		my_myvector.push_back(my_myint);
	} while (my_myint);

	std::cout << "My myvector stores " << int(my_myvector.size()) << " numbers.\n";

}

void pop_back_test()
{
	std::vector<int> myvector;
	int sum(0);
	myvector.push_back(100);
	myvector.push_back(200);
	myvector.push_back(300);

	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}

	std::cout << "The elements of myvector add up to " << sum << '\n';
	///////////////////////////////////////////////////////////////////
	ft::vector<int> my_myvector;
	int my_sum(0);
	my_myvector.push_back(100);
	my_myvector.push_back(200);
	my_myvector.push_back(300);

	while (!my_myvector.empty())
	{
		my_sum += my_myvector.back();
		my_myvector.pop_back();
	}

	std::cout << "My The elements of myvector add up to " << my_sum << '\n';
}

void operatorskobki_test()
{
	std::vector<int> myvector(10); // 10 zero-initialized elements

	std::vector<int>::size_type sz = myvector.size();

	// assign some values:
	for (unsigned i = 0; i < sz; i++)
		myvector[i] = i;

	// reverse vector using operator[]:
	for (unsigned i = 0; i < sz / 2; i++)
	{
		int temp;
		temp = myvector[sz - 1 - i];
		myvector[sz - 1 - i] = myvector[i];
		myvector[i] = temp;
	}

	std::cout << "myvector contains:";
	for (unsigned i = 0; i < sz; i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	//////////////////////////////////////////////////
	ft::vector<int> my_myvector(10); // 10 zero-initialized elements

	ft::vector<int>::size_type my_sz = my_myvector.size();

	// assign some values:
	for (unsigned i = 0; i < my_sz; i++)
		my_myvector[i] = i;

	// reverse vector using operator[]:
	for (unsigned i = 0; i < my_sz / 2; i++)
	{
		int my_temp;
		my_temp = my_myvector[my_sz - 1 - i];
		my_myvector[my_sz - 1 - i] = my_myvector[i];
		my_myvector[i] = my_temp;
	}

	std::cout << "My myvector contains:";
	for (unsigned i = 0; i < my_sz; i++)
		std::cout << ' ' << my_myvector[i];
	std::cout << '\n';
}

void operatorass_test()
{
	std::vector<int> foo(3, 0);
	std::vector<int> bar(5, 0);

	bar = foo;
	foo = std::vector<int>();

	std::cout << "Size of foo: " << int(foo.size()) << '\n';
	std::cout << "Size of bar: " << int(bar.size()) << '\n';
	//////////////////////////////////////////////////////////
	ft::vector<int> my_foo(3, 0);
	ft::vector<int> my_bar(5, 0);

	my_bar = my_foo;
	my_foo = ft::vector<int>();

	std::cout << "My Size of foo: " << int(my_foo.size()) << '\n';
	std::cout << "My Size of bar: " << int(my_bar.size()) << '\n';
}

void max_size()
{
	std::vector<int> myvector;

	// set some content in the vector:
	for (int i = 0; i < 100; i++)
		myvector.push_back(i);

	std::cout << "size: " << myvector.size() << "\n";
	std::cout << "capacity: " << myvector.capacity() << "\n";
	std::cout << "max_size: " << myvector.max_size() << "\n";
	///////////////////////////////////////////////////////////
	ft::vector<int> my_myvector;

	// set some content in the vector:
	for (int i = 0; i < 100; i++)
		my_myvector.push_back(i);

	std::cout << "My size: " << my_myvector.size() << "\n";
	std::cout << "My capacity: " << my_myvector.capacity() << "\n";
	std::cout << "My max_size: " << my_myvector.max_size() << "\n";
}

void insert_test()
{
	std::vector<int> myvector(3, 100);
	std::vector<int>::iterator it;

	it = myvector.begin();
	it = myvector.insert(it, 200);

	myvector.insert(it, 2, 300);

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	std::vector<int> anothervector(2, 400);
	myvector.insert(it + 2, anothervector.begin(), anothervector.end());

	int myarray[] = {501, 502, 503};
	myvector.insert(myvector.begin(), myarray, myarray + 3);

	std::cout << "Orig vector contains:";
	for (it = myvector.begin(); it < myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	/////////////////////////////////////////////////////////////
	ft::vector<int> my_myvector(3, 100);
	ft::vector<int>::iterator my_it;

	my_it = my_myvector.begin();
	my_it = my_myvector.insert(my_it, 200);

	my_myvector.insert(my_it, 2, 300);

	// "it" no longer valid, get a new one:
	my_it = my_myvector.begin();

	ft::vector<int> my_anothervector(2, 400);
	my_myvector.insert(my_it + 2, my_anothervector.begin(), my_anothervector.end());

	int my_myarray[] = {501, 502, 503};
	my_myvector.insert(my_myvector.begin(), my_myarray, my_myarray + 3);

	std::cout << "My vector contains:";
	for (my_it = my_myvector.begin(); my_it < my_myvector.end(); my_it++)
		std::cout << ' ' << *my_it;
	std::cout << '\n';
}

void get_allocator_test()
{
	std::vector<int> myvector;
	int *p;
	unsigned int i;

	// allocate an array with space for 5 elements using vector's allocator:
	p = myvector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i = 0; i < 5; i++)
		myvector.get_allocator().construct(&p[i], i);

	std::cout << "The allocated array contains:";
	for (i = 0; i < 5; i++)
		std::cout << ' ' << p[i];
	std::cout << '\n';

	
	// destroy and deallocate:
	for (i = 0; i < 5; i++)
		myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p, 5);
	/////////////////////////////////////////////////////////////////////
	ft::vector<int> my_myvector;
	int *my_p;
	unsigned int my_i;

	// allocate an array with space for 5 elements using vector's allocator:
	my_p = my_myvector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i = 0; i < 5; i++)
		my_myvector.get_allocator().construct(&my_p[i], i);

	std::cout << "The allocated array contains:";
	for (i = 0; i < 5; i++)
		std::cout << ' ' << my_p[i];
	std::cout << '\n';

	// destroy and deallocate:
	for (i = 0; i < 5; i++)
		my_myvector.get_allocator().destroy(&my_p[i]);
	my_myvector.get_allocator().deallocate(my_p, 5);
}

void front_test()
{
	std::vector<int> myvector;

	myvector.push_back(78);
	myvector.push_back(16);

	// now front equals 78, and back 16

	myvector.front() -= myvector.back();

	std::cout << "Original vector.front() is now " << myvector.front() << '\n';
	////////////////////////////////////////////
	ft::vector<int> my_myvector;

	my_myvector.push_back(78);
	my_myvector.push_back(16);

	// now front equals 78, and back 16

	my_myvector.front() -= my_myvector.back();

	std::cout << "My vector.front() is now " << my_myvector.front() << '\n';
}

void erase_test()
{
	std::vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i = 1; i <= 10; i++)
		myvector.push_back(i);

	// erase the 6th element
	myvector.erase(myvector.begin() + 5);

	// erase the first 3 elements:
	myvector.erase(myvector.begin(), myvector.begin() + 3);

	std::cout << "Original vector contains:";
	for (unsigned i = 0; i < myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	std::cout << "SIZE " << myvector.size() << std::endl;
	std::cout << "CAPACITY " << myvector.capacity() << std::endl;
	/////////////////////////////////////////////////////////////
	ft::vector<int> my_myvector;

	// set some values (from 1 to 10)
	for (int i = 1; i <= 10; i++)
		my_myvector.push_back(i);

	// erase the 6th element
	my_myvector.erase(my_myvector.begin() + 5);

	// erase the first 3 elements:
	my_myvector.erase(my_myvector.begin(), my_myvector.begin() + 3);

	std::cout << "My vector contains:";
	for (unsigned i = 0; i < my_myvector.size(); ++i)
		std::cout << ' ' << my_myvector[i];
	std::cout << '\n';
	std::cout << "SIZE " << my_myvector.size() << std::endl;
	std::cout << "CAPACITY " << my_myvector.capacity() << std::endl;
}

void end_test()
{
	std::vector<int> myvector;
	for (int i = 1; i <= 5; i++)
		myvector.push_back(i);

	std::cout << "My vector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	////////////////////////////////////////////////
	ft::vector<int> my_myvector;
	for (int i = 1; i <= 5; i++)
		my_myvector.push_back(i);

	std::cout << "my_myvector contains:";
	for (ft::vector<int>::iterator my_it = my_myvector.begin(); my_it != my_myvector.end(); ++my_it)
		std::cout << ' ' << *my_it;
	std::cout << '\n';
}

void empty_test()
{
	std::vector<int> myvector;
	int sum(0);

	for (int i = 1; i <= 10; i++)
		myvector.push_back(i);

	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}

	std::cout << "total: " << sum << '\n';
	std::cout << "SIZE " << myvector.size() << std::endl;
	std::cout << "CAPACITY " << myvector.capacity() << std::endl;
	/////////////////////////////////////////////////
	ft::vector<int> my_myvector;
	int my_sum(0);

	for (int i = 1; i <= 10; i++)
		my_myvector.push_back(i);

	while (!my_myvector.empty())
	{
		my_sum += my_myvector.back();
		my_myvector.pop_back();
	}

	std::cout << "total: " << my_sum << '\n';
	std::cout << "SIZE " << my_myvector.size() << std::endl;
	std::cout << "CAPACITY " << my_myvector.capacity() << std::endl;
}

void clear_test()
{
	std::vector<int> myvector;
	myvector.push_back(100);
	myvector.push_back(200);
	myvector.push_back(300);

	std::cout << "Original vector contains:";
	for (unsigned i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	myvector.clear();
	myvector.push_back(1101);
	myvector.push_back(2202);

	std::cout << "Original vector contains:";
	for (unsigned i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	std::cout << "CAPACITY " << myvector.capacity() << std::endl;
	/////////////////////////////////////////////////
	ft::vector<int> my_myvector;
	my_myvector.push_back(100);
	my_myvector.push_back(200);
	my_myvector.push_back(300);

	std::cout << "myvector contains:";
	for (unsigned i = 0; i < my_myvector.size(); i++)
		std::cout << ' ' << my_myvector[i];
	std::cout << '\n';

	my_myvector.clear();
	my_myvector.push_back(1101);
	my_myvector.push_back(2202);

	std::cout << "myvector contains:";
	for (unsigned i = 0; i < my_myvector.size(); i++)
		std::cout << ' ' << my_myvector[i];
	std::cout << '\n';
	std::cout << "CAPACITY " << my_myvector.capacity() << std::endl;
}

void capacity_test()
{
	std::vector<int> myvector;
	for (int i = 0; i < 100; i++)
		myvector.push_back(i);

	std::cout << "size: " << myvector.size() << '\n';
	std::cout << "capacity: " << myvector.capacity() << '\n';
	std::cout << "max_size: " << myvector.max_size() << '\n';
	std::cout << std::endl;
	/////////////////////////////////////////////////////////////////////
	ft::vector<int> my_myvector;
	for (int i = 0; i < 100; i++)
		my_myvector.push_back(i);

	std::cout << "size: " << my_myvector.size() << '\n';
	std::cout << "capacity: " << my_myvector.capacity() << '\n';
	std::cout << "max_size: " << my_myvector.max_size() << '\n';
}

void begin_test()
{
	std::vector<int> myvector;
	for (int i = 1; i <= 5; i++)
		myvector.push_back(i);

	std::cout << "Original vector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	///////////////////////////////////////////////
	ft::vector<int> my_myvector;
	for (int i = 1; i <= 5; i++)
		my_myvector.push_back(i);

	std::cout << "My vector contains:";
	for (ft::vector<int>::iterator my_it = my_myvector.begin(); my_it != my_myvector.end(); ++my_it)
		std::cout << ' ' << *my_it;
	std::cout << '\n';
}

void back_test()
{
	std::vector<int> myvector;

	myvector.push_back(10);

	while (myvector.back() != 0)
	{
		myvector.push_back(myvector.back() - 1);
	}

	std::cout << "Orig vector contains:";
	for (unsigned i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	std::cout << "CAPACITY " << myvector.capacity() << std::endl;
	///////////////////////////////////////////////////////
	ft::vector<int> my_myvector;

	my_myvector.push_back(10);

	while (my_myvector.back() != 0)
	{
		my_myvector.push_back(my_myvector.back() - 1);
	}

	std::cout << "My vector contains:";
	for (unsigned i = 0; i < my_myvector.size(); i++)
		std::cout << ' ' << my_myvector[i];
	std::cout << '\n';
	std::cout << "CAPACITY " << my_myvector.capacity() << std::endl;
}

void at_test()
{
	std::vector<int> myvector(10); // 10 zero-initialized ints

	// assign some values:
	for (unsigned i = 0; i < myvector.size(); i++)
		myvector.at(i) = i;

	std::cout << "Original yvector contains:";
	for (unsigned i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector.at(i);
	std::cout << '\n';
	//////////////////////////////////////////////////////////////
	ft::vector<int> my_myvector(10); // 10 zero-initialized ints

	// assign some values:
	for (unsigned i = 0; i < my_myvector.size(); i++)
		my_myvector.at(i) = i;

	std::cout << "myvector contains:";
	for (unsigned i = 0; i < my_myvector.size(); i++)
		std::cout << ' ' << my_myvector.at(i);
	std::cout << '\n';
}

void assign_test()
{
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;

	first.assign(7, 100); // 7 ints with a value of 100

	std::vector<int>::iterator it;
	it = first.begin() + 1;

	second.assign(it, first.end() - 1); // the 5 central values of first

	int myints[] = {1776, 7, 4};
	third.assign(myints, myints + 3); // assigning from array.

	std::cout << "Original vector:" << std::endl;
	std::cout << "Size of first: " << int(first.size()) << '\n';
	std::cout << "Size of second: " << int(second.size()) << '\n';
	std::cout << "Size of third: " << int(third.size()) << '\n';
	std::cout << "sizes and capacitys" << std::endl;
	std::cout << first.capacity() << std::endl;
	std::cout << first.size() << std::endl;
	std::cout << second.capacity() << std::endl;
	std::cout << second.size() << std::endl;
	std::cout << third.capacity() << std::endl;
	std::cout << third.size() << std::endl;
	///////////////////////////////////////////////////////////////
	ft::vector<int> my_first;
	ft::vector<int> my_second;
	ft::vector<int> my_third;

	my_first.assign(7, 100); // 7 ints with a value of 100

	ft::vector<int>::iterator my_it;
	my_it = my_first.begin() + 1;

	my_second.assign(my_it, my_first.end() - 1); // the 5 central values of first

	int my_myints[] = {1776, 7, 4};
	my_third.assign(my_myints, my_myints + 3); // assigning from array.

	std::cout << "My vector:" << std::endl;
	std::cout << "Size of first: " << int(my_first.size()) << '\n';
	std::cout << "Size of second: " << int(my_second.size()) << '\n';
	std::cout << "Size of third: " << int(my_third.size()) << '\n';
	std::cout << "sizes and capacitys" << std::endl;

	std::cout << my_first.capacity() << std::endl;
	std::cout << my_first.size() << std::endl;
	std::cout << my_second.capacity() << std::endl;
	std::cout << my_second.size() << std::endl;
	std::cout << my_third.capacity() << std::endl;
	std::cout << my_third.size() << std::endl;
}

void constructors_test()
{
	std::vector<int> first;
	std::vector<int> second(4, 100);
	std::vector<int> third(second.begin(), second.end());
	std::vector<int> fourth;
	fourth = third;

	int myints[] = {16, 2, 77, 29};
	std::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

	std::cout << "Original vector:" << std::endl;
	std::cout << "The contents of fifth are:";
	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "sizes and capacitys" << std::endl;
	std::cout << first.capacity() << std::endl;
	std::cout << first.size() << std::endl;
	std::cout << second.capacity() << std::endl;
	std::cout << second.size() << std::endl;
	std::cout << third.capacity() << std::endl;
	std::cout << third.size() << std::endl;
	std::cout << fourth.capacity() << std::endl;
	std::cout << fourth.size() << std::endl;
	std::cout << fifth.capacity() << std::endl;
	std::cout << fifth.size() << std::endl;
	//////////////////////////////////////////////////////////////////////////
	ft::vector<int> my_first;
	ft::vector<int> my_second(4, 100);
	ft::vector<int> my_third(my_second.begin(), my_second.end());
	ft::vector<int> my_fourth;
	my_fourth = my_third;

	int myints1[] = {16, 2, 77, 29};
	ft::vector<int> my_fifth(myints1, myints1 + sizeof(myints1) / sizeof(int));

	std::cout << "My vector:" << std::endl;
	std::cout << "The contents of my_fifth are:";
	for (ft::vector<int>::iterator it1 = my_fifth.begin(); it1 != my_fifth.end(); ++it1)
		std::cout << ' ' << *it1;
	std::cout << '\n';
	std::cout << "sizes and capacitys" << std::endl;

	std::cout << my_first.capacity() << std::endl;
	std::cout << my_first.size() << std::endl;
	std::cout << my_second.capacity() << std::endl;
	std::cout << my_second.size() << std::endl;
	std::cout << my_third.capacity() << std::endl;
	std::cout << my_third.size() << std::endl;
	std::cout << my_fourth.capacity() << std::endl;
	std::cout << my_fourth.size() << std::endl;
	std::cout << my_fifth.capacity() << std::endl;
	std::cout << my_fifth.size() << std::endl;
}

int main()
{
	// constructors_test();
	// assign_test();
	// at_test();
	// back_test();
	// begin_test();
	// capacity_test();
	// clear_test();
	// empty_test();
	// end_test();
	// erase_test();
	// front_test();
	// get_allocator_test();
	// insert_test();
	// max_size();
	// operatorass_test();
	// operatorskobki_test();
	// pop_back_test();
	// push_back_test();
	// rbegin_test();
	// rend_test();
	// reserve_test();
	// resize_test();
	// size_test();
	// swap_test();
	// relation_oper_test();
	// swap2_test();
	const_iter_test();
	const_reverse_iter_test();
	
	// while (1);
}