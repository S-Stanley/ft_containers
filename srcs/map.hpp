#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <limits>
#include "iterators_traits.hpp"
#include "reverse_iterator.hpp"
#include "../srcs/pair.hpp"

namespace ft {

    template <typename K, typename T>
    struct map_pointer{
        K   first;
        T   second;
    };

    template <typename K, typename T>
    struct map_pointer_lst{
        map_pointer<K, T>       *lst;
        map_pointer_lst<K, T>   *next;
    };

    template <typename T, typename K = std::string, class Alloc = std::allocator<ft::pair<K, T> > >
    class iterator_map
    {
        public:
            typedef Alloc   allocator_type;

            iterator_map(): _values(NULL), _position(0), _lst(NULL), _reverse(false){
	    };
            virtual ~iterator_map()
            {
            };

            void    setValues(ft::pair<K, T> *data){
            	if (data != NULL)
			this->_values = data;
	    }
            ft::map_pointer<K, T> *operator->(void)
            {
                return (&this->it);
            }
            bool    operator!=(iterator_map<K, T> src)
            {
                if (this->getPosition() != src.getPosition())
                    return (true);
                return (false);
            }
            bool    operator<(iterator_map<K, T> src)
            {
                return (src.getPosition() != this->getPosition());
            }
            void    operator++(int){
                ft::pair<K, T>    *tmp;
                unsigned int            tmp_position;

                if (this->_reverse)
                {
                    this->_position--;
                    tmp_position = this->_position;
                    tmp = this->_values;
                    if (this->_values != NULL)
                    {
                        while (tmp)
                        {
                            if (tmp_position == 0)
                                break;
                            tmp = tmp->next;
                            tmp_position--;
                        }
                        if (tmp) {
                            this->it.first = tmp->first;
                            this->it.second = tmp->second;
                        }
                    }
                }
                else
                {
                    this->_position++;
                    tmp_position = this->_position;
                    tmp = this->_values;
                    if (this->_values != NULL)
                    {
                        while (tmp)
                        {
                            if (tmp_position == 0)
                                break;
                            tmp = tmp->next;
                            tmp_position--;
                        }
                        if (tmp) {
                            this->it.first = tmp->first;
                            this->it.second = tmp->second;
                        }
                    }
                }
            }
            void    operator--(int){
                ft::pair<K, T>    *tmp;
                unsigned int            tmp_position;

                if (this->_reverse)
                {
                    this->_position++;
                    tmp_position = this->_position;
                    tmp = this->_values;
                    if (this->_values != NULL)
                    {
                        while (tmp)
                        {
                            if (tmp_position == 0)
                                break;
                            tmp = tmp->next;
                            tmp_position--;
                        }
                        if (tmp) {
                            this->it.first = tmp->first;
                            this->it.second = tmp->second;
                        }
                    }
                }
                else
                {
                    this->_position--;
                    tmp_position = this->_position;
                    tmp = this->_values;
                    if (this->_values != NULL)
                    {
                        while (tmp)
                        {
                            if (tmp_position == 0)
                                break;
                            tmp = tmp->next;
                            tmp_position--;
                        }
                        if (tmp) {
                            this->it.first = tmp->first;
                            this->it.second = tmp->second;
                        }
                    }
                }
            }
            unsigned int    getPosition(void){
                return (this->_position);
            }
            void            setPosition(unsigned int position){
                ft::pair<K, T>    *tmp;

                this->_position = position;
                tmp = this->_values;
                if (tmp)
                {
                    while (tmp)
                    {
                        if (position == 0)
                            break;
                        tmp = tmp->next;
                        position--;
                    }
                    if (tmp) {
                        this->it.first = tmp->first;
                        this->it.second = tmp->second;
                    }
                }
            }
            void    setReverse(void)
            {
                this->_reverse = true;
            }
            bool    getReverse(void)
            {
                return (this->_reverse);
            }
        protected:
            allocator_type  get_allocator(void) const {
                allocator_type  alloc;
                return (alloc);
            }
        private:
            ft::pair<K, T>              *_values;
            unsigned int                _position;
            ft::map_pointer<K, T>       it;
            ft::map_pointer_lst<K, T>   *_lst;
            bool                        _reverse;

