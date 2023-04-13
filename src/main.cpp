#include "common/std_basic.h"

#include "structs/mylist.h"

int main()
{
    std::cout << "Hello World!" << std::endl;


    return 0;

}

//生成随机二进制文件的函数
void generateRandomBinaryFile(const char* filename, int size)
{
    std::ofstream out(filename, std::ios::binary);
    for (int i = 0; i < size; i++)
    {
        char c = rand() % 256;
        out.write(&c, 1);
    }
    out.close();
}