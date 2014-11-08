#ifndef SomeUniqueName
#define SomeUniqueName

class MyClass
{
public:
	int add(int number) {return numero_ += number;}
	int someAnother(int an);

	//parameterless ctor
	MyClass() { };

	MyClass(int i):numero_(i)

	//destructor, cannot throw any exception (if not available, default implementation is created automatically)
	~MyClass() { }

	//forbidding copying
	MyClass(const MyClass & a) = delete;
	MyClass & operator =(const MyClass & a) = delete; 

private:
	int numero_;
};


#endif