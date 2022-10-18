#include <iostream>

template<typename DATA_TYPE = int>
class CircularBuffer
{
typedef int INDEX_TYPE;
private:
    DATA_TYPE* _data;
    INDEX_TYPE _head;
    INDEX_TYPE _tail;
    INDEX_TYPE _countOfElements;
    INDEX_TYPE _size;
public:
    CircularBuffer(INDEX_TYPE bufferSize)
    {
        _data = new DATA_TYPE[bufferSize];
        _size = bufferSize;
        _countOfElements = 0;
        _head = 0;
        _tail = 0;
    }
    
    bool write(DATA_TYPE newValue)
    {
        if (isFull())
            return false;

        _data[_tail] = newValue;
        _tail = (_tail + 1) % _size;
        _countOfElements++;
        return true;
    }

    bool read(DATA_TYPE& value)
    {
        if (isEmpty())
            return false;

        value = _data[_head];
        _head = (_head + 1) % _size;
        _countOfElements--;
        return true;
    }

    INDEX_TYPE size()
    {
        return _size;
    }

    bool isFull()const
    {
        return _countOfElements == _size;
    }

    bool isEmpty() const
    {
        return !(_countOfElements);
    }

    void clear()
    {
        _head = 0;
        _tail = 0;
        _countOfElements = 0;
    }
};

