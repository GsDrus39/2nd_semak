#include <iostream>
#include <string>

template<class T>
class Stack {
private:
    unsigned int maxNumberOfElements, numberOfElements = 0;
    T *elements;

public:
    Stack(unsigned int size) {
        maxNumberOfElements = size;

        try {
            elements = new T[size];
        } catch (const std::bad_alloc &e) {
            std::cout << "INIT ERROR: too big size";
        }
    }

    ~Stack() {
        delete[] elements;
    }

    int size() {
        return numberOfElements;
    }

    bool empty() {
        return numberOfElements != 0;
    }

    bool push(T new_element) {
        if (numberOfElements < maxNumberOfElements) {
            elements[numberOfElements] = new_element;
            numberOfElements++;
        } else {
            throw std::overflow_error("PUSH EXCEPTION: stack is full");
        }
    }

    T pop() {
        if (numberOfElements == 0) {
            throw std::out_of_range("POP EXCEPTION: stack is empty");
        } else {
            T element = elements[0];
            for (int i = 0; i < maxNumberOfElements - 1; i++) {
                elements[i] = elements[i + 1];
            }
            numberOfElements--;
            return element;
        }
    }

    void top() {
        if (numberOfElements == 0) {
            throw std::logic_error("TOP EXCEPTION: stack is empty");
        } else {
            std::cout << elements[numberOfElements - 1] << std::endl;
        }
    }
};


int main() {
    Stack<int> stack(100);
    std::cout << "Stack is empty: " << stack.empty() << std::endl;

    for (int i = 10; i < 20; i++) {
        stack.push(i);
    }
    std::cout << "Stack is empty: " << stack.empty() << std::endl;
    std::cout << "Stack size: " << stack.size() << std::endl;
    stack.top();
    std::cout << "First element from stack: " << stack.pop() << std::endl;
}
