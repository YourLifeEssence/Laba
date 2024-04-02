#include <iostream>

using namespace std;

class CompNum{
private:
	double real;
	double imagine;
public:
	CompNum(double _real = 0, double _imagine = 0) : real(_real), imagine(_imagine){}

	CompNum operator +(const CompNum& other) {
		return CompNum(real + other.real, imagine + other.imagine);
	}

	CompNum operator -(const CompNum& other) {
		return CompNum(real - other.real, imagine - other.imagine);
	}

	CompNum operator *(const CompNum& other) {
		return CompNum(real * other.real - imagine * other.imagine, real * other.imagine + imagine * other.real);
	}

	CompNum operator /(const CompNum& other) {
		double denominator = other.real * other.real + other.imagine * other.imagine;
		return CompNum((real * other.real + imagine * other.imagine) / denominator, (imagine * other.real - real * other.imagine) / denominator);
	}

	double getABS() {
		return sqrt(real * real + imagine * imagine);
	}

	double getArgument() {
		return atan2(imagine, real);
	}

	void print() {
		std::cout << "(" << real << " + " << imagine << "i)" << std::endl;
	}

};

int main() {
	setlocale(LC_ALL, "Ru");
	CompNum x(2, 3);
	CompNum y(5, -6);

	CompNum sum = x + y;
	CompNum diff = x - y;
	CompNum mult = x * y;
	CompNum div = x / y;

	cout << "Сумма: ";
	sum.print();
	cout << "\nРазность: ";
	diff.print();
	cout << "Произведение: ";
	mult.print();
	cout << "Частное: ";
	div.print();
	cout << "Модуль x: " << x.getABS() << endl;
	cout << "Аргумент x: " << y.getArgument() << endl;

	return 0;
}