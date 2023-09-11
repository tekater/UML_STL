#include <iostream>
#include <array>
#include <vector>
using namespace std;

using std::endl;
using std::cin;
using std::cout;

#define tab "\t"

//#define STL_ARRAY
#define STL_VECTOR
#define STL_

template<typename T>
void vector_properties(const std::vector<T>& vec) {
    cout << "Size:     " << vec.size() << endl;
    cout << "MaxSize:  " << vec.max_size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;
    cout << endl;
}

int main()
{
    setlocale(0, "");

#ifdef STL_ARRAY
    //array - это контейнер, который хранит данные в виде статического массива.

    const int N = 5;

    std::array<int, N> arr = { 3,5,8,13,21 };

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << tab;
    }
    cout << endl;

#endif // STL_ARRAY

#ifdef STL_VECTOR
    //vector - это контейнер, который хранит данные в виде динамического массива.

    std::vector<int> vec = { 3,5,8,13,21,1,2,3,4,5 };

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << tab;
    }

    cout << endl << endl;

    cout << "<Int>\n";
    vector_properties(vec);

    cout << "Resize:\n";
    vec.resize(18);
    vec.reserve(120);
    vector_properties(vec);
    vec.shrink_to_fit();
    for (int i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << tab;
    }
    cout << endl << endl;
    vector_properties(vec);

    vec.push_back(55);
    vector_properties(vec);

    

    cout << "Vec2\n";
    std::vector<int> vec2(100);
    vector_properties(vec2);
    vec2.push_back(1024);
    vector_properties(vec2);

    std::vector<double> d_vec = { 2.7, 3.14, 8.3 };
    cout << "<Double>\n";
    vector_properties(d_vec);



#endif //STL_VECTOR

#ifdef STL_
    //


#endif // STL_



}
