#include <iostream>
#include <random>
#include <time.h>

const int LOOP_TIME = 900000;

int main()
{
    int inside = 0;
    int outside = 0;

    for (int i = 0; i < LOOP_TIME; i++)
    {
        int x = rand() % 100;
        int y = rand() % 100;

        // std::cout << x << std::endl;
        // std::cout << y << std::endl;
        // std::cout << x * x + y * y << std::endl;

        if (x * x + y * y > 10000)
        {
            outside++;
        }
        else if (x * x + y * y <= 10000)
        {
            inside++;
        }
    }

    double sum = inside + outside;
    double tmp = 4 * inside;
    std::cout << tmp / sum << std::endl;
}
