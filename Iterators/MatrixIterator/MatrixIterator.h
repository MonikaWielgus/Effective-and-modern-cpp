#ifndef MATRIXITERATOR_H
#define MATRIXITERATOR_H

using namespace std;

template <typename M>
void printMatrix(const M & m, int width = 10){
    for(int i = 1; i <= m.numberOfRows(); ++i){
        for(int j = 1; j <= m.numberOfColumns(); ++j){
            if(j != 1)
                cout << " ";
            cout << setw(width) <<  m(i,j) ;
        }
        cout << endl;
    }
}

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
    Matrix(){ //default
        for(int i=0; i<N*M; i++){
            array[i]=T();
        }
        cout << "constructor of static " << N << "x" << M << " matrix" << endl;
    }
    Matrix(const Matrix &m){ //copy
        for(int i=0; i<N*M; i++){
            array[i]=m.array[i];
        }
        cout << "copy constructor of static matrix" << endl;
    }
    Matrix(std::initializer_list<std::initializer_list<T>> list){
        for(int i=0; i<Rows; i++){
            for(int j=0; j<Columns; j++){
                array[j+i*Columns]=*((*(list.begin()+i)).begin()+j);
            }
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
    class iterator;
    friend class iterator;

    class iterator{
        Matrix<T,N,M> &m;
        unsigned int index;
    public:
        iterator(Matrix<T,N,M>& mArg):m(mArg),index(0){}

        const iterator& operator++(){
            ++index;
            return *this;
        }
        iterator operator++(int){
            iterator it(*this);
            ++index;
            return it;
        }
        T& operator*()const{
            return m.array[index];
        }
        T* operator->() const{
            return &m.array[index];
        }
        bool operator<(const iterator* ite)const{
            return index<ite.index;
        }
        bool operator==(const iterator& ite){
            return index==ite.index;
        }
        bool operator!=(const iterator& ite){
            return index!=ite.index;
        }
        friend class Matrix<T,N,M>;
    };

    iterator begin(){
        return iterator(*this);
    }
    iterator end(){
        iterator ite(*this);
        ite.index=M*N;
        return ite;
    }

    class row_iterator;
    friend class row_iterator;

    class row_iterator{
        Matrix<T,N,M> &m;
        unsigned int index;
    public:
        row_iterator(Matrix<T,N,M>& mArg):m(mArg),index(0){}

        const row_iterator& operator++(){
            ++index;
            return *this;
        }
        row_iterator operator++(int){
            row_iterator it(*this);
            ++index;
            return it;
        }
        T& operator*()const{
            return m.array[index];
        }
        T* operator->() const{
            return &m.array[index];
        }
        bool operator<(const row_iterator* ite)const{
            return index<ite.index;
        }
        bool operator==(const row_iterator& ite){
            return index==ite.index;
        }
        bool operator!=(const row_iterator& ite){
            return index!=ite.index;
        }
        friend class Matrix<T,N,M>;
    };

    row_iterator row_begin(int number){
        row_iterator ite(*this);
        ite.index=(number-1)*M;
        return ite;
    }
    row_iterator row_end(int number){
        row_iterator ite(*this);
        ite.index=number*M;
        return ite;
    }

    class col_iterator;
    friend class col_iterator;

    class col_iterator{
        Matrix<T,N,M> &m;
        unsigned int index;
    public:
        col_iterator(Matrix<T,N,M>& mArg):m(mArg),index(0){}

        const col_iterator& operator++(){
            index+=M;
            return *this;
        }
        col_iterator operator++(int){
            col_iterator it(*this);
            index+=M;
            return it;
        }
        T& operator*()const{
            return m.array[index];
        }
        T* operator->() const{
            return &m.array[index];
        }
        bool operator<(const col_iterator* ite)const{
            return index<ite.index;
        }
        bool operator==(const col_iterator& ite){
            return index==ite.index;
        }
        bool operator!=(const col_iterator& ite){
            return index!=ite.index;
        }
        friend class Matrix<T,N,M>;
    };

    col_iterator col_begin(int number){
        col_iterator ite(*this);
        ite.index=(number-1);
        return ite;
    }
    col_iterator col_end(int number){
        col_iterator ite(*this);
        ite.index=(number-1)+N*M;
        return ite;
    }

};
#endif