            ft::pair<K, T>    *new_node(K key, T value)
            {
                ft::pair<K, T>    *item = this->get_allocator().allocate(1);
                ft::pair<K, T>    val;


                val.first = key;
                val.second = value;
                val.next = NULL;
                val.previous = NULL;
                this->get_allocator().construct(item, val);
                return (item);
            }
    };

    template <typename T, typename K>
    class value_compare
    {
        public:
            bool operator() (ft::iterator_map<T, K> x, ft::iterator_map<T, K> y)
              {
                return (x->first < y->first);
              }
    };

    template <typename T>
    struct list_iterator
    {
        iterator_map<T>     iterator;
        list_iterator<T>    *next;
    };

    template <typename Key, typename T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<Key, T> > >
    class map {
        public:
            typedef Key                             key_type;
            typedef T                               mapped_type;
            typedef std::pair<const Key, T>         value_type;
            typedef Compare                  	    key_compare;
            typedef ft::value_compare<Key, T>       value_compare;
            typedef Alloc                           allocator_type;
            typedef value_type&                     reference;
            typedef const value_type&               const_reference;
            typedef value_type*                     pointer;
            typedef const value_type*               const_pointer;
            typedef iterator_map<T, Key>            iterator;
            typedef iterator_map<T, Key>            const_iterator;
            typedef iterator_map<T, Key>            reverse_iterator;
            typedef const iterator_map<T, Key>      const_reverse_iterator;
            typedef ptrdiff_t                       difference_type;
            typedef size_t                          size_type;

            map(void): _values(NULL), _len(0) {};
            ~map(void)
            {
                this->free_lst(this->_values);
                this->_values = NULL;
            };
            map &operator=(map &x)
            {
                ft::pair<Key, T>    *tmp = x._values;
                ft::pair<Key, T>    *dup = NULL;
                ft::pair<Key, T>    *new_node = NULL;


                this->free_lst(this->_values);
                if (!tmp)
                    return *(this);
                while (tmp->previous)
                {
                    tmp = tmp->previous;
                }
                while (tmp)
                {
                    this->_len++;
                    new_node = this->new_node(tmp->first, tmp->second);
                    dup = this->insert_node(dup, new_node, dup);
                    tmp = tmp->next;
                }
                this->_values = dup;
                return *(this);
            }

            iterator    begin(void)
            {
                this->setIterator();
                return (this->getIterator());
            }
            const_iterator    begin(void) const
            {
                this->setIterator();
                return (this->getIterator());
            }
            iterator    end(void)
            {
                iterator    it;
                ft::pair<Key, T>  *tmp = this->_values;

                this->setIterator();
                it = this->getIterator();
                while (tmp)
                {
                    tmp = tmp->next;
                    it++;
                }
                return (it);
            }
            const_iterator    end(void) const
            {
                const_iterator    it;
                ft::pair<Key, T>  *tmp = this->_values;

                this->setIterator();
                it = this->getIterator();
                while (tmp)
                {
                    tmp = tmp->next;
                    it++;
                }
                return (it);
            }
            reverse_iterator   rbegin(void)
            {
                this->setIterator();
                iterator it = this->getIterator();
                it.setReverse();
                return (it);
            }
            const reverse_iterator   rbegin(void) const
            {
                this->setIterator();
                iterator it = this->getIterator();
                it.setReverse();
                return (it);
            }
            reverse_iterator   rend(void)
            {
                this->setIterator();
                iterator it = this->getIterator();
                it.setReverse();
                it.setPosition(this->_getLen());
                return (it);
            }
            const reverse_iterator   rend(void) const
            {
                this->setIterator();
                iterator it = this->getIterator();
                it.setReverse();
                it.setPosition(this->_getLen());
                return (it);
            }

            /* capacity */
            bool    empty(void) const
            {
                if (!this->_values)
                    return (true);
                return (false);
            }
            unsigned int    size(void) const
            {
                return (this->_len);
            }
            size_type   max_size(void) const
            {
                return (this->get_allocator().max_size());
            }

            /* elements access */
            T   operator[](const Key &k)
            {
                ft::pair<Key, T>  *tmp;

                tmp = this->find_node(this->_values, k);
                if (tmp)
                    return (tmp->second);
                return (0);
            }

