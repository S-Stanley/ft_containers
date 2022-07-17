#ifndef STACK_HPP
# define STACK_HPP

namespace ft {
    template <typename Value, typename Container = std::vector<Value> >

    class stack {
        public:
            stack(void){
                this->_data = NULL;
                this->_size = 0;
            };
            virtual ~stack(void){
                if (this->_data) {
                    delete[] this->_data;
                }
            };

            typedef unsigned int size_type;
            typedef Value value_type;

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
            value_type  *_data;
            size_type   _size;
    };
}

#endif
