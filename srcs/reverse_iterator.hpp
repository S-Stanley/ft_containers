#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iostream>

#include "../srcs/pair.hpp"


template <typename T, typename K = std::string>
class RIterator: public std::iterator<std::random_access_iterator_tag, T>
{
	public:
		RIterator(void): _index(NULL), _position(-1), _keys(NULL){};
		virtual ~RIterator(void){
			// delete[] this->_index;
		};
		RIterator<T>	operator=(int *new_index)
		{
			if (new_index)
				this->_index = new_index;
			return (*this);
		}
		RIterator<T>	operator=(void	*tmp)
		{
			this->_index = static_cast<T *>(tmp);
			this->_position = 0;
			return (*this);
		}
		bool		operator!=(RIterator<T> comp)
		{
			return (this->getPosition() != comp.getPosition());
		}
		void		setPosition(unsigned int pos)
		{
			this->_position = pos;
		}
		void	operator++(int)
		{
			this->_index--;
			this->_position--;
		}
		void	operator--(int)
		{
			if (this->_position != -1)
				this->_index++;
			this->_position++;
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
		void	setIndex(unsigned int len = 0, T *tmp = NULL)
		{
			unsigned int    i = 0;
			T   arr_values[len];
			unsigned int tmp_len = len - 1;

			while (tmp_len >  0)
			{
				arr_values[i] = tmp[i];
				i++;
				tmp_len--;
			}
			this->setPosition(len - 1);
			this->_index = arr_values;
		}
		void	setKeys(K *new_keys)
		{
			if (this->_keys)
				delete this->_keys;
			this->_keys = new_keys;
		}
		T		*getArray(void)
		{
			return (this->_index);
		}
		K		*getKeys(void)
		{
			K	*arr = this->_keys;
			return (arr);
		}
	private:
		T				*_index;
		unsigned int	_position;
		K				*_keys;
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, RIterator<T> &src)
{
	o << src.getArray()[src.getPosition() - 1];
	return (o);
}

#endif
