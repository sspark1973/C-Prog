

template <class T> class IntElement { 
public:
	IntElement(T value) : next(NULL), data(value) {}
	~IntElement() {}

	IntElement *getNext() const { return next; }
	const T& value() const { return data }
	void setNext(IntElement *elem) { next = elem; }
	void setValue(const T& value) { data = value; }

private:
	IntElement *next;
	T data;
};
