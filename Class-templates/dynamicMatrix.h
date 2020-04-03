//Monika Wielgus
#ifndef DYNAMICMATRIX_H
#define DYNAMICMATRIX_H

#include <iostream>
#include <iomanip>
#include "staticMatrix.h"

using namespace std;

template<typename T, int N, int M>
Matrix<T,M,N> transpose(Matrix<T,N,M> &m){
    Matrix<T,M,N> matrix=Matrix<T,M,N>(m.Columns,m.Rows);

    for(int i=1; i<=m.Rows; i++)
        for(int j=1; j<=m.Columns; j++)
            matrix(j,i)=m(i,j);

    return matrix;
}

template <typename T>
class Matrix<T,0,0>{
public:
    unique_ptr<T[]> array;
    int Rows;
    int Columns;

    Matrix<T,0,0>(Uninitialized, int Rows=0, int Columns=0){
        array=make_unique<T[]>(Rows*Columns);
        cout << "constructor of dynamic uninitialized matrix" << endl;
    }
    Matrix() : Rows(0), Columns(0){
        array=nullptr;
        cout << "default constructor of dynamic matrix" << endl;
    }
    Matrix(int n, int m) : Rows(n), Columns(m){
        array = make_unique<T[]>(Rows*Columns);
        for(int i=0; i<Rows*Columns; i++)
            array[i]=T();
        cout << "constructor of dynamic " << Rows << "x" << Columns << " matrix" << endl;
    }
    Matrix(const Matrix &matrix) : Rows(matrix.Rows) , Columns(matrix.Columns){
        array = make_unique<T[]>(Rows*Columns);
        for(int i=0; i < Rows * Columns; i++)
            array[i]=matrix.array[i];

        cout << "copy constructor of dynamic matrix" << endl;
    }
    Matrix(std::initializer_list<std::initializer_list<T>> list) : Rows(list.size()),Columns(list.begin()->size()){
        array = make_unique<T[]>(Rows*Columns);
        for(int i=0; i<Rows; i++){
            for(int j=0; j<Columns; j++){
                array[j+i*Columns]=*((*(list.begin()+i)).begin()+j);
            }
        }
        cout << "constructor of dynamic " << Rows << "x" << Columns << " matrix from initializer list" << endl;
    }

    Matrix(Matrix && matrix) : Rows(std::move(matrix.Rows)) , Columns(std::move(matrix.Columns)){
        array=std::move(matrix.array);
        matrix.array=nullptr;
        cout << "move constructor" << endl;
    }
    T operator() (int i, int j)const{ return array[(i-1)*Columns+j-1];}
    T & operator() (int i, int j){ return array[(i-1)*Columns+j-1];}
    int numberOfColumns()const{ return Columns;}
    int numberOfRows()const{ return Rows;}

    Matrix &operator=(Matrix && matrix){
        if(&matrix!=this){
            Rows=std::move(matrix.Rows);
            Columns=std::move(matrix.Columns);
            array=std::move(matrix.array);
            matrix.Rows=0;
            matrix.Columns=0;
            matrix.array=nullptr;
        }
        cout << "move assignment operator" << endl;
        return *this;
    }
    Matrix operator +(const Matrix &m){
        if(m.Columns!=Columns||m.Rows!=Rows){
            MatrixException e("Incompatible dimensions in operator +");
            throw e;
        }
        Matrix A(Rows, Columns);
        for(int i=0; i <A.Columns * A.Rows; i++){
            A.array[i]=array[i]+m.array[i];
        }
        return A;
    }
    Matrix operator *(const Matrix &m){
        if(Columns!=m.Rows){
            MatrixException e("Incompatible dimensions in operator *");
            throw e;
        }
        Uninitialized x;
        Matrix<T,0,0> A(x,Rows,m.Columns);
        for(int i=0; i<Rows*m.Columns; i++)
            A.array[i]=0;

        for(int i=1; i<=Rows; i++){
            for(int j=1; j<=m.Columns; j++)
                for(int k=1; k<=Columns; k++) {
                    A(i,j)+=array[(i-1)*Columns+k-1]*m(k,j);
                }
        }
        return A;
    }
    template<int N, int M>
    explicit operator Matrix<T,N,M>(){
        Matrix<T,N,M> A;
        for(int i=0; i<N*M; i++)
            A.array[i]=array[i];

        cout << "conversion from dynamic to static matrix" << endl;
        return A;
    }
    template<int N, int M>
    Matrix<T,N,M> operator+(Matrix<T,N,M>& m){
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
    template<int N, int M>
    Matrix<T,0,0> operator*(Matrix<T,N,M>& m){
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
#endif // DYNAMICMATRIX_H
