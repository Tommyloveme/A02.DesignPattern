#include "gtest/gtest.h"
#include "Data.h"

using namespace Data;

class TestData : public ::testing::Test {
protected:
    virtual void SetUp()
    {}

    virtual void TearDown()
    {}
};

TEST_F(TestData, common) {
    Message message;
    message.id = 2;
    message.name = "dyl";
    EhcDataIntf::SetMessage(message);
    cout << EhcData::Instance(); // {id:2, name:dyl}

    std::function<void(Message&)> func = [](Message &message) {message.id = 3; };
    EhcDataIntf::Modify(func);
    cout << EhcData::Instance(); // {id:3, name:dyl}

    EhcDataIntf::Modify([](Message &message) {message.id = 4; });
    cout << EhcData::Instance(); // {id:4, name:dyl}
}