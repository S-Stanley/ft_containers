#include "test.map.hpp"

ft::pair<std::string, int> create_ft_pair(std::string key, int value)
{
    ft::pair<std::string, int> to_return;

    to_return.first = key;
    to_return.second = value;
    return (to_return);
}

ft::pair<std::string, std::string> create_ft_pair(std::string key, std::string value)
{
    ft::pair<std::string, std::string> to_return;

    to_return.first = key;
    to_return.second = value;
    return (to_return);
}

std::pair<std::string, int> create_std_pair(std::string key, int value)
{
    std::pair<std::string, int> to_return;

    to_return.first = key;
    to_return.second = value;
    return (to_return);
}

std::pair<std::string, std::string> create_std_pair(std::string key, std::string value)
{
    std::pair<std::string, std::string> to_return;

    to_return.first = key;
    to_return.second = value;
    return (to_return);
}


void    test_map_compile(bool is_real_container)
{
    if (is_real_container) {
        std::map<std::string, int>    map_std;
    } else {
        ft::map<std::string, int>     map_ft;
    }
}

void    test_map_insert(bool is_real_container)
{
    std::cout << "TESTING MAP INSERT" << std::endl;

    if (is_real_container) {
        std::map<std::string, int>    map_std;
        std::map<std::string, int>    map_std_2;
        std::map<std::string, int>::iterator it;
        std::pair<std::string, int>     val1 = create_std_pair("cpp", 7);
        std::pair<std::string, int>     val2 = create_std_pair("ts", 8);
        std::pair<std::string, int>     val3 = create_std_pair("py", 8);

        map_std.insert(val1);
        map_std.insert(val2);
        it = map_std.end();
        map_std.insert(it, val3);
        std::cout << map_std["cpp"] << std::endl;
        std::cout << map_std["ts"] << std::endl;
        std::cout << map_std["py"] << std::endl;
        map_std_2.insert(map_std.begin(), map_std.end());
        std::cout << map_std_2["cpp"] << std::endl;
        std::cout << map_std_2["ts"] << std::endl;
        std::cout << map_std_2["py"] << std::endl;
        std::cout << map_std_2.size() << std::endl;
    } else {
        ft::map<std::string, int>                   map_ft;
        ft::map<std::string, int>                   map_ft_2;
        ft::map<std::string, int>::iterator         it;
        ft::pair<std::string, int>     val1 = create_ft_pair("cpp", 7);
        ft::pair<std::string, int>     val2 = create_ft_pair("ts", 8);
        ft::pair<std::string, int>     val3 = create_ft_pair("py", 8);

        map_ft.insert(val1);
        map_ft.insert(val2);
        it = map_ft.end();
        map_ft.insert(it, val3);
        std::cout << map_ft["cpp"] << std::endl;
        std::cout << map_ft["ts"] << std::endl;
        std::cout << map_ft["py"] << std::endl;
        map_ft_2.insert(val1);
	map_ft_2.insert(val2);
	map_ft_2.insert(val3);
        std::cout << map_ft_2["cpp"] << std::endl; 
        std::cout << map_ft_2["ts"] << std::endl;
        std::cout << map_ft_2["py"] << std::endl;
        std::cout << map_ft_2.size() << std::endl;
    }
}

void    test_map_rbegin_and_rend(bool is_real_container)
{
    if (is_real_container)
    {
        std::map<std::string, std::string>  map_std;
        std::map<std::string, std::string>  map_std_2;
        std::pair<std::string, std::string>     val1 = create_std_pair("test", "value test");
        std::pair<std::string, std::string>     val2 = create_std_pair("test 1", "value test 1");

        map_std.insert(val1);
        map_std.insert(val2);
        std::map<std::string, std::string>::reverse_iterator   rit = map_std.rbegin();
        map_std_2.insert(rit, map_std.rend());
        std::cout << map_std_2["test"] << std::endl;
        std::cout << map_std_2["test 1"] << std::endl;
    } else {
        ft::map<std::string, std::string>  map_ft;
        ft::map<std::string, std::string>  map_ft_2;
        ft::pair<std::string, std::string>     val1 = create_ft_pair("test", "value test");
        ft::pair<std::string, std::string>     val2 = create_ft_pair("test 1", "value test 1");

        map_ft.insert(val1);
        map_ft.insert(val2);
        RIterator<std::string>    rit = map_ft.rbegin();
        map_ft_2.insert(rit, map_ft.rend());
        std::cout << map_ft_2["test"] << std::endl;
        std::cout << map_ft_2["test 1"] << std::endl;
    }
}

