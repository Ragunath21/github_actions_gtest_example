#include<gtest/gtest.h>

class C {};
class B {
    C* ptr;
    public: 
    B(C* addressOfObject): ptr(addressOfObject){

    }
};

class A {
    B* ptr;
    public: 
    A(B* addressOfObject): ptr(addressOfObject){

    }
    bool operation(){
        return true;
    }
};

TEST("TestFixtureTestSuite", "OperationTest"){
    //Arrange
    C cObj;
    B bObj(aObj);
    A aObj(bObj);
    //Act
    ASSERT_TRUE(aObj.operation());
}

TEST("TestFixtureTestSuite", "OperationTest"){
    //Arrange
    C cObj;
    B bObj(aObj);
    A aObj(bObj);
    //Act
    ASSERT_FALSE(aObj.operation());
}
