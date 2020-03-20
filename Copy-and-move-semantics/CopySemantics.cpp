//Monika Wielgus
#include <iostream>

using namespace std;
class Matrix
{
    double* data;
    int N; //down
    int M; //->
public:
    Matrix();
    Matrix(int, int);
    Matrix(std::initializer_list<std::initializer_list<double>> list);
    Matrix(const Matrix &);

    double operator() (int, int) const;
    double & operator() (int, int);

    friend ostream& operator<<(ostream&, const Matrix &);

    Matrix & operator=(const Matrix &);

    ~Matrix();

};

Matrix::Matrix() : N(0), M(0){
    data=nullptr;
    cout << "default constructor" << endl;
}
Matrix::Matrix(int n, int m) : N(n), M(m){
    data = new double[N*M];

    std::fill(data, data+N*M, 0.0);

    cout << "constructor of " << n << "x" << m << " matrix" << endl;
}
Matrix::Matrix(std::initializer_list<std::initializer_list<double>> list){
    N=list.size();
    size_t maxSize=0;
    for( auto & row: list){
        maxSize=std::max(maxSize, row.size());
    }

    M=maxSize;
    data = new double[N*M];

    double *p=data;
    double *pRow=data;
    for(auto & row: list){
        p=std::copy(row.begin(), row.end(), pRow); //([first,last),where to copy)    p=one after the last of where to copy
        std::fill(p, pRow+maxSize, 0.0);
        pRow += maxSize;
    }
    cout << "constructor of " << N << "x" << M << " matrix from initializer_list" << endl;

}
Matrix::Matrix(const Matrix & matrix) : N(matrix.N) , M(matrix.M){
    data = new double[N*M];
    std::copy(matrix.data, matrix.data+N*M,data);
    cout << "copy constructor" << endl;
}

double Matrix::operator() (int i, int j) const{ return data[(i-1)*M+j-1];}
double & ::Matrix::operator() (int i, int j) {return data[(i-1)*M+j-1];}

ostream& operator<<(ostream& out, const Matrix & matrix){
    for(int n=1; n<=matrix.N; n++){
        out << "{";
        for(int m=1; m<=matrix.M; m++){
            if(m!=matrix.M) out << matrix(n,m) << ", ";
            else out << matrix(n,m);
        }
        out << "}" << endl;
     }

     return out;
}

Matrix & Matrix::operator=(const Matrix & matrix){
    if(&matrix != this){
        if(N*M!=matrix.N*matrix.M){
            delete []data;
            data = new double[matrix.M*matrix.N];
        }
        N=matrix.N;
        M=matrix.M;
        std::copy(matrix.data, matrix.data+N*M, data);
    }
    cout << "copy assignment operator" << endl;
    return *this;
}

Matrix::~Matrix(){
    if(data!=nullptr){
        delete [] data;
    }
}

int main(){
    Matrix m1; // default constructor: N=M=0, data=nullptr
    Matrix m2(3,4); // N = 3, M = 4, data = N*M doubles set to 0.0
    Matrix m3({{1,2,3},{32, 23, 22},{3,234,23,44}}); // from initializer_list
    cout << m2(1,1) << endl; // 0 - the first element in data (we count from 1)
    cout << m3(2,2) << endl; // 23
    cout << m3; // prints matrix
    cout << "Copy semantics \n";
    Matrix m4 = m2; // copy constructor that makes deep copy of the matrix m2
    m4 = m3;
}
