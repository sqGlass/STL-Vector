/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:40:16 by sglass            #+#    #+#             */
/*   Updated: 2021/05/29 12:09:24 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef iterator_h
#define iterator_h

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip> 
#include <exception>

namespace ft
{
template <class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class iterator
{
	public:

		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;



		iterator (void) : point()
		{
		};

		iterator (pointer p)
		{
			point = p;
		};


		template <class _U>
		iterator(const iterator<_U> & obj) : point(obj.point)
		{
		}

		~iterator( void ) //надо что-то ?
		{
			
		};

		iterator&	operator=( iterator const &rhs )
		{
			if (this == &rhs)
				return (*this);
			point = rhs.point;
			return (*this);
		};

		iterator( iterator const &src )
		{
			*this = src;
		};

		// reference		operator*()
		// {
		// 	return (*this->point);
		// };
		
		reference operator*() const  
		{
			return (*this->point);
		};

		// pointer         operator->() 
		// {
		// 	return &(*this->point);
		// };

		pointer         operator->() const
		{
			return &(*this->point);
		};

		iterator&		operator++()
		{
			this->point++;
			return(*this);
		};

		iterator  operator++(int)
		{
			iterator<T> tmp(*this);
			operator++();
			return (tmp);
		};

		iterator&		operator--()
		{
			this->point--;
			return(*this);
		};

		iterator  operator--(int)
		{
			iterator<T> tmp(*this);
			operator--();
			return (tmp);
		};
		
		bool			operator==( iterator const &p2) const
		{
			return (this->point == p2.point);
		};
		
		bool			operator!=( iterator const &p2) const
		{
			return (this->point != p2.point);
		};

		iterator &		operator+=(int  n)
		{
			if (n >= 0) while (n--) this->point++;
			else while (n++) this->point--;
			return (*this);
		};
		
		iterator &		operator-=(int  n)
		{
			this->point += -n;
			return (*this);
		};

		iterator		operator+(int n)
		{
			iterator<value_type> temp(*this); 
			temp.point = temp.point + n;
			return (temp);
		};

		iterator		operator-(int  n)
		{
			iterator<value_type> temp(*this); 
			temp.point = temp.point - n;
			return (temp);
		};

		difference_type		operator-(iterator T2)
		{
			return (this->point - T2.point);
		};

		reference operator[](int index) const
		{
			return(*(point + index));
		};

		// reference operator[](int index)
		// {
		// 	return(*(point + index));
		// };

		reference		operator[](int index)
		{
			return(*(point + index));
		};

		bool			operator<( iterator const &p2) const
		{
			return p2.point - this->point > 0;
		};

		bool			operator>( iterator const &p2) const
		{
			return (p2.point < this->point);
		};

		bool			operator<=( iterator const &p2) const
		{
			return (!(this->point > p2.point));
		};
		bool			operator>=(iterator const &p2) const
		{
			return (!(this->point < p2.point));
		};

		
		pointer point;
};

	template <class T, class Distance, class Pointer, class Reference>
	iterator <T, Distance, Pointer, Reference> operator+(int n, const iterator<T,Distance, Pointer, Reference> & it)
	{
			iterator<T,Distance, Pointer, Reference> temp(it); 
			temp.point = temp.point + n;
			return (temp);
	}
}

#endif