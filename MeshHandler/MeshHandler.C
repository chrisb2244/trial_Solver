#include "MeshHandler.H"
#include <iostream>

// #include "Vector2D.H"


MeshHandler::MeshHandler(SetupFile& setupFile):
    setupFile_(setupFile)
{
    setDimensions();
    std::cout<< "Set dimensions" << std::endl;

    createFields();
    std::cout<< "Created/read fields" << std::endl;
}

void MeshHandler::setDimensions()
{
    xCells = setupFile_.lookup<int>("xCells");
    yCells = setupFile_.lookup<int>("yCells");
    zCells = setupFile_.lookupOrDefault<int>("zCells", 0);
    xRange = setupFile_.lookup<double>("xRange");
    yRange = setupFile_.lookup<double>("yRange");
    zRange = setupFile_.lookupOrDefault<double>("zRange", 0);
    if (zCells == 0 || zRange == 0)
    {
        std::cout<< "Creating two dimensional mesh." << std::endl;
    }
    else
    {
        std::cout<< "Creating three dimensional mesh." << std::endl;
    }
}

void MeshHandler::createFields()
{
//    U = Field("U", Field::FieldType::Vector);
//    P = Field("P", Field::FieldType::Scalar);
//    Alpha = Field("Alpha", Field::FieldType::Scalar);
#if DIMENSION == 2
    std::string g = setupFile_.lookupOrDefault("Gravity", "(0, -9.81)");
    if (g.find(',', g.find(',', 0)+1) != std::string::npos)
    {
        std::cerr << "Two commas indicates a 3d vector for a 2d setup. "
                  << "Returning to default. " << std::endl;
    }
    g = "(0, -9.81)";
#elif DIMENSION == 3
    std::string g = setupFile_.lookupOrDefault("Gravity", "(0, 0, -9.81)");
#endif
    std::cout << "g = " << g << std::endl;
}

int MeshHandler::getCell(int x, int y)
{
    // Basic, uniform grid
    // No error/range checking
    return (y*xCells) + x;
}

void MeshHandler::writeFields()
{

}
