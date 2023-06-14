#include <iostream>
#include <chrono>
#include <math.h>

const int TIME = 1000 * 1000 * 1000;

int normal()
{
    double x = 2;
    std::chrono::system_clock::time_point loopStart, loopEnd;
    loopStart = std::chrono::system_clock::now();

    for (int i = 0; i < TIME; i++)
    {
        x *x;
    }

    loopEnd = std::chrono::system_clock::now();
    double loopElapsed = std::chrono::duration_cast<std::chrono::milliseconds>(loopEnd - loopStart).count();
    std::cout << "Time for normal: " << loopElapsed << "ms" << std::endl;

    return 0;
}

int usingPow()
{
    double x = 2;
    std::chrono::system_clock::time_point loopStart, loopEnd;
    loopStart = std::chrono::system_clock::now();

    for (long long int i = 0; i < TIME; i++)
    {
        pow(x, 2.0);
    }

    loopEnd = std::chrono::system_clock::now();
    double loopElapsed = std::chrono::duration_cast<std::chrono::milliseconds>(loopEnd - loopStart).count();
    std::cout << "Time for pow: " << loopElapsed << "ms" << std::endl;
    
    return 0;
}


int main()
{
    usingPow();
    normal();
}