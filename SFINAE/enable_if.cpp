//Monika Wielgus
#include <iostream>
#include <vector>
#include <type_traits>
using namespace std;

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

namespace v1{
    template <typename T>
    typename enable_if<hasValueType<T>::value, size_t>::type
    getSize(const T& x){
        return  x.size()*sizeof(typename T::value_type);
    }

    template <typename T>
    typename enable_if<!hasValueType<T>::value, size_t>::type
    getSize(const T& x){
        return sizeof(x);
    }
}

namespace v2{
    template <typename T>
    size_t getSize(const T& x) {
        if constexpr(hasValueType<T>::value)
            return  x.size()*sizeof(typename T::value_type);
        else
            return sizeof(x);
    }
}

int main() {
    std::vector<int> v{1,2,3,4,5};
    cout << v1::getSize(5) << endl;
    cout << v1::getSize(v) << endl;
    cout << v2::getSize(5) << endl;
    cout << v2::getSize(v) << endl;
}
