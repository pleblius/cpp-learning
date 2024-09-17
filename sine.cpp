#include "sine.h"
#include <cmath>

Sine::Sine(double amplitude, double wavelength, double increment) {
    _theta = 0.0;
    _amplitude = amplitude;
    _increment = increment;
    _wavelength = wavelength;
}

double Sine::currentAngle() const {
    return _theta;
}

double Sine::currentHeight() const {
    return _amplitude * sin(2.0 * PI * _theta / _wavelength);
}

Sine& Sine::operator++() {
    _theta += _increment;

    return *this;
}

Sine Sine::operator++(int) {
    Sine result = *this;

    operator++();

    return result;
}

std::ostream& operator<<(std::ostream &os, const Sine &sine) {
    os << sine.currentAngle() << ", " << sine.currentHeight();

    return os;
}
