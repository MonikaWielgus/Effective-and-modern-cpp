//Monika Wielgus
#include <iostream>

template<int A, int B>
struct Power{
    static const int value=A*Power<A,B-1>::value;
};
template <int A>
struct Power<A, 0>{
    static const int value=1;
};

template<int A, int B>
struct Binomial{
    static const long int value=Binomial<A-1,B>::value+Binomial<A-1,B-1>::value;
};
template<int A>
struct Binomial<A,A>{
    static const long int value=1;
};
template<int A>
struct Binomial<A, 0>{
    static const long int value=1;
};

int main() {
    std::cout << Power<5,3>::value <<std::endl;
    std::cout << Binomial<4,2>::value << std::endl;
    std::cout << Binomial<100,0>::value << std::endl;
    std::cout << Binomial<100,1>::value << std::endl;
    std::cout << Binomial<100,7>::value << std::endl;
}
