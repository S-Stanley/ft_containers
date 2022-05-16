#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "iterators_traits.hpp"

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
            map(void): _values(NULL) {};
            ~map(void) {};

            /* Iterators */
            Iterator<T>    end(void)
            {
                Iterator<T>    it;
                ft::map_values<Key, T>  *tmp = this->_values;

                while (tmp)
                    tmp = tmp->next;
                it = tmp;
                return (it);
            }
            const Iterator<T>  end(void) const
            {
                ft::map_values<Key, T>  *tmp = this->_values;

                while (tmp)
                    tmp = tmp->next;
                const Iterator<T>    it = tmp;
                return (it);
            }

            /* elements access */
            T   operator[](const Key &k)
            {
                ft::map_values<Key, T>  *tmp;

                tmp = this->_values;
                while (tmp)
                {
                    if (tmp->key == k)
                        return (tmp->value);
                    tmp = tmp->next;
                }
                return (this->_values->value);
            }

            /* modifiers */
            std::pair<Iterator<T>, bool> insert(const std::pair<Key, T> &val)
            {
                std::pair<Iterator<T>, bool>   to_return;
                Iterator<T>    it;
                ft::map_values<Key, T>  *tmp = this->_values;
                ft::map_values<Key, T>  *to_add = new ft::map_values<Key, T>;
                bool    inserted = false;

                it = this->find(val.first);
                if (it.isNull()) {
                    to_add->key = val.first;
                    to_add->value = val.second;
                    to_add->next = NULL;
                    if (!this->_values)
                        this->_values = to_add;
                    else
                    {
                        while (tmp->next)
                            tmp = tmp->next;
                        tmp->next = to_add;
                        it = tmp->next;
                        to_return.first = it;
                        to_return.second = true;
                    }
                }
                to_return.first = it;
                to_return.second = inserted;
                return (to_return);
            }
            Iterator<T> insert(Iterator<T> position, const std::pair<Key, T> &val)
            {
                std::pair<Iterator<T>, bool>   to_return;
                Iterator<T>    it;
                ft::map_values<Key, T>  *tmp = this->_values;
                ft::map_values<Key, T>  *to_add = new ft::map_values<Key, T>;

                (void)position;
                it = this->find(val.first);
                if (it.isNull()) {
                    to_add->key = val.first;
                    to_add->value = val.second;
                    to_add->next = NULL;
                    if (!this->_values)
                        this->_values = to_add;
                    else
                    {
                        while (tmp->next)
                            tmp = tmp->next;
                        tmp->next = to_add;
                        it = tmp->next;
                        to_return.first = it;
                        to_return.second = true;
                        return (to_return.first);
                    }
                }
                to_return.first = it;
                return (to_return.first);
            }
            // Iterator<T> insert(Iterator<T> position, const std::pair<Key, T> &val)
            // {
            //     std::pair<Iterator<T>, bool>   to_return;
            //     Iterator<T>    it;
            //     ft::map_values<Key, T>  *tmp = this->_values;
            //     ft::map_values<Key, T>  *to_add = new ft::map_values<Key, T>;
            //     bool    inserted = false;

            //     it = this->find(val.first);
            //     if (it.isNull()) {
            //         to_add->key = val.first;
            //         to_add->value = val.second;
            //         to_add->next = NULL;
            //         if (!this->_values)
            //             this->_values = to_add;
            //         else
            //         {
            //             while (tmp->next)
            //                 tmp = tmp->next;
            //             tmp->next = to_add;
            //             it = tmp->next;
            //             to_return.first = it;
            //             to_return.second = true;
            //         }
            //     }
            //     to_return.first = it;
            //     to_return.second = inserted;
            //     return (to_return);
            // }

            // void    insert(Key key, T value)
            // {
            //     ft::map_values<Key, T>  *to_add = new ft::map_values<Key, T>;

            //     to_add->key = key;
            //     to_add->value = value;
            //     to_add->next = NULL;
            //     if (!this->_values) {
            //         this->_values = to_add;
            //     } else {
            //         ft::map_values<Key, T>  *tmp;

            //         tmp = this->_values;
            //         while (this->_values->next)
            //             this->_values = this->_values->next;
            //         this->_values->next = to_add;
            //         this->_values = tmp;
            //     }
            // }

            /* operation */
            Iterator<T>    find(const Key &k)
            {
                ft::map_values<Key, T> *tmp;
                Iterator<T>    it;

                tmp = this->_values;
                while (tmp)
                {
                    if (tmp->key == k)
                    {
                        it = tmp;
                        return (it);
                    }
                    tmp = tmp->next;
                }
                it = tmp;
                return (it);
            }
            const Iterator<T>  find(const Key &k) const
            {
                ft::map_values<Key, T> *tmp;

                tmp = this->_values;
                while (tmp)
                {
                    if (tmp->key == k)
                    {
                        const Iterator<T>    it = tmp;
                        return (it);
                    }
                    tmp = tmp->next;
                }
                const Iterator<T>    it = tmp;
                return (it);
            }
        private:
            ft::map_values<Key, T> *_values;
    };
}

#endif