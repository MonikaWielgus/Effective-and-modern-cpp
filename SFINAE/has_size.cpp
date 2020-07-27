//Monika Wielgus
#include <iostream>
#include <vector>
#include <type_traits>

using namespace std;

template<typename T>
class hasSize{
    typedef char yes[1];
    typedef char no[2];
    template<typename C>
    static yes& test(int C::*);
    template<typename C>
    static no&  test(...);
public:
    static bool const value = sizeof(test<T>(0)) == sizeof(yes);
};

template<typename T>
class hasValueType{
    typedef char yes[1];
    typedef char no[2];
    template<typename C>
    static yes& test(int C::*);
    template<typename C>
    static no&  test(...);
public:
    static bool const value = sizeof(test<T>(0)) == sizeof(yes);
};

int main() {
    std::cout << std::boolalpha;
    cout << hasSize<int>::value << endl;
    cout << hasSize<vector<int>>::value << endl;
    cout << hasValueType<int>::value << endl;
    cout << hasValueType<vector<int>>::value << endl;
}
