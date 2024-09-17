#ifndef SINE_H
#define SINE_H
#include <iostream>
#define PI 3.1415926

class Sine {
private:
    double _theta;
    double _height;
    double _amplitude;
    double _increment;
    double _wavelength;

public:
    Sine(double, double, double);

    double currentAngle() const;
    double currentHeight() const;

    Sine& operator++();
    Sine operator++(int);
};

std::ostream& operator<<(std::ostream&, const Sine&);

#endif
