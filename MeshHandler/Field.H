#ifndef FIELD_H
#define FIELD_H

#include <string>

class Field
{
public:
    enum FieldType {Scalar, Vector};
    Field(const std::string &fieldName, const FieldType fieldType);
private:
    std::string name;
    std::string type;
};

#endif // FIELD_H
