#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {
    template <typename Key, typename Value>
    struct pair{
        Key     first;
        Value   second;
        pair    *next;
        pair    *previous;
    };

    template <typename Key, typename Value>
    pair<Key, Value>    make_pair(Key key, Value value){
        pair<Key, Value>    to_return;

        to_return.first = key;
        to_return.second = value;
        return (to_return);
    }

    template<class T>
    struct is_integral: public std::__false_type {};

    template<>
    struct is_integral<bool>: public std::__true_type {};

    template<>
    struct is_integral<wchar_t>: public std::__true_type {};

    template<>
    struct is_integral<signed char>: public std::__true_type {};

    template<>
    struct is_integral<short int>: public std::__true_type {};

    template<>
    struct is_integral<int>: public std::__true_type {};

    template<>
    struct is_integral<long int>: public std::__true_type {};

    template<>
    struct is_integral<long long int>: public std::__true_type {};

    template<>
    struct is_integral<unsigned char>: public std::__true_type {};

    template<>
    struct is_integral<unsigned short int>: public std::__true_type {};

    template<>
    struct is_integral<unsigned int>: public std::__true_type {};

    template<>
    struct is_integral<unsigned long int>: public std::__true_type {};

    template<>
    struct is_integral<unsigned long long int>: public std::__true_type {};
    template <bool B, class T = void>
    struct enable_if {
        typedef T type;
    };

    template <class iterator1, class iterator2>
    bool equal ( iterator1 first1, iterator1 last1, iterator2 first2 )
    {
        while (first1.getPosition() != last1.getPosition() ) {
            if (first1->first != first2->first){
                return (false);
            }
            first1++;
            first2++;
        }
        return (true);
    }
}

#endif
