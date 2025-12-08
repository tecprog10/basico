#include "../include/Vetor2D.h"

Vetor2D::Vetor2D() : x(0.0), y(0.0) {}

Vetor2D::Vetor2D(double x, double y) : x(x), y(y) {}

double Vetor2D::getX() const {
    return x;
}

double Vetor2D::getY() const {
    return y;
}

void Vetor2D::setX(double x) {
    this->x = x;
}

void Vetor2D::setY(double y) {
    this->y = y;
}

double Vetor2D::magnitude() const {
    return std::sqrt(x * x + y * y);
}

Vetor2D Vetor2D::normalizado() const {
    double mag = magnitude();
    if (mag > 0) {
        return Vetor2D(x / mag, y / mag);
    }
    return Vetor2D(0, 0);
}

Vetor2D Vetor2D::operator+(const Vetor2D& outro) const {
    return Vetor2D(x + outro.x, y + outro.y);
}

Vetor2D Vetor2D::operator-(const Vetor2D& outro) const {
    return Vetor2D(x - outro.x, y - outro.y);
}

Vetor2D Vetor2D::operator*(double escalar) const {
    return Vetor2D(x * escalar, y * escalar);
}

Vetor2D Vetor2D::operator/(double escalar) const {
    if (escalar != 0) {
        return Vetor2D(x / escalar, y / escalar);
    }
    return Vetor2D(0, 0);
}

Vetor2D& Vetor2D::operator+=(const Vetor2D& outro) {
    x += outro.x;
    y += outro.y;
    return *this;
}

Vetor2D& Vetor2D::operator-=(const Vetor2D& outro) {
    x -= outro.x;
    y -= outro.y;
    return *this;
}