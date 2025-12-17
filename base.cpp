#include "Base.h"
#include <iostream>
using namespace std;

// 静态成员初始化（类外初始化）
int Base::count = 0;

// 基类构造函数：初始化a,b,c，统计对象个数
Base::Base(int a_val, int b_val, int c_val) : a(a_val), b(b_val), c(c_val) {
	count++;
	cout << "Base构造函数调用，当前对象总数：" << count << endl;
}

// 基类析构函数
Base::~Base() {
	count--;
	cout << "Base析构函数调用，当前对象总数：" << count << endl;
}

// 输出公有成员a和保护成员b（私有成员c无法直接输出）
void Base::print() const {
	cout << "Base类 - a: " << a << ", b: " << b << "（c为私有成员，无法直接访问）" << endl;
}

// 静态成员函数：返回对象总数
int Base::Manage() {
	return count;
}

// ------------------------------
// 公有继承派生类Derived1实现
// ------------------------------
Derived1::Derived1(int a_val, int b_val, int c_val) : Base(a_val, b_val, c_val) {
	cout << "Derived1（公有继承）构造函数调用" << endl;
}

Derived1::~Derived1() {
	cout << "Derived1（公有继承）析构函数调用" << endl;
}

// 测试派生类内访问基类成员
void Derived1::testAccess() const {
	cout << "Derived1类内访问基类成员：" << endl;
	cout << "基类公有a: " << a << "（可直接访问）" << endl;
	cout << "基类保护b: " << b << "（可直接访问）" << endl;
	// cout << c;  // 错误：基类私有成员，派生类无法直接访问
	print();  // 基类公有成员函数，可直接调用
}

// ------------------------------
// 私有继承派生类Derived2实现
// ------------------------------
Derived2::Derived2(int a_val, int b_val, int c_val) : Base(a_val, b_val, c_val) {
	cout << "Derived2（私有继承）构造函数调用" << endl;
}

Derived2::~Derived2() {
	cout << "Derived2（私有继承）析构函数调用" << endl;
}

// 测试派生类内访问基类成员
void Derived2::testAccess() const {
	cout << "Derived2类内访问基类成员：" << endl;
	cout << "基类公有a: " << a << "（类内可访问，类外不可见）" << endl;
	cout << "基类保护b: " << b << "（类内可访问，类外不可见）" << endl;
	// cout << c;  // 错误：基类私有成员，派生类无法直接访问
	print();  // 基类公有成员函数，类内可调用
}

// ------------------------------
// 保护继承派生类Derived3实现
// ------------------------------
Derived3::Derived3(int a_val, int b_val, int c_val) : Base(a_val, b_val, c_val) {
	cout << "Derived3（保护继承）构造函数调用" << endl;
}

Derived3::~Derived3() {
	cout << "Derived3（保护继承）析构函数调用" << endl;
}

// 测试派生类内访问基类成员
void Derived3::testAccess() const {
	cout << "Derived3类内访问基类成员：" << endl;
	cout << "基类公有a: " << a << "（类内可访问，类外不可见）" << endl;
	cout << "基类保护b: " << b << "（类内可访问，类外不可见）" << endl;
	// cout << c;  // 错误：基类私有成员，派生类无法直接访问
	print();  // 基类公有成员函数，类内可调用
}