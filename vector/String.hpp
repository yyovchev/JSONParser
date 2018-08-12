#ifndef STRING_H
#define STRING_H

#include "Vector.hpp"
#include <cstring>
#include <istream>

class String : public Vector<char>
{
public:
    String() = default;
    String(const char* str) : Vector(str, strlen(str)) {
        append('\0');
        --size;
    }
	operator char*() {
		append('\0');
		--size;
		return data;
	}
	String& operator+=(const String& str) {
		Vector::operator+=(str);
		return *this;
	}
	String operator+(const String& str) {
		String temp(*this);
		temp += str;
		return temp;
	}
	String& operator+=(const char *str) {
		String temp(str);
		this->operator+=(temp);
		return *this;
	}
	String operator+(const char *str) {
		String temp(*this);
		temp += str;
		return temp;
	}
    String& operator +=(char ch){
        char t[1];
        t[0]=ch;
        this->operator+=(t);
        return *this;
    }
    String operator+(char ch) {
        char t[1];
        t[0]=ch;
        String temp(*this);
        temp += t;
        return temp;
    }
	String operator=(const Vector<char>& other) {
        Vector::operator=(other);
		return *this;
	}
    operator char*()const {
        return data;
    }
    bool operator ==(const String &other)const{
        return !strcmp((char*)(*this) ,(char*)(other));
    }
    bool operator ==(const char *str)const{
        return !strcmp((char*)(*this) , str);
    }
    bool operator !=(const String &other)const{
        return !(*this == other);
    }
    bool operator !=(const char *str)const{
        return !(*this == str);
    }
    void removenulls(){
        while (size>=1 && data[size - 1] == '\0')
            --size;
    }
};

#endif
