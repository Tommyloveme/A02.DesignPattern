#include "Data.h"

using namespace Data;
using namespace std;

const Message& EhcDataIntf::GetMessage() noexcept
{
    TRACE()
    static Message message;
    message.id = EhcData::Instance().m_id;
    message.name = EhcData::Instance().m_name;
    return message;
}

void EhcDataIntf::SetMessage(const Message& message) noexcept
{
    TRACE()
    EhcData& data = EhcData::Instance();
    data.m_id = message.id;
    data.m_name = message.name;
}

const string& EhcDataIntf::GetName() noexcept
{
    EhcData& data = EhcData::Instance();
    return data.m_name;
}

void EhcDataIntf::SetName(const std::string& name) noexcept
{
    EhcData& data = EhcData::Instance();
    data.m_name = name;
}

void EhcDataIntf::Modify(const std::function<void(Message&)>& setter) noexcept
{
    Message message = GetMessage();
    setter(message);
    SetMessage(message);
}

void EhcDataIntf::Modify(const std::function<void(std::string&)>& setter) noexcept
{
    std::string name = GetName();
    setter(name);
    SetName(name);
}