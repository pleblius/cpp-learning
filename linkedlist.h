#pragma once
#include <iostream>
/*
    A simple C++ implementation of a singly-linked list. Contains API options to add or remove elements at a specific index,
    get and set the value at a specific index, check if an element is contained within the list, clear the list, and to print the list.
*/
template <typename T>
class LinkedList {
private:
    struct Node {
        T data {};
        Node* next {nullptr};
    };

    Node* head {nullptr};
    Node* tail {nullptr};

    unsigned int size {0};

public:
    /*
    Creates a new, empty linked list.
    */
    LinkedList() {}

    /*
    LinkedList destructor. Frees data memory before element is deleted.
    */
    ~LinkedList() {
        clear();
    }

    /*
    Returns the number of elements contained in the list.
    */
    unsigned long int getSize() const {
        return this -> size;
    }

    /*
    Returns true if the list is empty.
    */
    bool isEmpty() const {
        return getSize() == 0;
    }

    /*
    Appends the element data to the end of the list.
    */
    void addLast(const T& data) {
        if (isEmpty()) {
            head = new Node{data, nullptr};
            tail = head;
        }
        else {
            tail -> next = new Node{data, nullptr};
            tail = tail -> next;
        }

        ++size;
    }

    /*
    Adds the element data to the list at index 0.
    */
    void addFirst(const T& data) {
        Node* n = new Node {data, head};
        head = n;

        if (isEmpty()) tail = head;

        ++size;
    }

    /*
    Adds the element data to the list at index i. Entries at or above index i are shifted.
    Throws an exception if index i is outside the bounds of the list.
    */
    void add(int i, const T& data) {
        if (i > size) throw -1;
        if (i == size) {
            addLast(data);
            return;
        }
        if (i == 0) {
            addFirst(data);
            return;
        }

        int curIndex = 0;
        Node* curNode = head;

        while (curIndex < i-1) {
            ++curIndex;
            curNode = curNode -> next;
        }

        curNode -> next = new Node{data, curNode -> next};
        ++size;
    }

    /*
    Sets the value of the element at index i to data.
    Throws an exception if index i is outside the bounds of the list.
    */
    void set(int i, const T& data) {
        if (i >= size) throw -1;

        int curIndex = 0;
        Node* curNode = head;

        while (curIndex < i) {
            ++curIndex;
            curNode = curNode -> next;
        }

        curNode -> data = data;
    }

    /*
    Gets the element contained at index i.
    Throws an exception if index i is outside the bounds of the list.
    */
    T get(int i) const {
        if (i >= size) throw -1;
        if (i == size - 1) return tail -> data;

        int curIndex = 0;
        Node* curNode = head;

        while (curIndex < i) {
            ++curIndex;
            curNode = curNode -> next;
        }

        return curNode -> data;
    }

    /*
    Checks if an element matching data is contained within the list.
    Returns true if a matching element is found.
    */
    bool contains (const T& data) const {
        Node* curNode = head;

        while (curNode != nullptr) {
            if (curNode -> data == data) return true;

            curNode = curNode -> next;
        }

        return false;
    }

    /*
    Removes the element at index i from the list.
    */
    T remove(int i) {
        if (i >= size || isEmpty()) throw -1;
        if (i == 0) return removeFirst();

        int curIndex = 0;
        Node* curNode = head;
        Node* prevNode;

        while (curIndex < i) {
            ++curIndex;
            prevNode = curNode;
            curNode = curNode -> next;
        }
        T data = curNode -> data;

        prevNode -> next = curNode -> next;
        delete curNode;
        --size;

        if (i == size) tail = prevNode;

        return data;
    }

    /*
    Removes the first element from the list.
    */
    T removeFirst() {
        if (isEmpty()) throw -1;

        T data = head -> data;

        Node* nextNode = head -> next;
        delete head;
        head = nextNode;
        --size;

        return data;
    }

    /*
    Clears every element in the list
    */
    void clear() {
        Node* curNode = head;
        Node* nextNode;

        while (curNode != nullptr) {
            nextNode = curNode -> next;
            delete curNode;
            curNode = nextNode;
        }

        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    /*
    Prints the size of the list, then on a new line prints every element in the list.
    */
    void print() const {
        std::cout << "Size: " << getSize() << '\n';
        std::cout << "List: ";

        Node* curNode = head;
        while (curNode != nullptr) {
            std::cout << curNode -> data << ' ';
            curNode = curNode -> next;
        }

        std::cout << '\n';
    }
    
    /*
    Sorts the list in ascending order. (0, 1, 2 ...)
    */
    void sortAscending() {
        auto order = [](T a, T b) {return a < b;};

        bubbleSort(order);
    }
    
    /*
    Sorts the list in descending order. (3, 2, 1, 0)
    */
    void sortDescending() {
        auto order = [](T a, T b) {return b < a;};

        bubbleSort(order);
    }

private:
    /*
    Sorts the list using bubble sort. Takes a function to compare two values and return the desired left-most value.
    */
   template <typename F>
    void bubbleSort(const F& fn) {
        if (getSize() <= 1) return;

        for (int i = 0; i < getSize(); ++i) {
            Node* curNode = head;
            for (int j = 0; j < getSize() - i - 1; ++j) {
                T left = curNode -> data;
                T right = (curNode -> next) -> data;

                if (!fn(left, right)) {
                    std::swap(curNode -> data, (curNode -> next) -> data);
                }

                curNode = curNode -> next;
            }
        }
    }    
};
