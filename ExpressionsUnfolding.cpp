//Monika Wielgus
#include <iostream>
using namespace std;

template<int N>
class Vector{
    int data[N];
public:
    Vector(){
        cout << " Default constr" << endl;
    }
    Vector(std::initializer_list<int> list){
        cout << " Init list constr" << endl;
        auto it = list.begin();
        for(int i=0; i<N; i++){
            data[i] = *it++;
        }
    }
    Vector(const Vector & m){
        std::copy(m.data, m.data+N, data);
        cout << " Copy constr" << endl;
    }
    int operator[](int index) const{
        return data[index];
    }
    int & operator[](int index){
        return data[index];
    }

    friend ostream & operator << (ostream & out, const Vector & m){
        for(auto x : m.data){
            cout << x << ", ";
        }
        return out;
    }
};
template<typename L, typename R>
class AddNode{
    L left;
    R right;
public:
    AddNode(L && l, R && r): left(std::forward<L>(l)), right(std::forward<R>(r)){}
    ~AddNode(){}
    int operator[](int x) const{
        return left[x]+right[x];
    }
    template<int N>
    operator Vector<N>(){
        Vector<N> v;
        for(int i=0; i<N; i++)
            v[i]=(*this)[i];
        return v;
    }
};
template<typename L, typename R>
class MinusNode{
    L left;
    R right;
public:
    MinusNode(L && l, R && r): left(std::forward<L>(l)), right(std::forward<R>(r)){}
    ~MinusNode(){}
    int operator[](int x) const{
        return left[x]-right[x];
    }
    template<int N>
    operator Vector<N>(){
        Vector<N> v;
        for(int i=0; i<N; i++)
            v[i]=(*this)[i];
        return v;
    }
};
template<typename L, typename R>
class Multiply{
    L left;
    R right;
public:
    Multiply(L && l, R && r): left(std::forward<L>(l)), right(std::forward<R>(r)){}
    ~Multiply(){}
    int operator[](int x) const{
        return left*right[x];
    }
    template<int N>
    operator Vector<N>(){
        Vector<N> v;
        for(int i=0; i<N; i++)
            v[i]=(*this)[i];
        return v;
    }
};
template<typename L,typename R>
AddNode<L,R> operator+(L && left, R &&right){
    return AddNode<L,R>(std::forward<L>(left),std::forward<R>(right));
}
template<typename L,typename R>
MinusNode<L,R> operator-(L && left, R &&right){
    return MinusNode<L,R>(std::forward<L>(left),std::forward<R>(right));
}
template<typename L,typename R>
Multiply<L,R> operator*(L && left, R &&right){
    return Multiply<L,R>(std::forward<L>(left),std::forward<R>(right));
}
int main(){
    using V=Vector<10>;
    V v{1,2,3,4,5,6,7,8,9,10};
    V x(v);
    V y{4,4,2,5,3,2,3,4,2,1};

    cout << "Lazy operations :\n";
    V z=v+x+3*y-2*x;
    cout << z << endl;

    int e=(z+x+y)[2];
    cout << " e = " << e << endl;
    return 0;
}
