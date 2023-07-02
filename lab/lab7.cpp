#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <math.h>

class Shape {
private:
    double coord[2];
    std::string color;

public:
    Shape(const double coord[2], std::string color) {
        this->coord[0] = coord[0];
        this->coord[1] = coord[1];

        this->color = color;
    }
};

class Triangle : public Shape {
private:
    double sides[3];

public:
    Triangle(double coord[2], std::string color, double sides[3]) : Shape(coord, color) {
        for (int i = 0; i < 3; i++) {
            this->sides[i] = sides[i];
        }
    }

    double calculateArea() {
        double a = sides[0], b = sides[1], c = sides[2];
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

class Rectangle : public Shape {
private:
    double sides[2];
public:
    Rectangle(double coord[2], std::string color, double sides[2]) : Shape(coord, color) {
        this->sides[0] = sides[0];
        this->sides[1] = sides[1];
    }

    double calculateArea() {
        return sides[0] * sides[1] / 2;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double coord[2], std::string color, double radius) : Shape(coord, color) {
        this->radius = radius;
    }

    double calculateArea() {
        return M_2_PI * std::pow(radius, 2);
    }
};

int main() {
    double defaultCoord[2] = {0, 0};

    double triangleSizes[3] = {4, 5, 7};
    Triangle *triangle = new Triangle(defaultCoord, "#ffffff", triangleSizes);
    std::cout << "Triangle's area: " << triangle->calculateArea() << std::endl;

    double rectangleSize[2] = {11, 22};
    Rectangle *rectangle = new Rectangle(defaultCoord, "#961d1d", rectangleSize);
    std::cout << "Rectangle's area: " << rectangle->calculateArea() << std::endl;

    Circle *circle = new Circle(defaultCoord, "#f74d4d", 33);
    std::cout << "Circle's area: " << circle->calculateArea() << std::endl;
}
