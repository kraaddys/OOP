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
	// Здесь я создал 2 виртуальных метода, которые считывают общую стоимость указанного кол-ва продуктов и которые
	// выводят общую информацию о конкретном продукте.

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
	// Данная строчка кода переопределяет виртуальный метод calculateTotalCost из базового класса Product.
	// Он рассчитывает общую стоимость указанного количества продуктов и затем умножает цену продукта(price)
	// на количество(quantity).

	void displayProductDetails() override {
		cout << "--Electronics--" << endl;
		cout << "Name: " << productName << endl;
		cout << "Cost: " << price << " lei." << endl;
		cout << "Count: " << quantity << " pieces." << endl;
		cout << "Warranty: " << warrantyPeriod << " months." << endl;
		cout << "Manufacturer: " << manufacturer << endl;
		cout << endl;
	}

	void extendWarranty(int months) { warrantyPeriod += months; } // Продлевает гарантию на количество месяцев, указанных в
	//months.
	void updateManufacturer(string newManufacturer) { manufacturer = newManufacturer; }
	// Обновляет производителя на newManufacturer.
};

class Clothing : public Product {
private:
	string size;

public:
	Clothing(string name, double price, int quantity, string size) : Product(name, price, quantity) {
		this->size = size;
	}

	double calculateTotalCost(int quantity) override { return price * quantity; }
	// Данная строчка кода переопределяет виртуальный метод calculateTotalCost из базового класса Product.
	// Он рассчитывает общую стоимость указанного количества продуктов и затем умножает цену продукта(price)
	// на количество(quantity).

	void displayProductDetails() override {
		cout << "--Clothes--" << endl;
		cout << "Name: " << productName << endl;
		cout << "Cost: " << price << " lei." << endl;
		cout << "Count: " << quantity << " pieces." << endl;
		cout << "Size: " << size << endl;
	}

	void changeSize(string newSize) { size = newSize; } // Новые размеры сохраняются в newSize.
	bool isSizeAvailable(string newSize) { return size == newSize; } // Возвращает булево значение, если мы спросим есть ли
	// доступный размер до и после обновления размеров.
};

int main() {
	// Создание объектов
	Electronics tv("TV", 20000, 10, 12, "LG");
	Clothing shirt("T-Shirt", 1000, 20, "M");

	// Демонстрация функциональности
	tv.displayProductDetails();
	tv.extendWarranty(6);
	tv.updateManufacturer("Samsung");
	tv.displayProductDetails();

	shirt.displayProductDetails();
	shirt.changeSize("S");
	cout << "L size is available? " << (shirt.isSizeAvailable("L") ? "Yes" : "No") << endl;

	return 0;
}