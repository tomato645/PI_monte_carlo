#include <iostream>
#include <random>
#include <time.h>

const int LOOP_TIME = 900000;
const int RADIUS = 100;

int main()
{
    int insidePoints = 0;
    int outsidePoints = 0;

    for (int i = 0; i < LOOP_TIME; i++)
    {
        int x = rand() % RADIUS;
        int y = rand() % RADIUS;

        if (x * x + y * y > RADIUS * RADIUS)
        {
            outsidePoints++;
        }
        else if (x * x + y * y <= RADIUS * RADIUS)
        {
            insidePoints++;
        }
    }

    double sum = insidePoints + outsidePoints;
    double calculatedPI = (4.0 * insidePoints) / sum;
    std::cout << calculatedPI << std::endl;

    return 0;
}
