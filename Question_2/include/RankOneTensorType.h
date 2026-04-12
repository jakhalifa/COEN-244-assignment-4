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

        friend std::ostream& operator<<(std::ostream& os, const RankOneTensorType<T>& tensor_out);
        friend std::istream& operator>>(std::istream& is, RankOneTensorType<T>& tensor_in);
};

template class RankOneTensorType<double>;
template class RankOneTensorType<char>;
template class RankOneTensorType<int>;
template class RankOneTensorType<std::string>;
