#include <iostream>
#include <string>
#include <memory>

class Call {
public:
    std::string description;
    Call(const std::string& desc) : description(desc) {}
};

class Employee {
public:
    virtual ~Employee() = default;

    // Set the next employee in the chain
    void setNext(const std::shared_ptr<Employee>& nextEmployee) 
    {
        next = nextEmployee;
    }

    // Handle the call or pass it to the next
    virtual void handleCall(const Call& call)
    {
        if (next) {
            next->handleCall(call);
        } else {
            std::cout << "The call could not be handled: " << call.description << std::endl;
        }
    }
protected:
    std::shared_ptr<Employee> next; // Pointer to the next level
};

class Operator : public Employee {
public:
    void handleCall(const Call& call) override {
        if (canHandle(call)) {
            std::cout << "Operator is handling the call: " << call.description << std::endl;
        } else {
            std::cout << "Operator can't handle the call, passing to the manager." << std::endl;
            Employee::handleCall(call);
        }
    }

private:
    bool canHandle(const Call&) {
        // Logic to determine if the operator can handle the call
        return false; // Example: Operator can't handle the call
    }
};

class Manager : public Employee {
public:
    void handleCall(const Call& call) override {
        if (canHandle(call)) {
            std::cout << "Manager is handling the call: " << call.description << std::endl;
        } else {
            std::cout << "Manager can't handle the call, passing to the director." << std::endl;
            Employee::handleCall(call);
        }
    }

private:
    bool canHandle(const Call&) {
        // Logic to determine if the manager can handle the call
        return false; // Example: Manager can't handle the call
    }
};

class Director : public Employee {
public:
    void handleCall(const Call& call) override {
        if (canHandle(call)) {
            std::cout << "Director is handling the call: " << call.description << std::endl;
        } else {
            std::cout << "Director can't handle the call. End of chain." << std::endl;
        }
    }

private:
    bool canHandle(const Call&) {
        // Logic to determine if the director can handle the call
        return true; // Example: Director can always handle the call
    }
};

int main() {
    // Create employees
    auto operatorEmployee = std::make_shared<Operator>();
    auto managerEmployee = std::make_shared<Manager>();
    auto directorEmployee = std::make_shared<Director>();

    // Set the chain of responsibility
    operatorEmployee->setNext(managerEmployee);
    managerEmployee->setNext(directorEmployee);

    // Create a call
    Call call("Customer needs assistance with a complex issue.");

    // Start handling the call
    operatorEmployee->handleCall(call);

    return 0;
}
