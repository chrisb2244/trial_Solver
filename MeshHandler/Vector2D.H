#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
public:
    // Construct as (0,0,0)
    Vector2D();
    // Construct with initial values
    Vector2D(double x, double y);
    void x();
    void y();
private:
    double X_, Y_;
};

#endif // VECTOR2D_H
