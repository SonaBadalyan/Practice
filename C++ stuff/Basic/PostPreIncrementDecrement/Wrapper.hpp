#ifndef WRAPPER_H
#define WRAPPER_H

class Integer
{
    public:
        Integer(int data) : m_data(data) {}

        Integer&  operator++() // pre-increment 
        {
            ++m_data;
            return *this;  
        }

        Integer operator++(int) // post-increment
        {
            Integer temp_data = *this;
            m_data++;
            return temp_data;
        } 

        Integer& operator--() // pre-decrement
        {
            --m_data;
            return *this;

        }

        Integer operator--(int) // post-decrement
        {
            Integer temp_data = *this;
            m_data--;
            return temp_data;
        }

        int get_value() const 
        {
            return m_data;
        }

    private:
        int m_data;
};

#endif // WRAPPER_H