#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "addMock.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "add3.h"
#ifdef __cplusplus
}
#endif

using ::testing::_;
using ::testing::Args;
using ::testing::DoAll;
using ::testing::NiceMock;
using ::testing::NotNull;
using ::testing::Return;
using ::testing::SaveArg;
using ::testing::SetArgPointee;

class Add3Test : public ::testing::Test
{
   protected:
    virtual void SetUp()
    {
        addMock = new NiceMock<AddMock>;

        AddMock_SetMock(addMock);
    }
    virtual void TearDown()
    {
        delete addMock;
    }
    NiceMock<AddMock>* addMock;
};

TEST_F(Add3Test, ShouldReturn2)
{
    EXPECT_CALL(*addMock, Sub(_, _))
        .Times(1)
        .WillOnce(Return(5));

    EXPECT_EQ(Add3(8, 3), 2);
}
