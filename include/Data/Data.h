#ifndef TEST_TEMPLATE_H_CPP_H
#define TEST_TEMPLATE_H_CPP_H

#include <string>
#include <iostream>
#include <algorithm>
#include <functional>

namespace Data {

using namespace std;

class Trace;

#define TRACE() Trace trace = Trace(__func__);

class Trace {
public:
    Trace(std::string funcName) : m_funcName(funcName)
    {
        // std::cout << "--> " << funcName << "()" << endl;
    }

    ~Trace()
    {
        // std::cout << "<-- " << m_funcName << "()" << endl;
    }
protected:
    std::string m_funcName;
};

struct Message {
    int id {0};
    string name {"undefined"};

    friend ostream& operator<<(ostream& os, const Message& self)
    {
        os << "{id:" << self.id << ", name:" << self.name << "}" << endl;
        return os;
    }
};

class EhcData {
public:
    static EhcData& Instance()
    {
        TRACE()
        static EhcData ehcData {};
        return ehcData;
    }

    friend ostream& operator<<(ostream& os, const EhcData& self)
    {
        os << "{id:" << self.m_id << ", name:" << self.m_name << "}" << endl;
        return os;
    }

protected:
    EhcData() = default;
    EhcData(EhcData&) = delete;
    EhcData operator=(EhcData&) = delete;
    int m_id = 0;
    string m_name{"undefined"};
    friend class EhcDataIntf;
};

struct EhcDataIntf {
public:
    static const Message& GetMessage() noexcept;
    static void SetMessage(const Message& message) noexcept;
    static void Modify(const std::function<void(Message&)>& setter) noexcept;

    static const std::string& GetName() noexcept;
    static void SetName(const std::string& name) noexcept;
    static void Modify(const std::function<void(std::string&)>& setter) noexcept;
};

} // namespace Test

#endif // TEST_TEMPLATE_H_CPP_H