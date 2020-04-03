//Monika Wielgus
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
using namespace std;

template<typename T, T (*f)(T), int N>
void process(T array[]){
    for(int i=0; i<N; i++)
        array[i]=f(array[i]);
}
int main(){

    double a[] = {1, 2, 3, 4};
    process<double, sin, 4> (a);
    for( auto x: a)
        cout << x << " ";
    cout << endl;
    return 0;
}