            /* modifiers */
	    ft::pair<iterator, bool> insert(ft::pair<Key, T> &val)
            {
                ft::pair<iterator, bool>   to_return;
                ft::pair<Key, T>  *to_add = NULL;
                unsigned int actual_len = this->_len;

                this->_len++;
		        to_add = this->new_node(val.first, val.second);
                this->_values = this->insert_node(this->_values, to_add, this->_values);

                to_return.second = (this->_len > actual_len);
                return (to_return);
            }
            iterator insert(iterator position, ft::pair<Key, T> &val)
            {
                ft::pair<iterator, bool>   to_return;
                iterator_map<T>    it = this->begin();
                ft::pair<Key, T>  *to_add = NULL;

                (void)position;

                this->_len++;
                to_add = this->new_node(val.first, val.second);
                this->_values = this->insert_node(this->_values, to_add, this->_values);

                this->setIterator();
                it.setPosition(this->find_index_node(this->_values, val.first));
                return (it);
            }
            void    insert(iterator first, iterator last)
            {
                ft::pair<Key, T>   *to_add = NULL;

                while (first.getPosition() < last.getPosition())
                {
                    this->_len++;
                    to_add = this->new_node(first->first, first->second);
                    this->_values = this->insert_node(this->_values, to_add, this->_values);
                    if (first.getReverse() == false)
                        first++;
                    else
                        first--;
                }
            }
            void    clear(void)
            {
                this->free_lst(this->_values);
            }
            void    erase(iterator pos)
            {
                this->_values = this->delete_node(this->_values, pos->first);
            }
            unsigned int    erase(const Key &k)
            {
                this->_values = this->delete_node(this->_values, k);
                return (1);
            }
            void        erase(iterator first, iterator last)
            {
                iterator    it = this->begin();
                ft::pair<Key, T>  *tmp = this->_values;
                ft::pair<Key, T>  *buff = this->_values;
                unsigned int            pos_started = first.getPosition();

                while (it.getPosition() != first.getPosition())
                {
                    if (!tmp)
                        return;
                    tmp = tmp->next;
                    it++;
                }
                while (first.getPosition() != last.getPosition())
                {
                    if (!tmp)
                        return ;
                    buff = tmp->next;
                    first++;
                    this->_values = this->delete_node(this->_values, tmp->first);
                    tmp = buff;
                }
                if (pos_started == 0){
                    this->_values = buff;
                }
            }
            void    swap(map &x)
            {
                ft::pair<Key, T> *tmp;

                tmp = x._values;
                x._values = this->_values;
                this->_values = tmp;
        }

            /* observers */
            key_compare     key_comp(void) const
            {
                key_compare  comp;

                return (comp);
            }
            value_compare      value_comp(void)
            {
                value_compare  comp;

                return (comp);
            }

