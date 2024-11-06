#include <iostream>

using namespace std;

class Product {
protected:
	string productName;
	double price;
	int quantity;

public:
	Product(string name, double price, int quantity) {
		this->productName = name;
		this->price = price;
		this->quantity = quantity;
	}

	string getName() { return productName; }
	double getPrice() { return price; }
	int getQuantity() { return quantity; }

	virtual double calculateTotalCost(int quantity) = 0;
	virtual void displayProductDetails() = 0;
	// ����� � ������ 2 ����������� ������, ������� ��������� ����� ��������� ���������� ���-�� ��������� � �������
	// ������� ����� ���������� � ���������� ��������.

};

class Electronics: public Product {
private:
	int warrantyPeriod;
	string manufacturer;

public:
	Electronics(string name, double price, int quantity, int warrantyPeriod, string manufacturer)
	: Product(name, price, quantity) {
		this->warrantyPeriod = warrantyPeriod;
		this->manufacturer = manufacturer;
	}

	double calculateTotalCost(int quantity) override { return price * quantity; }
	// ������ ������� ���� �������������� ����������� ����� calculateTotalCost �� �������� ������ Product.
	// �� ������������ ����� ��������� ���������� ���������� ��������� � ����� �������� ���� ��������(price)
	// �� ����������(quantity).

	void displayProductDetails() override {
		cout << "--Electronics--" << endl;
		cout << "Name: " << productName << endl;
		cout << "Cost: " << price << " lei." << endl;
		cout << "Count: " << quantity << " pieces." << endl;
		cout << "Warranty: " << warrantyPeriod << " months." << endl;
		cout << "Manufacturer: " << manufacturer << endl;
		cout << endl;
	}

	void extendWarranty(int months) { warrantyPeriod += months; } // ���������� �������� �� ���������� �������, ��������� �
	//months.
	void updateManufacturer(string newManufacturer) { manufacturer = newManufacturer; }
	// ��������� ������������� �� newManufacturer.
};

class Clothing : public Product {
private:
	string size;

public:
	Clothing(string name, double price, int quantity, string size) : Product(name, price, quantity) {
		this->size = size;
	}

	double calculateTotalCost(int quantity) override { return price * quantity; }
	// ������ ������� ���� �������������� ����������� ����� calculateTotalCost �� �������� ������ Product.
	// �� ������������ ����� ��������� ���������� ���������� ��������� � ����� �������� ���� ��������(price)
	// �� ����������(quantity).

	void displayProductDetails() override {
		cout << "--Clothes--" << endl;
		cout << "Name: " << productName << endl;
		cout << "Cost: " << price << " lei." << endl;
		cout << "Count: " << quantity << " pieces." << endl;
		cout << "Size: " << size << endl;
	}

	void changeSize(string newSize) { size = newSize; } // ����� ������� ����������� � newSize.
	bool isSizeAvailable(string newSize) { return size == newSize; } // ���������� ������ ��������, ���� �� ������� ���� ��
	// ��������� ������ �� � ����� ���������� ��������.
};

int main() {
	// �������� ��������
	Electronics tv("TV", 20000, 10, 12, "LG");
	Clothing shirt("T-Shirt", 1000, 20, "M");

	// ������������ ����������������
	tv.displayProductDetails();
	tv.extendWarranty(6);
	tv.updateManufacturer("Samsung");
	tv.displayProductDetails();

	shirt.displayProductDetails();
	shirt.changeSize("S");
	cout << "L size is available? " << (shirt.isSizeAvailable("L") ? "Yes" : "No") << endl;

	return 0;
}