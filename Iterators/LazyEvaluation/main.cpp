//Monika Wielgus
#include "Filter.h"
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main(){

    bool debug=true;
    auto message=[&debug](int x, bool v){
        if(debug  and !v) cout << " - skipping " << x << endl;
        return v;
    };
    auto addMessage=[message](auto f){
        return [message, f](int x) { return message(x, f(x)); };
    };

    auto isEven=[](int x){
        return x%2==1;
    };
    auto isPrime=[](int x){
        if(x<=1) return false;
        for(auto i=2; i*i<=x; ++i)
            if(x%i==0)return false;
        return true;
    };

    std::vector<int> v={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 23};

    auto even=make_filter(v, addMessage(isEven));

    auto evenPrime=make_filter(even, addMessage(isPrime));

    v[2]=1001;
    v.push_back(101);

    for(auto x:evenPrime){
        cout << x << endl;
    }
    cout << "=======================\n";
    auto primeEven=make_filter( make_filter(v, isPrime), isEven);
    for(auto x : primeEven){
        cout << x << endl;
    }
    cout << "=======================\n";
    auto evenPrimeWithOne=make_filter(evenPrime, [](int x){
        while(x!=0)
            if(x%10==1)
                return true;
            else
                x/=10;
        return false;
    });
    debug=false;
    for(auto x : evenPrimeWithOne){
        cout << x << endl;
    }
    return 0;
}
