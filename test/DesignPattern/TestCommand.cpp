#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>

// 1. 命令接口
class ICommand {
public:
    virtual bool execute() = 0;  // 成功返回 true，失败返回 false
    virtual void undo() = 0;      // 失败时回滚
    virtual ~ICommand() = default;
};

// 2. 具体命令 A
class CommandA : public ICommand {
public:
    bool execute() override {
        std::cout << "Executing CommandA...\n";
        return true; // 执行成功
    }
    void undo() override {
        std::cout << "Undoing CommandA...\n";
    }
};

// 3. 具体命令 B
class CommandB : public ICommand {
public:
    bool execute() override {
        std::cout << "Executing CommandB... FAILED!\n";
        return false; // 执行失败
    }
    void undo() override {
        std::cout << "Undoing CommandB...\n";
    }
};

// 4. **宏命令（组合多个命令）**
class MacroCommand : public ICommand {
public:
    void addCommand(std::shared_ptr<ICommand> cmd) {
        commands.push_back(cmd);
    }

    bool execute() override {
        executedCommands.clear();
        for (auto& cmd : commands) {
            if (!cmd->execute()) { // 只要有失败，就回滚
                std::cout << "MacroCommand failed! Rolling back...\n";
                undo();
                return false;
            }
            executedCommands.push_back(cmd);
        }
        return true;
    }

    void undo() override {
        for (auto it = executedCommands.rbegin(); it != executedCommands.rend(); ++it) {
            (*it)->undo();
        }
    }

private:
    std::vector<std::shared_ptr<ICommand>> commands;
    std::vector<std::shared_ptr<ICommand>> executedCommands;
};

// 5. **命令管理器（注册 & 调用常用命令组合）**
class CommandManager {
public:
    // 注册单个命令
    void registerCommand(const std::string& name, std::shared_ptr<ICommand> cmd) {
        commands[name] = cmd;
    }

    // 注册宏命令
    void registerMacroCommand(const std::string& name, std::initializer_list<std::shared_ptr<ICommand>> cmdList) {
        auto macroCmd = std::make_shared<MacroCommand>();
        for (auto& cmd : cmdList) {
            macroCmd->addCommand(cmd);
        }
        commands[name] = macroCmd;
    }

    // 执行命令
    bool executeCommand(const std::string& name) {
        if (commands.find(name) != commands.end()) {
            return commands[name]->execute();
        }
        std::cout << "Command not found: " << name << std::endl;
        return false;
    }

    // 回滚命令
    void undoCommand(const std::string& name) {
        if (commands.find(name) != commands.end()) {
            commands[name]->undo();
        }
    }

private:
    std::unordered_map<std::string, std::shared_ptr<ICommand>> commands;
};

// 6. **客户端代码**
int main() {
    CommandManager manager;

    // 注册单个命令
    manager.registerCommand("cmdA", std::make_shared<CommandA>());
    manager.registerCommand("cmdB", std::make_shared<CommandB>());

    // 注册宏命令（包含多个命令）
    manager.registerMacroCommand("macro1", {std::make_shared<CommandA>(), std::make_shared<CommandB>()});

    // 执行单个命令
    std::cout << "Running single command 'cmdA':\n";
    manager.executeCommand("cmdA");

    // 执行宏命令
    std::cout << "\nRunning macro command 'macro1':\n";
    manager.executeCommand("macro1");

    return 0;
}
