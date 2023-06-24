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

int main(int argc, char *argv[])
{
    int LOOP_TIME;
    if (argc >= 2)
    {
        LOOP_TIME = atoi(argv[1]);
    }
    else
    {
        LOOP_TIME = 1000 * 100;
        // printf("引数が足りません\n");
        // exit(1);
    }

    std::cout << LOOP_TIME << "回実行します。" << std::endl;

    long double x[LOOP_TIME];
    long double y[LOOP_TIME];

    for (int i = 0; i < LOOP_TIME; i++)
    {
        x[i] = makeRand();
        y[i] = makeRand();
        // std::cout << "x:" << x[i] << " y:" << y[i] << std::endl;
        if (i % (LOOP_TIME / 10) == 0)
        {
            char test[] = "123456789";
            std::cout << "\r" << std::flush;
            for (int j = 0; j < i / (LOOP_TIME / 10); j++)
            {
                std::cout << test[j] << std::flush;
            }
        }
    }
    std::cout << std::endl;
    std::cout << "配列の生成が終了" << std::endl;

    for (int i = 0; i < LOOP_TIME; i++)
    {
        long double powed = (x[i] * x[i]) + (y[i] * y[i]);
        // std::cout << powed << std::endl;
        if (powed <= 1.0)
        {
            insideCount++;
        }
    }

    std::cout << "insideCount = " << insideCount << std::endl;
    long double tmp = (4 * insideCount);
    std::cout << "PI = " << tmp / (LOOP_TIME) << std::endl;
}
