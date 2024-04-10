#pragma once

template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type>* link;
};

template <class Type>
class LinkList {
protected:
	nodeType<Type>* first;
	nodeType<Type>* last;
private:
	int length;
public:
	LinkList() {
		first = nullptr;
		last = nullptr;
		length = 0;
	}
	int getLength() {
		return length;
	}
	void reduceLength() {
		length--;
	}
	void increaseLength() {
		length++;
	}
};

