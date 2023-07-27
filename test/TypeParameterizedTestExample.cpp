#include "gtest/gtest.h"
using testing::Types;

class ITempSensor{
    public:
    virtual int getOutSideTemp()=0;
};
class ModelATempSensor:public ITempSensor{
    public:
    int getOutSideTemp(){ return  23;}
};
class ModelBTempSensor:public ITempSensor{
    public:
    int getOutSideTemp(){ return  23;}
};
class ModelCTempSensor:public ITempSensor{
    public:
    int getOutSideTemp(){ return  23;}
};
class AutoTempRegulator{
    ITempSensor* tempSensorPtr;
    public:
    AutoTempRegulator(ITempSensor* address):tempSensorPtr{address} {}
    void  regulateTemp(){
         this->tempSensorPtr->getOutSideTemp();
    }  
};

template <typename T>
ITempSensor* createObject();
template <>
ITempSensor* createObject<ModelATempSensor>() { return new ModelATempSensor(); }
template <>
ITempSensor* createObject<ModelBTempSensor>() { return new ModelBTempSensor(); }
template <>
ITempSensor* createObject<ModelCTempSensor>() { return new ModelCTempSensor(); }

template <typename T>
class TempSensorFixture:public testing::Test{
    protected:
    TempSensorFixture():objUnderTest{ createObject<T>()}{}
    //arrange
    ITempSensor* objUnderTest;

};

typedef Types<ModelATempSensor,ModelBTempSensor,ModelCTempSensor> Implementations;

TYPED_TEST_SUITE(TempSensorFixture, Implementations);

TYPED_TEST(TempSensorFixture,GetTempTest){
    ASSERT_EQ(this->objUnderTest->getOutSideTemp(),23);
}

//Interaction Based testing

//Fake dependency
class FakeTempSensor:public ITempSensor{
    public:
    int getOutsideTempCallCount=0;
    int getOutsideTemp(){
        getOutsideTempCallCount=getOutsideTempCallCount+1;
        return 0;
    }
};

//Test Suite
TEST(AutoTempRegulatorTestSuite, RegulateTempTest){
    FakeTempSensor stub;
    AutoTempRegulator codeUnderTest(&stub);
    codeUnderTest.regulateTemp();
}

