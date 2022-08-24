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

    template <typename T, typename K = std::string>
    class iterator_map
    {
        public:
            iterator_map(): _values(NULL), _position(0), _lst(NULL), _reverse(false){};
            ~iterator_map(){
                ft::map_pointer_lst<K, T>   *tmp = NULL;

                while (this->_lst)
                {
                    tmp = this->_lst->next;
                    this->_lst = tmp;
                }
            };

            void    setValues(ft::pair<K, T> *data){
                if (data == NULL)
                    return;
                this->_values = data;
            }
            ft::map_pointer<K, T> *operator->(void)
            {
                return (&this->it);
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
                if (this->_values != NULL)
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

        private:
            ft::pair<K, T>              *_values;
            unsigned int                _position;
            ft::map_pointer<K, T>       it;
            ft::map_pointer_lst<K, T>   *_lst;
            bool                        _reverse;
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

            typedef const ft::pair<Key, T>*         const_iterator;
            typedef iterator_map<T, Key>            iterator;
            typedef Alloc                           allocator_type;
            typedef std::pair<const Key, T>         value_type;
            typedef Compare                  	    key_compare;
            typedef ft::value_compare<Key, T>       value_compare;
            typedef size_t                          size_type;
            typedef ptrdiff_t                       difference_type;
            typedef iterator_map<T, Key>            reverse_iterator;

            map(void): _values(NULL), _it(NULL), _it_const(NULL) {};
            ~map(void)
            {
                ft::pair<Key, T>		*tmp;
                ft::list_iterator<T>        *lst;

                while (this->_it != NULL)
                {
                    lst = this->_it->next;
                    delete this->_it;
                    this->_it = lst;
                }

                while (this->_values){
                    tmp = this->_values->next;
                    this->get_allocator().deallocate(this->_values, 1);
                    this->_values = tmp;
                }
            };
            map &operator=(map &x)
            {
                ft::pair<Key, T>  *new_values = NULL;
                ft::pair<Key, T>  *tmp;
                ft::pair<Key, T>  *tmp_src;
                ft::pair<Key, T>  buff;
                unsigned int      len = 0;

                tmp_src = x._values;
                while (x._values)
                {
                    buff.first = x._values->first;
                    buff.second = x._values->second;
                    buff.next = NULL;
                    new_values = this->get_allocator().allocate(1);
                    this->get_allocator().construct(new_values, buff);

                    if (len == 0)
                    {
                        this->_values = new_values;
                    }
                    else
                    {
                        tmp = this->_values;
                        while (tmp->next)
                            tmp = tmp->next;
                        tmp->next = new_values;
                    }
                    x._values = x._values->next;
                    len++;
                }
                x._values = tmp_src;
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
            const iterator_map<T, Key>    end(void) const
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
            reverse_iterator   rbegin(void)
            {
                this->setIterator();
                iterator it = this->getIterator();
                it.setReverse();
                return (it);
            }
            const reverse_iterator   rbegin(void) const
            {
                const reverse_iterator    it;
                ft::pair<Key, T>  *tmp = this->_values;
                unsigned int    i = 0;
                Key *arr_keys = new Key[this->_getLen()];
                T   *arr_values = new T[this->_getLen()];

                while (tmp)
                {
                    arr_keys[i] = tmp->first;
                    arr_values[i] = tmp->second;
                    tmp = tmp->next;
                    i++;
                }
                it = tmp;
                it.setPosition(this->_getLen() - 1);
                it.setIndex(arr_values);
                it.setKeys(arr_keys);
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
                const reverse_iterator    it;
                ft::pair<Key, T>  *tmp = this->_values;
                unsigned int    i = 0;
                Key *arr_keys = new Key[this->_getLen()];
                T   *arr_values = new T[this->_getLen()];

                while (tmp)
                {
                    arr_keys[i] = tmp->first;
                    arr_values[i] = tmp->second;
                    tmp = tmp->next;
                    i++;
                }
                it = tmp;
                it.setIndex(arr_values);
                it.setKeys(arr_keys);
                it.setPosition(-1);
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
                ft::pair<Key, T>  *tmp = this->_values;
                unsigned int count = 0;

                if (!tmp)
                    return (count);
                while (tmp)
                {
                    tmp = tmp->next;
                    count++;
                }
                return (count);
            }
            size_type   max_size(void) const
            {
                return (this->get_allocator().max_size());
            }

            /* elements access */
            T   operator[](const Key &k)
            {
                ft::pair<Key, T>  *tmp;

                tmp = this->_values;
                if (!tmp)
                    return (0);
                while (tmp)
                {
                    if (tmp->first == k)
                        return (tmp->second);
                    tmp = tmp->next;
                }
                return (this->_values->second);
            }

            /* modifiers */
            ft::pair<iterator, bool> insert(ft::pair<Key, T> &val)
            {
                ft::pair<iterator, bool>   to_return;
                iterator_map<T>    it = this->begin();
                ft::pair<Key, T>  *tmp = this->_values;
                ft::pair<Key, T>  *previous = NULL;
                ft::pair<Key, T>  *to_add = this->get_allocator().allocate(1);
                bool    inserted = false;
                unsigned int i = 0;

                val.next = NULL;
                this->get_allocator().construct(to_add, val);
                if (this->_values == NULL) {
                    this->_values = to_add;
                } else {
                    while (tmp)
                    {
                        if (to_add->first < tmp->first) {
                            to_add->next = tmp;
                            if (previous) {
                                previous->next = to_add;
                                it.setPosition(i - 1);
                            } else {
                                this->_values = to_add;
                                it.setPosition(0);
                            }
                            to_return.first = it;
                            to_return.second = inserted;
                            this->setIterator();
                            return (to_return);
                        }
                        previous = tmp;
                        tmp = tmp->next;
                        i++;
                    }
                    previous->next = to_add;
                    it.setPosition(i);
                    to_return.first = it;
                    to_return.second = true;
                    this->setIterator();
                    return (to_return);
                }
                to_return.first = it;
                to_return.second = inserted;
                this->setIterator();
                return (to_return);
            }
            iterator insert(iterator position, ft::pair<Key, T> &val)
            {
                ft::pair<iterator, bool>   to_return;
                iterator    it;
                ft::pair<Key, T>  *tmp = this->_values;
                ft::pair<Key, T>  *to_add = this->get_allocator().allocate(1);
                unsigned int i = 0;

                it = this->find(val.first);
                val.next = NULL;
                this->get_allocator().construct(to_add, val);
                if (!this->_values)
                    this->_values = to_add;
                else
                {
                    while (tmp->next)
                    {
                        if (i > position.getPosition()){
                            to_add->next = tmp->next->next;
                            break;
                        }
                        tmp = tmp->next;
                        i++;
                    }
                    tmp->next = to_add;
                    it.setPosition(i);
                    to_return.first = it;
                    to_return.second = true;
                    return (to_return.first);
                }
                to_return.first = it;
                return (to_return.first);
            }
            void    insert(iterator first, iterator last)
            {
                ft::pair<Key, T>   to_add;

                while (first.getPosition() < last.getPosition())
                {
                    to_add.first = first->first;
                    to_add.second = first->second;
                    this->insert(to_add);
                    if (first.getReverse() == false)
                        first++;
                    else
                        first--;
                }
            }
            void    clear(void)
            {
                ft::pair<Key, T>	*tmp;

                while (this->_values)
                {
                    tmp = this->_values->next;
                    this->get_allocator().deallocate(this->_values, 1);
                    this->_values = tmp;
                }
                this->_values = NULL;
            }
            void    erase(iterator pos)
            {
                iterator  first = this->begin();
                ft::pair<Key, T>  *tmp = this->_values;
                ft::pair<Key, T> *buffer = this->_values;
                ft::pair<Key, T> *start = this->_values;

                if (this->_values == NULL)
                    return ;
                while (first.getPosition() <= pos.getPosition())
                {
                    if (first.getPosition() == pos.getPosition())
                    {
                        buffer->next = tmp->next;
                        if (first.getPosition() == 0){
                            this->_values = tmp->next;
                            this->get_allocator().deallocate(tmp, 1);
                        } else {
                            this->get_allocator().deallocate(tmp, 1);
                            this->_values = start;
                        }
                        return ;
                    }
                    first++;
                    buffer = tmp;
                    tmp = tmp->next;
                }
            }
            unsigned int    erase(const Key &k)
            {
                ft::pair<Key, T>  *tmp = this->_values;
                ft::pair<Key, T>  *buff = this->_values;
                unsigned int            pos = 0;

                if (!tmp)
                    return (0);
                while (tmp)
                {
                    if (tmp->first == k)
                    {
                        if (pos == 0) {
                            if (this->size() == 1) {
                                this->_values = NULL;
                            } else {
                                this->_values = this->_values->next;
                            }
                            this->get_allocator().deallocate(tmp, 1);
                            return (1);
                        } else {
                            buff->next = tmp->next;
                            this->get_allocator().deallocate(tmp, 1);
                            return (1);
                        }
                    }
                    buff = tmp;
                    tmp = tmp->next;
                    pos++;
                }
                return (0);
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
                    this->get_allocator().deallocate(tmp, 1);
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
            ft::pair<Key, T>  *_values;
            ft::list_iterator<T>    *_it;
            const_iterator          _it_const;

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
                ft::list_iterator<T> *new_lst_it = new ft::list_iterator<T>;
                iterator     new_it;
                ft::list_iterator<T>    *tmp;

                if (this->_values != NULL)
                {
                    new_it.setValues(this->_values);
                }
                new_it.setPosition(0);
                new_lst_it->iterator = new_it;
                new_lst_it->next = NULL;

                if (this->_it == NULL)
                {
                    this->_it = new_lst_it;
                }
                else
                {
                    tmp = this->_it;
                    while (tmp->next)
                        tmp = tmp->next;
                    tmp->next = new_lst_it;
                }
            }
            iterator getIterator()
            {
                ft::list_iterator<T>    *tmp = NULL;

                if (this->_it == NULL)
                    return tmp->iterator;
                tmp = this->_it;
                while (tmp->next != NULL)
                    tmp = tmp->next;
                return (tmp->iterator);
            }
    };
}

#endif
