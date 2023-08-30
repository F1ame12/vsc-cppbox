#include "../common/std_basic.h"
#include "toybox.h"
#include "impl/toybox_impl.h"


const int SmallToy::GetToyMaxSize()
{
    return SmallToy::MaxSize;
}

bool SmallToy::checkData() const
{
    return this->pImpl->checkData();
}