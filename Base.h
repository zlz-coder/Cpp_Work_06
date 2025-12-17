#ifndef BASE_H
#define BASE_H

// 基类base
class Base {
public:
	int a;  // 公有数据成员
protected:
	int b;  // 保护数据成员
private:
	int c;  // 私有数据成员
	static int count;  // 私有静态成员：统计对象创建个数
public:
	// 构造函数：初始化a,b,c
	Base(int a_val, int b_val, int c_val);
	// 析构函数
	~Base();
	// 输出公有和保护成员（私有成员c无法直接访问）
	void print() const;
	// 静态成员函数：获取对象创建个数（类级别的数据共享）
	static int Manage();
};

// 公有继承派生类
class Derived1 : public Base {
public:
	Derived1(int a_val, int b_val, int c_val);
	~Derived1();
	// 测试派生类内访问基类成员
	void testAccess() const;
};

// 私有继承派生类
class Derived2 : private Base {
public:
	Derived2(int a_val, int b_val, int c_val);
	~Derived2();
	// 测试派生类内访问基类成员
	void testAccess() const;
};

// 保护继承派生类
class Derived3 : protected Base {
public:
	Derived3(int a_val, int b_val, int c_val);
	~Derived3();
	// 测试派生类内访问基类成员
	void testAccess() const;
};

#endif // BASE_H#pragma once
