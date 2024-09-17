#include "fraction.h"

Fraction::Fraction() {
    _num = 1;
    _den = 1;
}

Fraction::Fraction(int num, int den) {
    _num = num;
    _den = den;
}

void Fraction::invert() {
    int temp = _num;
    _num = _den;
    _den = temp;   
}

int Fraction::get_den() const {
    return _den;
}

int Fraction::get_num() const {
    return _num;
}

Fraction Fraction::operator*(const Fraction& F1) {
    int num = _num * F1.get_num();
    int den = _den * F1.get_den();

    return Fraction(num, den);
}

Fraction Fraction::operator/(const Fraction& F1) {
    int num = _num * F1.get_den();
    int den = _den * F1.get_num();

    return Fraction(num, den);
}

Fraction& Fraction::operator++() {
    _num += _den;

    return *this;
}

Fraction Fraction::operator++(int i) {
    Fraction result = *this;

    operator++();

    return result;
}

Fraction& Fraction::operator--() {
    _num -= _den;

    return *this;
}

Fraction Fraction::operator--(int i) {
    Fraction result = *this;

    operator--();

    return result;
}
