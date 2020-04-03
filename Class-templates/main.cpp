//Monika Wielgus
#include <iostream>
#include <iomanip>
#include "dynamicMatrix.h"
#include "staticMatrix.h"

using namespace std;
template <typename M>
void printMatrix(const M & m, int width=10){
	for(int i=1; i<=m.numberOfRows(); ++i){
		for(int j=1; j<=m.numberOfColumns(); ++j){
			if(j!=1)
				cout << " ";
			cout << setw(width) <<  m(i,j) ;
		}
		cout  << endl;
	}
    cout << "------------------------\n";
}

template <int N, int M>
using SMatrix=Matrix<double, N, M>;

using DMatrix=Matrix<double, 0, 0>;

int main(){
    cout << fixed << setprecision(2);
	using AMatrix = Matrix<double, 3, 4>;
    AMatrix a0{};
	printMatrix(a0);
	AMatrix a1({{1,  2,  3,  4},
		       { 5,  6,  7,  8},
		       { 9, 10, 11, 12}});
	printMatrix(a1);
	AMatrix a2=a1; // copy constructor
	a2(2,1)=-5;  a2(3,2)=-20; // mutable access
	AMatrix a3=a1+a2; // matrix sum (with equal sizes)
	//auto mm=m1*m2; // compilation ERROR
	printMatrix(a3);
	Matrix<double, 4, 2> a4({
		{1.2, 1},
		{21, 2},
		{34, 2},
		{2, 32}});
	auto a5=a1*a4;    // matrix multiplication
	// auto mm=m1+m4;   // compilation ERROR
	printMatrix(a5);

	DMatrix m1({{1,  2,  3,  4},
		       { 5,  6,  7,  8},
		       { 9, 10, 11, 12}});
	printMatrix(m1);

	DMatrix m2=transpose(m1);
	printMatrix(m2);

	SMatrix<4,2> m3({
		{1.2, 1},
		{21, 2},
		{34, 2},
		{2, 32}});
    printMatrix(m3);

	SMatrix<2,4> m4=transpose(m3);
    printMatrix(m4);

	return 0;
}
