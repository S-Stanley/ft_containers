#ifndef ITERATORS_TRAITS_HPP
#define ITERATORS_TRAITS_HPP

#include <iostream>

#include "../srcs/pair.hpp"

template <typename T, typename K = std::string>
class Iterator: public std::iterator<std::random_access_iterator_tag, T>
{
	public:
		Iterator(void): it(NULL), _index(NULL), _position(0), _keys(NULL), _len(0){};
		virtual ~Iterator(void){};
		Iterator	operator=(int *new_index)
		{
			if (new_index)
				this->_index = new_index;
			this->_position = 0;
			return (*this);
		}
		Iterator	operator=(void	*tmp)
		{
			this->_index = static_cast<T *>(tmp);
			this->_position = 0;
			return (*this);
		}
		void	operator++(int)
		{
			this->_position++;
		}
		void	operator--(int)
		{
			this->_index--;
			this->_position--;
		}
		bool	operator!=(Iterator<T> src)
		{
			if ((src.getPosition()) == this->_position)
				return (false);
			return (true);
		}
		bool	operator!=(Iterator<T> *src)
		{
			if ((src->getPosition()) == this->_position)
				return (false);
			return (true);
		}
		bool	operator==(Iterator<T> src)
		{
			if ((src.getPosition()) == this->_position)
				return (true);
			return (false);
		}
		bool	operator==(Iterator<T> const src) const
		{
			if ((src.getPosition()) == this->_position)
				return (true);
			return (false);
		}
		bool	operator<(Iterator<T> src)
		{
			if (this->_position < src.getPosition())
				return (true);
			return (false);
		}
		bool	operator<(Iterator<T> *src)
		{
			if (this->_position < src->getPosition())
				return (true);
			return (false);
		}
		T		getIndex(void)
		{
			return (this->_index[0]);
		}
		void	*getAddress(void)
		{
			return (this->_index);
		}
		unsigned int	getPosition(void)
		{
			return (this->_position);
		}
		unsigned int	getPosition(void) const
		{
			return (this->_position);
		}
		void	setPosition(unsigned int position)
		{
			this->_position = position;
		}
		void	setArray(T *array, unsigned int len = 0)
		{
			this->_len = len;
			this->_index = array;
		}
		T		*getArray(void)
		{
			T	*arr = this->_index;
			return (arr);
		}
		void	setKeys(K *keys)
		{
			this->_keys = keys;
		}
		bool	isNull(void)
		{
			if (this->_index)
				return (false);
			return (true);
		}
		ft::pair<K, T>	*it;
		K				first;
		T				second;
	private:
		T				*_index;
		unsigned int	_position;
		K				*_keys;
		unsigned int	_len;
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, Iterator<T> &src)
{
	o << src.getArray()[src.getPosition()];
	return (o);
}

#endif
