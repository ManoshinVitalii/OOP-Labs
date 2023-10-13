#include <string>
#include <iostream>
#include <algorithm>
#include <exception>
#include <math.h>
using namespace std;

class Decimal {
    private: 
	size_t size;
	size_t capacity;
	unsigned char* digits;

    public:

bool IsDecimal(char value) {
	return value >= '0' && value <= '9';
}

void Init(size_t n) {
	size = n;
	capacity = size * 2;
	digits = new unsigned char[capacity];
}

void Delete() {
    if(digits != nullptr) {
	    delete[] digits;
	    digits = nullptr;
    }
    size = 0;
	capacity = 0;
	throw logic_error("This digit doesn't belong to Decimal system");
}

Decimal() : size(0), capacity(0), digits{ nullptr } {}

Decimal(const size_t& n, unsigned char t) {
	if (!IsDecimal(t))
		Delete();
	Init(n);
	for (size_t i = 0; i < size; ++i)
		digits[i] = t;
}

Decimal(const string& t) {
	for (auto elem : t) if (!IsDecimal(elem)) Delete();
	Init(t.size());
	for (size_t i = 0; i < size; ++i)
		digits[i] = t[size - i - 1];
}

Decimal(const Decimal& other) {
	size = other.size;
	capacity = other.capacity;
	digits = new unsigned char[capacity];
	for (size_t i = 0; i < size; ++i)
		digits[i] = other.digits[i];
}

Decimal(Decimal&& other) {
	size = other.size;
	capacity = other.capacity;
	digits = other.digits;
	other.size = 0;
	other.capacity = 0;
	other.digits = nullptr;
}

friend void reallocate(Decimal & D, const size_t& newcapacity) {
	unsigned char* newArray = new unsigned char[newcapacity];
	D.capacity = newcapacity;
	for (size_t i = 0; i < D.size; ++i)
		newArray[i] = D.digits[i];
	for (size_t i = D.size; i < D.capacity; ++i)
        newArray[i] = '0';  
	delete[] D.digits;
	D.digits = newArray;
}

void reallocate( const size_t& newcapacity) {
	unsigned char* newArray = new unsigned char[newcapacity];
	capacity = newcapacity;
	for (size_t i = 0; i < size; ++i)
		newArray[i] = digits[i];
	for (size_t i = size; i < capacity; ++i)
        newArray[i] = '0';  
	delete[] digits;
	digits = newArray;
}

size_t getsize() {
	return size;
}

~Decimal() {
    if(digits != nullptr) {
	    delete[] digits;
	    digits = nullptr;
    }
    size = 0;
	capacity = 0;
}

string getstring() {
	string s, ans;
	for (size_t i = 0; i < size; ++i)
		s += digits[i];
	for (int i = 0; i < size; ++i)
		ans += s[size - i - 1];
	return ans;
}

friend ostream& operator << (ostream& out, Decimal& obj) {
	for (int i = obj.size - 1; i >= 0; --i)
		out << obj.digits[i];
	return out;
}

void operator = (const Decimal& other) {
	if (capacity < other.capacity)
		reallocate(other.capacity);
	size = other.size;
	for (size_t i = 0; i < size; ++i)
		digits[i] = other.digits[i];
}

void operator = (Decimal&& other) {
	size = other.size;
	capacity = other.capacity;
	delete[] digits;
	digits = other.digits;

	other.digits = nullptr;
	other.capacity = 0;
	other.size = 0;
}

void operator += (const Decimal& other) {
	reallocate(max(other.capacity, capacity) + 1);
	int del = 0;
	for (int i = 0; i < capacity; ++i) {
        char c;
        if(i < other.size) c = other.digits[i];
        else c = '0';
		del += digits[i] + c - 2 * '0';
		digits[i] = del % 10 + '0';
		del /= 10;
		if (digits[i] != '0') size = i + 1;
	}
}

void operator -= (const Decimal& other) {
	if (size < other.size) {
		throw logic_error("The size of left value is less than size of right value");
	}
	reallocate(size + 1);

	for (int i = 0; i < capacity; ++i) {

        char c;
        if(i < other.size) c = other.digits[i];
        else c = '0';
		if (digits[i] < c) {
			digits[i] += 10;
			digits[i + 1] -= 1;
		}
		digits[i] = digits[i] - c + '0';
    }
    	
	if (digits[capacity - 1] < '0')
		throw logic_error("The size of left value is less than size of right value");
    size = 1;
	for (int i = 0; i < capacity; ++i) {
		if (digits[i] != '0') size = i + 1;
    }
}

friend Decimal operator + (const Decimal& l, const Decimal& r) {
	Decimal ans = l;
	ans += r;
	return ans;
}

friend Decimal operator - (const Decimal& l, const Decimal& r) {
	Decimal ans = l;
	ans -= r;
	return ans;
}

friend bool operator == (const Decimal& l, const Decimal& r) {
	if (l.size != r.size) return 0;
	for (int i = 0; i < l.size; ++i) {
		if (l.digits[i] != r.digits[i]) return 0;
	}
	return 1;
}

friend bool operator != (const Decimal& l, const Decimal& r) {
	return !(l == r);
}

friend bool operator < (const Decimal& l, const Decimal& r) {
	if (l.size != r.size) return l.size < r.size;

	for (int i = l.size - 1; i >= 0; --i) {
		if (l.digits[i] != r.digits[i]) return l.digits[i] < r.digits[i];
	}
	return 0;
}

friend bool operator > (const Decimal& l, const Decimal& r) {
	return (r < l) || (l == r);
}

friend bool operator >= (const Decimal& l, const Decimal& r) {
	return r < l;
}

friend bool operator <= (const Decimal& l, const Decimal& r) {
	return r > l;
}
};
