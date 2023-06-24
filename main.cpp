#include <iostream>
#include <random>
#include <chrono>
#include <ctime>

long long int LOOP_TIME = 1000 * 1000;
const int RADIUS = 1;

int main(int argc, char *argv[])
{
    if (argv[1] != NULL)
    {
        LOOP_TIME = atoi(argv[1]);
    }

    std::chrono::system_clock::time_point loopStart, loopEnd;

    double insidePoints = 0;
    // int outsidePoints = 0;

    loopStart = std::chrono::system_clock::now();

    for (long long int i = 0; i < LOOP_TIME; i++)
    {
        srand(time(NULL));
        int x = rand() % RADIUS;
        int y = rand() % RADIUS;

        // if (x * x + y * y > RADIUS * RADIUS)
        // {
        //     outsidePoints++;
        // }
        if (x * x + y * y <= RADIUS * RADIUS)
        {
            insidePoints++;
        }

        // if (i % (LOOP_TIME / 10) == 0 && i != 0)
        // {
        //     std::cout << progress << "実行中" << std::endl;
        // }
    }

    loopEnd = std::chrono::system_clock::now();

    double loopElapsed = std::chrono::duration_cast<std::chrono::milliseconds>(loopEnd - loopStart).count();

    // double sum = insidePoints + outsidePoints;
    double sum = LOOP_TIME;
    double calculatedPI = (4.0 * insidePoints) / sum;

    std::cout << calculatedPI << std::endl;
    std::cout << "Looptime: " << LOOP_TIME << std::endl;
    std::cout << "Time: " << loopElapsed / 1000 << "s" << std::endl;

    return 0;
}