void    test_map_empty(bool is_real_container)
{
    if (is_real_container) {
        std::map<std::string, std::string>  map_std;
        std::pair<std::string, std::string> val = create_std_pair("hello", "world");

        std::cout << map_std.empty() << std::endl;
        map_std.insert(val);
        std::cout << map_std.empty() << std::endl;
    } else {
        ft::map<std::string, std::string>  map_ft;
        ft::pair<std::string, std::string> val = create_ft_pair("hello", "world");

        std::cout << map_ft.empty() << std::endl;
        map_ft.insert(val);
        std::cout << map_ft.empty() << std::endl;
    }
}

void    test_map_size(bool is_real_container)
{
    if (is_real_container) {
        std::map<std::string, std::string>  map_std;
        std::pair<std::string, std::string> val = create_std_pair("hello", "world");
        std::pair<std::string, std::string> val1 = create_std_pair("container", "map");

        std::cout << map_std.size() << std::endl;
        map_std.insert(val);
        std::cout << map_std.size() << std::endl;
        map_std.insert(val1);
        std::cout << map_std.size() << std::endl;
    } else {
        ft::map<std::string, std::string>  map_ft;
        ft::pair<std::string, std::string> val = create_ft_pair("hello", "world");
        ft::pair<std::string, std::string> val1 = create_ft_pair("container", "map");

        std::cout << map_ft.size() << std::endl;
        map_ft.insert(val);
        std::cout << map_ft.size() << std::endl;
        map_ft.insert(val1);
        std::cout << map_ft.size() << std::endl;
    }
}

void    test_map_clear(bool is_real_container)
{
    if (is_real_container) {
        std::map<std::string, std::string>  map_std;
        std::pair<std::string, std::string> val = create_std_pair("hello", "world");
        std::pair<std::string, std::string> val1 = create_std_pair("container", "map");

        map_std.insert(val);
        map_std.insert(val1);
        std::cout << map_std.size() << std::endl;
        map_std.clear();
        std::cout << map_std.size() << std::endl;
    } else {
        ft::map<std::string, std::string>  map_ft;
        ft::pair<std::string, std::string> val = create_ft_pair("hello", "world");
        ft::pair<std::string, std::string> val1 = create_ft_pair("container", "map");

        map_ft.insert(val);
        map_ft.insert(val1);
        std::cout << map_ft.size() << std::endl;
        map_ft.clear();
        std::cout << map_ft.size() << std::endl;
    }
}

void    test_map_count(bool is_real_container)
{
    if (is_real_container) {
        std::map<std::string, std::string>  map_std;
        std::pair<std::string, std::string> val = create_std_pair("hello", "world");
        std::pair<std::string, std::string> val1 = create_std_pair("container", "map");

        map_std.insert(val);
        map_std.insert(val1);
        std::cout << map_std.count("hello") << std::endl;
        map_std.clear();
        std::cout << map_std.count("do no exist") << std::endl;
    } else {
        ft::map<std::string, std::string>  map_ft;
        ft::pair<std::string, std::string> val = create_ft_pair("hello", "world");
        ft::pair<std::string, std::string> val1 = create_ft_pair("container", "map");

        map_ft.insert(val);
        map_ft.insert(val1);
        std::cout << map_ft.count("hello") << std::endl;
        map_ft.clear();
        std::cout << map_ft.count("do no exist") << std::endl;
    }
}

