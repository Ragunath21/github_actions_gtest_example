#include <gtest/gtest.h>

int divFun(int numerator,int denominator){

    if(denominator==0 || denominator < 0){
        return 0;
    }

    return numerator/denominator;
}

class MultipleParametersTestFixture :public ::testing::TestWithParam<std::tuple<int, int, int>> {
protected:

    //Constructor
    MultipleParametersTestFixture(){

    }

    //Destructor
    ~MultipleParametersTestFixture(){

    }
};

TEST_P(MultipleParametersTestFixture, ValidateInputs) {
    int numerator = std::get<0>(GetParam());;
    int denomiator = std::get<1>(GetParam());
    int expectedValue = std::get<2>(GetParam());
    int actualValue = divFun(numerator,denomiator);
    ASSERT_EQ(expectedValue, actualValue);
}

INSTANTIATE_TEST_SUITE_P(        
        MultipleParametersTestFixtureParameters,
        MultipleParametersTestFixture,
        ::testing::Values(
                std::make_tuple(10, 5, 2),
                std::make_tuple(10, 0, 2),
                std::make_tuple(10, -5, 2)));