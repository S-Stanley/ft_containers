#ifndef VECTOR_HPP
# define VECTOR_HPP

namespace ft {
    template <typename T>
    class vector {
        public:
            vector(void): _tab(NULL), _len(0) {};
            ~vector(void) {};
            void    push_back(const T &val)
            {
                T   *update = new T[this->size() + 1];
                int     i;

                for (i = 0; i < this->size(); i++)
                    update[i] = this->_tab[i];
                update[i] = val;
                this->_tab = update;
                this->_len++;
            }
            int     size(void)
            {
                return (this->_len);
            }
            T       &operator[](const unsigned int N)
            {
                return (this->_tab[N]);
            }
        private:
            T               *_tab;
            unsigned int    _len;
    };
}


#endif