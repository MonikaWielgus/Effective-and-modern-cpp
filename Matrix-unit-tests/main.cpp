//Monika Wielgus
#include <iostream>
#include <iomanip>
#include "dynamicMatrix.h"
#include "staticMatrix.h"

using namespace std;
template <typename M>
void printMatrix(const M & m, int width = 10){
    for(int i=1; i<=m.numberOfRows(); ++i){
        for(int j=1; j<=m.numberOfColumns(); ++j){
            if(j!=1)
                cout << " ";
            cout << setw(width) << m(i,j) ;
        }
        cout << endl;
    }
}

template <int N, int M>
using SMatrix=Matrix<double, N, M>;

using DMatrix=Matrix<double, 0, 0>;

int main(){
    cout << fixed << setprecision(2);

    DMatrix m1({{1,2,3},
                {5,6,7},
                {9,10,11}});
    printMatrix(m1);

    SMatrix<3,3> m2={{1,-1,0},
                    {2,-2,1},
                    {4,-4,2}};
    printMatrix(m2);

    auto m3=(SMatrix<3,3>)(m1);
    printMatrix(m3);

    auto m4=m1+m2+m1;
    printMatrix(m4);

    auto m4d=static_cast<DMatrix>(m4);
    printMatrix(m4d);

    auto m5=m3*m1*m2;
    printMatrix(m5);

    DMatrix m6({{4}});
    try{
        auto mm=m2*m6;
    }catch(MatrixException & e){
        cout << "Exception : " << e.what() << endl;
    }

    try{
        auto mm=m2+m6;
    }catch(MatrixException & e){
        cout << "Exception : " << e.what() << endl;
    }

    return 0;
}

