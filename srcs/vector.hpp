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

	template <typename T, class Alloc = std::allocator<T> >
	class vector {
		public:

			typedef T					value_type;
			typedef Alloc				allocator_type;
			typedef value_type&			reference;
			typedef const value_type&	const_reference;
			typedef value_type*			pointer;
			typedef const value_type*	const_pointer;
			typedef Iterator<T>			iterator;
			typedef const Iterator<T>	const_iterator;
			typedef RIterator<T>		reverse_iterator;
			typedef const RIterator<T>	const_reverse_iterator;
			typedef ptrdiff_t			difference_type;
			typedef unsigned int		size_type;

			vector(void): _tab(NULL), _len(0), _max_cap(0){};
			virtual ~vector(void)
			{
				if (this->_tab)
					this->clear();
			};
			ft::vector<T>	&operator=(const ft::vector<T> &src)
			{
				T	*update = this->get_allocator().allocate(src._len);

				if (this->_tab)
					this->clear();
				for (unsigned int i = 0; i < src._len; i++)
				{
					this->get_allocator().construct(&update[i], src._tab[i]);
				}
				if (this->_tab)
					this->get_allocator().deallocate(this->_tab, this->_max_cap);
				this->_tab = update;
				this->_len = src._len;
				this->_max_cap = src._len;
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
				iterator	tmp;
				tmp.setArray(this->_tab, this->_len);
				tmp.setPosition(0);
				return (tmp);
			}
			const_iterator		begin(void) const
			{
				const_iterator	tmp;
				tmp.setArray(this->_tab, this->_len);
				tmp.setPosition(0);
				return (tmp);
			}
			iterator		end(void)
			{
				iterator	tmp;
				tmp.setArray(this->_tab, this->_len);
				tmp.setPosition(this->_len);
				return (tmp);
			}
			const_iterator		end(void) const
			{
				const_iterator	tmp;
				tmp.setArray(this->_tab, this->_len);
				tmp.setPosition(this->_len);
				return (tmp);
			}
			reverse_iterator			rbegin(void)
			{
				reverse_iterator	index;

				index.setIndex(this->_len, this->_tab);
				index.setPosition(this->_len);
				return (index);
			}
			const_reverse_iterator		rbegin(void) const
			{
				const_reverse_iterator	index;

				index.setIndex(this->_len, this->_tab);
				index.setPosition(this->_len);
				return (index);
			}
			reverse_iterator			rend(void)
			{
				reverse_iterator	index;

				index.setIndex(this->_len, this->_tab);
				index.setPosition(0);
				return (index);
			}
			const_reverse_iterator			rend(void) const
			{
				const_reverse_iterator	index;

				index.setIndex(this->_len, this->_tab);
				index.setPosition(0);
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
				return (this->_max_cap);
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
				T   *update = this->get_allocator().allocate(this->_max_cap);

				this->_len--;
				for (unsigned int i = 0; i < this->_len; i++)
					this->get_allocator().construct(&update[i], this->_tab[i]);
				this->get_allocator().deallocate(this->_tab, this->size());
				this->_tab = update;
			}
			iterator	insert(iterator position, const value_type &val)
			{
				T   			*update = this->get_allocator().allocate(this->_len + 1);
				unsigned int	i = 0;

				while (i < position.getPosition() && i < this->_len)
				{
					this->get_allocator().construct(&update[i], this->_tab[i]);
					i++;
				}
				this->get_allocator().construct(&update[i], val);
				i++;
				while (i < this->_len)
				{
					this->get_allocator().construct(&update[i], this->_tab[i - 1]);
					i++;
				}
				if (this->_tab)
					this->get_allocator().deallocate(this->_tab, this->_max_cap);
				this->_tab = update;
				this->_len++;
				this->_max_cap = this->_len + 1;
				return (position);
			}
			void		insert(iterator position, size_type n, const value_type &val)
			{
				unsigned int	new_max_cap = this->_max_cap + n;
				T   			*update = this->get_allocator().allocate(new_max_cap);
				unsigned int	i = 0;
				unsigned int	tab_i = 0;
				unsigned int	new_len = this->_len + n;

				while (i < position.getPosition() && i < this->_len)
				{
					this->get_allocator().construct(&update[tab_i], this->_tab[i]);
					i++;
					tab_i++;
				}
				while (n != 0)
				{
					this->get_allocator().construct(&update[tab_i], val);
					tab_i++;
					n--;
				}
				while (i < this->_len)
				{
					this->get_allocator().construct(&update[tab_i], this->_tab[i]);
					i++;
					tab_i++;
				}
				if (this->_tab)
					this->get_allocator().deallocate(this->_tab, this->_max_cap);
				this->_tab = update;
				this->_len = new_len;
				this->_max_cap = new_max_cap;
			}
			void		insert(iterator position, iterator first, iterator last)
			{
				unsigned int	nb_item_to_add = (last.getPosition() - first.getPosition());
				unsigned int	new_max_cap = this->_max_cap + nb_item_to_add;
				T   			*update = this->get_allocator().allocate(new_max_cap);
				unsigned int	i = 0;
				unsigned int	tab_i = 0;
				unsigned int	new_len = this->_len + nb_item_to_add;

				while (i < position.getPosition() && i < this->_len)
				{
					this->get_allocator().construct(&update[tab_i], this->_tab[i]);
					i++;
					tab_i++;
				}
				while (first.getPosition() != last.getPosition())
				{
					this->get_allocator().construct(&update[tab_i], first.getArray()[first.getPosition()]);
					first++;
					tab_i++;
				}
				while (i < this->_len)
				{
					this->get_allocator().construct(&update[i], this->_tab[tab_i]);
					i++;
					tab_i++;
				}
				if (this->_tab)
					this->get_allocator().deallocate(this->_tab, this->_max_cap);
				this->_tab = update;
				this->_len = new_len;
				this->_max_cap = new_max_cap;
			}
			void	clear(void)
			{
				if (this->_tab != NULL)
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
					this->get_allocator().deallocate(this->_tab, this->_max_cap);
					T	*update = this->get_allocator().allocate(N);
					this->_len = N;
					this->_max_cap = N;
					for (unsigned int i = 0; i < N; i++)
						this->get_allocator().construct(&update[i], val);
					this->_tab = update;
				} else {
					for (unsigned int i = 0; i < N; i++)
						this->get_allocator().construct(&this->_tab[i], val);
				}

			}
			void	assign(iterator first, iterator last)
			{
				T	*update = this->get_allocator().allocate(this->_len);
				(void)first;
				(void)last;

				for (unsigned int i = 0; i < this->_len; i++)
					this->get_allocator().construct(&update[i], this->_tab[i]);
				if (this->_tab)
					this->get_allocator().deallocate(this->_tab, this->_max_cap);
				this->_tab = update;
				this->_max_cap = this->_len;
			}
			iterator		erase(iterator position)
			{
				unsigned int count = 0;
				T	*update = this->get_allocator().allocate(this->_max_cap -1);

				for (unsigned int i = 0; i < this->_len - 1; i++)
				{
					if (&this->_tab[i] != position.getAddress())
					{
						this->get_allocator().construct(&update[i], this->_tab[i]);
						count++;
					}
				}
				if (this->_tab)
					this->get_allocator().deallocate(this->_tab, this->_max_cap);
				this->_tab = update;
				this->_len--;
				this->_max_cap--;
				return (position);
			}
			iterator		erase(iterator first, iterator last)
			{
				T	*update = this->get_allocator().allocate(this->_max_cap - (last.getPosition() - first.getPosition()));
				iterator index = this->begin();
				int	count = 0;
				this->_max_cap = this->_max_cap - (last.getPosition() - first.getPosition());

				for (unsigned int i = 0; i < this->_len; i++)
				{
					if (i < first.getPosition() && i > last.getPosition())
					{
						this->get_allocator().construct(&update[i], this->_tab[i]);
						count++;
					}
					if (i < last.getPosition())
						index++;
				}
				if (this->_tab)
					this->get_allocator().deallocate(this->_tab, this->_max_cap);
				this->_tab = update;
				this->_len = count;
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
	};
}


#endif
