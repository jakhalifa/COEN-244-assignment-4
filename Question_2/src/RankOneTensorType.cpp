#include <stdlib.h>
#include <string>
#include <stdexcept>
#include <algorithm>

#include "RankOneTensorType.h"

using namespace std;

template <typename T>
RankOneTensorType<T>::RankOneTensorType() : data(0)
{
    /* nothing to do */
}

template <typename T>
RankOneTensorType<T>::RankOneTensorType(int size) : data(size)
{
    /* nothing to do */
}

template<typename T>
void RankOneTensorType<T>::set_data_size(int size)
{
    data.resize(size);
}

template <typename T>
int RankOneTensorType<T>::get_data_size() const
{
    return data.size();
}

template <typename T>
T RankOneTensorType<T>::get_data_element(int index) const
{
    return data.at(index);
}

/*

    Value Gen
    - double
    - char
    - int
    - string

*/
template <typename T>
static T valueGen() {
    return T();
}

template <>
double valueGen<double>()
{
    return rand() % 100 / 10.0;
}

/*
    A bit sketchy, but generate a number from 0 -> 25, then add 65 to bring to the range 65 -> 90, then cast to char

    using doubles and casting will make it more "random"
*/
template <>
char valueGen<char>()
{
    return (char)((int)((double)rand() / ((double)RAND_MAX + 1) * 26) + 65);
}

/* 0 -> rand_max inclusive */
template <>
int valueGen<int>()
{
    return rand();
}

template <>
string valueGen<string>() {
    string foo = "";
    for (int i = 0; i < 10; i++)
    {
        char str[2] = { 0 };
        str[0] = valueGen<char>();
        foo.append(str);
    }
    return foo;
}

/*

    Load Data

*/
template<>
void RankOneTensorType<double>::loadData()
{
    fill(data.begin(), data.end(), valueGen<double>());
}
template<>
void RankOneTensorType<char>::loadData()
{
    fill(data.begin(), data.end(), valueGen<char>());
}
template<>
void RankOneTensorType<int>::loadData()
{
    fill(data.begin(), data.end(), valueGen<int>());
}
template<>
void RankOneTensorType<string>::loadData()
{
    fill(data.begin(), data.end(), valueGen<string>());
}

/*

    Handle operators

*/

template<typename T>
RankOneTensorType<T>& RankOneTensorType<T>::operator++()
{
    for (int i = 0; i < data.size(); i++)
        data[i] += 1;
    return *this;
}

template<typename T>
RankOneTensorType<T> RankOneTensorType<T>::operator+(const RankOneTensorType<T>& other) const
{
    if (data.size() != other.data.size())
        throw invalid_argument("Size mismatch");

    RankOneTensorType<T> result(data.size());

    for (int i = 0; i < data.size(); i++)
        result.data[i] = data[i] + other.data[i];

    return result;
}

template<typename T>
RankOneTensorType<T> RankOneTensorType<T>::operator+(const T& value) const
{
    RankOneTensorType<T> result(data.size());

    for (int i = 0; i < data.size(); i++)
        result.data[i] = data[i] + value;

    return result;
}

template<typename T>
RankOneTensorType<T>& RankOneTensorType<T>::operator=(const RankOneTensorType<T>& other)
{
    if (data.size() != other.data.size())
        throw invalid_argument("Size mismatch");

    data = other.data;
    return *this;
}

template<typename T>
T& RankOneTensorType<T>::operator[](int index)
{
    if (index < 0 || index >= data.size())
        throw invalid_argument("Out of range");

    return data[index];
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const RankOneTensorType<T>& tensor_out)
{
    for(const auto& val : tensor_out.data)
        os << val << " ";
    return os;
}

template<typename T>
std::istream& operator>>(std::istream& is, RankOneTensorType<T>& tensor_in)
{
    for(auto& val : tensor_in.data)
        is >> val;
    return is;
}