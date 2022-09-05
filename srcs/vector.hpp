#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <cmath>
#include <typeinfo>
#include <cstddef>

#include "iterators_traits.hpp"
#include "reverse_iterator.hpp"
#include "../srcs/pair.hpp"

namespace ft {

	template <typename T>
	struct iterator_pointor {
		Iterator<T>			*iterator;
		iterator_pointor	*next;
	};

	template <typename T, class Alloc = std::allocator<T> >
	class vector {
		public:

			typedef T					value_type;
			typedef Alloc				allocator_type;
			typedef value_type&			reference;
			typedef const value_type&	const_reference;
			typedef value_type*			pointer;
			typedef const value_type*	const_pointer;
			typedef Iterator<T>*		iterator;
			typedef const Iterator<T>*	const_iterator;
			typedef RIterator<T>		reverse_iterator;
			typedef const RIterator<T>	const_reverse_iterator;
			typedef ptrdiff_t			difference_type;
			typedef unsigned int		size_type;

			vector(void): _tab(NULL), _len(0), _max_cap(0), _it(NULL), _it_const(NULL), _pts(NULL) {};
			virtual ~vector(void)
			{
				ft::iterator_pointor<T>		*tmp;

				if (this->_tab)
					this->clear();
				while (this->_pts)
				{
					tmp = this->_pts->next;
					delete this->_pts->iterator;
					delete this->_pts;
					this->_pts = tmp;
				}
			};
			ft::vector<T>	operator=(const ft::vector<T> &src)
			{
				T	*update = this->get_allocator().allocate(src._len);

				if (this->_tab)
					this->clear();
				for (unsigned int i = 0; i < src._len; i++)
				{
					this->get_allocator().construct(&update[i], src._tab[i]);
				}
				this->_tab = update;
				this->_len = src._len;
				this->_max_cap = src._max_cap;
				return *(this);
			}

			bool	operator==(const ft::vector<T, Alloc> &comp)
			{
				unsigned int i = 0;

				if (this->size() != comp.size())
					return (false);
				while (i != this->_len)
				{
					if (this->_tab[i] != comp._tab[i])
						return (false);
					i++;
				}
				return (true);
			}
			bool	operator!=(const ft::vector<T, Alloc> &comp)
			{
				unsigned int i = 0;

				if (this->size() != comp.size())
					return (true);
				while (i != this->_len)
				{
					if (this->_tab[i] != comp._tab[i])
						return (true);
					i++;
				}
				return (false);
			}
			bool	operator<(const ft::vector<T, Alloc> &comp)
			{
				unsigned int i = 0;

				if (this->size() < comp.size())
					return (true);
				while (i != this->_len)
				{
					if (this->_tab[i] >= comp._tab[i])
						return (false);
					i++;
				}
				return (true);
			}
			bool	operator<=(const ft::vector<T, Alloc> &comp)
			{
				unsigned int i = 0;

				if (this->size() > comp.size())
					return (false);
				while (i != this->_len && i != comp._len)
				{
					if (this->_tab[i] > comp._tab[i])
						return (false);
					i++;
				}
				return (true);
			}
			bool	operator>(const ft::vector<T, Alloc> &comp)
			{
				unsigned int i = 0;

				if (this->size() > comp.size())
					return (true);
				while (i != this->_len)
				{
					if (this->_tab[i] <= comp._tab[i])
						return (false);
					i++;
				}
				return (true);
			}
			bool	operator>=(const ft::vector<T, Alloc> &comp)
			{
				unsigned int i = 0;

				if (this->size() < comp.size())
					return (false);
				while (i != this->_len && i != comp._len)
				{
					if (this->_tab[i] < comp._tab[i])
						return (false);
					i++;
				}
				return (true);
			}

			/* Iterators  */

			iterator		begin(void)
			{
				ft::iterator_pointor<T>		*tmp = this->getIterator();
				tmp->iterator->setArray(this->_tab, this->_len);
				tmp->iterator->setPosition(0);
				return (tmp->iterator);
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
				ft::iterator_pointor<T>		*tmp = this->getIterator();
				tmp->iterator->setArray(this->_tab, this->_len);
				tmp->iterator->setPosition(this->_len);
				return (tmp->iterator);
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
				return (this->get_allocator().max_size());
			}
			void	resize(unsigned int N, T val)
			{
				T *update = this->get_allocator().allocate(N);

				if (N < this->_len)
				{

					for (unsigned int i = 0; i < N; i++)
						this->get_allocator().construct(&update[i], this->_tab[i]);
				}
				else
				{
					unsigned int i = 0;

					while (i < this->_len)
					{
						this->get_allocator().construct(&update[i], this->_tab[i]);
						i++;
					}
					while (i < N)
					{
						this->get_allocator().construct(&update[i], val);
						i++;
					}
				}
				this->get_allocator().deallocate(this->_tab, this->_max_cap);
				this->_tab = update;
				this->_len = N;
				this->_max_cap = N;
			}
			void	resize(unsigned int N)
			{
				T   *update = this->get_allocator().allocate(N);

				if (N < this->_len)
				{

					for (unsigned int i = 0; i < N; i++)
						this->get_allocator().construct(&update[i], this->_tab[i]);
				}
				else
				{
					unsigned int i = 0;

					while (i < this->_len)
					{
						this->get_allocator().construct(&update[i], this->_tab[i]);
						i++;
					}
					while (i < N)
					{
						this->get_allocator().construct(&update[i], 0);
						i++;
					}
				}
				this->get_allocator().deallocate(this->_tab, this->_max_cap);
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
					T   *update = this->get_allocator().allocate(N);
					unsigned int new_len = 0;

					for (unsigned int i = 0; i < this->_len; i++) {
						this->get_allocator().construct(&update[i], this->_tab[i]);
						new_len++;
					}
					this->get_allocator().deallocate(this->_tab, this->_max_cap);
					this->_len = new_len;
					this->_tab = update;
					this->_max_cap = N;
				}
			}

