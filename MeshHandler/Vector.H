#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
public:
    // Construct as (0,0,0)
    Vector();
    // Construct with initial values
    Vector(double x, double y, double z);
    void x();
    void y();
    void z();
private:
    double X_, Y_, Z_;
};

#endif // VECTOR_H
