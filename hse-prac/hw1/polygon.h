#include <algorithm>
#include <iostream>
#include <map>
#include <type_traits>
#include <vector>

template <typename T> 
T Pow(const T& x, size_t degree) {
    if (degree == 1) {
        return x;
    } else if (degree & 1) {
        return x * Pow(x, degree - 1);
    }
    return Pow(Pow(x, degree / 2), 2);
}

template <typename CoefType>
class Polynomial {
    std::map<size_t, CoefType> data;

    void reduce() {
        std::vector<size_t> toRemove;
        for (auto &monome : data) {
            if (monome.second == 0) {
                toRemove.push_back(monome.first);
            }
        }
        for_each(toRemove.begin(), toRemove.end(), [this](size_t power) {data.erase(power);});
    }

    void divmod(const Polynomial &divisor, Polynomial &quotient, Polynomial & remainer) const {
        quotient = 0;
        remainer = (*this);
        while (remainer.Degree() >= divisor.Degree()) {
            auto monomePower = remainer.Degree() - divisor.Degree();
            auto monomeCoeff = remainer[remainer.Degree()] / divisor[divisor.Degree()];
            auto subtrahed = Polynomial(monomeCoeff, monomePower);
            quotient += subtrahed;
            remainer -= subtrahed * divisor;
        }
    }

    std::ostream& OutputMonome(std::ostream& out, size_t power, bool hasAnyOutput) const {
        CoefType currentCoeff = (*this)[power];
        if (currentCoeff > 0 && hasAnyOutput) {
            out << "+";
        } else if (currentCoeff < 0) {
            out << "-";
        }
        if (power == 0 || (currentCoeff != 1 && currentCoeff != -1)) {
            if (currentCoeff < 0) {
                out << -currentCoeff;
            } else {
                out << currentCoeff;
            }
        }
        if (power != 0) {
            if (currentCoeff != 1 && currentCoeff != -1) {
                out << "*";
            }
            out << "x";
        }
        if (power > 1) {
            out << "^" << power;
        }
        return out;

    }

 public:
    explicit Polynomial(const std::vector<CoefType>& coefficientsVector) {
        for (size_t i = 0; i < coefficientsVector.size(); i++) {
            data[i] = coefficientsVector[i];
        }
        reduce();
    }

    template <class Iterator,
              class = typename std::enable_if<!std::is_arithmetic<Iterator>::value>::type>
    explicit Polynomial(Iterator cbegin, Iterator cend) {
        int currentDegree = 0;
        while (cbegin != cend) {
            data[currentDegree++] = *cbegin++;
        }
        reduce();
    }

    Polynomial(const CoefType& first = CoefType(), size_t power = 0) {
        data[power] = first;
        reduce();
    }

    int Degree() const {
        if (data.empty()) {
            return -1;
        }
        return prev(data.end())->first;
    }

    CoefType operator[](const size_t index) const {
        auto indexPowerIt = data.find(index);
        if (indexPowerIt == data.end()) {
            return 0;
        }
        return indexPowerIt->second;
    }

    CoefType operator ()(const CoefType &point) const {
        CoefType ValueAtPoint = 0;
        CoefType currentPowerPoint = 1;
        size_t currentPower = 0;
        for (const auto &v : data) {
            currentPowerPoint *= Pow(point, v.first - currentPower);
            currentPower = v.first;
            ValueAtPoint += currentPowerPoint * v.second;
        }
        return ValueAtPoint;
    }

    Polynomial& operator += (const Polynomial &second) {
        for (const auto &monome : second.data) {
            data[monome.first] += monome.second;
        }
        reduce();
        return *this;
    }

    Polynomial& operator -= (const Polynomial &second) {
        return *this += second * -1;
    }

    Polynomial& operator *= (const Polynomial &second) {
        return *this = *this * second;
    }

    Polynomial& operator /= (const Polynomial &second) {
        return *this = *this / second;
    }

    Polynomial& operator %= (const Polynomial &second) {
        return *this = *this % second;
    }

    typename std::map<size_t, CoefType>::const_iterator begin() const {
        return data.begin();
    }
    typename std::map<size_t, CoefType>::const_reverse_iterator rbegin() const {
        return data.rbegin();
    }
    typename std::map<size_t, CoefType>::const_iterator end() const {
        return data.end();
    }
    typename std::map<size_t, CoefType>::const_reverse_iterator rend() const {
        return data.rend();
    }


    friend bool operator == (const Polynomial &first, const Polynomial &second) {
        return first.data == second.data;
    }

    friend bool operator != (const Polynomial &first, const Polynomial &second) {
        return first.data != second.data;
    }

    friend Polynomial operator + (Polynomial first, const Polynomial &second) {
        return first += second;
    }

    friend Polynomial operator - (const Polynomial &first, const Polynomial &second) {
        return first += second;
    }

    friend Polynomial operator * (const Polynomial &first, const Polynomial &second) {
        Polynomial third;
        for (const auto& firstMonom : first) {
            for (const auto& secondMonom : second) {
                third.data[firstMonom.first + secondMonom.first] += firstMonom.second *
                                                                    secondMonom.second;
            }
        }
        third.reduce();
        return third;
    }

    friend Polynomial operator / (const Polynomial &first, const Polynomial &second) {
        Polynomial quotient, remainer;
        first.divmod(second, quotient, remainer);
        return quotient;
    }

    friend Polynomial operator % (const Polynomial &first, const Polynomial &second) {
        Polynomial quotient, remainer;
        first.divmod(second, quotient, remainer);
        return remainer;
    }


    friend Polynomial operator , (const Polynomial &first, const Polynomial &second) {
        Polynomial a(first);
        Polynomial b(second);
        while (b != 0) {
            a %= b;
            std::swap(a, b);
        }
        a /= a[a.Degree()];
        return a;
    }

    friend std::ostream& operator << (std::ostream& out, const Polynomial &p) {
        bool hasAnyOutput = false;
        for (auto elemIt = p.rbegin(); elemIt != p.rend(); elemIt++) {
            if (elemIt->second != 0) {
                p.OutputMonome(out, elemIt->first, hasAnyOutput);
                hasAnyOutput = true;
            }
        }
        if (!hasAnyOutput) {
           out << 0;
        }
        return out;
    }
};
