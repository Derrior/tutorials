#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>


inline int mod(int val, int mod) {
    if (val < 0) {
        return mod - abs(val) % mod;
    }
    return val % mod;
}

template <typename T>
class Array {
    std::vector<T> data_;

 public:
    Array(const std::initializer_list<T> &elems) : data_(elems.begin(), elems.end()) {
    }
    Array(const std::vector<T> &elems) : data_(elems.begin(), elems.end()) {
    }
    Array(size_t length = 0, const T &val = T()) : data_(length, val) {
    }

    size_t size() const {
        return data_.size();
    }

    bool empty() const {
        return data_.empty();
    }

    Array slice(int begin, int end) const {
        if (begin >= end) {
            return Array();
        }
        std::vector<T> result;
        while (begin < end) {
            result.push_back((*this)[begin]);
            begin++;
        return Array(result);
    }

    std::ostream& out(const std::string &sep = " ", std::ostream& stream = std::cout) const {
        bool isFirstElement = true;
        for (size_t i = 0; i + 1 < size(); i++) {
            stream << data_[i];
            if (!isFirstElement) {
                stream << sep;
            }
            isFirstElement = false;
        }
        return stream;
    }

    const T& operator[](int index) const {
        if (empty()) {
            throw std::range_error("Array index out of range");
        }
        index = mod(index, size());
        return data_[index];
    }

    T& operator[](int index) {
        if (empty()) {
            throw std::range_error("Array index out of range\n");
        }
        index = mod(index, size());
        return data_[index];
    }

    typename std::vector<T>::const_iterator begin() const {
        return data_.cbegin();
    }
    typename std::vector<T>::const_iterator end() const {
        return data_.cend();
    }

    typename std::vector<T>::iterator begin() {
        return data_.begin();
    }
    typename std::vector<T>::iterator end() {
        return data_.end();
    }

    friend Array operator + (const Array &first, const Array &second) {
        std::vector<T> concatenated_data(first.data_);
        concatenated_data.insert(concatenated_data.end(), second.begin(), second.end());
        return Array(concatenated_data);
    }

    friend bool operator == (const Array &first, const Array &second) {
        return first.data_ == second.data_;
    }

    friend bool operator != (const Array &first, const Array &second) {
        return first.data_ != second.data_;
    }
};
