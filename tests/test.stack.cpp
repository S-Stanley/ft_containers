#include "./test.stack.hpp"

void    compile_stack(bool is_real_container)
{
    if (is_real_container) {
        std::stack<int> std_stack;
        std::stack<int, std::vector<int> > std_stack_2;

        std_stack.push(4);
        std_stack_2.push(4);
    } else {
        ft::stack<int> ft_stack;
        ft::stack<int, ft::vector<int> > ft_stack_2;

        ft_stack.push(4);
        ft_stack_2.push(4);
    }
}

void    stack_empty(bool is_real_container)
{
    if (is_real_container) {
        std::stack<int, std::vector<int> > std_stack;

        std::cout << std_stack.empty() << std::endl;
        std_stack.push(4);
        std::cout << std_stack.empty() << std::endl;
    } else {
        ft::stack<int, ft::vector<int> > ftm;

        std::cout << ftm.empty() << std::endl;
        ftm.push(4);
        std::cout << ftm.empty() << std::endl;
    }
}

void    stack_size(bool is_real_container)
{
    if (is_real_container) {
        std::stack<int, std::vector<int> > std_stack;

        std::cout << std_stack.size() << std::endl;
        std_stack.push(4);
        std::cout << std_stack.size() << std::endl;
        std_stack.push(42);
        std::cout << std_stack.size() << std::endl;
    } else {
        ft::stack<int, ft::vector<int> > ft_stack;

        std::cout << ft_stack.size() << std::endl;
        ft_stack.push(4);
        std::cout << ft_stack.size() << std::endl;
        ft_stack.push(42);
        std::cout << ft_stack.size() << std::endl;
    }
}

void    stack_top(bool is_real_container)
{
    if (is_real_container) {
        std::stack<int, std::vector<int> > std_stack;

        std_stack.push(4);
        std::cout << std_stack.top() << std::endl;
        std_stack.push(42);
        std::cout << std_stack.top() << std::endl;
        std_stack.push(2);
        std::cout << std_stack.top() << std::endl;
    } else {
        ft::stack<int, ft::vector<int> > ft_stack;

        ft_stack.push(4);
        std::cout << ft_stack.top() << std::endl;
        ft_stack.push(42);
        std::cout << ft_stack.top() << std::endl;
        ft_stack.push(2);
        std::cout << ft_stack.top() << std::endl;
    }
}

void    stack_push(bool is_real_container)
{
    if (is_real_container) {
        std::stack<int, std::vector<int> > std_stack;

        std::cout << std_stack.size() << std::endl;
        std_stack.push(4);
        std::cout << std_stack.size() << std::endl;
    } else {
        ft::stack<int, ft::vector<int> > ft_stack;

        std::cout << ft_stack.size() << std::endl;
        ft_stack.push(4);
        std::cout << ft_stack.size() << std::endl;
    }
}

void    stack_pop(bool is_real_container)
{
    if (is_real_container) {
        std::stack<int, std::vector<int> > std_stack;

        std::cout << std_stack.size() << std::endl;
        std_stack.push(4);
        std_stack.push(42);
        std::cout << std_stack.size() << std::endl;
        std::cout << std_stack.top() << std::endl;
        std_stack.pop();
        std::cout << std_stack.size() << std::endl;
        std::cout << std_stack.top() << std::endl;
    } else {
        ft::stack<int, ft::vector<int> > ft_stack;

        std::cout << ft_stack.size() << std::endl;
        ft_stack.push(4);
        ft_stack.push(42);
        std::cout << ft_stack.size() << std::endl;
        std::cout << ft_stack.top() << std::endl;
        ft_stack.pop();
        std::cout << ft_stack.size() << std::endl;
        std::cout << ft_stack.top() << std::endl;
    }
}