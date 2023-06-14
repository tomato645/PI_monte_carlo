#include <iostream>
#include <random>
#include <time.h>

const int LOOP_TIME = 900000;

int main()
{
    int insidePoints = 0;
    int outsidePoints = 0;

    for (int i = 0; i < LOOP_TIME; i++)
    {
        int x = rand() % 100;
        int y = rand() % 100;

        // std::cout << x << std::endl;
        // std::cout << y << std::endl;
        // std::cout << x * x + y * y << std::endl;

        if (x * x + y * y > 10000)
        {
            outsidePoints++;
        }
        else if (x * x + y * y <= 10000)
        {
            insidePoints++;
        }
    }

    double sum = insidePoints + outsidePoints;
    double tmp = 4 * insidePoints;
    std::cout << tmp / sum << std::endl;
}
