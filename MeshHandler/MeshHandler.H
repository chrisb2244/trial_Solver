#ifndef MESHHANDLER_H
#define MESHHANDLER_H

#include "Dim2.H"

#include "SetupFile.H"
#include "Field.H"

class MeshHandler
{
public:
    MeshHandler(SetupFile& setupFile);
    void writeFields();
private:
    void setDimensions();
    void createFields();
    int  getCell(int x,int y);

    SetupFile& setupFile_;

    int xCells, yCells, zCells;
    double xRange, yRange, zRange;
    int dimension;

//    Field U;
//    Field P;
    //    Field Alpha;

};

#endif // MESHHANDLER_H
