/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:44:09 by sglass            #+#    #+#             */
/*   Updated: 2021/05/29 12:13:54 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef reverse_iterator_h
#define reverse_iterator_h

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip> 
#include <exception>

namespace ft
{
template <class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class reverse_iterator
{
	public:

		typedef T         _iter;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;



		reverse_iterator (void) : iter()
		{
		};

		explicit reverse_iterator (_iter it) : iter(it)
		{
		}

		template <class _U>
		reverse_iterator(const reverse_iterator<_U> & obj) : iter(obj.iter)
		{
			
		}

		reverse_iterator (reverse_iterator const &rev_it)
		{
			*this = rev_it;
		}



		~reverse_iterator( void ) //надо что-то ?
		{
			
		};

		reverse_iterator&	operator=( reverse_iterator const &rhs )
		{
			if (this == &rhs)
				return (*this);
			iter = rhs.iter;
			return (*this);
		};

		_iter base() const {return iter;}

		typename _iter::value_type&		operator*() const
		{
			_iter tmp = iter;
			return (*--tmp.point);
		};
		

		pointer         operator->() const
		{
			return &(*this->point);
		};

		reverse_iterator&		operator++()
		{
			--iter;
			return(*this);
		};

		reverse_iterator  operator++(int)
		{
			reverse_iterator<T> tmp(*this);
			operator++();
			return (tmp);
		};

		reverse_iterator&		operator--()
		{
			++iter;
			return(*this);
		};

		reverse_iterator  operator--(int)
		{
			reverse_iterator<T> tmp(*this);
			++iter;
			return (tmp);
		};
		
		bool			operator==( reverse_iterator const &p2) const
		{
			return (this->iter == p2.iter);
		};
		
		bool			operator!=( reverse_iterator const &p2) const
		{
			return ((this->iter != p2.iter));
		};

		reverse_iterator &		operator+=(int  n)
		{
			if (n >= 0) while (n--) iter--;
			else while (n++) iter++;
			return (*this);
		};
		
		reverse_iterator &		operator-=(int  n)
		{
			iter -= -n;
			return (*this);
		};

		reverse_iterator		operator+(int n)
		{
			T tmp = iter;
			tmp = tmp - n;
			// iter = iter - n;
			return (reverse_iterator(tmp));
		};

		reverse_iterator		operator-(int  n)
		{
			T tmp = iter;
			tmp = tmp + n;
			// iter = iter + n;
			return (reverse_iterator(tmp));
		};

		difference_type		operator-(const reverse_iterator &T2)
		{
			return (T2.base() - this->base());
		};

		typename _iter::value_type&		operator[](int index) const
		{
			T tmp = iter;
			--tmp;
			return *(tmp.point - index);
		};

		bool			operator<( reverse_iterator const &p2) const
		{
			return p2.base() - this->base() < 0;
		};

		bool			operator>( reverse_iterator const &p2) const
		{
			return (p2.iter > this->iter);
		};

		bool			operator<=( reverse_iterator const &p2) const
		{
			return (!(this->iter < p2.iter));
		};
		bool			operator>=(reverse_iterator const &p2) const
		{
			return (!(this->iter > p2.iter));
		};

		
		_iter iter;
};

	template <class T, class Distance, class Pointer, class Reference>
	reverse_iterator <T, Distance, Pointer, Reference> operator+(int n, const reverse_iterator<T,Distance, Pointer, Reference> & it)
	{
			reverse_iterator<T,Distance, Pointer, Reference> temp(it); 
			temp.iter = temp.iter - n;
			return (temp);
	}
}

#endif