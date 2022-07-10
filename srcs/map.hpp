#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <algorithm>
#include <cmath>
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

    template <typename Key, typename T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
    class map {
        public:

            typedef const ft::pair<Key, T>*         const_iterator;
            typedef Iterator<T>*                    iterator;
            typedef Alloc                           allocator_type;
            typedef std::pair<const Key, T>         value_type;
            typedef std::less<iterator>             value_compare;
            typedef size_t                          size_type;
            typedef ptrdiff_t                       difference_type;

            map(void): _values(NULL) {};
            ~map(void) {};
            map &operator=(const map &x)
            {
                delete this->_values;
                this->_values = x._values;
                return *(this);
            }

            iterator    begin(void)
            {
                Iterator<T>             *it = new Iterator<T>;
                ft::map_values<Key, T>  *tmp = this->_values;

                while (tmp)
                {
                    it->addToArr(tmp->value);
                    it->addToKeys(tmp->key);
                    tmp = tmp->next;
                }
                it->setPosition(0);
                return (it);
            }
            const_iterator    begin(void) const
            {
                Iterator<T>  it;
                ft::map_values<Key, T>  *tmp = this->_values;

                while (tmp)
                {
                    it.addToArr(tmp->value);
                    it.addToKeys(tmp->key);
                    tmp = tmp->next;
                }
                it.setPosition(0);
                return (it.it);
            }
            iterator    end(void)
            {
                Iterator<T>             *it = new Iterator<T>;
                ft::map_values<Key, T>  *tmp = this->_values;
                unsigned int    position = 0;
                Key *arr_keys = new Key[this->_getLen()];
                T   *arr_values = new T[this->_getLen()];
                unsigned int    i = 0;

                while (tmp)
                {
                    position++;
                    arr_keys[i] = tmp->key;
                    arr_values[i] = tmp->value;
                    tmp = tmp->next;
                    i++;
                }
                // it = tmp;
                it->setPosition(position);
                it->setArray(arr_values);
                it->setKeys(arr_keys);
                return (it);
            }
            const Iterator<T>    end(void) const
            {
                const Iterator<T>    it;
                ft::map_values<Key, T>  *tmp = this->_values;
                unsigned int    position = 0;
                Key *arr_keys = new Key[this->_getLen()];
                T   *arr_values = new T[this->_getLen()];
                unsigned int    i = 0;

                while (tmp)
                {
                    position++;
                    arr_keys[i] = tmp->key;
                    arr_values[i] = tmp->value;
                    tmp = tmp->next;
                    i++;
                }
                it = tmp;
                it.setPosition(position);
                it.setArray(arr_values);
                it.setKeys(arr_keys);
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
                return (std::numeric_limits<difference_type>::max());
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
                iterator    it = this->begin();
                ft::map_values<Key, T>  *tmp = this->_values;
                ft::map_values<Key, T>  *previous = NULL;
                ft::map_values<Key, T>  *to_add = new ft::map_values<Key, T>;
                bool    inserted = false;
                unsigned int i = 0;

                to_add->key = val.first;
                to_add->value = val.second;
                to_add->next = NULL;
                if (!this->_values) {
                    this->_values = to_add;
                } else {
                    while (tmp)
                    {
                        if (to_add->key < tmp->key) {
                            to_add->next = tmp;
                            if (previous) {
                                previous->next = to_add;
                                it->setPosition(i - 1);
                            } else {
                                this->_values = to_add;
                                it->setPosition(0);
                            }
                            to_return.first = it;
                            to_return.second = inserted;
                            return (to_return);
                        }
                        previous = tmp;
                        tmp = tmp->next;
                        i++;
                    }
                    previous->next = to_add;
                    it->setPosition(i);
                    to_return.first = it;
                    to_return.second = true;
                    return (to_return);
                }
                to_return.first = it;
                to_return.second = inserted;
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
                        if (i > position->getPosition()){
                            to_add->next = tmp->next->next;
                            break;
                        }
                        tmp = tmp->next;
                        i++;
                    }
                    tmp->next = to_add;
                    it->setPosition(i);
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
                Key *keys = first->getKeys();
                T   *values = first->getArray();

                while (first->getPosition() < last->getPosition())
                {
                    to_add.first = keys[first->getPosition()];
                    to_add.second = values[first->getPosition()];
                    this->insert(to_add);
                    (*first)++;
                }
            }
            void    insert(RIterator<T> first, RIterator<T> last)
            {
                ft::pair<Key, T>   to_add;
                Key *keys = first.getKeys();
                T   *values = first.getArray();
                (void)keys;
                (void)values;

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
                if (this->_values)
                    delete this->_values;
                this->_values = NULL;
            }
            void    erase(iterator pos)
            {
                iterator  first = this->begin();
                ft::map_values<Key, T>  *tmp = this->_values;
                ft::map_values<Key, T> *buffer = this->_values;
                ft::map_values<Key, T> *start = this->_values;

                if (!this->_values)
                    return ;
                while (first->getPosition() <= pos->getPosition())
                {
                    if (first->getPosition() == pos->getPosition())
                    {
                        buffer->next = tmp->next;
                        if (first->getPosition() == 0){
                            this->_values = tmp->next;
                            delete tmp;
                        } else {
                            delete tmp;
                            this->_values = start;
                        }
                        return ;
                    }
                    (*first)++;
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
                unsigned int            pos_started = first->getPosition();

                while (it->getPosition() != first->getPosition())
                {
                    if (!tmp)
                        return;
                    tmp = tmp->next;
                    (*it)++;
                }
                while (first->getPosition() != last->getPosition())
                {
                    if (!tmp)
                        return ;
                    buff = tmp->next;
                    delete tmp;
                    tmp = buff;
                    (*first)++;
                }
                if (pos_started == 0){
                    this->_values = buff;
                }
            }
            void    swap(map &x)
            {
                map buff;

                buff._values = x._values;
                x._values = this->_values;
                this->_values = buff._values;
            }

            /* observers */
            std::less<Key>     key_comp(void) const
            {
                std::less<Key>  comp;

                return (comp);
            }
            value_compare      value_comp(void) const
            {
                value_compare  comp;

                return (comp);
            }

            /* operation */
            iterator    find(const Key &k)
            {
                ft::map_values<Key, T> *tmp = this->_values;
                Iterator<T>             *it = this->begin();
                unsigned int    i = 0;

                while (tmp)
                {
                    if (tmp->key == k)
                    {
                        it->setPosition(i);
                        return (it);
                    }
                    tmp = tmp->next;
                    i++;
                }
                it->setPosition(-1);
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
                        it->setPosition(i);
                        return (it);
                    }
                    tmp = tmp->next;
                    i++;
                }
                it->setPosition(i - 1);
                return (it);
            }
            iterator    upper_bound(const Key &k)
            {
                ft::map_values<Key, T>      *tmp = this->_values;
                iterator                    it = this->begin();
                unsigned int                i = 0;
                std::less<std::string>      key_comp = this->key_comp();

                it->setPosition(-1);
                while (tmp)
                {
                    if (key_comp(k, tmp->key) == 1)
                    {
                        it->setPosition(i);
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
                iterator                        it_first;
                iterator                        it_second;
                ft::map_values<Key, T>          *tmp = this->_values;
                unsigned int                    i = 0;

                it_first = NULL;
                it_second = NULL;
                while (tmp)
                {
                    if (tmp->key == k)
                    {
                        it_first->setPosition(i);
                        it_second->setPosition(i);
                        to_return.first = it_first;
                        to_return.second = it_second;
                        return (to_return);
                    }
                    if (tmp->key > k)
                    {
                        it_first->setPosition(i);
                        it_second->setPosition(i);
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
                        it_first->setPosition(i);
                        it_second->setPosition(i);
                        to_return.first = it_first;
                        to_return.second = it_second;
                        return (to_return);
                    }
                    if (tmp->key > k)
                    {
                        it_first->setPosition(i);
                        it_second->setPosition(i);
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
            ft::map_values<Key, T> *_values;

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
    };
}

#endif