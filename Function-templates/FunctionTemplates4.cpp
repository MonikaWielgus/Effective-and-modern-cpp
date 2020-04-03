//Monika Wielgus
#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;

bool biggerThan5(int x){
    return x>5;
}

template<template <typename, typename> class OutContainer, typename T, typename Alloc, template <typename, typename> class InContainer, typename Predicate>
OutContainer<T,Alloc> selectIf(InContainer<T,Alloc>  c, Predicate p){
    OutContainer<T,Alloc> container;
    for(auto const &value: c){
        if(p(value))
            container.push_back(value);
    }
    return container;
}

int main(){
    auto print=[](auto v) {
        for(auto x: v) cout << x << " ";
        cout << endl;
    };

    std::vector<int> v={1, 2, 13, 4, 5, 54};
    std::list<int> result = selectIf<std::list>(v, biggerThan5);
    print(result);

    auto result2 = selectIf<std::deque>(v, [](int x)->bool{ return x%2; } );
    print(result2);

    auto result3 = selectIf<std::vector>(result2, biggerThan5);
    print(result3);
    return 0;
}
