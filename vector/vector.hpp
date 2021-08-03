/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:02:44 by sglass            #+#    #+#             */
/*   Updated: 2021/05/29 11:59:18 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip> 
#include <exception>
#include "iterator.hpp"
// #include "const_iterator.hpp"
#include "reverse_iterator.hpp"
// #include "const_reverse_iterator.hpp"

namespace ft
{
template <class _Tp, class _Allocator = std::allocator<_Tp> >
class vector
{
    public:
		typedef		_Tp							value_type;
		typedef		_Allocator					allocator_type;
		typedef  	value_type&					reference;
		typedef 	const  value_type&			const_reference;
		typedef 	std::size_t					size_type;
		typedef 	std::ptrdiff_t				difference_type;
		typedef 	value_type*					pointer;
		typedef 	const value_type*			const_pointer;
		typedef	typename ft::iterator<value_type>	iterator;
		typedef	typename ft::iterator<const value_type>	const_iterator;
		// typedef	typename ft::const_iterator<value_type>	const_iterator;
		typedef	typename ft::reverse_iterator<iterator>	reverse_iterator;
		typedef	typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		// typedef	typename ft::const_reverse_iterator<iterator>	const_reverse_iterator;
		

		template <bool, typename T = void>
		struct enable_if
		{};

		template <typename T>
		struct enable_if<true, T> {
		typedef T type;
		};


        explicit vector (const allocator_type& alloc = allocator_type());
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
		template <class InputIterator>
        vector (InputIterator first, InputIterator last,
                const allocator_type& alloc = allocator_type(), typename enable_if<!(std::numeric_limits<InputIterator>::is_integer), InputIterator>::type* = 0);
		vector (const vector& x);
		~vector();
		vector& operator= (const vector& x);
		reference operator[] (size_type n);
		const_reference operator[] (size_type n) const;

		void swap (vector& x);
		void resize (size_type n, value_type val = value_type());
		void reserve (size_type n);
		void pop_back();
		size_type max_size() const;
		template <class InputIterator>
   		void insert (iterator position, InputIterator first, InputIterator last,
		   	typename enable_if<!(std::numeric_limits<InputIterator>::is_integer), InputIterator>::type* = 0);
		void insert (iterator position, size_type n, const value_type& val);
		iterator insert (iterator position, const value_type& val);
		allocator_type get_allocator() const;
		reference front();
		const_reference front() const;
		iterator erase (iterator first, iterator last);
		iterator erase (iterator position);
		bool empty() const;
		size_type capacity() const;
		const_reference back() const;
		reference back();
		void assign (size_type n, const value_type& val);
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last, typename enable_if<!(std::numeric_limits<InputIterator>::is_integer), InputIterator>::type* = 0);
		void clear();
		void push_back (const value_type& val);
		size_type size() const;
		reference at(size_type n);
		const_reference at (size_type n) const;
		const_reverse_iterator rbegin() const;
		reverse_iterator rbegin();
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

    private:
		pointer arr;
		allocator_type myAlloc;

        size_type sizeofArr;
		size_type _capacity;
		
};


template <class _Tp, class _Allocator>
vector <_Tp, _Allocator>::vector(const allocator_type& alloc): myAlloc(alloc)
{
	arr = 0;
	sizeofArr = 0;
	_capacity = 0;
}

template <class _Tp, class _Allocator>
vector <_Tp, _Allocator>:: vector(size_type n, const value_type& val, const allocator_type& alloc): myAlloc(alloc)
{
	if (n == 0)
		return;
	sizeofArr = n;
	_capacity = n;
	arr = myAlloc.allocate(n);
	for(size_t i = 0; i < n; i++)
	{
		myAlloc.construct(&arr[i], val);
	}
}

template<class _Tp, class _Allocator>
template <class InputIterator>
vector<_Tp, _Allocator>::vector (InputIterator first, InputIterator last, const allocator_type& alloc, typename enable_if<!(std::numeric_limits<InputIterator>::is_integer), InputIterator>::type*) :myAlloc(alloc)
{
	_capacity = 0;
	sizeofArr = 0;
	assign(first, last);
}				


template <class _Tp, class _Allocator>
vector <_Tp, _Allocator>:: vector (const vector& x)
{
	sizeofArr = x.sizeofArr;
	_capacity = x.sizeofArr;   // original ne copiruet capas?
	myAlloc = allocator_type(x.myAlloc);  // pravilniy constructor?
	if (x.sizeofArr != 0)
	{
		arr = myAlloc.allocate(x.sizeofArr);
		for(size_t i = 0; i < x.sizeofArr; i++)
		{
			myAlloc.construct(&arr[i], x.arr[i]);
		}
	}
	
}

template <class _Tp, class _Allocator>
vector <_Tp, _Allocator>:: ~vector()
{
	clear();
	if (_capacity != 0)
		myAlloc.deallocate(arr, _capacity);	
}

template <class _Tp, class _Allocator>
vector<_Tp, _Allocator>& vector <_Tp, _Allocator>::operator= (const vector& x)
{
	size_type i = 0;
	if (sizeofArr > 0)
	{
		clear();
		myAlloc.deallocate(arr, _capacity);
	}
	myAlloc = x.myAlloc;
	sizeofArr = x.sizeofArr;
	_capacity = x._capacity;
	if (x.sizeofArr == 0)
		return (*this);
	arr = myAlloc.allocate(x._capacity);
	while(i < x.sizeofArr)
	{
		myAlloc.construct(&arr[i], x.arr[i]);
		i++;
	}
	return(*this);
}


template <class _Tp, class _Allocator>
typename vector <_Tp, _Allocator>::reference vector <_Tp, _Allocator>::operator[] (size_type n)
{
	return(arr[n]);
}

template <class _Tp, class _Allocator>
typename vector <_Tp, _Allocator>::const_reference vector <_Tp, _Allocator>::operator[] (size_type n) const
{
	return(arr[n]);
}

template <class _Tp, class _Allocator>
typename vector <_Tp, _Allocator>::reference vector <_Tp, _Allocator>::at(size_type n)
{
	if (n >= sizeofArr)
		throw std::out_of_range("out of range");
	else
	{
		return (arr[n]);
	}
}
template <class _Tp, class _Allocator>
typename vector <_Tp, _Allocator>::const_reference vector <_Tp, _Allocator>::at (size_type n) const
{
	if (n >= sizeofArr)
		throw std::out_of_range("out of range");
	else
	{
		return (arr[n]);
	}
}

template <class _Tp, class _Allocator>
typename vector <_Tp, _Allocator>::iterator vector <_Tp, _Allocator>::begin(void) //chto esli elementov net
{
	return (iterator(&arr[0]));
	// return &arr[0];
}

template <class _Tp, class _Allocator>
typename vector <_Tp, _Allocator>::reverse_iterator vector <_Tp, _Allocator>::rbegin(void)
{
	return(reverse_iterator(iterator(&arr[sizeofArr])));
}


template <class _Tp, class _Allocator>
typename vector <_Tp, _Allocator>::const_reverse_iterator vector <_Tp, _Allocator>::rbegin(void) const
{
	return(const_reverse_iterator(iterator(&arr[sizeofArr])));
}


template <class _Tp, class _Allocator>
typename vector <_Tp, _Allocator>::const_iterator vector <_Tp, _Allocator>::begin(void) const
{
	return (const_iterator(&arr[0]));
}

template <class _Tp, class _Allocator>
typename vector <_Tp, _Allocator>::iterator vector <_Tp, _Allocator>::end(void)
{
	return (iterator(&arr[sizeofArr]));
}

template <class _Tp, class _Allocator>
typename vector <_Tp, _Allocator>::reverse_iterator vector <_Tp, _Allocator>::rend(void)
{
	return(reverse_iterator(iterator(&arr[0])));
	// return (reverse_iterator(&arr[0] - 1));
}

template <class _Tp, class _Allocator>
typename vector <_Tp, _Allocator>::const_reverse_iterator vector <_Tp, _Allocator>::rend(void) const
{
	return(const_reverse_iterator(iterator(&arr[0])));
	// return (reverse_iterator(&arr[0] - 1));
}

template <class _Tp, class _Allocator>
typename vector <_Tp, _Allocator>::const_iterator vector <_Tp, _Allocator>::end(void) const
{
	
	return (const_iterator(&arr[sizeofArr]));
}

template <class _Tp, class _Allocator>
typename vector <_Tp, _Allocator>::size_type vector <_Tp, _Allocator>::size(void) const
{
	return (sizeofArr);
}

template <class _Tp, class _Allocator>
void	vector <_Tp, _Allocator>::push_back(const value_type& val) //umnojat copacity posle iteracii?
{
	pointer temp;
	if (sizeofArr == 0 && _capacity == 0)
	{
		sizeofArr = 1;
		_capacity = 1;
		arr = myAlloc.allocate(1);
		myAlloc.construct(&arr[0], val);
	}
	else
	{
		size_type i = 0;
		size_type tmpsize = sizeofArr;
		size_type oldcapacity = _capacity;
		iterator it(&arr[0]);
		iterator it2(&arr[sizeofArr]);
		if (sizeofArr + 1 > _capacity)
		{
			temp = myAlloc.allocate((sizeofArr) * 2);
			_capacity = (sizeofArr ) * 2;
			while (it < it2)
			{
				myAlloc.construct(&temp[i], arr[i]);
				i++;
				it++;
			}
			myAlloc.construct(&temp[i], val);
			tmpsize++;
			clear();
			if (oldcapacity != 0)
				myAlloc.deallocate(arr, oldcapacity);
			sizeofArr = tmpsize;
			arr = temp;
		}
		else
		{
			myAlloc.construct(&arr[sizeofArr], val);
			sizeofArr++;
		}
	}
}

template <class _Tp, class _Allocator>
void	vector <_Tp, _Allocator>::clear()
{
	size_type i = 0;
	while(i < sizeofArr)
	{
		myAlloc.destroy(&arr[i]);
		i++;
	}
	sizeofArr = 0;
}

template <class _Tp, class _Allocator>
template <class InputIterator>

void vector <_Tp, _Allocator>::assign (InputIterator first, InputIterator last, typename enable_if<!(std::numeric_limits<InputIterator>::is_integer), InputIterator>::type*)
{
	iterator it(first);
	iterator it2(last);
	size_type i = 0;
	clear();
	if (it2 - it > (difference_type)_capacity)
	{
		if (_capacity != 0)
			myAlloc.deallocate(arr, _capacity);  //nado li dealocate;
		arr = myAlloc.allocate(it2 - it);
		_capacity = it2 - it;
	}
	while (it < it2)
	{
		myAlloc.construct(&arr[i], *it);
		it++;
		i++;
	}
	sizeofArr = it2 - first;
}

template <class _Tp, class _Allocator>
void vector<_Tp, _Allocator>::assign (size_type n, const value_type& val)
{
	size_type i = 0;
	clear();
	if (n > _capacity)
	{
		if (_capacity != 0)
			myAlloc.deallocate(arr, _capacity);  //nado li dealocate;
		arr = myAlloc.allocate(n);
		_capacity = n;
	}
	while (i < n)
	{
		myAlloc.construct(&arr[i], val);
		i++;
	}
	sizeofArr = n;
}


template <class _Tp, class _Allocator>
typename vector<_Tp, _Allocator>::reference vector<_Tp, _Allocator>::back()
{
	return(arr[sizeofArr - 1]);
}

template <class _Tp, class _Allocator>
typename vector<_Tp, _Allocator>::const_reference vector<_Tp, _Allocator>::back() const
{
	return(arr[sizeofArr - 1]);
}


template <class _Tp, class _Allocator>
typename vector<_Tp, _Allocator>::size_type vector<_Tp, _Allocator>::capacity() const
{
	return(_capacity);
}

template <class _Tp, class _Allocator>
bool vector<_Tp, _Allocator>::empty() const
{
	return(sizeofArr == 0);
}

template <class _Tp, class _Allocator>
typename vector<_Tp, _Allocator>::iterator vector<_Tp, _Allocator>::erase(iterator position)
{
	size_type saveInd = position - begin();
	myAlloc.destroy(&arr[position - begin()]);
	while (position != end() - 1)
	{
		myAlloc.construct(&arr[position - begin()], *(position + 1));
		myAlloc.destroy(&arr[*(position + 1)]);
		position++;
	}
	sizeofArr--;
	return(iterator(&arr[saveInd]));
}

template <class _Tp, class _Allocator>
typename vector<_Tp, _Allocator>::iterator vector<_Tp, _Allocator>::erase(iterator first, iterator last)
{
	iterator saveit(first);
	iterator saveit2(first);
	size_type newsizeofarr = sizeofArr - (last - first);
	while(first < last)
	{
		myAlloc.destroy(&arr[first - begin()]);
		first++;
	}
	while (last < end())
	{
		myAlloc.construct(&arr[saveit - begin()], *(last));
		myAlloc.destroy(&arr[last - begin()]);
		saveit++;
		last++;
	}
	sizeofArr = newsizeofarr;
	return (saveit2);
	
}


template<class _Tp, class _Allocator>
typename vector<_Tp, _Allocator>::reference vector<_Tp, _Allocator>::front() 
{
	return (arr[0]);
}


template<class _Tp, class _Allocator>
typename vector<_Tp, _Allocator>::const_reference vector<_Tp, _Allocator>::front() const
{
	return(arr[0]);
}


template<class _Tp, class _Allocator>
typename vector<_Tp, _Allocator>::allocator_type vector<_Tp, _Allocator>::get_allocator() const
{
	// _A
	return(allocator_type(myAlloc));
}


template<class _Tp, class _Allocator>
typename vector<_Tp, _Allocator>::iterator vector<_Tp, _Allocator>::insert(iterator position, const value_type& val)
{
	pointer temp;
	size_type i = 0;
	size_type tmpsize = sizeofArr;
	size_type oldcapacity = _capacity;
	iterator it(&arr[0]);
	iterator it2(position);
	difference_type ret = position - begin();
	if (sizeofArr + 1 > _capacity)
	{
		temp = myAlloc.allocate(sizeofArr * 2);
		_capacity = sizeofArr * 2;
		while(it < position)
		{
			myAlloc.construct(&temp[i], arr[i]);
			i++;
			it++;
		}
		myAlloc.construct(&temp[i], val);
		i++;
		while(it < end())
		{
			myAlloc.construct(&temp[i], arr[i - 1]);
			i++;
			it++;
		}
		tmpsize++;
		clear();
		if (oldcapacity != 0)
			myAlloc.deallocate(arr, oldcapacity);
		sizeofArr = tmpsize;
		arr = temp;
	}
	else
	{
		value_type tmp = arr[it2 - begin()];
		myAlloc.destroy(&arr[it2 - begin()]);
		myAlloc.construct(&arr[it2 - begin()], val);
		it2++;
		while (it2 < end() + 1)
		{
			value_type tmp2 = arr[it2 - begin()];
			myAlloc.destroy(&arr[it2 - begin()]);
			myAlloc.construct(&arr[it2 - begin()], tmp);
			tmp = tmp2;
			it2++;
		}
		sizeofArr++;
	}
	return(iterator(&arr[ret]));
}


template<class _Tp, class _Allocator>
void vector<_Tp, _Allocator>::insert(iterator position, size_type n, const value_type& val)
{
	pointer temp;
	size_type i = 0;
	size_type j = 0;
	size_type tmpsize = sizeofArr;
	size_type oldcapacity = _capacity;
	iterator it(&arr[0]);
	iterator it2(position);

	if (sizeofArr + n > _capacity)
	{
		temp = myAlloc.allocate(sizeofArr + n);
		_capacity = sizeofArr + n;

		while(it < position)
		{
			myAlloc.construct(&temp[i], arr[i]);
			i++;
			it++;
		}

		while (j < n)
		{
			myAlloc.construct(&temp[i], val);
			i++;
			j++;
		}
		while(it < end())
		{
			myAlloc.construct(&temp[i], arr[i - n]);
			i++;
			it++;
		}
		clear();
		if (oldcapacity != 0)
			myAlloc.deallocate(arr, oldcapacity);
		sizeofArr = tmpsize + n;
		arr = temp;
	}
	else
	{
		j = sizeofArr - 1;
		i = 0;
		while(it2 < end())
		{
			myAlloc.construct(&arr[j + n], arr[j]);
			myAlloc.destroy(&arr[j]);
			j--;
			it2++;
		}
		while(i < n)
		{
			myAlloc.construct(&arr[position - begin()], val);
			i++;
			position++;
		}
		sizeofArr = sizeofArr + n;
	}
}

template<class _Tp, class _Allocator>
template <class InputIterator>
void vector<_Tp, _Allocator>::insert(iterator position, InputIterator first, InputIterator last, typename enable_if<!(std::numeric_limits<InputIterator>::is_integer), InputIterator>::type*)
{
	pointer temp;
	long i = 0;
	long j = 0;
	size_type tmpsize = sizeofArr;
	size_type oldcapacity = _capacity;
	iterator it(&arr[0]);
	iterator it2(position);
	difference_type dif = last - first;
	if (sizeofArr + dif > _capacity)
	{
		temp = myAlloc.allocate(sizeofArr + dif);
		_capacity = sizeofArr + dif;

		while(it < position)
		{
			myAlloc.construct(&temp[i], arr[i]);
			i++;
			it++;
		}

		while (first < last)
		{
			myAlloc.construct(&temp[i], *first);
			i++;
			first++;
		}
		while(it < end())
		{
			myAlloc.construct(&temp[i], arr[i - dif]);
			i++;
			it++;
		}
		clear();
		if (oldcapacity != 0)
			myAlloc.deallocate(arr, oldcapacity);
		sizeofArr = tmpsize + dif;
		arr = temp;
	}
	else
	{
		j = sizeofArr - 1;
		i = 0;
		while(it2 < end())
		{
			myAlloc.construct(&arr[j + dif], arr[j]);
			myAlloc.destroy(&arr[j]);
			j--;
			it2++;
		}
		while(first < last)
		{
			myAlloc.construct(&arr[position - begin()], *(first));
			first++;
			position++;
		}
		sizeofArr = sizeofArr + dif;
	}
}

template<class _Tp, class _Allocator>
typename vector<_Tp, _Allocator>::size_type vector<_Tp, _Allocator>::max_size() const
{
	return(myAlloc.max_size());
}


template<class _Tp, class _Allocator>
void vector<_Tp, _Allocator>::pop_back()
{
	if (sizeofArr == 0)
		return ;
	myAlloc.destroy(&arr[sizeofArr - 1]);
	sizeofArr--;
}

template<class _Tp, class _Allocator>
void vector<_Tp, _Allocator>::reserve (size_type n)
{

	size_type tmpsizeofArr = sizeofArr;
	pointer tmp;
	if (_capacity >= n)
		return;
	tmp = myAlloc.allocate(n);
	for(size_t i = 0; i < sizeofArr; i++)
	{
		myAlloc.construct(&tmp[i], arr[i]);
	}
	if (sizeofArr > 0)
	{
		clear();
		if (_capacity != 0)
			myAlloc.deallocate(arr, _capacity);
	}
	sizeofArr = tmpsizeofArr;
	_capacity = n;
	arr = tmp;
	
}

template<class _Tp, class _Allocator>
void vector<_Tp, _Allocator>::resize (size_type n, value_type val)
{
	if (n == 0) // zashita na otricat n
	{
		clear();
		return;
	}
	if (n == sizeofArr)
		return;
	if (n < sizeofArr)  //proverit!!
	{
		while(n < sizeofArr)
		{
			myAlloc.destroy(&arr[sizeofArr - 1]);
			sizeofArr--;
		}
	}
	else if (n > sizeofArr && n <= _capacity)
	{
		while(n > sizeofArr)
		{
			myAlloc.construct(&arr[sizeofArr], val);
			sizeofArr++;
		}
	}
	else
	{
		size_type tmpsizeofArr = sizeofArr;
		pointer tmp;
		tmp = myAlloc.allocate(n);
		for(size_t i = 0; i < sizeofArr; i++)
		{
			myAlloc.construct(&tmp[i], arr[i]);
		}
		while(n > tmpsizeofArr)
		{
			myAlloc.construct(&tmp[tmpsizeofArr], val);
			tmpsizeofArr++;
		}
		if (sizeofArr > 0)
		{
			clear();
			if (_capacity != 0)
				myAlloc.deallocate(arr, _capacity);
		}
		sizeofArr = tmpsizeofArr;
		_capacity = n;
		arr = tmp;
	}

}

template<class _Tp, class _Allocator>
void vector<_Tp, _Allocator>::swap (vector& x)
{
	pointer tmp_arr = x.arr;
	size_type tmp_sizeofArr = x.sizeofArr;
	size_type tmp__capacity = x._capacity;
	allocator_type tmp_myAlloc = x.myAlloc;

	x.arr = arr;
	x.sizeofArr = sizeofArr;
	x._capacity = _capacity;
	x.myAlloc = myAlloc;

	arr = tmp_arr;
	sizeofArr = tmp_sizeofArr;
	_capacity = tmp__capacity;
	myAlloc = tmp_myAlloc;
	
}

template<class _Tp, class _Allocator>
bool operator== (const vector<_Tp,_Allocator>& lhs, const vector<_Tp,_Allocator>& rhs)
{	
	typename vector<_Tp, _Allocator>::const_iterator it1(lhs.begin());
	typename vector<_Tp, _Allocator>::const_iterator it2(lhs.end());
	typename vector<_Tp, _Allocator>::const_iterator itrhs(rhs.begin());
	if (lhs.size() != rhs.size())
		return (false);
	while(it1 != it2)
	{
		if (!(*it1 == *itrhs))
			return (false);
		++it1;
		++itrhs;
	}
	return (true);

}

template<class _Tp, class _Allocator>
bool operator!= (const vector<_Tp,_Allocator>& lhs, const vector<_Tp,_Allocator>& rhs)
{
	return(!(lhs == rhs));
}

template<class _Tp, class _Allocator>
bool operator< (const vector<_Tp,_Allocator>& lhs, const vector<_Tp,_Allocator>& rhs)
{
	typename vector<_Tp, _Allocator>::const_iterator it1(lhs.begin());
	typename vector<_Tp, _Allocator>::const_iterator it2(lhs.end());
	typename vector<_Tp, _Allocator>::const_iterator itrhs(rhs.begin());
	while(it1 != it2)
	{
		if (itrhs == rhs.end() || *itrhs < *it1)
			return(false);
		else if (*it1 < *itrhs)
			return(true);
		++it1;
		++itrhs;
	}
	 return (itrhs!=rhs.end());
}

template<class _Tp, class _Allocator>
bool operator> (const vector<_Tp,_Allocator>& lhs, const vector<_Tp,_Allocator>& rhs)
{
	return(rhs < lhs);
}

template<class _Tp, class _Allocator>
bool operator<= (const vector<_Tp,_Allocator>& lhs, const vector<_Tp,_Allocator>& rhs)
{
		return(!(rhs<lhs));
}

template<class _Tp, class _Allocator>
bool operator>= (const vector<_Tp,_Allocator>& lhs, const vector<_Tp,_Allocator>& rhs)
{
		return(!(lhs<rhs));
}

template<class _Tp, class _Allocator>
void swap (vector<_Tp,_Allocator>& x, vector<_Tp,_Allocator>& y)
{
	x.swap(y);
}

}
# endif