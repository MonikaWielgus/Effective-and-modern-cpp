//Monika Wielgus
#include <iostream>
template<int N, typename T>
struct DotProd{
    static const T product(T* a, T* b){
        return a[N-1]*b[N-1]+DotProd<N-1,T>::product(a,b);
    }
};
template <typename T>
struct DotProd<0,T>{
    static const T product(T* a, T* b){
        return 0;
    }
};
template <int N, typename T>
T DotProduct(T a[], T b[]){
    return DotProd<N,T>::product(a,b);
}

template<int N, int M, int W, typename T>
struct Multi{
    static void result(T* A, T* x, T* y){
        if(W==M) y[N-1]=0;
        y[N-1]+=A[(N-1)*W+M-1]*x[M-1];
        Multi<N,M-1,W,T>::result(A,x,y);
    }
};
template<int N, int W, typename T>
struct Multi<N,1,W,T>{
    static void result(T* A, T* x, T* y){
        y[N-1]+=A[(N-1)*W]*x[0];
        Multi<N-1,W,W,T>::result(A,x,y);
    }
};
template<int W, typename T>
struct Multi<1,1,W,T>{
    static void result(T* A, T* x, T* y){
        y[0]+=A[0]*x[0];
        return;
    }
};
template<int N, int M, typename T>
void Multiply(T A[], T x[], T y[]){
    Multi<N,M,M,T>::result(A,x,y);
}
int main() {
    double a[] = {1, 2, 3};
    double b[] = {1, 1, 1};
    std::cout<< DotProduct<3>(a, b) << std::endl;
    double x[] = {1, 1, 0};
    double A[] = {1, 0, 0,
                  2, -5, 1};
    double y[2];
    Multiply<2,3>(A, x, y);
    std::cout << y[0] << " " << y[1];
}
