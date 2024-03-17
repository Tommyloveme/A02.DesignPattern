#include <iostream>
#include <map>
#include <string>
#include "TestBoost.h"
#include "gtest/gtest.h"

using namespace testBoost;

// 定义状态机的状态
enum class State {
    STATE_A,
    STATE_B,
    STATE_C
};
BOOST_DESCRIBE_ENUM(State, STATE_A, STATE_B, STATE_C)

// 定义状态机类
class StateMachine {
public:
    // 构造函数，初始状态为 STATE_A
    StateMachine() : currentState(State::STATE_A) {
        // 初始化状态转移规则
        transitionRules[State::STATE_A] = { State::STATE_B };
        transitionRules[State::STATE_B] = { State::STATE_C };
        transitionRules[State::STATE_C] = { State::STATE_A };
    }

    // 检查当前状态是否有效
    bool isStateValid() const {
        return transitionRules.find(currentState) != transitionRules.end();
    }

    // 处理输入事件
    void handleInput(State nextState) {
        if (isStateValid()) {
            std::cout << "Handling input in " << stateToString(currentState) << std::endl;
            // 检查下一个状态是否在允许的状态列表中
            const auto& allowedStates = transitionRules[currentState];
            if (std::find(allowedStates.begin(), allowedStates.end(), nextState) != allowedStates.end()) {
                currentState = nextState;
            } else {
                std::cout << "Invalid transition to " << stateToString(nextState) << std::endl;
            }
        } else {
            std::cout << "Invalid state detected!" << std::endl;
        }
    }

private:
    // 辅助函数，将枚举状态转换为字符串
    std::string stateToString(State state) const {
        return ToString(currentState);
    }

    // 当前状态
    State currentState;

    // 状态转移规则
    std::map<State, std::vector<State>> transitionRules;
};

class TestStateMachine : public testing::Test
{
    void SetUp() {}

    void TearDown() {}
};

TEST_F(TestStateMachine, base)
{
    StateMachine stateMachine;

    // 模拟处理输入事件
    stateMachine.handleInput(State::STATE_B);
    stateMachine.handleInput(State::STATE_C);
    stateMachine.handleInput(State::STATE_A);
    stateMachine.handleInput(State::STATE_B); // 无效状态切换
}