void    test_map_erase(bool is_real_container)
{
    if (is_real_container) {
        std::map<std::string, std::string>  map_std;
        std::pair<std::string, std::string> val = create_std_pair("hello", "world");
        std::pair<std::string, std::string> val1 = create_std_pair("container", "map");
        std::pair<std::string, std::string> val2 = create_std_pair("cout", "std");
        std::pair<std::string, std::string> val3 = create_std_pair("cin", "std");

        std::cout << "TEST MAP ERASE WITH ONE IT" << std::endl;
        map_std.insert(val);
        map_std.insert(val1);
        std::cout << map_std.size() << std::endl;
        std::map<std::string, std::string>::iterator it = map_std.begin();
        map_std.erase(it);
        std::cout << map_std.size() << std::endl;

        std::cout << "TEST MAP ERASE WITH KEY" << std::endl;
        map_std.clear();
        map_std.insert(val);
        map_std.insert(val1);
        std::cout << map_std.size() << std::endl;
        map_std.erase("hello");
        std::cout << map_std.size() << std::endl;
        map_std.erase("container");
        std::cout << map_std.size() << std::endl;

        std::cout << "TEST MAP ERASE WITH RANGE OF IT" << std::endl;
        map_std.clear();
        map_std.insert(val);
        map_std.insert(val1);
        map_std.insert(val2);
        map_std.insert(val3);
        std::map<std::string, std::string>::iterator it1 = map_std.begin();
        std::map<std::string, std::string>::iterator it2 = map_std.begin();
        it2++;
        std::cout << map_std.size() << std::endl;
        map_std.erase(it1, it2);
        std::cout << map_std.size() << std::endl;
    } else {
        ft::map<std::string, std::string>  map_ft;
        ft::pair<std::string, std::string> val = create_ft_pair("hello", "world");
        ft::pair<std::string, std::string> val1 = create_ft_pair("container", "map");
        ft::pair<std::string, std::string> val2 = create_ft_pair("cout", "std");
        ft::pair<std::string, std::string> val3 = create_ft_pair("cin", "std");

        std::cout << "TEST MAP ERASE WITH ONE IT" << std::endl;
        map_ft.insert(val);
        map_ft.insert(val1);
        std::cout << map_ft.size() << std::endl;
        ft::map<std::string, std::string>::iterator  it = map_ft.begin();
        map_ft.erase(it);
        std::cout << map_ft.size() << std::endl;

        std::cout << "TEST MAP ERASE WITH KEY" << std::endl;
        map_ft.clear();
        map_ft.insert(val);
        map_ft.insert(val1);
        std::cout << map_ft.size() << std::endl;
        map_ft.erase("hello");
        std::cout << map_ft.size() << std::endl;
        map_ft.erase("container");
        std::cout << map_ft.size() << std::endl;

        std::cout << "TEST MAP ERASE WITH RANGE OF IT" << std::endl;
        map_ft.clear();
        map_ft.insert(val);
        map_ft.insert(val1);
        map_ft.insert(val2);
        map_ft.insert(val3);
        ft::map<std::string, std::string>::iterator  it1 = map_ft.begin();
        ft::map<std::string, std::string>::iterator  it2 = map_ft.begin();
        (*it2)++;
        std::cout << map_ft.size() << std::endl;
        map_ft.erase(it1, it2);
        std::cout << map_ft.size() << std::endl;
    }
}

void    test_key_comp(bool is_real_container)
{
    if (is_real_container) {
        std::map<std::string, std::string>                  map_std;
        std::map<std::string, std::string>::iterator  it;
        std::pair<std::string, std::string> val = create_std_pair("hello", "world");
        std::pair<std::string, std::string> val1 = create_std_pair("container", "map");
        std::pair<std::string, std::string> val2 = create_std_pair("cout", "std");
        std::pair<std::string, std::string> val3 = create_std_pair("cin", "std");

        map_std.insert(val);
        map_std.insert(val1);
        map_std.insert(val2);
        map_std.insert(val3);
        it = map_std.begin();
        std::cout << it->first << std::endl;
        std::less<std::string>    key_comp = map_std.key_comp();
        std::cout << key_comp(it->first, "hello world") << std::endl;
        std::cout << key_comp(it->first, "cin") << std::endl;
    } else {
        ft::map<std::string, std::string>                   map_ft;
        ft::map<std::string, std::string>::iterator   it;
        ft::pair<std::string, std::string> val = create_ft_pair("hello", "world");
        ft::pair<std::string, std::string> val1 = create_ft_pair("container", "map");
        ft::pair<std::string, std::string> val2 = create_ft_pair("cout", "std");
        ft::pair<std::string, std::string> val3 = create_ft_pair("cin", "std");

        map_ft.insert(val);
        map_ft.insert(val1);
        map_ft.insert(val2);
        map_ft.insert(val3);
        it = map_ft.begin();
        std::cout << it->first << std::endl;
        std::less<std::string>    key_comp = map_ft.key_comp();
        std::cout << key_comp(it->first, "hello world") << std::endl;
        std::cout << key_comp(it->first, "cin") << std::endl;
    }
}

