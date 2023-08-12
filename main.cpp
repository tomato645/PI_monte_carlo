#include <iostream>
#include <random>
#include <string>

bool simpleOutput;

long double makeRand()
{
    // 乱数生成器を初期化
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<long double> dis(0.0, 1.0);

    // 0から1までの乱数を生成して返す
    return dis(gen);
}

void checkProgress(int count, int loop_time)
{
    if (loop_time < 10)
    {
        return;
    }
    if (count % (loop_time / 10) == 0)
    {
        char test[] = "123456789";
        std::cout << "\r" << std::flush;
        for (int j = 0; j < count / (loop_time / 10); j++)
        {
            std::cout << test[j] << std::flush;
        }
    }
}

double monte(int LOOP_TIME)
{
    double x, y;
    long insideCount = 0;
    for (int i = 0; i < LOOP_TIME; i++)
    {
        x = makeRand();
        y = makeRand();

        long double powed = (x * x) + (y * y);
        // std::cout << powed << std::endl;

        if (powed <= 1.0)
        {
            insideCount++;
        }

        if (!simpleOutput)
        {
            checkProgress(i, LOOP_TIME);
        };
    }
    if (!simpleOutput)
    {
        std::cout << std::endl;
    }

    if (!simpleOutput)
    {
        std::cout << "insideCount = " << insideCount << std::endl;
    }
    long double tmp = (4 * insideCount);
    std::cout << "PI = " << tmp / (LOOP_TIME) << std::endl;

    return 0;
}

bool str2bool(std::string str)
{
    if (str == "true")
    {
        return true;
    }
    if (str == "false")
    {
        return false;
    }
    std::cout << "\e[31mtrue or false\e[0m" << std::endl;
    exit(1);
}

int main(int argc, char *argv[])
{
    int LOOP_TIME;
    int calculateTimes;
    if (argc == 1)
    {
        LOOP_TIME = 1000;
        calculateTimes = 1;
        simpleOutput = false;
    }
    else if (argc == 4)
    {
        LOOP_TIME = atoi(argv[1]);
        calculateTimes = atoi(argv[2]);
        simpleOutput = str2bool(argv[3]);
    }
    else
    {
        std::cout << "\e[31mIt seems missing arguments.\e[0m" << std::endl;
        std::cout << "\e[3mUsage: ./main [int: loop time] [int: calculation times] [bool: simpleOutput]\e[0m" << std::endl;
        exit(1);
    }

    std::cout << LOOP_TIME << "回を" << calculateTimes << "回実行します。" << std::endl;

    for (int i = 0; i < calculateTimes; i++)
    {
        monte(LOOP_TIME);
    }
}
