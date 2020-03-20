//Monika Wielgus
#include <iostream>
#include <memory>

using namespace std;

class Matrix
{
protected:
    unique_ptr<double[]> data;
    int N; //down
    int M; //->
public:
    Matrix();
    Matrix(int, int);
    Matrix(std::initializer_list<std::initializer_list<double>>);
    Matrix(const Matrix &); //copy constructor
    Matrix(Matrix &&); //move constructor

    double operator() (int, int) const;
    double & operator() (int, int);

    friend ostream& operator<<(ostream&, const Matrix &);

    Matrix & operator=(const Matrix &); //copy assignment
    Matrix & operator=(Matrix &&); //move assignment
    Matrix operator-();

};

Matrix::Matrix() : N(0), M(0){
    data=nullptr;
    cout << "default constructor" << endl;
}
Matrix::Matrix(int n, int m) : N(n), M(m){
    data = make_unique<double[]>(N*M);

    for(int i=0; i<N*M; i++)
    {
        data[i]=0.0;
    }

    cout << "constructor of " << n << "x" << m << " matrix" << endl;
}
Matrix::Matrix(std::initializer_list<std::initializer_list<double>> list){
    N=list.size();
    size_t maxSize=0;
    for( auto & row: list){
        maxSize=std::max(maxSize, row.size());
    }

    M=maxSize;
    data = make_unique<double[]>(N*M);

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            size_t s = (*(list.begin()+i)).size();
            if(j >= s){
                data[j+i*M]=0;
            }
            else
                data[j+i*M]=*((*(list.begin()+i)).begin()+j);
        }
    }
    cout << "constructor of " << N << "x" << M << " matrix from initializer_list" << endl;

}
Matrix::Matrix(const Matrix & matrix) : N(matrix.N) , M(matrix.M){
    data = make_unique<double[]>(N*M);
    for(int i=0; i<N*M; i++)
        data[i]=matrix.data[i];
    cout << "copy constructor" << endl;
}
Matrix::Matrix(Matrix && matrix) : N(std::move(matrix.N)) , M(std::move(matrix.M)){
    data=std::move(matrix.data);
    matrix.data=nullptr;
    cout << "move constructor" << endl;
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
            data = make_unique<double[]>(matrix.M*matrix.N);
        }
        N=matrix.N;
        M=matrix.M;
        for(int i=0; i<N*M; i++){
            data[i]=matrix.data[i];
        }
    }
    cout << "copy assignment operator" << endl;
    return *this;
}
Matrix & Matrix::operator=(Matrix && matrix){

    if(&matrix!=this){
        N=std::move(matrix.N);
        M=std::move(matrix.M);
        data=std::move(matrix.data);
        matrix.N=0;
        matrix.M=0;
        matrix.data=nullptr;
    }
    cout << "move assignment operator" << endl;
    return *this;
}
Matrix Matrix::operator-(){
    Matrix n(N,M);
    for(int i=0; i<N*M; i++)
        n.data[i]=-data[i];

    return n;
}

class MatrixPair{
public:
    Matrix left;
    Matrix right;

    MatrixPair(const MatrixPair &)=delete; //copy constructor
    MatrixPair(MatrixPair &&)=default; //move constructor
    MatrixPair & operator=(const MatrixPair &)=delete; //copy assignment
    MatrixPair & operator=(MatrixPair &&)=default; //move assignment

};

int main(){
    Matrix m1({{1,2},{4,4}}), m2(4,5);
    MatrixPair p1 {m1, std::move(m2)};
//    MatrixPair p2 = p1; // ERROR!
    MatrixPair p3 = std::move(p1);
    Matrix a = p3.left, b=p3.right;
    MatrixPair p4{a,b};
//    p1 = p4; // ERROR!
    p1 = std::move(p4);
}
