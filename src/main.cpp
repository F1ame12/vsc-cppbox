#include "./common/std_basic.h"
#include "./test/util_test.hpp"
#include "./test/testing_box.hpp"
#include "./test/struct_test.hpp"

void CreateMap(int MapData[100][100])
{
    std::random_device rd;
    std::mt19937_64 mt(rd());
    std::uniform_int_distribution uni(1, 100);
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            int randN = uni(mt);
            if (randN <= 30)
            {
                MapData[i][j] = 0;
            }
            else
            {
                MapData[i][j] = 1;
            }
        }
    }
}

int main()
{
    int Data[100][100];
    CreateMap(Data);

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            std::cout << Data[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}