			/* Elements access */

			/* Modifiers */

			void    push_back(const T &val)
			{
				unsigned int new_size = (this->size() * 2) + 1;
				unsigned     i;

				if (this->_max_cap > this->size())
				{
					this->get_allocator().construct(&this->_tab[this->_len], val);
					this->_len++;
				}
				else
				{
					T   *update = this->get_allocator().allocate(new_size);

					for (i = 0; i < this->size(); i++)
						this->get_allocator().construct(&update[i], this->_tab[i]);
					this->get_allocator().construct(&update[i], val);
					if (this->_tab)
						this->get_allocator().deallocate(this->_tab, this->_max_cap);
					this->_tab = update;
					this->_len++;
					this->_max_cap = new_size;
				}
			}
			void    pop_back(void)
			{
				T   *update = this->get_allocator().allocate(this->_len);

				this->_len--;
				this->_max_cap--;
				for (unsigned int i = 0; i < this->_len; i++)
					this->get_allocator().construct(&update[i], this->_tab[i]);
				this->get_allocator().deallocate(this->_tab, this->size());
				this->_tab = update;
			}
			void	clear(void)
			{
				this->get_allocator().deallocate(this->_tab, this->_max_cap);
				this->_len = 0;
				this->_max_cap = 0;
				this->_tab = NULL;
			}
			void	swap(ft::vector<T> &src)
			{
				unsigned int 	tmp_len = this->_len;
				T				*tmp_tab = this->_tab;

				this->_len = src._len;
				this->_tab = src._tab;

				src._len = tmp_len;
				src._tab = tmp_tab;
			}
			void	assign(unsigned int N, const T &val)
			{
				if (N > this->_len)
				{
					this->get_allocator().deallocate(this->_tab);
					T	*update = this->get_allocator().allocate(N);
					this->_len = N;
					this->_max_cap = N;
					for (unsigned int i = 0; i < N; i++)
						this->get_allocator().construct(&update[i], val[i]);
				} else {
					for (unsigned int i = 0; i < N; i++)
						this->get_allocator().construct(&this->_tab[i], val[i]);
				}

			}
			void	assign(std::input_iterator_tag first, std::input_iterator_tag last)
			{
				T	*update = this->get_allocator().allocate(this->_len);
				(void)first;
				(void)last;

				for (unsigned int i = 0; i < this->_len; i++)
					this->get_allocator().construct(&update[i], this->_tab[i]);
				this->get_allocator().deallocate(this->_tab, this->_max_cap);
				this->_tab = update;
			}
			iterator		erase(iterator position)
			{
				T	*update = this->get_allocator().allocate(this->_len -1);
				unsigned int count = 0;

				for (unsigned int i = 0; i < this->_len; i++)
				{
					if (&this->_tab[i] != position->getAddress())
					{
						this->get_allocator().construct(&update[i], this->_tab[i]);
						count++;
					}
				}
				this->get_allocator().deallocate(this->_tab, this->_max_cap);
				this->_tab = update;
				this->_len--;
				this->_max_cap--;
				return (position);
			}
			iterator		erase(iterator first, iterator last)
			{
				T	*update = this->get_allocator().allocate(this->_len - (last->getPosition() - first->getPosition()));
				Iterator<T>	index = new Iterator<T>;
				int	count = 0;

				for (unsigned int i = 0; i < this->_len; i++)
				{
					if (i < first->getPosition() && i > last->getPosition())
					{
						this->get_allocator().construct(&update[i], this->_tab[i]);
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
			T               		*_tab;
			unsigned int    		_len;
			unsigned int			_max_cap;
			iterator				_it;
			const_iterator			_it_const;
			ft::iterator_pointor<T>	*_pts;

            ft::iterator_pointor<T>		*getIterator(void)
            {
				ft::iterator_pointor<T>	*tmp;
				ft::iterator_pointor<T>	*new_node = new ft::iterator_pointor<T>;
				iterator				new_iterator = new Iterator<T>;

				new_node->iterator = new_iterator;
				new_node->next = NULL;
				if (!this->_pts)
				{
					this->_pts = new_node;
					return (new_node);
				}
				tmp = this->_pts;
				while (tmp->next)
				{
					tmp = tmp->next;
				}
				tmp->next = new_node;
				return (new_node);
            }
	};
}


#endif
