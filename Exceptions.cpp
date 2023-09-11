#include <iostream>

using namespace std;

int main()
{
    setlocale(0, "");

    try {
        throw 1;
    }
    catch (int e) {
        std::cerr << "Error #" << e << endl;
    }
}
