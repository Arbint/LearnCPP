#pragma once
#include <iostream>
/*
https://www.learncpp.com/cpp-tutorial/15-1-intro-to-smart-pointers-move-semantics/
*/
/*Dangerous Smart Pointer Implementation, 
*copy constructor will duplicate owner ship, cause other owner
*To point to null if one of the owners goes out of scope and called delete.
*/
template<class T>
class AutoPtr
{
	T* m_ptr;
public:
	AutoPtr(T* ptr = nullptr)
		:m_ptr(ptr)
	{

	}
	~AutoPtr()
	{
		delete m_ptr;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
};


//Smart single ownership ptr uses move semantics, dangerous when pass to function
template<class T>
class AutoPtrMS
{
	T* m_ptr;
public:
	AutoPtrMS(T* ptr=nullptr)
		:m_ptr(ptr)
	{

	}
	~AutoPtrMS()
	{
		delete m_ptr;
	}

	//Copy constructor that implements move semantics to transfer owner ship
	AutoPtrMS(AutoPtrMS& inAutoPtr)
	{
		m_ptr = inAutoPtr.m_ptr;
		inAutoPtr.m_ptr = nullptr;
	}

	AutoPtrMS& operator=(AutoPtrMS& inAutoPtr)
	{
		if (&inAutoPtr==this)
		{
			return *this;
		}
		delete m_ptr;
		m_ptr = inAutoPtr.m_ptr;
		inAutoPtr.m_ptr = nullptr;
		return *this;
	}

	T& operator*() { return *m_ptr; }
	T* operator->() { return m_ptr; }

	bool isNull() const { return m_ptr == nullptr; }
};



//Test Class
class TestDynamicAllowcatingClass
{
public:
	TestDynamicAllowcatingClass();
	~TestDynamicAllowcatingClass();
public:
	void print();
};


//C++11 adds a new type of reference called an r-value reference. An r-value reference is a reference that is designed to be initialized with an r-value (only). While an l-value reference is created using a single ampersand, an r-value reference is created using a double ampersand:
void DemoRValueReference();

class Fraction
{
private:
	int m_numerator;
	int m_denominator;
public:
	Fraction(int numerator = 0, int denominator = 1);	
	friend std::ostream& operator<<(std::ostream& out, const Fraction &f1);
};

template<class T>
class Auto_ptr3
{
	T* m_ptr;
public:
	Auto_ptr3(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	~Auto_ptr3()
	{
		delete m_ptr;
	}

	// Copy constructor
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr3(const Auto_ptr3& a)
	{
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}

	// Copy assignment
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr3& operator=(const Auto_ptr3& a)
	{
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete m_ptr;

		// Copy the resource
		m_ptr = new T;
		*m_ptr = *a.m_ptr;

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};


template<class T>
class Auto_ptr4
{
	T* m_ptr;
public:
	Auto_ptr4(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	~Auto_ptr4()
	{
		delete m_ptr;
	}

	// Copy constructor
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr4(const Auto_ptr4& a)
	{
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}

	// Move constructor
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr4(Auto_ptr4&& a)
		: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr; // we'll talk more about this line below
	}

	// Copy assignment
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr4& operator=(const Auto_ptr4& a)
	{
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete m_ptr;

		// Copy the resource
		m_ptr = new T;
		*m_ptr = *a.m_ptr;

		return *this;
	}

	// Move assignment
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr4& operator=(Auto_ptr4&& a)
	{
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete m_ptr;

		// Transfer ownership of a.m_ptr to m_ptr
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr; // we'll talk more about this line below

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};