void    test_map_lower_bound(bool is_real_container)
{
    if (is_real_container) {
        std::map<std::string, std::string>              map_std;
        std::map<std::string, std::string>::iterator    it;
        std::pair<std::string, std::string> val = create_std_pair("hello", "world");
        std::pair<std::string, std::string> val1 = create_std_pair("container", "map");
        std::pair<std::string, std::string> val2 = create_std_pair("cout", "std");
        std::pair<std::string, std::string> val3 = create_std_pair("cin", "std");

        map_std.insert(val);
        map_std.insert(val1);
        map_std.insert(val2);
        map_std.insert(val3);
        it = map_std.lower_bound("hello");
        std::cout << it->first << std::endl;
        it = map_std.lower_bound("aaaa");
        std::cout << it->first << std::endl;
        it = map_std.lower_bound("containeq");
        std::cout << it->first << std::endl;
    } else {
        ft::map<std::string, std::string>               map_ft;
        ft::map<std::string, std::string>::iterator    it;
        ft::pair<std::string, std::string> val3 = create_ft_pair("cin", "std");
        ft::pair<std::string, std::string> val1 = create_ft_pair("container", "map");
        ft::pair<std::string, std::string> val2 = create_ft_pair("cout", "std");
        ft::pair<std::string, std::string> val = create_ft_pair("hello", "world");

        map_ft.insert(val);
        map_ft.insert(val1);
        map_ft.insert(val2);
        map_ft.insert(val3);
        it = map_ft.lower_bound("hello");
        std::cout << it->first << std::endl;
        it = map_ft.lower_bound("aaaa");
        std::cout << it->first << std::endl;
        it = map_ft.lower_bound("containeq");
        std::cout << it->first << std::endl;
    }
}

void    test_map_sorted(bool is_real_container)
{
    if (is_real_container) {
        std::map<std::string, std::string>              map_std;
        std::map<std::string, std::string>::iterator    it;
        std::pair<std::string, std::string> val = create_std_pair("hello", "world");
        std::pair<std::string, std::string> val1 = create_std_pair("container", "map");
        std::pair<std::string, std::string> val2 = create_std_pair("cout", "std");
        std::pair<std::string, std::string> val3 = create_std_pair("cin", "std");

        map_std.insert(val);
        map_std.insert(val1);
        map_std.insert(val2);
        map_std.insert(val3);

        it = map_std.begin();
        while (it != map_std.end())
        {
            std::cout << it->first << std::endl;
            it++;
        }
    } else {
        ft::map<std::string, std::string>               map_ft;
        ft::map<std::string, std::string>::iterator    it;
        ft::pair<std::string, std::string> val = create_ft_pair("hello", "world");
        ft::pair<std::string, std::string> val1 = create_ft_pair("container", "map");
        ft::pair<std::string, std::string> val2 = create_ft_pair("cout", "std");
        ft::pair<std::string, std::string> val3 = create_ft_pair("cin", "std");

        map_ft.insert(val);
        map_ft.insert(val1);
        map_ft.insert(val2);
        map_ft.insert(val3);

        it = map_ft.begin();

        while (it->getPosition() < map_ft.end()->getPosition())
        {
            std::cout << it->first << std::endl;
            (*it)++;
        }
    }
}

