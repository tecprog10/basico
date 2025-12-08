#ifndef VETOR2D_H
#define VETOR2D_H

#include <cmath>

class Vetor2D {
private:
    double x;
    double y;

public:
    Vetor2D();
    Vetor2D(double x, double y);
    
    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);
    
    double magnitude() const;
    Vetor2D normalizado() const;
    
    Vetor2D operator+(const Vetor2D& outro) const;
    Vetor2D operator-(const Vetor2D& outro) const;
    Vetor2D operator*(double escalar) const;
    Vetor2D operator/(double escalar) const;
    
    Vetor2D& operator+=(const Vetor2D& outro);
    Vetor2D& operator-=(const Vetor2D& outro);
};

#endif