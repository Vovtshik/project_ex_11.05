#include "../std_lib_facilities.h"

void tolower_s(string& s);

int main()
{

    return 0;
}

void tolower_s(string& s)
{
    for(char& x: s) x = tolower(x);
}