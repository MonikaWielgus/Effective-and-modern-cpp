//Monika Wielgus
#include <complex>
#include "gtest/gtest.h"
#include "dynamicMatrix.h"
#include "staticMatrix.h"

TEST(staticMatrix, defaultConstructorInt){
    Matrix<int,1,5> m;
    ASSERT_EQ(m.Rows,1);
    ASSERT_EQ(m.Columns,5);
    ASSERT_EQ(m.array[4],int());
}
TEST(staticMatrix, defaultConstructorShort){
    Matrix<short,5,1> m;
    ASSERT_EQ(m.Rows,5);
    ASSERT_EQ(m.Columns,1);
    ASSERT_EQ(m.array[4],short());
}
TEST(staticMatrix, defaultConstructorDouble){
    Matrix<double,5,1> m;
    ASSERT_EQ(m.Rows,5);
    ASSERT_EQ(m.Columns,1);
    ASSERT_EQ(m.array[4],double());
}
TEST(staticMatrix, defaultConstructorComplex){
    Matrix<complex<double>,5,1> m;
    ASSERT_EQ(m.Rows,5);
    ASSERT_EQ(m.Columns,1);
    ASSERT_EQ(m.array[4],complex<double>());
}
TEST(staticMatrix, copyConstructorInt){
    Matrix<int,1,5> m;
    Matrix m2(m);
    ASSERT_EQ(m.Rows,m2.Rows);
    ASSERT_EQ(m.Columns,m2.Columns);
    for(int i=0; i<5; i++){
        ASSERT_EQ(m.array[i],m2.array[i]);
    }
}
TEST(staticMatrix, copyConstructorShort){
    Matrix<short,1,5> m;
    Matrix m2(m);
    ASSERT_EQ(m.Rows,m2.Rows);
    ASSERT_EQ(m.Columns,m2.Columns);
    for(int i=0; i<5; i++){
        ASSERT_EQ(m.array[i],m2.array[i]);
    }
}
TEST(staticMatrix, copyConstructorDouble){
    Matrix<double,1,5> m;
    Matrix m2(m);
    ASSERT_EQ(m.Rows,m2.Rows);
    ASSERT_EQ(m.Columns,m2.Columns);
    for(int i=0; i<5; i++){
        ASSERT_EQ(m.array[i],m2.array[i]);
    }
}
TEST(staticMatrix, copyConstructorComplex){
    Matrix<complex<double>,1,5> m;
    Matrix m2(m);
    ASSERT_EQ(m.Rows,m2.Rows);
    ASSERT_EQ(m.Columns,m2.Columns);
    for(int i=0; i<5; i++){
        ASSERT_EQ(m.array[i],m2.array[i]);
    }
}
TEST(staticMatrix, constructorFromInitializerListInt){
    Matrix<int,1,5> m{{0,1,2,3,4}};
    for(int i=0; i<5; i++){
        ASSERT_EQ(m.array[i],i);
    }
}
TEST(staticMatrix, constructorFromInitializerListShort){
    Matrix<short,5,1> m{{0},{1},{2},{3},{4}};
    for(int i=0; i<5; i++){
        ASSERT_EQ(m.array[i],i);
    }
}
TEST(staticMatrix, constructorFromInitializerListComplex){
    Matrix<complex<double>,5,1> m{{complex<double>()},{complex<double>()},{complex<double>()},{complex<double>()},{complex<double>()}};
    for(int i=0; i<5; i++){
        ASSERT_EQ(m.array[i],complex<double>());
    }
}
TEST(staticMatrix, constructorFromInitializerListAndCopyConstructorInt){
    Matrix<int,1,5> m{{2,3,2,3,4}};
    Matrix m2(m);
    for(int i=0; i<5; i++){
        ASSERT_EQ(m.array[i],m2.array[i]);
    }
}
TEST(staticMatrix, constructorFromInitializerListAndCopyConstructorDouble){
    Matrix<double,1,5> m{{2.2,3,2.1,3,4}};
    Matrix m2(m);
    for(int i=0; i<5; i++){
        ASSERT_EQ(m.array[i],m2.array[i]);
    }
}
TEST(staticMatrix, constructorFromInitializerListAndCopyConstructorShort){
    Matrix<short,1,5> m{{2,3,2,3,4}};
    Matrix m2(m);
    for(int i=0; i<5; i++){
        ASSERT_EQ(m.array[i],m2.array[i]);
    }
}
TEST(staticMatrix, operator1){
    Matrix<int,1,5> m{{0,1,2,3,4}};
    ASSERT_EQ(m.array[1],m(1,2));
}
TEST(staticMatrix, operator1Int){
    Matrix<int,1,5> m{{0,0,0,0,0}};
    m(1,2)=2;
    ASSERT_EQ(m.array[1],2);
}
TEST(staticMatrix, operator1Short){
    Matrix<short,1,5> m{{0,0,0,0,0}};
    m(1,2)=2;
    ASSERT_EQ(m.array[1],2);
}
TEST(staticMatrix, operator1Double){
    Matrix<double,1,5> m{{0,0,0,0,0}};
    m(1,2)=2.2;
    ASSERT_EQ(m.array[1],2.2);
}
TEST(staticMatrix, operator1Complex){
    Matrix<complex<double>,1,5> m{{0,0,0,0,0}};
    m(1,2)=2.2;
    ASSERT_EQ(m.array[1],2.2);
}
TEST(staticMatrix, function1){
    Matrix<int,5,4> m;
    ASSERT_EQ(m.numberOfRows(),m.Rows);
}
TEST(staticMatrix, function2){
    Matrix<int,5,4> m;
    ASSERT_EQ(m.numberOfColumns(),m.Columns);
}
TEST(staticMatrix, operator2Int){
    Matrix<int,1,5> m{{1,0,2,4,1}};
    Matrix<int,1,5> m2{{3,4,2,0,3}};
    for(int i=1; i<=5; i++){
        ASSERT_EQ((m+m2)(1,i),4);
    }
}
TEST(staticMatrix, operator2Short){
    Matrix<short,1,5> m{{1,0,2,4,1}};
    Matrix<short,1,5> m2{{3,4,2,0,3}};
    for(int i=1; i<=5; i++){
        ASSERT_EQ((m+m2)(1,i),4);
    }
}
TEST(staticMatrix, operator2Double){
    Matrix<double,1,5> m{{1.2,0.2,2.2,4.2,1.2}};
    Matrix<double,1,5> m2{{3.2,4.2,2.2,0.2,3.2}};
    for(int i=1; i<=5; i++){
        ASSERT_EQ((m+m2)(1,i),4.4);
    }
}
TEST(staticMatrix, operator2Complex){
    Matrix<complex<double>,1,5> m{{1.2,0.2,2.2,4.2,1.2}};
    Matrix<complex<double>,1,5> m2{{3.2,4.2,2.2,0.2,3.2}};
    for(int i=1; i<=5; i++){
        ASSERT_EQ((m+m2)(1,i),4.4);
    }
}
TEST(staticMatrix, operator3Int){
    Matrix<int,3,4> m({{1,2,3,4},{5,6,7,8},{9,10,11,12}});
    Matrix<int,4,2> m2({{1,1},{21,2},{34,2},{2,32}});
    auto result=m*m2;
    ASSERT_EQ(result.Rows,3);
    ASSERT_EQ(result.Columns,2);
    ASSERT_EQ(result.array[0],153);
    ASSERT_EQ(result.array[1],139);
    ASSERT_EQ(result.array[2],385);
    ASSERT_EQ(result.array[3],287);
    ASSERT_EQ(result.array[4],617);
    ASSERT_EQ(result.array[5],435);
}


