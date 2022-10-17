#include <iostream>

template <int SIZE, typename DATA_TYPE = int>
class CircularBuffer
{
public:
    typedef int INDEX_TYPE;
private:
    DATA_TYPE _data[SIZE];
    INDEX_TYPE _readCount { 0 };
    INDEX_TYPE _writeCount { 0 };
    static const INDEX_TYPE _indexMask = SIZE - 1;
public:
    bool write(DATA_TYPE newValue)
    {
        if (isFull())
            return false;
        _data[_writeCount++ & _indexMask] = newValue;
        return true;
    }

    bool read(DATA_TYPE& value)
    {
        if (isEmpty())
            return false;
        value = _data[_readCount++ & _indexMask];
        return true;
    }

    INDEX_TYPE size()
    {
        return SIZE;
    }

    bool isFull() const
    {
        return ((INDEX_TYPE)(_writeCount - _readCount) & (INDEX_TYPE)~(_indexMask)) != 0;
    }

    bool isEmpty() const
    {
        return _writeCount == _readCount;
    }

    void clear()
    {
        _readCount = 0;
        _writeCount = 0;
    }
};


