#include <iostream>
#include <random>
#include <chrono>

const int LOOP_TIME = 9000000;
const int RADIUS = 100;

int main()
{
    std::chrono::system_clock::time_point loopStart, loopEnd;

    int insidePoints = 0;
    int outsidePoints = 0;

    loopStart = std::chrono::system_clock::now();

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

    loopEnd = std::chrono::system_clock::now();

    double loopElapsed = std::chrono::duration_cast<std::chrono::milliseconds>(loopEnd - loopStart).count();

    double sum = insidePoints + outsidePoints;
    double calculatedPI = (4.0 * insidePoints) / sum;

    std::cout << calculatedPI << std::endl;
    std::cout << "Looptime: " <<LOOP_TIME << std::endl;
    std::cout << "Time: " << loopElapsed / 1000 << "s" << std::endl;

    return 0;
}
