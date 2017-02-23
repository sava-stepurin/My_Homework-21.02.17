#include <iostream>
#include "string.h"

mipt::String::String() {
	values = new char[101];
	capacity = 101;
	values[0] = 0;
}

mipt::String::String(const char *temp) {
	int size = strlen(temp);
	values = new char[size + 1];
	capacity = size + 1;
	std::memcpy(values, temp, size);
	values[size] = 0;
}

mipt::String::String(const String &that) {
	this->capacity = that.capacity;
	this->values = new char[that.capacity];
	for (int i = 0; i < that.capacity; i++) {
		this->values[i] = that.values[i];
	}
}

mipt::String::~String() {
	delete[]this->values;
}

void mipt::String::print() {
	for (int i = 0; i < size(); i++) {
		std::cout << values[i];
	}
	std::cout << std::endl;
}

size_t mipt::String::size() const {
	return strlen(this->values);
}

size_t mipt::String::find(const char temp) {
	size_t res = 0;
	for (int i = 0; i < size(); i++) {
		if (values[i] == temp) {
			res = i;
		}
	}
	return res;
}

void mipt::String::resize() {
	char *temp = new char[this->capacity * 2];
	for (int i = 0; i < this->size(); i++) {
		temp[i] = this->values[i];
	}
	temp[this->size()] = 0;
	delete[]this->values;
	this->values = temp;
	this->capacity = this->capacity * 2;
}

mipt::String &mipt::String::append(const char temp) {
	while (this->capacity < 1 + this->size() + 1) {
		this->resize();
	}
	this->values[this->size() + 1] = 0;
	this->values[this->size()] = temp;
	return *this;
}

mipt::String &mipt::String::append(const char *temp) {
	int length = strlen(temp);
	while (this->capacity < length + this->size() + 1) {
		this->resize();
	}
	size_t this_length = this->size();
	for (int i = this_length; i < length + this_length; i++) {
		this->values[i] = temp[i - this_length];
	}
	this->values[length + this_length] = 0;
	return *this;
}

mipt::String &mipt::String::append(const String &that) {
	int that_length = that.size();
	while (this->capacity < that_length + this->size() + 1) {
		this->resize();
	}
	size_t this_length = this->size();
	for (int i = this_length; i < that_length + this_length; i++) {
		this->values[i] = that.values[i - this_length];
	}
	this->values[that_length + this_length] = 0;
	return *this;
}

mipt::String mipt::String::substring(size_t start, size_t finish) const {
	if (finish == -1) {
		finish = this->size() - 1;
	}
	char *res = new char[finish - start + 2];
	for (int i = start; i <= finish; i++) {
		res[i - start] = this->values[i];
	}
	res[finish - start + 1] = 0;
	String result(res);
	return result;
}

mipt::String mipt::String::operator+(const String &that) const {
	char *line = new char[this->size() + that.size() + 1];
	for (int i = 0; i < this->size(); i++) {
		line[i] = this->values[i];
	}
	for (int i = this->size(); i < this->size() + that.size(); i++) {
		line[i] = that.values[i - this->size()];
	}
	line[this->size() + that.size()] = 0;
	String result(line);
	return result;
}

mipt::String mipt::String::operator+(const char *temp) const {
	int length = strlen(temp);
	char *line = new char[this->size() + length + 1];
	for (int i = 0; i < this->size(); i++) {
		line[i] = this->values[i];
	}
	for (int i = this->size(); i < this->size() + length; i++) {
		line[i] = temp[i - this->size()];
	}
	line[this->size() + length] = 0;
	String result(line);
	return result;
}

mipt::String mipt::String::operator+(const char symbol) const {
	char *line = new char[capacity + 1];
	std::memcpy(line, this->values, this->size());
	line[size()] = symbol;
	line[size() + 1] = 0;
	String result(line);
	return result;
}

namespace mipt {
	String operator+(const char *temp, const String &str) {
		int length = strlen(temp);
		char *line = new char[str.size() + length + 1];
		for (int i = 0; i < str.size(); i++) {
			line[i] = temp[i];
		}
		for (int i = str.size(); i < str.size() + length; i++) {
			line[i] = str.values[i - str.size()];
		}
		line[str.size() + length] = 0;
		String result(line);
		return result;
	}
}

char &mipt::String::operator[] (const int number) const {
	return values[number];
}

mipt::String &mipt::String::operator=(const char *temp) {
	int sum = strlen(temp);
	char *res = new char[sum + 1];
	for (int i = 0; i < sum; i++) {
		res[i] = temp[i];
	}
	res[sum] = 0;
	delete[]this->values;
	this->values = res;
	this->capacity = sum + 1;
	return *this;
}

mipt::String &mipt::String::operator=(const char temp) {
	char *res = new char[2];
	res[0] = temp;
	res[1] = 0;
	delete[]this->values;
	this->values = res;
	this->capacity = 2;
	return *this;
}

namespace mipt {
	std::ostream &operator<<(std::ostream &os, const String &temp) {
		for (int i = 0; i < temp.size(); i++) {
			os << temp.values[i];
		}
		return os;
	}
	std::istream &operator >> (std::istream &is, const String &temp) {
		is >> temp.values;
		return is;
	}
}
