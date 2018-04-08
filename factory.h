#ifndef FACTORY_H
#define FACTORY_H
#include <iostream>

class Ball {
public:
    Ball(int mass, int radius, int x_position, int y_position, int x_velocity, int y_velocity, std::string colour)
        : m_mass(mass), m_radius(radius), m_colour(colour) {
        m_x_position = x_position;
        m_y_position = y_position;
        m_y_velocity = y_velocity;
        m_x_velocity = x_velocity;
    }

private:
    const int m_mass;
    const int m_radius;
    int m_x_position;
    int m_y_position;
    int m_x_velocity;
    int m_y_velocity;
    const std::string m_colour;
};

class Table {
public:
    Table(int x_size, int y_size, std::string colour, double friction)
        : m_x_size(x_size), m_y_size(y_size), m_colour(colour), m_friction(friction) {

    }
private:
    const int m_x_size;
    const int m_y_size;
    const std::string m_colour;
    const double m_friction;
};

class Abstract_Factory {
public:
    virtual Ball* createBall() = 0;
    virtual Table* createTable() = 0;
};

class Factory : public Abstract_Factory {
public:
    Ball* createBall(int mass, int radius, int x_position, int y_position, int x_velocity, int y_velocity, std::string colour) {
        return new Ball(mass, radius, x_position, y_position, x_velocity, y_velocity, colour);
    }

    Table* createTable(int x_size, int y_size, std::string colour, double friction) {
        return new Table(x_size, y_size, colour, friction);
    }
};

#endif // FACTORY_H
