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
            if(j >= s)
                data[j+i*M]=0;
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

class MatrixWithLabel : public Matrix{
    string matrixlabel = "A";
    using Matrix::Matrix;
public:
    MatrixWithLabel(string, int, int);
    MatrixWithLabel(string, std::initializer_list<std::initializer_list<double>>);
    MatrixWithLabel(const MatrixWithLabel&);
    MatrixWithLabel(MatrixWithLabel&&);
    MatrixWithLabel & operator=(const MatrixWithLabel &); //copy assignment
    MatrixWithLabel & operator=(MatrixWithLabel &&); //move assignment


    MatrixWithLabel(const Matrix &);
    string getLabel();
    void setLabel(string);

};

MatrixWithLabel::MatrixWithLabel(string label, int N, int M) : Matrix(N,M){
    matrixlabel=label;
}
MatrixWithLabel::MatrixWithLabel(string label, std::initializer_list<std::initializer_list<double>> list) : Matrix(list){
    matrixlabel=label;
}
MatrixWithLabel::MatrixWithLabel(const MatrixWithLabel& matrix) : matrixlabel(matrix.matrixlabel) , Matrix(matrix){
    cout << "copy constructor of matrixwithlabel" << endl;
}
MatrixWithLabel::MatrixWithLabel(MatrixWithLabel&& matrix)=default;
MatrixWithLabel & MatrixWithLabel::operator=(const MatrixWithLabel & matrix)=default; //copy assignment
MatrixWithLabel & MatrixWithLabel::operator=(MatrixWithLabel && matrix)=default; //move assignment

string MatrixWithLabel::getLabel(){
    return matrixlabel;
}

void MatrixWithLabel::setLabel(string a){
    matrixlabel=a;
}


int main(){

	Matrix m1;
	Matrix m2(3,4);
	Matrix m3({{1,2,3},{32, 23, 22},{3,234,23,44}});
	cout << m2(1,1) << endl;  // 0
	cout << m3(2,2) << endl;  // 23
	cout << m3;

	cout << "Copy semantics \n";
	Matrix m4 = m2;
	m4 = m3;

	cout << "Move semantics \n";
	Matrix m7 = std::move(m2);
	m4 = -m3;

	cout << "Copy elision \n";
	Matrix m6 = -m4;
	Matrix * pm = new Matrix(-m4);
	cout << m6(2,1) << endl; // 32

	cout << "Inheritance \n";
	MatrixWithLabel l0("B", 3, 4);
	MatrixWithLabel l1({{1,2},{4,5}});
	l1.setLabel("A");
	MatrixWithLabel l2 = l1;
	MatrixWithLabel l3 = std::move(l1);
	cout << l2.getLabel() << " " << l3.getLabel() << endl;
	// 	cout << l1.getLabel() << endl;

	return 0;
}
