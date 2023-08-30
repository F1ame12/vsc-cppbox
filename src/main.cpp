#include "./common/std_basic.h"
#include "./test/util_test.hpp"
#include "./test/testing_box.hpp"
#include "./test/struct_test.hpp"

int main()
{
    namespace fs = std::filesystem;

    const fs::path cwd = fs::current_path();
    std::cout << cwd.string() << std::endl;

    return 0;
}