            /* operation */
            iterator    find(const Key &k)
            {
                ft::pair<Key, T> *tmp = this->_values;
                iterator             it = this->begin();
                unsigned int    i = 0;

                while (tmp)
                {
                    if (tmp->first == k)
                    {
                        it.setPosition(i);
                        return (it);
                    }
                    tmp = tmp->next;
                    i++;
                }
                it.setPosition(-1);
                return (it);
            }
            const_iterator  find(const Key &k) const
            {
                ft::pair<Key, T> *tmp;

                tmp = this->_values;
                while (tmp)
                {
                    if (tmp->first == k)
                    {
                        const iterator    it = tmp;
                        return (it);
                    }
                    tmp = tmp->next;
                }
                const iterator    it = tmp;
                return (it);
            }
            unsigned int    count(const Key &k) const
            {
                ft::pair<Key, T>    *tmp = this->_values;

                if (!tmp)
                    return (0);
                while (tmp)
                {
                    if (tmp->first == k)
                        return (1);
                    tmp = tmp->next;
                }
                return (0);
            }
            iterator    lower_bound(const Key &k)
            {
                ft::pair<Key, T>      *tmp = this->_values;
                iterator                    it = this->begin();
                unsigned int                i = 0;
                std::less<std::string>      key_comp = this->key_comp();

                while (tmp)
                {
                    if (key_comp(k, tmp->first) == 1)
                    {
                        it.setPosition(i);
                        return (it);
                    }
                    tmp = tmp->next;
                    i++;
                }
                it.setPosition(i - 1);
                return (it);
            }
            iterator    upper_bound(const Key &k)
            {
                ft::pair<Key, T>      *tmp = this->_values;
                iterator                    it = this->begin();
                unsigned int                i = 0;
                std::less<std::string>      key_comp = this->key_comp();

                it.setPosition(-1);
                while (tmp)
                {
                    if (key_comp(k, tmp->first) == 1)
                    {
                        it.setPosition(i);
                        break ;
                    }
                    tmp = tmp->next;
                    i++;
                }
                return (it);
            }
            ft::pair<iterator, iterator>  equal_range(const Key &k)
            {
                ft::pair<iterator, iterator>   to_return;
                iterator                        it_first = this->begin();
                iterator                        it_second = this->begin();
                ft::pair<Key, T>          *tmp = this->_values;
                unsigned int                    i = 0;

                while (tmp)
                {
                    if (tmp->first == k)
                    {
                        it_first.setPosition(i);
                        it_second.setPosition(i);
                        to_return.first = it_first;
                        to_return.second = it_second;
                        return (to_return);
                    }
                    if (tmp->first > k)
                    {
                        it_first.setPosition(i);
                        it_second.setPosition(i);
                        to_return.first = it_first;
                        to_return.second = it_second;
                        return (to_return);
                    }
                    i++;
                    tmp = tmp->next;
                }
                to_return.first = it_first;
                to_return.second = it_second;
                return (to_return);
            }
            ft::pair<const_iterator, const_iterator>  equal_range(const Key &k) const
            {
                ft::pair<const iterator, const iterator>   to_return;
                const iterator                              it_first;
                const iterator                              it_second;
                ft::pair<Key, T>          *tmp = this->_values;
                unsigned int                    i = 0;

                while (tmp)
                {
                    if (tmp->first == k)
                    {
                        it_first.setPosition(i);
                        it_second.setPosition(i);
                        to_return.first = it_first;
                        to_return.second = it_second;
                        return (to_return);
                    }
                    if (tmp->first > k)
                    {
                        it_first.setPosition(i);
                        it_second.setPosition(i);
                        to_return.first = it_first;
                        to_return.second = it_second;
                        return (to_return);
                    }
                    i++;
                    tmp = tmp->next;
                }
                to_return.first = it_first;
                to_return.second = it_second;
                return (to_return);
            }

            /* Allocator */
            allocator_type  get_allocator(void) const {
                allocator_type  alloc;
                return (alloc);
            }
        private:
            ft::pair<Key, T>        *_values;
            ft::list_iterator<T>    *_it;
            unsigned int            _len;

