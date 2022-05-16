#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>

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
            T   operator[](const Key &k)
            {
                ft::map_values<Key, T>  *tmp;

                tmp = this->_values;
                while (tmp->next)
                {
                    if (tmp->key == k)
                        return (tmp->value);
                    tmp = tmp->next;
                }
                return (this->_values->value);
            }
            void    insert(Key key, T value)
            {
                ft::map_values<Key, T>  *to_add = new ft::map_values<Key, T>;

                to_add->key = key;
                to_add->value = value;
                to_add->next = NULL;
                if (!this->_values) {
                    this->_values = to_add;
                } else {
                    ft::map_values<Key, T>  *tmp;

                    tmp = this->_values;
                    while (this->_values->next)
                        this->_values = this->_values->next;
                    this->_values->next = to_add;
                    this->_values = tmp;
                }
            }
        private:
            ft::map_values<Key, T> *_values;
    };
}

#endif