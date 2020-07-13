//Monika Wielgus
#include <iostream>
#include <typeinfo>
#include <cstdarg>
using namespace std;

double f(int x, double y, const int & z, int & w){
    w += 2;
    cout << x << " " << y<< " " << z << " " << w <<endl;
    return (x*y - z*w);
}

template<typename T>
void showNames(T arg){
    cout << typeid(arg).name() << " = " << arg << endl;
}
template<typename T, class...Args>
void showNames(T arg1, Args ... arg2){
    cout << typeid(arg1).name() << " = " << arg1 << endl;
    return showNames(arg2...);
}

template<typename T>
class Proxy{
    T f;
public:
    Proxy(T arg):f(arg){}

    template<class...Args>
    auto operator()(Args&& ... arg){
        showNames(arg...);
        return f(arg...);
    }
};
template<typename T>
Proxy<T> make_proxy(T arg) {
    return Proxy<T>(arg);
}
int main(){
    int x=4;
    const int y=8;
    showNames(x, 4.5, y, f);
    showNames(1, 1.0f, 1.0, 1LL, &x, &y);

    auto p=make_proxy(f);
   // auto p = Proxy(f);    /// with C++ 17
    auto result1=p(12, 5.1, y, x);
    cout << "result1 = " << result1 << endl;
    auto result2=p(12, 5.1, y, x);
    cout << "result2 = " << result2 << endl;
    auto result3=p(3, 3, 5, x);
    cout << "result3 = " << result3 << endl;

    auto g=make_proxy([](int &x, int & y){ y = x; return y; }) ;
   // auto g = Proxy([](int &x, int & y){ y = x; return y; }) ; // with C++ 17
    cout << g(5, x) << endl;
    cout << "x = " <<  x << endl;
    return 0;
}