void    test_map_iterator(bool is_real_container)
{
    if (is_real_container){
        std::map<std::string, std::string>              map_std;
        std::map<std::string, std::string>::iterator    it;
        std::pair<std::string, std::string> val = create_std_pair("hello", "world");
        std::pair<std::string, std::string> val1 = create_std_pair("container", "map");
        std::pair<std::string, std::string> val2 = create_std_pair("cout", "std");

        map_std.insert(val);
        map_std.insert(val1);
        map_std.insert(val2);
        it = map_std.begin();
        std::cout << it->first << std::endl;
        it++;
        std::cout << it->first << std::endl;
    } else {
        ft::map<std::string, std::string>           map_ft;
        ft::map<std::string, std::string>::iterator it;
        ft::pair<std::string, std::string> val = create_ft_pair("hello", "world");
        ft::pair<std::string, std::string> val1 = create_ft_pair("container", "map");
        ft::pair<std::string, std::string> val2 = create_ft_pair("cout", "std");

        map_ft.insert(val);
        map_ft.insert(val1);
        map_ft.insert(val2);
        it = map_ft.begin();
        std::cout << it->first << std::endl;
        (*it)++;
        std::cout << it->first << std::endl;
    }
}

void    test_map_upper_bound(bool is_real_container)
{
    if (is_real_container) {
        std::map<std::string, std::string>  map_std;
        std::pair<std::string, std::string> val3 = create_std_pair("cin", "std");
        std::pair<std::string, std::string> val1 = create_std_pair("container", "map");
        std::pair<std::string, std::string> val2 = create_std_pair("cout", "std");
        std::pair<std::string, std::string> val = create_std_pair("hello", "world");

        map_std.insert(val);
        map_std.insert(val1);
        map_std.insert(val2);
        map_std.insert(val3);
        std::cout << map_std.upper_bound("cout")->first << std::endl;
        std::cout << map_std.upper_bound("cin")->first << std::endl;
    } else {
        ft::map<std::string, std::string>  map_ft;
        ft::pair<std::string, std::string> val3 = create_ft_pair("cin", "std");
        ft::pair<std::string, std::string> val1 = create_ft_pair("container", "map");
        ft::pair<std::string, std::string> val2 = create_ft_pair("cout", "std");
        ft::pair<std::string, std::string> val = create_ft_pair("hello", "world");

        map_ft.insert(val);
        map_ft.insert(val1);
        map_ft.insert(val2);
        map_ft.insert(val3);
        std::cout << map_ft.upper_bound("cout")->first << std::endl;
        std::cout << map_ft.upper_bound("cin")->first << std::endl;
    }
}

void    test_map_find(bool is_real_container)
{
    if (is_real_container) {
        std::map<std::string, std::string>  map_std;
        std::pair<std::string, std::string> val3 = create_std_pair("cin", "std");
        std::pair<std::string, std::string> val1 = create_std_pair("container", "map");
        std::pair<std::string, std::string> val2 = create_std_pair("cout", "std");
        std::pair<std::string, std::string> val = create_std_pair("hello", "world");

        map_std.insert(val);
        map_std.insert(val1);
        map_std.insert(val2);
        map_std.insert(val3);
        std::cout << map_std.find("container")->second << std::endl;
        std::cout << map_std.find("cin")->second << std::endl;
    } else {
        ft::map<std::string, std::string>  map_ft;
        ft::pair<std::string, std::string> val3 = create_ft_pair("cin", "std");
        ft::pair<std::string, std::string> val1 = create_ft_pair("container", "map");
        ft::pair<std::string, std::string> val2 = create_ft_pair("cout", "std");
        ft::pair<std::string, std::string> val = create_ft_pair("hello", "world");

        map_ft.insert(val);
        map_ft.insert(val1);
        map_ft.insert(val2);
        map_ft.insert(val3);
        std::cout << map_ft.find("container")->second << std::endl;
        std::cout << map_ft.find("cin")->second << std::endl;
    }
}

void    test_map_element_access(bool is_real_container)
{
    if (is_real_container) {
        std::map<std::string, std::string>  map_std;
        std::pair<std::string, std::string> val3 = create_std_pair("cin", "std");
        std::pair<std::string, std::string> val1 = create_std_pair("container", "map");
        std::pair<std::string, std::string> val2 = create_std_pair("cout", "std::");
        std::pair<std::string, std::string> val = create_std_pair("hello", "world");

        map_std.insert(val);
        map_std.insert(val1);
        map_std.insert(val2);
        map_std.insert(val3);
        std::cout << map_std["cout"] << std::endl;
        std::cout << map_std["hello"] << std::endl;
        std::cout << map_std["cin"] << std::endl;
    } else {
        ft::map<std::string, std::string>  map_ft;
        ft::pair<std::string, std::string> val3 = create_ft_pair("cin", "std");
        ft::pair<std::string, std::string> val1 = create_ft_pair("container", "map");
        ft::pair<std::string, std::string> val2 = create_ft_pair("cout", "std::");
        ft::pair<std::string, std::string> val = create_ft_pair("hello", "world");

        map_ft.insert(val);
        map_ft.insert(val1);
        map_ft.insert(val2);
        map_ft.insert(val3);
        std::cout << map_ft["cout"] << std::endl;
        std::cout << map_ft["hello"] << std::endl;
        std::cout << map_ft["cin"] << std::endl;
    }
}

