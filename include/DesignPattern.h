#ifndef DESIGN_PATTERN_HEADER
#define DESIGN_PATTERN_HEADER
#include <vector>
#include <iostream>
#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

namespace DP {

class DesignPattern
{
public:
    DesignPattern() {};
    ~DesignPattern() {};
protected:
    std::shared_ptr<spdlog::logger> m_logger;
};
} // namespace DP

#endif