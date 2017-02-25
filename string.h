#include <iostream>

namespace mipt {
	class String {
	private:
		char *values;
		size_t capacity;
	public :
		String(int cap = 1);
		String(const char *);
		String(const String &);
		~String();
		void print();
		size_t size() const;
		size_t find(const char);
		void resize(int newcapacity);
		String &append(const char);
		String &append(const char *);
		String &append(const String &);
		String substring(size_t start = 0, size_t finish = -1) const;
		String operator+(const String &) const;
		String operator+(const char *) const;
		String operator+(const char) const;
		friend String operator+(const char *, const String &);
		char &operator[](const int) const;
		String &operator=(const char*);
		String &operator=(const char);
		friend std::ostream &operator<<(std::ostream &, const String &);
		friend std::istream &operator>>(std::istream &, const String &);
		operator char*() const { return this->values; }
		operator int() const { return atoi(this->values); }
		operator double() const { return atof(this->values); }
	};
}