void    test_map_operator_equal(bool is_real_container)
{
    if (is_real_container) {
        std::map<std::string, std::string>  map_std;
        std::map<std::string, std::string>  map_std_2;
        std::pair<std::string, std::string> val3 = create_std_pair("cin", "std");
        std::pair<std::string, std::string> val1 = create_std_pair("container", "map");
        std::pair<std::string, std::string> val2 = create_std_pair("cout", "std::");
        std::pair<std::string, std::string> val = create_std_pair("hello", "world");

        map_std.insert(val);
        map_std.insert(val1);
        map_std.insert(val2);
        map_std.insert(val3);
        map_std_2 = map_std;
        std::cout << map_std_2["cout"] << std::endl;
        std::cout << map_std_2["hello"] << std::endl;
        std::cout << map_std_2["cin"] << std::endl;
    } else {
        ft::map<std::string, std::string>  map_ft;
        ft::map<std::string, std::string>  map_ft_2;
        ft::pair<std::string, std::string> val3 = create_ft_pair("cin", "std");
        ft::pair<std::string, std::string> val1 = create_ft_pair("container", "map");
        ft::pair<std::string, std::string> val2 = create_ft_pair("cout", "std::");
        ft::pair<std::string, std::string> val = create_ft_pair("hello", "world");

        map_ft.insert(val);
        map_ft.insert(val1);
        map_ft.insert(val2);
        map_ft.insert(val3);
        map_ft_2 = map_ft;
        std::cout << map_ft_2["cout"] << std::endl;
        std::cout << map_ft_2["hello"] << std::endl;
        std::cout << map_ft_2["cin"] << std::endl;
    }
}

void    test_map_swap(bool is_real_container)
{
    if (is_real_container) {
        std::map<std::string, std::string>  map_std;
        std::map<std::string, std::string>  map_std_2;
        std::pair<std::string, std::string> val = create_std_pair("a", "a");
        std::pair<std::string, std::string> val1 = create_std_pair("b", "b");
        std::pair<std::string, std::string> val2 = create_std_pair("c", "c");
        std::pair<std::string, std::string> val3 = create_std_pair("d", "d");

        map_std.insert(val);
        map_std.insert(val1);
        map_std_2.insert(val2);
        map_std_2.insert(val3);
        std::cout << map_std.size() << " " << map_std_2.size() << std::endl;
        map_std.swap(map_std_2);
        std::cout << map_std.size() << " " << map_std_2.size() << std::endl;
        std::cout << map_std["c"] << std::endl;
        std::cout << map_std["d"] << std::endl;
        std::cout << map_std_2["a"] << std::endl;
        std::cout << map_std_2["b"] << std::endl;
        map_std_2.swap(map_std);
        std::cout << map_std.size() << " " << map_std_2.size() << std::endl;
        std::cout << map_std["a"] << std::endl;
        std::cout << map_std["b"] << std::endl;
        std::cout << map_std_2["c"] << std::endl;
        std::cout << map_std_2["d"] << std::endl;
    } else {
        ft::map<std::string, std::string>  map_ft;
        ft::map<std::string, std::string>  map_ft_2;
        ft::pair<std::string, std::string> val = create_ft_pair("a", "a");
        ft::pair<std::string, std::string> val1 = create_ft_pair("b", "b");
        ft::pair<std::string, std::string> val2 = create_ft_pair("c", "c");
        ft::pair<std::string, std::string> val3 = create_ft_pair("d", "d");

        map_ft.insert(val);
        map_ft.insert(val1);
        map_ft_2.insert(val2);
        map_ft_2.insert(val3);
        std::cout << map_ft.size() << " " << map_ft_2.size() << std::endl;
        map_ft.swap(map_ft_2);
        std::cout << map_ft.size() << " " << map_ft_2.size() << std::endl;
        std::cout << map_ft["c"] << std::endl;
        std::cout << map_ft["d"] << std::endl;
        std::cout << map_ft_2["a"] << std::endl;
        std::cout << map_ft_2["b"] << std::endl;
        map_ft_2.swap(map_ft);
        std::cout << map_ft.size() << " " << map_ft_2.size() << std::endl;
        std::cout << map_ft["a"] << std::endl;
        std::cout << map_ft["b"] << std::endl;
        std::cout << map_ft_2["c"] << std::endl;
        std::cout << map_ft_2["d"] << std::endl;
    }
}

