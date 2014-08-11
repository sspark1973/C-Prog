/*
18.3 Implement a singleton design pattern as a template such that, 
for any given class Foo, 
you can call Singleton::instance() and get a pointer to an instance of a singleton of type Foo. 

Assume the existence of a class Lock which has acquire() and release() methods. 

How could you make your implementation thread safe and exception safe?
*/

#include <iostream>
using namespace std;

/* Place holder for thread synchronization lock */
class Lock {
public:
	Lock() {}
	~Lock() {}
	void AcquireLock() {}
	void ReleaseLock() {}
};
	

/* Singleton class with a method that creates a new instance of the
 * class of the type of the passed in template if it does not
 * already exist. */
template <class T> class Singleton {
private:
	static Lock lock;
	static T* object;
protected:
	Singleton() { };
public:
	static T* instance();
};

Lock Singleton::lock;

T *Singleton::Instance() 
{
	if(object == 0) {
		lock.AcquireLock();

		if(object == 0) {
			object = new T;
		}
		lock.ReleaseLock();
	}
	return object;
}

int main()
{
	Foo *singleton_foo = Singleton<Foo>::Instance();
	return 0;
}

