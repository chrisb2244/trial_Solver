#include "Field.H"

Field::Field(const std::string &fieldName,
             const FieldType fieldType)
{
    name = fieldName;
    if (fieldType == FieldType::Vector)
    {
        type = "vector";
    }
    else
    {
        type = "scalar";
    }
}