            unsigned int    _getLen(void)
            {
                unsigned int i = 0;
                ft::pair<Key, T> *tmp;

                tmp = this->_values;
                while (tmp)
                {
                    i++;
                    tmp = tmp->next;
                }
                return (i);
            }
            void    setIterator()
            {
                return ;
            }
            iterator getIterator()
            {
                iterator    it;

                it.setValues(this->_values);
                it.setPosition(0);
                return (it);
            }
            ft::pair<Key, T>    *new_node(Key key, T value)
            {
                ft::pair<Key, T>    *item = this->get_allocator().allocate(1);
                ft::pair<Key, T>    val;


                val.first = key;
                val.second = value;
                val.next = NULL;
                val.previous = NULL;
                this->get_allocator().construct(item, val);
                return (item);
            }
            ft::pair<Key, T>    *insert_node(ft::pair<Key, T> *lst, ft::pair<Key, T> *new_node, ft::pair<Key, T> *pts)
            {
                ft::pair<Key, T>    *tmp;

                tmp = lst;
                if (!lst)
                {
                    lst = new_node;
                    pts = lst;
                }
                else if (tmp->first == new_node->first)
                {
                    this->_len--;
                    this->get_allocator().deallocate(new_node, 1);
                    return (pts);
                }
                else if (new_node->first > lst->first)
                {
                    if (lst->next && new_node->first > lst->next->first){
                        insert_node(lst->next, new_node, pts);
                    } else {
                        if (tmp->next)
                            if (tmp->next->first == new_node->first)
                            {
                                this->_len--;
                                this->get_allocator().deallocate(new_node, 1);
                                return (pts);
                            }
                        new_node->previous = tmp;
                        if (tmp->next)
                        {
                            new_node->next = tmp->next;
                            tmp->next->previous = new_node;
                        }
                        tmp->next = new_node;
                    }
                }
                else
                {
                    if (lst->previous && new_node->first < lst->previous->first){
                        insert_node(lst->previous, new_node, pts);
                    } else {
                        if (tmp->previous)
                        {
                            if (tmp->previous->first == new_node->first)
                            {
                                this->_len--;
                                this->get_allocator().deallocate(new_node, 1);
                                return (pts);
                            }
                        }
                        new_node->next = tmp;
                        if (tmp->previous)
                        {
                            new_node->previous = tmp->previous;
                            tmp->previous->next = new_node;
                        }
                        else
                        {
                            pts = new_node;
                        }
                        tmp->previous = new_node;
                        if (tmp->previous->previous)
                            tmp->previous->previous->next = new_node;
                    }
                }
                return (pts);
            }
            ft::pair<Key, T>    *find_node(ft::pair<Key, T> *lst, Key key)
            {
                ft::pair<Key, T>    *tmp = lst;

                if (!lst)
                {
                    return (NULL);
                }
                else if (lst->first == key)
                {
                    return (lst);
                }
                else if (key < lst->first)
                {
                    while (tmp)
                    {
                        if (tmp->first == key)
                            return (tmp);
                        tmp = tmp->previous;
                    }
                }
                else
                {
                    while (tmp)
                    {
                        if (tmp->first == key)
                            return (tmp);
                        tmp = tmp->next;
                    }
                }
                return (NULL);
            }
            unsigned int    find_index_node(ft::pair<Key, T> *lst, Key key)
            {
                ft::pair<Key, T>    *tmp = lst;
                unsigned int        index = 0;

                if (!lst || lst->first == key)
                {
                    return (0);
                }
                else if (key < lst->first)
                {
                    while (tmp)
                    {
                        if (tmp->first == key)
                            return (index);
                        tmp = tmp->previous;
                        index++;
                    }
                }
                else
                {
                    while (tmp)
                    {
                        if (tmp->first == key)
                            return (index);
                        tmp = tmp->next;
                        index++;
                    }
                }
                return (0);
            }
            void    free_lst(ft::pair<Key, T> *lst)
            {
                ft::pair<Key, T>    *tmp;

                if (!lst)
                    return ;
                while (lst->previous)
                {
                    lst = lst->previous;
                }
                while (lst)
                {
                    tmp = lst->next;
                    this->get_allocator().deallocate(lst, 1);
                    lst = tmp;
                }
                this->_values = NULL;
                this->_len = 0;
            }
            ft::pair<Key, T>    *delete_from_lst(ft::pair<Key, T> *lst)
            {
                ft::pair<Key, T>    *tmp = lst;
                ft::pair<Key, T>    *ptr;

                if (lst->previous)
                {
                    tmp = lst->previous;
                    ptr = lst;
                    lst->previous->next = lst->next;
                    if (lst->next == NULL)
                    {
                        tmp->next = NULL;
                    }
                    else
                    {
                        lst->next->previous = tmp;
                    }
                    this->get_allocator().deallocate(ptr, 1);
                    this->_len--;
                    return (tmp);
                }
                else if (lst->next)
                {
                    tmp = lst->next;
                    if (lst->previous == NULL)
                        tmp->previous = NULL;
                    ptr = lst;
                    this->get_allocator().deallocate(ptr, 1);
                    this->_len--;
                    return (tmp);
                }
                this->get_allocator().deallocate(lst, 1);
                this->_len--;
                return (NULL);
            }
            ft::pair<Key, T>    *delete_node(ft::pair<Key, T> *lst, Key key)
            {
                if (!lst)
                    return (NULL);
                else if (lst->first == key)
                {
                    return (delete_from_lst(lst));
                }
                else if (key < lst->first)
                {
                    while (lst)
                    {
                        if (key == lst->first)
                            return (delete_from_lst(lst));
                        lst = lst->previous;
                    }
                }
                else
                {
                    while (lst)
                    {
                        if (key == lst->first)
                        {
                            return (delete_from_lst(lst));
                        }
                        lst = lst->next;
                    }
                }
                return (NULL);
            }
    };
}

#endif
