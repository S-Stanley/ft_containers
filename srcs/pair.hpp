#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {
    template <typename Key, typename Value>
    struct pair{
        Key   first;
        Value   second;
    };

    template <typename Key, typename Value>
    pair<Key, Value>    make_pair(Key key, Value value){
        pair<Key, Value>    to_return;

        to_return.first = key;
        to_return.second = value;
        return (to_return);
    }

    /*
    template<class T>
    struct is_integral: public std::false_type {};

    template<>
    struct is_integral<bool>: public std::true_type {};

    template<>
    struct is_integral<char>: public std::true_type {};

    template<>
    struct is_integral<char16_t>: public std::true_type {};

    template<>
    struct is_integral<char32_t>: public std::true_type {};

    template<>
    struct is_integral<wchar_t>: public std::true_type {};

    template<>
    struct is_integral<signed char>: public std::true_type {};

    template<>
    struct is_integral<short int>: public std::true_type {};

    template<>
    struct is_integral<int>: public std::true_type {};

    template<>
    struct is_integral<long int>: public std::true_type {};

    template<>
    struct is_integral<long long int>: public std::true_type {};

    template<>
    struct is_integral<unsigned char>: public std::true_type {};

    template<>
    struct is_integral<unsigned short int>: public std::true_type {};

    template<>
    struct is_integral<unsigned int>: public std::true_type {};

    template<>
    struct is_integral<unsigned long int>: public std::true_type {};

    template<>
    struct is_integral<unsigned long long int>: public std::true_type {};

    */
    template <bool B, class T = void>
    struct enable_if {
        typedef T type;
    };
}

#endif
