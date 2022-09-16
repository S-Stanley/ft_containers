#ifndef STACK_HPP
# define STACK_HPP

namespace ft {
    template <typename Value, typename Container = std::deque<Value> >

    class stack {
        public:

            typedef Value 			value_type;
            typedef Container		container_type;
            typedef unsigned int	size_type;

            stack(void){
                this->_data = NULL;
                this->_size = 0;
            };
            virtual ~stack(void){
                if (this->_data) {
                    delete[] this->_data;
                }
            };

            bool	operator==(const ft::stack<Value> &comp)
            {
                unsigned int i = 0;

                if (this->size() != comp.size())
                    return (false);
                while (i != this->_size)
                {
                    if (this->_data[i] != comp._data[i])
                        return (false);
                    i++;
                }
                return (true);
            }
            bool	operator!=(const ft::stack<Value> &comp)
            {
                unsigned int i = 0;

                if (this->size() != comp.size())
                    return (true);
                while (i != this->_size)
                {
                    if (this->_data[i] != comp._data[i])
                        return (true);
                    i++;
                }
                return (false);
            }
            bool	operator<(const ft::stack<Value> &comp)
            {
                unsigned int i = 0;

                if (this->size() < comp.size())
                    return (false);
                while (i != this->_size)
                {
                    if (this->_data[i] >= comp._data[i])
                        return (false);
                    i++;
                }
                return (true);
            }
            bool	operator<=(const ft::stack<Value> &comp)
            {
                unsigned int i = 0;

                if (this->size() > comp.size())
                    return (false);
                while (i != this->_size && i != comp._size)
                {
                    if (this->_data[i] > comp._data[i])
                        return (false);
                    i++;
                }
                return (true);
            }
            bool	operator>(const ft::stack<Value> &comp)
            {
                unsigned int i = 0;

                if (this->size() > comp.size())
                    return (true);
                while (i != this->_size)
                {
                    if (this->_data[i] <= comp._data[i])
                        return (false);
                    i++;
                }
                return (true);
            }
            bool	operator>=(const ft::stack<Value> &comp)
            {
                unsigned int i = 0;

                if (this->size() < comp.size())
                    return (false);
                while (i != this->_size && i != comp._size)
                {
                    if (this->_data[i] < comp._data[i])
                        return (false);
                    i++;
                }
                return (true);
            }

            bool        empty(void) const {
                if (!this->_data) {
                    return (true);
                }
                return (false);
            }
            size_type   size(void) const {
                return (this->_size);
            }
            value_type  &top(void) {
                return (this->_data[this->_size -1]);
            }
            const value_type    &top(void) const {
                return (this->_data[this->_size -1]);
            }
            void        push(const value_type &val) {
                size_type   i = 0;
                value_type  *new_data = new value_type[this->_size + 1];

                if (!this->_data) {
                    new_data[0] = val;
                    this->_data = new_data;
                    this->_size = 1;
                    return ;
                }
                while (i < this->_size) {
                    new_data[i] = this->_data[i];
                    i++;
                }
                new_data[i] = val;
                delete[] this->_data;
                this->_data = new_data;
                this->_size++;
            }
            void        pop(void) {
                size_type   i = 0;
                value_type  *new_data = new value_type[this->_size - 1];

                if (!this->_data) {
                    return ;
                }
                while (i < (this->_size - 1)) {
                    new_data[i] = this->_data[i];
                    i++;
                }
                delete[] this->_data;
                this->_data = new_data;
                this->_size--;
            }
        private:
            value_type      *_data;
            size_type       _size;
        protected:
            container_type  c;
    };
}

#endif
