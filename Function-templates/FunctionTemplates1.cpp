//Monika Wielgus
#include <iostream>
#include <vector>
#include <list>
#include <cmath>

using namespace std;

template<typename T>
T sqr(T x){
    return x*x;
}
template<>
string sqr(string x){
    return x+x;
}
template<int N>
int mod(int x){
    return x%N;
}
template<>
int mod<0>(int x){
    return -x;
}
template<typename Container>
void print(const Container & v){
    for(auto const &value: v){
        cout << value << " ";
    }
    cout << endl;
}
template<typename C, typename F>
C apply (const C& c, F f){
    C new_container;
    for(auto const &value: c){
        new_container.push_back(f(value));
    }
    return new_container;
}

int main(){
    cout << sqr(4) << endl;
    cout << sqr(14.5) << endl;
    cout << sqr(string("hey")) << endl;

    cout << mod<5>(131) << endl;
    cout << mod<7>(131) << endl;
    cout << mod<0>(131) << endl;

    std::vector<int> v = {1, 21, 34, 4, 15};
    print(v);

    std::list<double> l = {1, 2.1, 3.2, 6.3};
    print(l);

    auto w = apply(v, sqr<int>);
    print(w);

    auto w2 = apply(w, mod<5> );
    print(w2);

    auto w3 = apply(w, mod<0> );
    print(w3);

    auto l2 = apply(l, sqr<double>);
    print(l2);

    auto l3 = apply(l2, mod<5>);
    print(l3);

    auto l4 = apply(l3, static_cast<double(*)(double)>(std::sin));
    print(l4);

    return 0;
}