TEST(dynamicMatrix, DefaultConstructor){
    Matrix<int,0,0> m;
    ASSERT_EQ(m.Rows,0);
    ASSERT_EQ(m.Columns,0);
}
TEST(dynamicMatrix, ConstructorInt){
    Matrix<int,0,0> m(1,5);
    ASSERT_EQ(m.Rows,1);
    ASSERT_EQ(m.Columns,5);
    ASSERT_EQ(m.array[4],int());
}
TEST(dynamicMatrix, ConstructorDouble){
    Matrix<double,0,0> m(1,5);
    ASSERT_EQ(m.Rows,1);
    ASSERT_EQ(m.Columns,5);
    ASSERT_EQ(m.array[4],double());
}
TEST(dynamicMatrix, ConstructorShort){
    Matrix<short,0,0> m(1,5);
    ASSERT_EQ(m.Rows,1);
    ASSERT_EQ(m.Columns,5);
    ASSERT_EQ(m.array[4],short());
}
TEST(dynamicMatrix, ConstructorComplex){
    Matrix<complex<double>,0,0> m(1,5);
    ASSERT_EQ(m.Rows,1);
    ASSERT_EQ(m.Columns,5);
    ASSERT_EQ(m.array[4],complex<double>());
}
TEST(dynamicMatrix, copyConstructorInt){
    Matrix<int,0,0> m(1,5);
    Matrix m2(m);
    ASSERT_EQ(m.Rows,m2.Rows);
    ASSERT_EQ(m.Columns,m2.Columns);
    for(int i=0; i<5; i++){
        ASSERT_EQ(m.array[i],m2.array[i]);
    }
}
TEST(dynamicMatrix, copyConstructorDouble){
    Matrix<double,0,0> m(1,5);
    Matrix m2(m);
    ASSERT_EQ(m.Rows,m2.Rows);
    ASSERT_EQ(m.Columns,m2.Columns);
    for(int i=0; i<5; i++){
        ASSERT_EQ(m.array[i],m2.array[i]);
    }
}
TEST(dynamicMatrix, copyConstructorshort){
    Matrix<short,0,0> m(1,5);
    Matrix m2(m);
    ASSERT_EQ(m.Rows,m2.Rows);
    ASSERT_EQ(m.Columns,m2.Columns);
    for(int i=0; i<5; i++){
        ASSERT_EQ(m.array[i],m2.array[i]);
    }
}
TEST(dynamicMatrix, copyConstructorComplex){
    Matrix<complex<double>,0,0> m(1,5);
    Matrix m2(m);
    ASSERT_EQ(m.Rows,m2.Rows);
    ASSERT_EQ(m.Columns,m2.Columns);
    for(int i=0; i<5; i++){
        ASSERT_EQ(m.array[i],m2.array[i]);
    }
}
TEST(dynamicMatrix, constructorFromInitializerListInt){
    Matrix<int,0,0> m{{0,1,2,3,4}};
    for(int i=0; i<5; i++){
        ASSERT_EQ(m.array[i],i);
    }
}
TEST(dynamicMatrix, constructorFromInitializerListDouble){
    Matrix<double,0,0> m{{0,1,2,3,4}};
    for(int i=0; i<5; i++){
        ASSERT_EQ(m.array[i],i);
    }
}
TEST(dynamicMatrix, constructorFromInitializerListShort){
    Matrix<short,0,0> m{{0,1,2,3,4}};
    for(int i=0; i<5; i++){
        ASSERT_EQ(m.array[i],i);
    }
}
TEST(dynamicMatrix, constructorFromInitializerListAndCopyConstructorInt){
    Matrix<int,0,0> m{{2,3,2,3,4}};
    Matrix m2(m);
    for(int i=0; i<5; i++){
        ASSERT_EQ(m.array[i],m2.array[i]);
    }
}
TEST(dynamicMatrix, constructorFromInitializerListAndCopyConstructorDouble){
    Matrix<double,0,0> m{{2.2,3.1,2,3,4}};
    Matrix m2(m);
    for(int i=0; i<5; i++){
        ASSERT_EQ(m.array[i],m2.array[i]);
    }
}
TEST(dynamicMatrix, constructorFromInitializerListAndCopyConstructorShort){
    Matrix<short,0,0> m{{2,3,2,3,4}};
    Matrix m2(m);
    for(int i=0; i<5; i++){
        ASSERT_EQ(m.array[i],m2.array[i]);
    }
}
TEST(dynamicMatrix, operator1){
    Matrix<int,0,0> m{{0,1,2,3,4}};
    ASSERT_EQ(m.array[1],m(1,2));
}
TEST(dynamicMatrix, operator1Int){
    Matrix<int,0,0> m{{0,0,0,0,0}};
    m(1,2)=2;
    ASSERT_EQ(m.array[1],2);
}
TEST(dynamicMatrix, operator1Short){
    Matrix<short,0,0> m{{0,0,0,0,0}};
    m(1,2)=2;
    ASSERT_EQ(m.array[1],2);
}
TEST(dynamicMatrix, operator1Double){
    Matrix<double,0,0> m{{0,0,0,0,0}};
    m(1,2)=2.2;
    ASSERT_EQ(m.array[1],2.2);
}
TEST(dynamicMatrix, operator1Complex){
    Matrix<complex<double>,0,0> m{{0,0,0,0,0}};
    m(1,2)=2.2;
    ASSERT_EQ(m.array[1],2.2);
}
TEST(dynamicMatrix, function1){
    Matrix<int,0,0> m(2,1);
    ASSERT_EQ(m.numberOfRows(),m.Rows);
}
TEST(dynamicMatrix, function2){
    Matrix<int,0,0> m(2,1);
    ASSERT_EQ(m.numberOfColumns(),m.Columns);
}



