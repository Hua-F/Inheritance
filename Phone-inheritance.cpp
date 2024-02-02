#include <iostream>
#include <string>
using namespace std;

class CellPhone {
protected:
    string model;
    string owner;
    long int phoneNumber;

public:
    CellPhone(const string& model, const string& owner, long int phoneNumber)
        : model(model), owner(owner), phoneNumber(phoneNumber) {
    }

    CellPhone(const string& owner, long int phoneNumber)
        : owner(owner), phoneNumber(phoneNumber) {
    }

    virtual void dial() const {
        cout << owner << " is calling from phone number: " << phoneNumber << endl;
    }

    virtual void hangup() const {
        cout << "Hanging up cell phone" << endl;
    }
};

class FlipPhone : public CellPhone {
public:
    FlipPhone(const string& model, const string& owner, long int phoneNumber)
        : CellPhone(model, owner, phoneNumber) {
    }

    void hangup() const override {
        cout << "Close phone" << endl;
    }
};

class SmartPhone : public CellPhone {
private:
    string os;
    int memorySize;

public:
    SmartPhone(const string& model, const string& owner, long int phoneNumber, const string& os, int memorySize)
        : CellPhone(model, owner, phoneNumber), os(os), memorySize(memorySize) {
    }

    void dial() const override {
        cout << model << " with " << os << " is calling from phone number: " << phoneNumber << endl;
    }

    void hangup() const override {
        cout << "Press end button" << endl;
    }
};

int main() {
    FlipPhone flipPhone1("Samsung Flip Z", "Micah", 650988102);
    SmartPhone smartPhone1("Samsung Galaxy S24 Ultra","Glen", 415688019, "Android", 128);
    SmartPhone smartPhone2("Iphone 15 Pro Max","Zach", 415205993, "IOS", 256);
    CellPhone cellPhone1("Motorola", "Christina", 800194471);

    CellPhone* phones[] = {&flipPhone1, &smartPhone1, &smartPhone2, &cellPhone1};

    for (int i = 0; i < sizeof(phones) ; i++) {
        CellPhone* phone = phones[i];
        phone->dial();
        phone->hangup();
        cout << endl;
    }

    return 0;
}
