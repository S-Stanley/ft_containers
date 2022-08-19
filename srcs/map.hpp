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
    template <typename Key, typename T>
    struct map_values {
        Key         key;
        T           value;
        map_values  *next;
    };

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
            iterator_map(): _values(NULL), _position(0), _lst(NULL){};
            ~iterator_map(){
                ft::map_pointer_lst<K, T>   *tmp = NULL;

                while (this->_lst)
                {
                    tmp = this->_lst->next;
                    delete this->_lst->lst;
                    delete this->_lst;
                    this->_lst = tmp;
                }
            };

            void    setValues(ft::map_values<K, T> *data){
                if (data == NULL)
                    return;
                this->_values = data;
            }
            ft::map_pointer<K, T> *operator->(void)
            {
                ft::map_pointer<K, T>   *to_return = new ft::map_pointer<K, T>;

                to_return->first = this->it.first;
                to_return->second = this->it.second;
                this->keep_track_map_pointer(to_return);
                return (to_return);
            }
            bool    operator<(iterator_map<K, T> src)
            {
                return (src.getPosition() != this->getPosition());
            }
            void    operator++(int){
                ft::map_values<K, T>    *tmp;
                unsigned int            tmp_position;

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
                        this->it.first = tmp->key;
                        this->it.second = tmp->value;
                    }
                }
            }
            unsigned int    getPosition(void){
                return (this->_position);
            }
            void            setPosition(unsigned int position){
                ft::map_values<K, T>    *tmp;

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
                        this->it.first = tmp->key;
                        this->it.second = tmp->value;
                    }
                }
            }

        private:
            void    keep_track_map_pointer(ft::map_pointer<K, T> *new_lst)
            {
                ft::map_pointer_lst<K, T>   *tmp = this->_lst;
                ft::map_pointer_lst<K, T>   *new_node = new ft::map_pointer_lst<K, T>;

                new_node->lst = new_lst;
                new_node->next = NULL;
                if (this->_lst == NULL)
                {
                    this->_lst = new_node;
                }
                else
                {

                    while (tmp->next)
                        tmp = tmp->next;
                    tmp->next = new_node;
                }
            }

            ft::map_values<K, T>        *_values;
            unsigned int                _position;
            ft::map_pointer<K, T>       it;
            ft::map_pointer_lst<K, T>   *_lst;
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

    template <typename Key, typename T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
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

            map(void): _values(NULL), _it(NULL), _it_const(NULL) {};
            ~map(void)
            {
                ft::map_values<Key, T>		*tmp;
                ft::list_iterator<T>        *lst;

                while (this->_it != NULL)
                {
                    lst = this->_it->next;
                    delete this->_it;
                    this->_it = lst;
                }

                while (this->_values){
                    tmp = this->_values->next;
                    delete this->_values;
                    this->_values = tmp;
                }
            };
            map &operator=(map &x)
            {
                ft::map_values<Key, T>  *new_values = NULL;
                ft::map_values<Key, T>  *tmp;
                ft::map_values<Key, T>  *tmp_src;
                unsigned int            len = 0;

                delete this->_values;
                tmp_src = x._values;
                while (x._values)
                {
                    new_values = new ft::map_values<Key, T>;

                    new_values->key = x._values->key;
                    new_values->value = x._values->value;
                    new_values->next = NULL;

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
                ft::map_values<Key, T>  *tmp = this->_values;

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
                ft::map_values<Key, T>  *tmp = this->_values;

                this->setIterator();
                it = this->getIterator();
                while (tmp)
                {
                    tmp = tmp->next;
                    it++;
                }
                return (it);
            }
            RIterator<T>   rbegin(void)
            {
                RIterator<T>    it;
                ft::map_values<Key, T>  *tmp = this->_values;
                unsigned int    i = 0;
                Key *arr_keys = new Key[this->_getLen()];
                T   *arr_values = new T[this->_getLen()];

                while (tmp)
                {
                    arr_keys[i] = tmp->key;
                    arr_values[i] = tmp->value;
                    tmp = tmp->next;
                    i++;
                }
                it = tmp;
                it.setPosition(this->_getLen() - 1);
                it.setIndex(arr_values);
                it.setKeys(arr_keys);
                return (it);
            }
            const RIterator<T>   rbegin(void) const
            {
                const RIterator<T>    it;
                ft::map_values<Key, T>  *tmp = this->_values;
                unsigned int    i = 0;
                Key *arr_keys = new Key[this->_getLen()];
                T   *arr_values = new T[this->_getLen()];

                while (tmp)
                {
                    arr_keys[i] = tmp->key;
                    arr_values[i] = tmp->value;
                    tmp = tmp->next;
                    i++;
                }
                it = tmp;
                it.setPosition(this->_getLen() - 1);
                it.setIndex(arr_values);
                it.setKeys(arr_keys);
                return (it);
            }
            RIterator<T>   rend(void)
            {
                RIterator<T>    it;
                ft::map_values<Key, T>  *tmp = this->_values;
                unsigned int    i = 0;
                Key *arr_keys = new Key[this->_getLen()];
                T   *arr_values = new T[this->_getLen()];

                while (tmp)
                {
                    arr_keys[i] = tmp->key;
                    arr_values[i] = tmp->value;
                    tmp = tmp->next;
                    i++;
                }
                it = tmp;
                it.setIndex(arr_values);
                it.setKeys(arr_keys);
                it.setPosition(-1);
                return (it);
            }
            const RIterator<T>   rend(void) const
            {
                const RIterator<T>    it;
                ft::map_values<Key, T>  *tmp = this->_values;
                unsigned int    i = 0;
                Key *arr_keys = new Key[this->_getLen()];
                T   *arr_values = new T[this->_getLen()];

                while (tmp)
                {
                    arr_keys[i] = tmp->key;
                    arr_values[i] = tmp->value;
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
                ft::map_values<Key, T>  *tmp = this->_values;
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
                ft::map_values<Key, T>  *tmp;

                tmp = this->_values;
                if (!tmp)
                    return (0);
                while (tmp)
                {
                    if (tmp->key == k)
                        return (tmp->value);
                    tmp = tmp->next;
                }
                return (this->_values->value);
            }

            /* modifiers */
            ft::pair<iterator, bool> insert(const ft::pair<Key, T> &val)
            {
                ft::pair<iterator, bool>   to_return;
                iterator_map<T>    it = this->begin();
                ft::map_values<Key, T>  *tmp = this->_values;
                ft::map_values<Key, T>  *previous = NULL;
                ft::map_values<Key, T>  *to_add = new ft::map_values<Key, T>;
                bool    inserted = false;
                unsigned int i = 0;

                to_add->key = val.first;
                to_add->value = val.second;
                to_add->next = NULL;
                if (this->_values == NULL) {
                    this->_values = to_add;
                } else {
                    while (tmp)
                    {
                        if (to_add->key < tmp->key) {
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
            iterator insert(iterator position, const ft::pair<Key, T> &val)
            {
                ft::pair<iterator, bool>   to_return;
                iterator    it;
                ft::map_values<Key, T>  *tmp = this->_values;
                ft::map_values<Key, T>  *to_add = new ft::map_values<Key, T>;
                unsigned int i = 0;

                it = this->find(val.first);
                to_add->key = val.first;
                to_add->value = val.second;
                to_add->next = NULL;
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
                    first++;
                }
            }
            void    insert(RIterator<T> first, RIterator<T> last)
            {
                ft::pair<Key, T>   to_add;
                Key *keys = first.getKeys();
                T   *values = first.getArray();

                while (first.getPosition() != last.getPosition())
                {
                    to_add.first = keys[first.getPosition()];
                    to_add.second = values[first.getPosition()];
                    this->insert(to_add);
                    first++;
                }
            }
            void    clear(void)
            {
                ft::map_values<Key, T>	*tmp;

                while (this->_values)
                {
                    tmp = this->_values->next;
                    delete this->_values;
                    this->_values = tmp;
                }
                this->_values = NULL;
            }
            void    erase(iterator pos)
            {
                iterator  first = this->begin();
                ft::map_values<Key, T>  *tmp = this->_values;
                ft::map_values<Key, T> *buffer = this->_values;
                ft::map_values<Key, T> *start = this->_values;

                if (this->_values == NULL)
                    return ;
                while (first.getPosition() <= pos.getPosition())
                {
                    if (first.getPosition() == pos.getPosition())
                    {
                        buffer->next = tmp->next;
                        if (first.getPosition() == 0){
                            this->_values = tmp->next;
                            delete tmp;
                        } else {
                            delete tmp;
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
                ft::map_values<Key, T>  *tmp = this->_values;
                ft::map_values<Key, T>  *buff = this->_values;
                unsigned int            pos = 0;

                if (!tmp)
                    return (0);
                while (tmp)
                {
                    if (tmp->key == k)
                    {
                        if (pos == 0) {
                            if (this->size() == 1) {
                                this->_values = NULL;
                            } else {
                                this->_values = this->_values->next;
                            }
                            delete tmp;
                            return (1);
                        } else {
                            buff->next = tmp->next;
                            delete tmp;
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
                ft::map_values<Key, T>  *tmp = this->_values;
                ft::map_values<Key, T>  *buff = this->_values;
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
                    delete tmp;
                    tmp = buff;
                }
                if (pos_started == 0){
                    this->_values = buff;
                }
            }
            void    swap(map &x)
            {
		    ft::map_values<Key, T> *tmp;

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
                ft::map_values<Key, T> *tmp = this->_values;
                iterator             it = this->begin();
                unsigned int    i = 0;

                while (tmp)
                {
                    if (tmp->key == k)
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
                ft::map_values<Key, T> *tmp;

                tmp = this->_values;
                while (tmp)
                {
                    if (tmp->key == k)
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
                ft::map_values<Key, T>    *tmp = this->_values;

                if (!tmp)
                    return (0);
                while (tmp)
                {
                    if (tmp->key == k)
                        return (1);
                    tmp = tmp->next;
                }
                return (0);
            }
            iterator    lower_bound(const Key &k)
            {
                ft::map_values<Key, T>      *tmp = this->_values;
                iterator                    it = this->begin();
                unsigned int                i = 0;
                std::less<std::string>      key_comp = this->key_comp();

                while (tmp)
                {
                    if (key_comp(k, tmp->key) == 1)
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
                ft::map_values<Key, T>      *tmp = this->_values;
                iterator                    it = this->begin();
                unsigned int                i = 0;
                std::less<std::string>      key_comp = this->key_comp();

                it.setPosition(-1);
                while (tmp)
                {
                    if (key_comp(k, tmp->key) == 1)
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
                ft::map_values<Key, T>          *tmp = this->_values;
                unsigned int                    i = 0;

                while (tmp)
                {
                    if (tmp->key == k)
                    {
                        it_first.setPosition(i);
                        it_second.setPosition(i);
                        to_return.first = it_first;
                        to_return.second = it_second;
                        return (to_return);
                    }
                    if (tmp->key > k)
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
                ft::map_values<Key, T>          *tmp = this->_values;
                unsigned int                    i = 0;

                while (tmp)
                {
                    if (tmp->key == k)
                    {
                        it_first.setPosition(i);
                        it_second.setPosition(i);
                        to_return.first = it_first;
                        to_return.second = it_second;
                        return (to_return);
                    }
                    if (tmp->key > k)
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

            Iterator<T>    iterator_traits;
            RIterator<T>   reverse_iterator;
        private:
            ft::map_values<Key, T>  *_values;
            ft::list_iterator<T>    *_it;
            const_iterator          _it_const;

            unsigned int    _getLen(void)
            {
                unsigned int i = 0;
                ft::map_values<Key, T> *tmp;

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
