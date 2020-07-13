//Monika Wielgus
#include <iostream>
using namespace std;

int totalNOfObjects;
int tSize;

template<typename T>
class Counter{
    static int nOfObjects;
public:
    Counter(){
        nOfObjects++;
        totalNOfObjects++;
        tSize+=sizeof(T);
    }
    Counter(const Counter&){
        nOfObjects++;
        totalNOfObjects++;
        tSize+=sizeof(T);
    }
    static int numberOfObjects(){
        return nOfObjects;
    }
    static int totalNumberOfObjects(){
        return totalNOfObjects;
    }
    static int totalSize(){
        return tSize;
    }

protected:
    ~Counter(){
        nOfObjects--;
        totalNOfObjects--;
        tSize-=sizeof(T);
    }
};
template <typename T> int Counter<T>::nOfObjects(0);


template <typename T, int N>
struct A : Counter<A<T,N>>{
    T data[N];
};

template <typename T, typename S>
struct P : Counter<P<T,S>>{
    T a=T{};
    S b=S{};
    P()=default;
    P(T &&a, S &&b) : a(std::forward<T&&>(a)), b(std::forward<S&&>(b)){}
};

int main(){
    using At=A<int,10>;
    using Pt=P<int, double>;
    using APt=A<Pt, 5>;
    At a1, a2;
    At * pa=new At{};

    cout << At::numberOfObjects() << " " << At::totalNumberOfObjects()
         << " " << At::totalSize() << endl;

    Pt p1{1, 5.3};
    Pt p3{p1};
    cout << At::numberOfObjects() << " " << At::totalNumberOfObjects()
         << " " << At::totalSize() << endl;
    cout << Pt::numberOfObjects() << " " << Pt::totalNumberOfObjects()
         << " " << Pt::totalSize() << endl;

    delete pa;
    cout << At::numberOfObjects() << " " << At::totalNumberOfObjects()
         << " " << At::totalSize() << endl;

    APt ap;
    cout << Pt::numberOfObjects() << " " << Pt::totalNumberOfObjects()
         << " " << Pt::totalSize() << endl;
    cout << APt::numberOfObjects() << " " << APt::totalNumberOfObjects()
         << " " << APt::totalSize() << endl;

    return 0;
}
