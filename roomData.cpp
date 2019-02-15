#include "main.h"

void roomData::setName(const std::string s)
{
    if (!s.empty())
        name = s;
    else
        name = "unknown";
}

std::string roomData::getName()
{
    return (this->name);
}
