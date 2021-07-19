#include <ostream>
#pragma once

using namespace std;

ostream& endll(ostream& output)
{
    output.flush();
    return output << '\n' << '\n';
}