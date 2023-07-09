#include <iostream>
#include <random>
#include <string>

// int LOOP_TIME = 10;
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

int checkProgress(int count, int loop_time)
{
    if (count % (loop_time / 10) == 0)
    {
        char test[] = "123456789";
        std::cout << "\r" << std::flush;
        for (int j = 0; j < count / (loop_time / 10); j++)
        {
            std::cout << test[j] << std::flush;
        }
    }
    return 0;
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

        if (!simpleOutput){checkProgress(i, LOOP_TIME);};
    }
    if (!simpleOutput){std::cout << std::endl;};

    if (!simpleOutput){std::cout << "insideCount = " << insideCount << std::endl;}
    long double tmp = (4 * insideCount);
    std::cout << "PI = " << tmp / (LOOP_TIME) << std::endl;

    return 0;
}

int main(int argc, char *argv[])
{
    int LOOP_TIME;
    int CalculateTimes;
    if (argc >= 3)
    {
        LOOP_TIME = atoi(argv[1]);
        CalculateTimes = atoi(argv[2]);
        if (std::string(argv[3]) == "true")
        {
            simpleOutput = true;
        }
    }
    else
    {
        LOOP_TIME = 1000;
        CalculateTimes = 1;
        bool simpleOutput = false;
        // printf("引数が足りません\n");
        // exit(1);
    }

    std::cout << LOOP_TIME << "回を" << CalculateTimes << "回実行します。" << std::endl;

    for (int i = 0; i < CalculateTimes; i++)
    {
        monte(LOOP_TIME);
    }
}
