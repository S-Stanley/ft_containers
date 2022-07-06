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
}

#endif