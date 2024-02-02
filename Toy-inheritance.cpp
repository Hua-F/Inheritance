#include <iostream>
#include <string>
using namespace std;

class FidgetToy {
private:
    string name;
    string description;
    int minAge;
    bool isSpinner;

public:
    FidgetToy(string name, string description, int minAge, bool isSpinner) {
    if (name.length() >= 2) {
        this->name = name;
    } else {
        this->name = "Unknown";
    }

    if (description.length() >= 2) {
        this->description = description;
    } else {
        this->description = "Unknown";
    }

    if (minAge >= 0) {
        this->minAge = minAge;
    } else {
        this->minAge = 0;
    }

    this->isSpinner = isSpinner;
}

FidgetToy(string name, int minAge) {
    if (name.length() >= 2) {
        this->name = name;
    } else {
        this->name = "Unknown";
    }

    this->description = this->name;

    if (minAge >= 0) {
        this->minAge = minAge;
    } else {
        this->minAge = 0;
    }

    this->isSpinner = false;
}

    string getName() const { 
        return name; 
    }
    void setName(string name) { 
        if (name.length() >= 2) this->name = name; 
    }

    string getDescription() const { 
        return description; 
    }
    void setDescription(string description) { 
        if (description.length() >= 2) this->description = description; 
    }

    int getMinAge() const { 
        return minAge; 
    }
    void setMinAge(int minAge) { 
        if (minAge >= 0) this->minAge = minAge; 
    }

    bool getIsSpinner() const { 
        return isSpinner; 
    }
    void setIsSpinner(bool isSpinner) { 
        this->isSpinner = isSpinner; 
    }

    void describe() const {
        cout << "Name: " << name << "\n" << "Description: " << description << "\n" << "Minimum Age: " << minAge << "\n" << "Is Spinner: " << (isSpinner ? "Yes" : "No") << endl;
    }

    void appendToDescription(string appendText) {
        description += appendText;
    }
};

int main() {
    FidgetToy toy1("Fidget Spinner", "Classic fidget spinner. Great stocking stuffer!", 5, true);
    FidgetToy toy2("Infinity Cube", "Infinity Cube. High quality materials", 4, false);

    FidgetToy toy3("Magic Cube", 6);
    FidgetToy* toyPtr = &toy3;

    toyPtr->setIsSpinner(true);
    toyPtr->appendToDescription(" A magical cube that spins!");

    FidgetToy toys[3] = {toy1, toy2, *toyPtr};

    for (int i = 0; i < 3; i++) {
        toys[i].describe();
        cout << endl;
    }

    return 0;
}
