#include <iostream>
#include <memory>

// 业务组件
class PaymentService {
public:
    void processPayment() { std::cout << "Processing payment...\n"; }
};

class InventoryService {
public:
    void updateStock() { std::cout << "Updating stock...\n"; }
};

class NotificationService {
public:
    void sendEmail() { std::cout << "Sending email notification...\n"; }
};

// 策略接口（定义不同流程）
class OrderProcessingStrategy {
public:
    virtual void processOrder(PaymentService&, InventoryService&, NotificationService&) = 0;
    virtual ~OrderProcessingStrategy() = default;
};

// 标准流程
class StandardOrderProcessing : public OrderProcessingStrategy {
public:
    void processOrder(PaymentService& payment, InventoryService& inventory, NotificationService& notify) override {
        payment.processPayment();
        inventory.updateStock();
        notify.sendEmail();
    }
};

// 仅库存更新，不处理支付
class InventoryOnlyProcessing : public OrderProcessingStrategy {
public:
    void processOrder(PaymentService&, InventoryService& inventory, NotificationService&) override {
        inventory.updateStock();
    }
};

// Facade 采用策略模式
class OrderFacade {
public:
    explicit OrderFacade(std::shared_ptr<OrderProcessingStrategy> strategy) : strategy(std::move(strategy)) {}

    void placeOrder() {
        strategy->processOrder(payment, inventory, notification);
    }

private:
    PaymentService payment;
    InventoryService inventory;
    NotificationService notification;
    std::shared_ptr<OrderProcessingStrategy> strategy;
};

// 使用不同的策略
int main() {
    auto standardOrder = std::make_shared<StandardOrderProcessing>();
    auto inventoryOnly = std::make_shared<InventoryOnlyProcessing>();

    OrderFacade orderFacade1(standardOrder);
    orderFacade1.placeOrder();  // 执行标准流程

    OrderFacade orderFacade2(inventoryOnly);
    orderFacade2.placeOrder();  // 仅更新库存

    return 0;
}
