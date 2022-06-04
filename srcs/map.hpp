#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "iterators_traits.hpp"
#include "reverse_iterator.hpp"

namespace ft {
    template <typename Key, typename T>

    struct map_values {
        Key         key;
        T           value;
        map_values  *next;
    };

    template <typename Key, typename T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
    class map {
        public:

            typedef const std::pair<Key, T>*    const_iterator;
            typedef Iterator<T>*                iterator;

            map(void): _values(NULL) {};
            ~map(void) {};

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
            std::pair<iterator, bool> insert(const std::pair<Key, T> &val)
            {
                std::pair<iterator, bool>   to_return;
                iterator    it;
                ft::map_values<Key, T>  *tmp = this->_values;
                ft::map_values<Key, T>  *previous = NULL;
                ft::map_values<Key, T>  *to_add = new ft::map_values<Key, T>;
                bool    inserted = false;
                unsigned int i = 0;

                it = this->find(val.first);
                if (it->isNull()) {
                    to_add->key = val.first;
                    to_add->value = val.second;
                    to_add->next = NULL;
                    if (!this->_values)
                        this->_values = to_add;
                    else
                    {
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
                }
                to_return.first = it;
                to_return.second = inserted;
                return (to_return);
            }
            iterator insert(iterator position, const std::pair<Key, T> &val)
            {
                std::pair<iterator, bool>   to_return;
                iterator    it;
                ft::map_values<Key, T>  *tmp = this->_values;
                ft::map_values<Key, T>  *to_add = new ft::map_values<Key, T>;
                unsigned int i = 0;

                (void)position;
                it = this->find(val.first);
                if (it->isNull()) {
                    to_add->key = val.first;
                    to_add->value = val.second;
                    to_add->next = NULL;
                    if (!this->_values)
                        this->_values = to_add;
                    else
                    {
                        while (tmp->next)
                        {
                            tmp = tmp->next;
                            i++;
                        }
                        tmp->next = to_add;
                        it->setPosition(i);
                        to_return.first = it;
                        to_return.second = true;
                        return (to_return.first);
                    }
                }
                to_return.first = it;
                return (to_return.first);
            }
            void    insert(iterator first, iterator last)
            {
                std::pair<Key, T>   to_add;
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
                std::pair<Key, T>   to_add;
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

            /* observers */
            std::less<Key>     key_comp(void) const
            {
                std::less<Key>  comp;

                return (comp);
            }

            /* operation */
            iterator    find(const Key &k)
            {
                ft::map_values<Key, T> *tmp;
                Iterator<T>             *it = new Iterator<T>;
                unsigned int    i = 0;

                tmp = this->_values;
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
                    if (key_comp(k, tmp->key) == 0 && k == tmp->key)
                    {
                        it->setPosition(i);
                        return (it);
                    }
                    if (k < tmp->key)
                    {
                        it->setPosition(i);
                        return (it);
                    }
                    tmp = tmp->next;
                    i++;
                }
                return (it);
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