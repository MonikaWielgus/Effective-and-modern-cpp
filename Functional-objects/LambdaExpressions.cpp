//Monika Wielgus
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <cassert>
#include <numeric>
#include <cmath>
#include <type_traits>
using namespace std;

void print(const std::vector<int> & v){
    for( auto x  : v) cout << x << " ";
    cout << endl;
}

int main(){
    std::vector<int> v={256, 64, 16*3, 16*9, 16, 8*7, 9, 3, 1, 6, 2, 5};
    print(v);

    int center=50;
    std::sort(v.begin(), v.end(),[center](int a, int b){
        if(abs(a-center)<abs(b-center))
            return true;
        return false;
        }
    );
    print(v);

    auto sharkovsky=[](int a, int b){
        if(a==b)
            return false;
        //easy cases
        if(a==3||b==1) //a>b
            return false;
        if(a==1||b==3) //a<b
            return true;

        if(a%2!=0&&b%2==0) //a>b
            return false;
        if(a%2==0&&b%2!=0) //a<b
            return true;
        if(a%2!=0&&b&2!=0){
            if(a>b)
                return true;
            return false;
        }
        //more complicated ones
        int count_a=0;
        int count_b=0;

        while(a%2==0){ //a*2^count_a
            a/=2;
            count_a++;
        }

        while(b%2==0){ //b*2^count_b
            b/=2;
            count_b++;
        }

        if(a==1&&b==1){
            if(count_a<count_b) //comparison of 2^count_a and 2^count_b
                return true;
            return false;
        }

        if(a==1&&b!=1) //for example a=2^3*1, b=2^3*7
            return true;
        if(a!=1&&b==1) // a=2^3*7, b=2^3*1
            return false;
        if(count_a==0&&count_b!=0) // a=7,b=2^3*3
            return true;
        if(count_a!=0&&count_b==0) //a=2^2*3
            return false;
        if(count_a!=0&&count_b!=0&&a!=1&&b!=1){ //a=2^3*3, b=2*4*5
            if(count_a>count_b) //more important part
                return true;
            if(count_a<count_b)
                return false;
            if(count_a==count_b){ //more important part is equal
                if(a>b) //less important part
                    return true;
                return false;
            }
        }
    };

    assert(sharkovsky(1,2));
    assert(sharkovsky(2,4));
    assert(sharkovsky(64,256));
    assert(sharkovsky(256,256*3));
    assert(sharkovsky(256*9,256*5));
    assert(sharkovsky(256*3,64*9));
    assert(!sharkovsky(1,1));
    assert(!sharkovsky(4,2));
    assert(!sharkovsky(256,64));
    assert(!sharkovsky(256*3,256));
    assert(!sharkovsky(256*5,256*9));
    assert(!sharkovsky(64*9,256*3));

    std::sort(v.begin(), v.end(), sharkovsky);
    print(v);

    srand(2019);
    int a=0, b=40;
    auto generator=[&a,&b](){
        return (std::rand()%(b-a+1))+a;
    };

    std::generate(v.begin(), v.end(), generator);
    print(v);

    a=100, b=200;
    std::generate(v.begin(), v.end(), generator);
    print(v);

    a=-10; b=10;
    auto evenGenerator=[a,b](){
        int number;
        do{
            number=std::rand()%(b-a+1)+a;
        }while(number%2!=0);

        return number;
    };
    std::generate(v.begin(), v.end(), evenGenerator);
    print(v);

    v.resize(20);
    a=0; b=100;
    std::generate(v.begin(), v.end(), evenGenerator);
    print(v);

    auto l1_norm=[](auto F){
        return std::accumulate(F.begin(), F.end(), 0.0, [](auto a, auto b){ return std::abs(a)+std::abs(b);});
    };                           // ( 5 )
    cout << l1_norm(v) << endl;

    vector<double> m = {1.4, 2.4, -2.4, -4.2, -43.3};
    cout << l1_norm(m) << endl;

    list<double> l(m.begin(), m.end());
    cout << l1_norm(l) << endl;

    auto polynomial=[](double *a, int n){
        return [a,n](double x){
            auto result=0.0;
            for (int i = 0; i <= n; i++){
                result += a[i] * pow(x, i);
            }
            return result;
        };
    };

    double c[]={1, 2, 3, 4, 5};
    auto w1 =polynomial(c, 4);
    cout << w1(1.0) << " " << w1(0.0) << " " << w1(2.0) << endl;

    auto w2=polynomial(c, 2);
    cout << w2(1.0) << " " << w2(0.0) << " " << w2(2.0) << endl;

    return 0;
}

