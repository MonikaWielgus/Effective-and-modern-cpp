//Monika Wielgus
#include "gtest/gtest.h"
#include "s.h"

TEST(constructorsTests, emptyConstructor){
    String s;
    ASSERT_EQ(s.str->size(),0);
    ASSERT_EQ(*(s.str),"");
}

TEST(constructorsTests, size2){
    String s(2);
    ASSERT_EQ(s.str->size(),2);
    ASSERT_EQ(*(s.str),"  ");
}

TEST(constructorsTests, sizeLessThanZero){
    EXPECT_ANY_THROW(String s(-5));
}

TEST(constructorsTests, copyConstructor){
    String s("hi");
    String s2(s);
    ASSERT_EQ(s.str->size(),s2.str->size());
    ASSERT_EQ(*(s.str),*(s2.str));
}

TEST(constructorsTests, copyConstructorNoEqual){
    String s("hi");
    String s2(s);
    String s3("hii");
    ASSERT_NE(s3.str->size(),s2.str->size());
    ASSERT_NE(*(s3.str),*(s2.str));
}

TEST(operatorsTests, operator1){
    String a("hi");
    ASSERT_EQ(a[0],'h');
    ASSERT_EQ(a[1],'i');
}

TEST(operatorsTests, operator2){
    String a("hi");
    ASSERT_EQ(*(a+a).str,"hihi");
}

TEST(operatorsTests, assignmentOperator){
    String a("hi");
    String b;
    String d=a+b;
    ASSERT_EQ(*(d.str),*(a.str));
}

TEST(operatorsTests, assignmentOperator2){
    String a("hi");
    String b("h");
    String d=a+b;
    ASSERT_NE(*(d.str),*(a.str));
    ASSERT_EQ(*(d.str),"hih");
}


TEST(operatorsTests, change){
    String a("hi");
    a[0]='l';
    ASSERT_EQ(a[1],'i');
    ASSERT_EQ(a[0],'l');
    ASSERT_EQ(*(a.str),"li");
}

TEST(operatorsTests, change2){
    String a("hi");
    String b(a);
    b[0]='l';
    ASSERT_EQ(b[1],'i');
    ASSERT_EQ(b[0],'l');
    ASSERT_EQ(*(b.str),"li");
}

TEST(fullTests, bigTest){
    String a("hi");
    String b;
    const String c=a;
    ASSERT_EQ(c.str->size(),a.str->size());
    ASSERT_EQ(*(c.str),*(a.str));
    String d=a+b;
    ASSERT_EQ(*(d.str),*(a+b).str);
    a[0]='l';
    a[1]='l';
    d=c+a;
    ASSERT_EQ(*(c+" "+d).str,"hi hill");
    ASSERT_EQ(c[0],'h');
}
