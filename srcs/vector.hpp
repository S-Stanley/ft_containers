#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <cmath>
#include <typeinfo>

#include "iterators_traits.hpp"
#include "reverse_iterator.hpp"
#include "../srcs/pair.hpp"

namespace ft {
	template <typename T, class Alloc = std::allocator<T> >

	class vector {
		public:

			typedef T				value_type;
			typedef Alloc			allocator_type;
			typedef Iterator<T>*	iterator;
			typedef const Iterator<T>*	const_iterator;

			vector(void): _tab(NULL), _len(0), _max_cap(0), _it(NULL), _it_const(NULL) {};
			~vector(void)
			{
				if (this->_tab)
					delete[] this->_tab;
				if (this->_it)
					delete this->_it;
			};

			/* Iterators  */

			iterator		begin(void)
			{
				if (this->_it)
					delete this->_it;
				this->_it = new Iterator<T>;
				this->_it[0] = this->_tab;
				return (this->_it);
			}
			const_iterator		begin(void) const
			{
				if (this->_it_const)
					delete this->_it_const;
				this->_it_const = new Iterator<T>;
				this->_it_const = this->_tab;
				return (this->_it_const);
			}
			iterator		end(void)
			{
				if (this->_it)
					delete this->_it;
				this->_it = new Iterator<T>;
				this->_it->setArray(this->_tab);
				this->_it->setPosition(this->_len + 1);
				return (this->_it);
			}
			const_iterator		end(void) const
			{
				if (this->_it_const)
					delete this->_it_const;
				this->_it_const = new Iterator<T>;
				this->_it_const->setArray(this->_tab);
				this->_it_const->setPosition(this->_len + 1);
				return (this->_it_const);
			}
			RIterator<T>			rbegin(void)
			{
				RIterator<T>		index;

				index = this->_tab[this->_len];
				index->setPosition(this->_len);
				return (index);
			}
			const RIterator<T>			rbegin(void) const
			{
				const RIterator<T>		index;

				index = this->_tab[this->_len];
				index->setPosition(this->_len);
				return (index);
			}
			RIterator<T>			rend(void)
			{
				RIterator<T>		index;

				index = this->_tab[0];
				index.setPosition(-1);
				return (index);
			}
			const RIterator<T>			rend(void) const
			{
				const RIterator<T>		index;

				index = NULL;
				index.setPosition(-1);
				return (index);
			}

			/* Capacity */
			unsigned int     size(void) const
			{
				return (this->_len);
			}

			/* Elements access */
			T       &operator[](unsigned int N)
			{
				return (this->_tab[N]);
			}
			T const &operator[](unsigned int N) const
			{
				const T value = this->_tab[N];
				return (value);
			}
			T		&front(void)
			{
				return (this->_tab[0]);
			}
			T const		&front(void) const
			{
				const T value = this->_tab[0];
				return (value);
			}
			T		&back(void)
			{
				return (this->_tab[this->_len -1]);
			}
			T const		&back(void) const
			{
				const T value = this->_tab[this->_len -1];
				return (value);
			}
			T       &at(unsigned int N)
			{
				if (N > this->_len -1)
					throw std::out_of_range("out of range");
				return (this->_tab[N]);
			}
			T const &at(unsigned int N) const
			{
				if (N > this->_len -1)
					throw std::out_of_range("out of range");
				const T value = this->_tab[N];
				return (value);
			}
			unsigned long long	max_size(void) const
			{
				return ((long)std::pow(2, 64))/sizeof(T) -1;
			}
			void	resize(unsigned int N, T val)
			{
				T *update = new T[N];

				if (N < this->_len)
				{

					for (unsigned int i = 0; i < N; i++)
						update[i] = this->_tab[i];
				}
				else
				{
					unsigned int i = 0;

					while (i < this->_len)
					{
						update[i] = this->_tab[i];
						i++;
					}
					while (i < N)
					{
						update[i] = val;
						i++;
					}
				}
				delete[] this->_tab;
				this->_tab = update;
				this->_len = N;
				this->_max_cap = N;
			}
			void	resize(unsigned int N)
			{
				T *update = new T[N];

				if (N < this->_len)
				{

					for (unsigned int i = 0; i < N; i++)
						update[i] = this->_tab[i];
				}
				else
				{
					unsigned int i = 0;

					while (i < this->_len)
					{
						update[i] = this->_tab[i];
						i++;
					}
					while (i < N)
					{
						update[i] = 0;
						i++;
					}
				}
				delete[] this->_tab;
				this->_tab = update;
				this->_len = N;
				this->_max_cap = N;
			}
			unsigned int	capacity(void) const
			{
				return (this->_len);
			}
			bool	empty(void) const
			{
				if (this->_len == 0)
					return (true);
				else
					return (false);
			}
			void	reserve(unsigned int N)
			{
				if (N > this->_max_cap)
				{
					T	*update = new T[N];
					unsigned int new_len = 0;
					for (unsigned int i = 0; i < this->_len; i++) {
						update[i] = this->_tab[i];
						new_len++;
					}
					this->_len = new_len;
					delete[] this->_tab;
					this->_tab = update;
					this->_max_cap = N;
				}
			}

			/* Elements access */

			/* Modifiers */

			void    push_back(const T &val)
			{
				T   *update = new T[this->size() + 1];
				unsigned     i;

				for (i = 0; i < this->size(); i++)
					update[i] = this->_tab[i];
				update[i] = val;
				if (this->_tab)
					delete[] this->_tab;
				this->_tab = update;
				this->_len++;
				this->_max_cap++;
			}
			void    pop_back(void)
			{
				T   *update = new T[this->_len];

				this->_len--;
				this->_max_cap--;
				for (unsigned int i = 0; i < this->_len; i++)
					update[i] = this->_tab[i];
				delete[] this->_tab;
				this->_tab = update;
			}
			void	clear(void)
			{
				this->_len = 0;
				this->_max_cap = 0;
				delete[] this->_tab;
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
					delete[] this->_tab;
					T	*update = new T[N];
					this->_len = N;
					this->_max_cap = N;
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
				(void)first;
				(void)last;

				for (unsigned int i = 0; i < this->_len; i++)
					update[i] = this->_tab[i];
				delete[] this->_tab;
				this->_tab = update;
			}
			iterator		erase(iterator position)
			{
				T	*update = new T[this->_len -1];
				unsigned int count = 0;

				for (unsigned int i = 0; i < this->_len; i++)
				{
					if (&this->_tab[i] != position->getAddress())
					{
						update[count] = this->_tab[i];
						count++;
					}
				}
				delete[] this->_tab;
				this->_tab = update;
				this->_len--;
				this->_max_cap--;
				return (position);
			}
			iterator		erase(iterator first, iterator last)
			{
				T	*update = new T[this->_len - (last->getPosition() - first->getPosition())];
				Iterator<T>	index = new Iterator<T>;
				int	count = 0;

				for (unsigned int i = 0; i < this->_len; i++)
				{
					if (i < first->getPosition() && i > last->getPosition())
					{
						update[count] = this->_tab[i];
						count++;
					}
					if (i < last->getPosition())
						index++;
				}
				return (index);
			}

			/* Allocator */
			allocator_type	get_allocator(void) const
			{
				allocator_type	to_return;
				return (to_return);
			}

		private:
			T               *_tab;
			unsigned int    _len;
			unsigned int	_max_cap;
			iterator	_it;
			const_iterator	_it_const;
	};
}


#endif
