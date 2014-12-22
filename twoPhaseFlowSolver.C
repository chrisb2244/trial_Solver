#include <iostream>

#include "SetupFile.H"
#include "MeshHandler.H"

int main()
{
    std::cout << "Hello World!" << std::endl;

    // Setup problem
    std::string sPath =
        "/home/christian/QT-Projects/Custom-TwoPhaseFlowSolver/SetupFile.txt";
    SetupFile sFile(sPath);

    MeshHandler mesh(sFile);


    float startTime = 0.0;
    float endTime = 5.0;

    // Step in time
    float time = startTime;
    while (time <= endTime)
    {
        // Calculate deltaT. Here, just constant
        float deltaT = 0.01;

        // Do stuff

        // U
        // Convection
        // Gravity
        // Viscosity
        // Pressure


        // Write stuff

        // Update time
        time += deltaT;
    }

    return 0;
}

