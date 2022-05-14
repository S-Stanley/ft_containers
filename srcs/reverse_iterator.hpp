#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

template <typename T>
class RIterator: public std::iterator<std::random_access_iterator_tag, T>
{
	public:
		RIterator(void): _index(NULL), _position(-1){};
		~RIterator(void){};
		RIterator	operator=(int *new_index)
		{
			if (new_index)
				this->_index = new_index;
			return (*this);
		}
		void		setPosition(unsigned int pos) const
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
		T		getPosition(void)
		{
			return (this->_position);
		}
	private:
		T		*_index;
		T		_position;
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, RIterator<T> &src)
{
	o << src.getIndex();
	return (o);
}

#endif