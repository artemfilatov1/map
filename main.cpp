#include <iostream>
#include "map.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Map<int, int> m;
    m[10] = 1;
    m[2] = 2;
    m[12] = 3;
    m[12] = 5;
    m.show();
    return 0;
}
