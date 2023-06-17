#include <iostream>
#include <random>

const int TIME = 1000*1000;
const int RANGE = 10;

int main () {
    int nums[RANGE] = {0,0,0,0,0,0,0,0,0,0}; // make an array

    for (int i = 0; i < TIME; i++) {
        int num = rand() % 10;
        nums[num]++;
        // std::cout << num << std::endl;
    }
    
    int sum = 0;
    for (int i = 0; i < RANGE; i++)
    {
        std::cout << i << ": " << nums[i] << std::endl;
        sum += nums[i];
    }
    std::cout << "sum: " << sum << std::endl;
}