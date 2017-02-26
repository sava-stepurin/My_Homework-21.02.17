#include "string.h"

void mipt::String::set_capacity(int capacity) {
	this->capacity = capacity;
	this->values = new char[capacity];
}

mipt::String::String(int capacity) {
	this->set_capacity(capacity);
	this->values[0] = 0;
}

mipt::String::String(const char *temp) {
	int size = strlen(temp);
	this->set_capacity(size + 1);
	std::memcpy(values, temp, size);
	values[size] = 0;
}

mipt::String::String(const String &that) {
	this->set_capacity(that.size() + 1);
	std::memcpy(values, that.values, that.size());
	this->values[that.size()] = 0;
}

mipt::String::~String() {
	delete[]this->values;
}

void mipt::String::print() {
	std::cout << this->values << std::endl;
}

size_t mipt::String::size() const {
	return strlen(this->values);
}

size_t mipt::String::find(const char temp) {
	size_t res = 0;
	bool flag = false;
	for (int i = 0; (i < size()) && (flag == false); i++) {
		if (values[i] == temp) {
			res = i;
			flag = true;
		}
	}
	return res;
}

void mipt::String::resize(int newcapacity) {
	char *temp = new char[newcapacity];
	std::memcpy(temp, this->values, this->size());
	temp[this->size()] = 0;
	delete[]this->values;
	this->values = temp;
	this->capacity = this->capacity * 2;
}

mipt::String &mipt::String::append(const char temp) {
	if (this->capacity < 1 + this->size() + 1) {
		this->resize(this->size() + 2);
	}
	this->values[this->size() + 1] = 0;
	this->values[this->size()] = temp;
	return *this;
}

mipt::String &mipt::String::append(const char *temp) {
	int length = strlen(temp);
	if (this->capacity < length + this->size() + 1) {
		this->resize(length + this->size() + 1);
	}
	size_t this_length = this->size();
	std::memcpy(this->values + this_length, temp, length);
	this->values[length + this_length] = 0;
	return *this;
}

mipt::String &mipt::String::append(const String &that) {
	return append(that.values);
}

mipt::String mipt::String::substring(size_t start, size_t finish) const {
	if (finish == -1) {
		finish = this->size() - 1;
	}
	char *res = new char[finish - start + 2];
	memcpy(res, this->values + start, finish - start + 1);
	res[finish - start + 1] = 0;
	String result(res);
	return result;
}

mipt::String mipt::String::operator+(const String &that) const {
	String res(*this);
	res.append(that);
	return res;
}

mipt::String mipt::String::operator+(const char *temp) const {
	String b(temp);
	return (*this + b);
}

mipt::String mipt::String::operator+(const char symbol) const {
	String b(&symbol);
	return(*this + b);
}

mipt::String mipt::operator+(const char *temp, const mipt::String &str) {
	mipt::String res(temp);
	return res + str;
}

char &mipt::String::operator[] (const int number) const {
	return values[number];
}

mipt::String &mipt::String::operator=(const char *temp) {
	int sum = strlen(temp);
	char *res = new char[sum + 1];
	std::memcpy(res, temp, sum);
	res[sum] = 0;
	delete[]this->values;
	this->values = res;
	this->capacity = sum + 1;
	return *this;
}

mipt::String &mipt::String::operator=(const char temp) {
	this->operator=(&temp);
	return *this;
}

namespace mipt {
	std::ostream &operator<<(std::ostream &os, const String &temp) {
		os << temp.values;
		return os;
	}
	std::istream &operator >> (std::istream &is, const String &temp) {
		is >> temp.values;
		return is;
	}
}
