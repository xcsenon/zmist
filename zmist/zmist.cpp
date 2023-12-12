#include <iostream>

// Subject
class Subject {
public:
    virtual void request() const = 0;
};

// RealSubject
class RealSubject : public Subject {
public:
    void request() const override {
        std::cout << "RealSubject request" << std::endl;
    }
};

// Proxy
class Proxy : public Subject {
private:
    RealSubject* const realSubject;  // Змінено на константний вказівник

public:
    Proxy() : realSubject(new RealSubject()) {}

    void request() const override {
        realSubject->request();
    }

    ~Proxy() {
        delete realSubject;
    }
};

int main() {
    Proxy proxy;
    proxy.request();

    return 0;
}