TEST(mixedOperators, multiplication){
    Matrix<int,0,0> m({{1,2,3,4},{5,6,7,8},{9,10,11,12}});
    Matrix<int,4,2> m2({{1,1},{21,2},{34,2},{2,32}});
    auto result=m*m2;
    ASSERT_EQ(result.Rows,3);
    ASSERT_EQ(result.Columns,2);
    ASSERT_EQ(result.array[0],153);
    ASSERT_EQ(result.array[1],139);
    ASSERT_EQ(result.array[2],385);
    ASSERT_EQ(result.array[3],287);
    ASSERT_EQ(result.array[4],617);
    ASSERT_EQ(result.array[5],435);
}
TEST(mixedOperators, multiplicationException){
    Matrix<int,0,0> m({{1,2,3},{5,6,7},{10,11,12}});
    Matrix<int,4,2> m2({{1,1},{21,2},{34,2},{2,32}});
    ASSERT_ANY_THROW(auto result=m*m2);
}
TEST(mixedOperators, addInt){
    Matrix<int,0,0> m{{1,0,2,4,1}};
    Matrix<int,1,5> m2{{3,4,2,0,3}};
    for(int i=1; i<=5; i++){
        ASSERT_EQ((m2+m)(1,i),4);
    }
}
TEST(mixedOperators, addDouble){
    Matrix<double,0,0> m{{1.1,0,2,4,1}};
    Matrix<double,1,5> m2{{2.9,4,2,0,3}};
    for(int i=1; i<=5; i++){
        ASSERT_EQ((m2+m)(1,i),4);
    }
}
