#ifndef ITERATORS_TRAITS_HPP
#define ITERATORS_TRAITS_HPP

template <typename T>
class Iterator: public std::iterator<std::random_access_iterator_tag, T>
{
	public:
		Iterator(void): _index(NULL), _position(-1){};
		~Iterator(void){};
		Iterator	operator=(int *new_index)
		{
			if (new_index)
				this->_index = new_index;
			this->_position = 0;
			return (*this);
		}
		void	operator++(int)
		{
			this->_index++;
			this->_position++;
		}
		void	operator--(int)
		{
			this->_index--;
			this->_position--;
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
		T		getPosition(void)
		{
			return (this->_position);
		}
		void	setPosition(T position)
		{
			this->_position = position;
		}
		void	setArray(T *array)
		{
			this->_index = array;
		}
	private:
		T		*_index;
		T		_position;
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, Iterator<T> &src)
{
	o << src.getIndex();
	return (o);
}

#endif