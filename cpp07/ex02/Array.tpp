#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T> Array<T>::Array() : _arr(NULL), _size(0)
{
}

template <typename T> Array<T>::Array(unsigned int n) : _arr(new T[n]), _size(n)
{
}

template <typename T>
Array<T>::Array(Array const &src) : _arr(new T[src._size]), _size(src._size)
{
    unsigned int i;

    i = 0;
    while (i < _size)
    {
        this->_arr[i] = src._arr[i];
        i++;
    }
}

template <typename T> Array<T>::~Array()
{
    delete[] _arr;
}

template <typename T> Array<T> &Array<T>::operator=(Array const &src)
{
    unsigned int i;

    i = 0;
    if (this != &src)
    {
        delete[] _arr;
        _size = src._size;
        _arr = new T[_size];
        while (i < _size)
        {
            _arr[i] = src._arr[i];
            i++;
        }
    }
    return (*this);
}

template <typename T> unsigned int Array<T>::size() const
{
    return (_size);
}

template <typename T> void Array<T>::printArray() const
{
    unsigned int i;

    i = 0;
    while (i < _size)
    {
        std::cout << _arr[i] << " ";
        i++;
    }
    std::cout << std::endl;
}

template <typename T> T &Array<T>::operator[](unsigned int i)
{
    if (i >= _size)
        throw OutOfBoundsException();
    return (_arr[i]);
}

template <typename T> T const &Array<T>::operator[](unsigned int i) const
{
    if (i >= _size)
        throw OutOfBoundsException();
    return (_arr[i]);
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
    return ("Index out of bounds");
}

#endif
