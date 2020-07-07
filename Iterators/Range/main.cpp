//Monika Wielgus
#include <iostream>
#include "Range.h"
using namespace std;

int main(){
    auto r1=Range<int>(1, 9, 2);
    for(auto x:r1)
        cout << x <<" ";
    cout << "\n";
    for(auto x : r1)
        cout << "--";
    cout << "\n";

    Range<double> r2(1, 9, 1.5);
    auto it=r2.begin();
    while(it!=r2.end()){
        cout << *it++ << " ";
    }
    cout << "\n------------\n";

    for(auto x:Range<int>(1, 5))
        cout << x << ", ";
    cout << "\n------------\n";

    for(auto x : Range<int>(7))
        cout << x << " ";
    cout << "\n------------\n";

    auto r3=make_range(-4.0, 3.5, 1.2);
    for(auto x : r3)
        cout << x << " ";
    cout << "\n------------\n";

    for(auto x: make_range(6))
        cout << x << " ";
    cout << "\n------------\n";

    return 0;
}

