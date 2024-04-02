#include <iostream>
#include <bitset>

using namespace std;

class logical_values_array {
private:
    unsigned int _value;

public:
    logical_values_array(unsigned int value = 0) : _value(value) {}

    // Accessor
    unsigned int get_value() const {
        return _value;
    }

    // Инверсия Ес
    logical_values_array invert() const {
        return logical_values_array(!_value);
    }

    // Конъюнкция Ес
    logical_values_array conjunction(const logical_values_array& other) const {
        return logical_values_array(_value & other._value);
    }

    // Дизъюнкция Ес
    logical_values_array disjunction(const logical_values_array& other) const {
        return logical_values_array(_value | other._value);
    }

    // Импликация Ес
    logical_values_array implication(const logical_values_array& other) const {
        return logical_values_array(!(_value) | other._value);
    }

    // Коимпликация 
    logical_values_array coimplication(const logical_values_array& other) const {
        /*logical_values_array x = implication(other);
        x = x.invert();
        logical_values_array y = other.implication(*this);
        y = y.invert();
        logical_values_array z = x.conjunction(y);
        return z;*/
        return implication(other).invert().conjunction(other.implication(*this).invert());
    }

    // Сложение по модулю 2
    logical_values_array modul2_sum(const logical_values_array& other) const {
        return logical_values_array((_value + other._value) % 2);
    }

    // Эквивалентность
    logical_values_array equivalence(const logical_values_array& other) const {
        return invert().modul2_sum(other.invert()).invert();
    }

    // Стрелка Пирса
    logical_values_array pierce_arrow(const logical_values_array& other) const {
        return invert().conjunction(other.invert());
    }

    // Штрих Шеффера
    logical_values_array sheffer_stroke(const logical_values_array& other) const {
        return conjunction(other).invert();
    }

    // Equals
    static bool equals(const logical_values_array& a, const logical_values_array& b) {
        return a._value == b._value;
    }

    // Позиция бита
    unsigned int get_bit(int position) const {
        return (_value >> position) & 1;
    }

    // Двоичное представление
    void binary_representation(char* output) const {
        for (int i = 31; i >= 0; --i) {
            output[31 - i] = '0' + get_bit(i);
        }
        output[32] = '\0';
    }
};

int main() {
    logical_values_array x(5);
    logical_values_array y(5);

    cout << logical_values_array::equals(x, y) << endl;

    logical_values_array c = x.sheffer_stroke(y);
    cout << c.get_value() << endl;

    logical_values_array d = x.equivalence(y);
    cout << d.get_value() << endl;

    char binary_represent[33];
    c.binary_representation(binary_represent);
    cout << "Binary representation c: " << binary_represent << endl;

    return 0;
}