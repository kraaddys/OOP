#include <iostream>

using namespace std;

class Side {
protected:
    double length;
    double width;

public:
    Side(double l, double w) : length(l), width(w) {}

    double getLength() const {
        return length;
    }

    double getWidth() const {
        return width;
    }
};

class Rectangle : public Side {
public:
    Rectangle(double l, double w) : Side(l, w) {}

    double calculateArea() const {
        return length * width;
    }
};

class RectangularTable : public Rectangle {
public:
    RectangularTable(double l, double w) : Rectangle(l, w) {}

    double calculateTableArea() const {
        return calculateArea();
    }

    bool canFitPeople(int numPeople) const {
        double spaceRequired = numPeople * 0.85;
        double availableSpace = (length - 0.85) * (width - 0.85); // учитываем, что у каждого человека нужно 0.85м от края стола
        return spaceRequired <= availableSpace;
    }
};

int main() {
    RectangularTable tables[6] = {
        RectangularTable(4.5, 3.5),
        RectangularTable(2, 1.2),
        RectangularTable(1.8, 0.9),
        RectangularTable(8.5, 3.5),
        RectangularTable(1.2, 0.8),
        RectangularTable(2.2, 1.4)
    };

    cout << "Tables Information:\n";
    for (int i = 0; i < 6; ++i) {
        cout << "Table " << i + 1 << " - Dimensions: " << tables[i].getLength() << "m x " << tables[i].getWidth() << "m\n";
        cout << "Area: " << tables[i].calculateTableArea() << " sq.m\n";
        cout << "Can fit 9 people? " << (tables[i].canFitPeople(9) ? "Yes" : "No") << "\n\n";
    }

    if (tables[0].getLength() > tables[3].getLength()) {
        cout << "Length of 1 rectangle is bigger than second.\n";
    }
    else if (tables[0].getLength() < tables[3].getLength()) {
        cout << "Length of 2 rectangle is bigger than second.\n";
    }
    else {
        cout << "Length of both rectangles are.\n";
    }


    return 0;
}
