#include <gtest/gtest.h>

class C{};

class B
{
   C* ptr;
   public:
   //universal object creation
   B(C* addressofObject): ptr(addressofObject){
   }
}; 

class A
{
   B* ptr;
   public:
   //universal object creation
   A(B* addressofObject): ptr(addressofObject){
   }
   bool operation(){
     return true;
   }

};

//Sharing Resources Between Tests in the Same Test Suite
class FixtureExampleTest : public testing::Test {
    //Always this class should be protected
    protected:
    A* aPtr;
    B* bPtr;
    C* cPtr;

    //Method 1 - Using constructor and destructor for consume & destory the object
    //Constructor
    FixtureExampleTest(){
        //initialization
    }

    //Destructor
    ~FixtureExampleTest(){
        //Releasing the object
    }

    //Method 2 - GTest framework methods to perform initialization & destruction of objects
    // Called before the first test in this test suite.
    void SetUp() {
        //Create resources
        this->cPtr=new C();
        this->bPtr = new B(cPtr);
        this->aPtr = new A(bPtr);
    }
    
    // Called after the last test in this test suite.
    void TearDown() {
        //Delete resources
        delete aPtr;
        delete bPtr;
        delete cPtr;

    }

};

TEST_F(FixtureExampleTest, OperationTrueTest){
    //Act and Assert
    ASSERT_TRUE(aPtr->operation());
}

TEST_F(FixtureExampleTest, OperationFalseTest){
    //Act and Assert
    ASSERT_FALSE(aPtr->operation());
}
