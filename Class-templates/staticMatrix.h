//Monika Wielgus
#ifndef STATICMATRIX_H
#define STATICMATRIX_H

#include <iostream>
#include <iomanip>
#include "dynamicMatrix.h"

using namespace std;

class MatrixException : public std::runtime_error{
public:
    const string message;
    MatrixException(const string &message) : runtime_error(message), message(message) {}
    const char * what () const throw () {
        return message.c_str();
    }
};

class Uninitialized{};

template <typename T, int N, int M>
class Matrix{
public:
    int Rows=N;
    int Columns=M;
    T array[N * M];

    Matrix<T,N,M>(Uninitialized, int rows=N, int columns=M){
        cout << "constructor of static uninitialized matrix" << endl;
    }
    Matrix(){
        for(int i=0; i<N*M; i++){
            array[i]=T();
        }
        cout << "constructor of static " << N << "x" << M << " matrix" << endl;
    }
    Matrix(const Matrix &m){
        for(int i=0; i<N*M; i++){
            array[i]=m.array[i];
        }
        cout << "copy constructor of static matrix" << endl;
    }
    Matrix(int n, int m){
        Rows=n;
        Columns=m;
        cout << "constructor of static " << n << "x" << m << " matrix" << endl;
    }
    Matrix(std::initializer_list<std::initializer_list<T>> list){
        double *pRow=array;
        for(auto & row: list){
            std::copy(row.begin(), row.end(), pRow);
            pRow+=M;
        }
        cout << "constructor of static " << N << "x" << M << " matrix from initializer list" << endl;
    }
    T operator() (int i, int j)const{ return array[(i-1)*M+j-1];}
    T & operator() (int i, int j){ return array[(i-1)*M+j-1];}
    int numberOfColumns()const{ return M;}
    int numberOfRows()const{ return N;}

    Matrix operator +(const Matrix &m){
        Uninitialized x;
        Matrix A(x);

        for(int i=0; i < M * N; i++){
            A.array[i]=array[i]+m.array[i];
        }
        return A;
    }
    template<int K>
    friend Matrix<T,N,K> operator*(const Matrix<T,N,M> &m1, const Matrix<T,M,K> &m2){
        Uninitialized x;
        Matrix<T,N,K> A(x);
        for(int i=0; i<N*K; i++)
            A.array[i]=0;

        for(int i=1; i<=N; i++){
            for(int j=1; j<=K; j++)
                for(int k=1; k<=M; k++) {
                    A(i,j)+=m1(i,k)*m2(k,j);
                }
        }
        return A;
    }
    explicit operator Matrix<T,0,0>(){
        Matrix<T,0,0> A(Rows,Columns);
        for(int i=0; i<N*M; i++)
            A.array[i]=array[i];

        cout << "conversion from static to dynamic matrix" << endl;
        return A;
    }
    Matrix<T,N,M> operator+(Matrix<T,0,0>& m){
        if(Rows!=m.Rows||Columns!=m.Columns){
            MatrixException e("Incompatible dimensions in operator +");
            throw e;
        }
        else{
            Matrix<T,N,M> A;
            for(int i=0; i<Rows*Columns; i++)
                A.array[i]=array[i]+m.array[i];

            return A;
        }
    }
    Matrix<T,0,0> operator*(Matrix<T,0,0>& m){
        if(Rows!=m.Rows||Columns!=m.Columns){
            MatrixException e("Incompatible dimensions in operator *");
            throw e;
        }
        else{
            Matrix<T,0,0> A(Rows,m.Columns);
            for(int i=0; i<Rows*m.Columns; i++)
                A.array[i]=0;

            for(int i=1; i<=Rows; i++){
                for(int j=1; j<=m.Columns; j++)
                    for(int k=1; k<=Columns; k++){
                        A(i,j)+=array[(i-1)*Columns+k-1]*m(k,j);
                    }
            }
            return A;
        }
    }
};

#endif // STATICMATRIX_H
