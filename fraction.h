#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
    private:
    int _num;
    int _den;

public:
    Fraction();
    Fraction(int, int);

    void invert();
    int get_num() const;
    int get_den() const;
    Fraction operator*(const Fraction&);
    Fraction operator/(const Fraction&);
    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    Fraction operator--(int);
};

#endif
