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

    try {
        throw std::exception("C++ Exception");
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << endl;
    }
    catch (...) {
        cout << "All" << endl;
    }

}
