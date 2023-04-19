#include "./common/std_basic.h"

#include "./test/util_test.hpp"
#include "./test/testing_box.hpp"

namespace fs = std::filesystem;

int main()
{
    //UtilTest::TestMultiGenStr();
    TestBox::testStream();

    return 0;

}