#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "BaseTensor.h"

template<typename T>
class RankOneTensorType : public BaseTensor
{
    private:
        std::vector<T> data;

    public:
        RankOneTensorType();
        RankOneTensorType(int size);

        void set_data_size(int size);
        int get_data_size() const;
        T get_data_element(int index) const;
        void loadData() override;

        RankOneTensorType<T>& operator++();
        RankOneTensorType<T> operator+(const RankOneTensorType<T>& other) const;
        RankOneTensorType<T> operator+(const T& scalar) const;
        RankOneTensorType<T>& operator=(const RankOneTensorType<T>& other);
        T& operator[](int index);
        const T& operator[](int index) const;

        template<typename U>
        friend std::ostream& operator<<(std::ostream& os, const RankOneTensorType<U>& tensor_out);

        template<typename U>
        friend std::istream& operator>>(std::istream& is, RankOneTensorType<U>& tensor_in);
};

template<typename U>
std::ostream& operator<<(std::ostream& os, const RankOneTensorType<U>& tensor_out)
{
    for (const auto& x : tensor_out.data)
        os << x << " ";
    return os;
}

template<typename U>
std::istream& operator>>(std::istream& is, RankOneTensorType<U>& tensor_in)
{
    for (auto& x : tensor_in.data)
        is >> x;
    return is;
}

template class RankOneTensorType<double>;
template class RankOneTensorType<char>;
template class RankOneTensorType<int>;
template class RankOneTensorType<std::string>;
