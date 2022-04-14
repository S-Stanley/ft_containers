#ifndef VECTOR_HPP
# define VECTOR_HPP

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
std::ostream	&operator<<(std::ostream &o, Iterator<T> &src)
{
	o << src.getIndex();
	return (o);
}

namespace ft {
	template <typename T>

	class vector {
		public:
			vector(void): _tab(NULL), _len(0) {};
			~vector(void) {};

			/* Iterators  */

			Iterator<T>		begin(void)
			{
				Iterator<T>		index;
				index = this->_tab;
				return (index);
			}

			/* Capacity */

			int     size(void)
			{
				return (this->_len);
			}
			T       &operator[](const unsigned int N)
			{
				return (this->_tab[N]);
			}

			/* Elements access */

			/* Modifiers */

			void    push_back(const T &val)
			{
				T   *update = new T[this->size() + 1];
				int     i;

				for (i = 0; i < this->size(); i++)
					update[i] = this->_tab[i];
				update[i] = val;
				delete this->_tab;
				this->_tab = update;
				this->_len++;
			}
			void    pop_back(void)
			{
				T   *update = new T[this->_len];

				this->_len--;
				for (unsigned int i = 0; i < this->_len; i++)
					update[i] = this->_tab[i];
				delete this->_tab;
				this->_tab = update;
			}
			void	clear(void)
			{
				this->_len = 0;
				delete this->_tab;
				this->_tab = NULL;
			}
			void	swap(ft::vector<T> &a)
			{
				ft::vector<T>	tmp;

				tmp = a;
				a = this;
				this = tmp;
			}
			void	assign(unsigned int N, const T &val)
			{
				if (N > this->_len)
				{
					delete this->_tab;
					T	*update = new T[N];
					this->_len = N;
					for (unsigned int i = 0; i < N; i++)
						update[i] = val[i];
				} else {
					for (unsigned int i = 0; i < N; i++)
						this->_tab[i] = val[i];
				}

			}
			void	assign(std::input_iterator_tag first, std::input_iterator_tag last)
			{
				T	*update = new T[this->_len];

				for (unsigned int i = 0; i < this->_len; i++)
					update[i] = this->_tab[i];
				delete this->_tab;
				std::for_each(update[first], update[last], this->push_back());
			}
			Iterator<T>		erase(Iterator<T> position)
			{
				T	*update = new T[this->_len -1];
				unsigned int count = 0;

				for (unsigned int i = 0; i < this->_len; i++)
				{
					if (&this->_tab[i] != position.getAddress())
					{
						update[count] = this->_tab[i];
						count++;
					}
				}
				delete this->_tab;
				this->_tab = update;
				this->_len--;
				return (position);
			}
			Iterator<T>		erase(Iterator<T> first, Iterator<T> last)
			{
				T	*update = new T[this->_len - (last.getPosition() - first.getPosition())];
				Iterator<T>	index;
				int	count = 0;

				for (unsigned int i = 0; i < this->_len; i++)
				{
					if (i < first.getPosition() && i > last.getPosition())
					{
						update[count] = this->_tab[i];
						count++;
					}
					if (i < last.getPosition())
						index++;
				}
				return (index);
			}

			/* Allocator */

		private:
			T               *_tab;
			unsigned int    _len;
	};
}


#endif