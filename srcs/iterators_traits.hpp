#ifndef ITERATORS_TRAITS_HPP
#define ITERATORS_TRAITS_HPP

#include <iostream>

template <typename T, typename K = std::string>
class Iterator: public std::iterator<std::random_access_iterator_tag, T>
{
	public:
		Iterator(void): _index(NULL), _position(-1), _keys(NULL){};
		~Iterator(void){};
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
			std::pair<K, T>	*new_it = new std::pair<K, T>;

			this->_index++;
			this->_position++;
			if (this->_keys && this->_index && this->getPosition() < (sizeof(K)/sizeof(*this->_keys)) && this->getPosition() < sizeof(T)/sizeof(*this->_index)) {
				new_it->first = this->_keys[this->getPosition()];
				new_it->second = this->_index[this->getPosition()];
				this->it = new_it;
			}
		}
		void	operator--(int)
		{
			std::pair<K, T>	*new_it = new std::pair<K, T>;

			this->_index--;
			this->_position--;
			if (this->_keys && this->_index && this->getPosition() <= (sizeof(K)/sizeof(*this->_keys)) && this->getPosition() <= sizeof(T)/sizeof(*this->_index)) {
				new_it->first = this->_keys[this->getPosition()];
				new_it->second = this->_index[this->getPosition()];
				this->it = new_it;
			}
		}
		bool	operator!=(Iterator<T> src)
		{
			if ((src.getPosition() -1) == this->_position)
				return (false);
			return (true);
		}
		bool	operator==(Iterator<T> src)
		{
			if ((src.getPosition() -1) == this->_position)
				return (true);
			return (false);
		}
		bool	operator<(Iterator<T> src)
		{
			if (this->_position < src.getPosition() -1)
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
		void	setPosition(unsigned int position)
		{
			std::pair<K, T>	*new_it = new std::pair<K, T>;

			this->_position = position;
			if (this->_keys && this->_index && this->getPosition() <= (sizeof(K)/sizeof(*this->_keys)) && this->getPosition() <= sizeof(T)/sizeof(*this->_index)) {
				new_it->first = this->_keys[this->getPosition()];
				new_it->second = this->_index[this->getPosition()];
				this->it = new_it;
			}
		}
		void	setArray(T *array)
		{
			this->_index = array;
		}
		T		*getArray(void)
		{
			T	*arr = this->_index;
			return (arr);
		}
		K		*getKeys(void)
		{
			K	*arr = this->_keys;
			std::pair<K, T>	*new_it = new std::pair<K, T>;

			if (this->_keys && this->_index && this->getPosition() <= (sizeof(K)/sizeof(*this->_keys)) && this->getPosition() <= sizeof(T)/sizeof(*this->_index)) {
				new_it->first = this->_keys[this->getPosition()];
				new_it->second = this->_index[this->getPosition()];
				this->it = new_it;
			}
			return (arr);
		}
		void	addToArr(T to_add)
		{
			unsigned int	size = sizeof(T)/sizeof(this->_index);
			unsigned int	i = 0;
			T				*new_arr = new T[size + 1];

			if (!this->_index)
			{
				new_arr[0] = to_add;
				this->_index = new_arr;
			} else {
				while (i != size)
				{
					new_arr[i] = this->_index[i];
					i++;
				}
				new_arr[i] = to_add;
				this->_index = new_arr;
			}
		}
		void	addToKeys(K to_add)
		{
			unsigned int	size = sizeof(K)/sizeof(this->_keys);
			unsigned int	i = 0;
			K				*new_arr = new T[size + 1];

			if (!this->_keys)
			{
				new_arr[0] = to_add;
				this->_keys = new_arr;
			} else {
				while (i != size)
				{
					new_arr[i] = this->_keys[i];
					i++;
				}
				new_arr[i] = to_add;
				this->_keys = new_arr;
			}
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
		std::pair<K, T>	*it;
	private:
		T				*_index;
		unsigned int	_position;
		K				*_keys;
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, Iterator<T> &src)
{
	o << src.getIndex();
	return (o);
}

#endif