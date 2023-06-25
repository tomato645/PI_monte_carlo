#include <iostream>
#include <random>
#include <string>

// int LOOP_TIME = 10;
long insideCount = 0;

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

int main(int argc, char *argv[])
{
    int LOOP_TIME;
    if (argc >= 2)
    {
        LOOP_TIME = atoi(argv[1]);
    }
    else
    {
        LOOP_TIME = 1000 * 1;
        // printf("引数が足りません\n");
        // exit(1);
    }

    std::cout << LOOP_TIME << "回実行します。" << std::endl;

    double x, y;
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

        checkProgress(i, LOOP_TIME);
    }
    std::cout << std::endl;

    std::cout << "insideCount = " << insideCount << std::endl;
    long double tmp = (4 * insideCount);
    std::cout << "PI = " << tmp / (LOOP_TIME) << std::endl;
}