void    test_map_equal_range(bool is_real_container)
{
    if (is_real_container) {
        std::map<std::string, std::string>  map_std;
        std::pair<std::string, std::string> val3 = create_std_pair("cin", "std");
        std::pair<std::string, std::string> val1 = create_std_pair("container", "map");
        std::pair<std::string, std::string> val2 = create_std_pair("cout", "std::");
        std::pair<std::string, std::string> val = create_std_pair("hello", "world");

        map_std.insert(val);
        map_std.insert(val1);
        map_std.insert(val2);
        map_std.insert(val3);

        std::cout << map_std.equal_range("cin").first->first << std::endl;
        std::cout << map_std.equal_range("hello").first->first << std::endl;
    } else {
        ft::map<std::string, std::string>  map_ft;
        ft::pair<std::string, std::string> val3 = create_ft_pair("cin", "std");
        ft::pair<std::string, std::string> val1 = create_ft_pair("container", "map");
        ft::pair<std::string, std::string> val2 = create_ft_pair("cout", "std::");
        ft::pair<std::string, std::string> val = create_ft_pair("hello", "world");

        map_ft.insert(val);
        map_ft.insert(val1);
        map_ft.insert(val2);
        map_ft.insert(val3);

        std::cout << map_ft.equal_range("cin").first->first << std::endl;
        std::cout << map_ft.equal_range("hello").first->first << std::endl;
    }
}

void    test_map_get_allocator(bool is_real_container)
{
    if (is_real_container) {
        std::map<char, int>  map_std;
        std::pair<const char, int> *p;

        p = map_std.get_allocator().allocate(5);
        std::cout << sizeof(std::map<char, int>::value_type) * 5 << std::endl;
        map_std.get_allocator().deallocate(p, 5);
    } else {
        ft::map<char, int>  map_ft;
        ft::pair<const char, int> *p;

        p = map_ft.get_allocator().allocate(5);
        std::cout << sizeof(ft::map<char, int>::value_type) * 5 << std::endl;
        map_ft.get_allocator().deallocate(p, 5);
    }
}

void    test_map_value_comp(bool is_real_container)
{
    if (is_real_container) {
        std::map<std::string, std::string>  map_std;
        std::map<std::string, std::string>::value_compare  value_comp = map_std.value_comp();
        std::pair<std::string, std::string> val3 = create_std_pair("cin", "std");
        std::pair<std::string, std::string> val = create_std_pair("hello", "world");

        map_std.insert(val);
        map_std.insert(val3);
        std::cout << value_comp(*map_std.end(), *map_std.begin()) << std::endl;
    } else {
        ft::map<std::string, std::string>  map_ft;
        ft::map<std::string, std::string>::value_compare  value_comp = map_ft.value_comp();
        ft::pair<std::string, std::string> val3 = create_ft_pair("cin", "std");
        ft::pair<std::string, std::string> val = create_ft_pair("hello", "world");

        map_ft.insert(val);
        map_ft.insert(val3);
        std::cout << value_comp(*map_ft.end(), *map_ft.begin()) << std::endl;
    }
}

void    test_map_max_size(bool is_real_container)
{
    if (is_real_container) {
        std::map<std::string, std::string>  map_std;

        std::cout << map_std.max_size() << std::endl;
    } else {
        ft::map<std::string, std::string>  map_ft;

        std::cout << map_ft.max_size() << std::endl;
    }
}
