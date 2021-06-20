#include "doubly-linked-list.h"

DoublyLinkedList::Node::Node(DataType data) {
    value = data;
    next = NULL;
    prev = NULL;
}

DoublyLinkedList::DoublyLinkedList() {
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList() {
    Node* temp = head_;
    Node* temp2 = head_;
    for (size_t i = 0; i < size_; i++) {
        temp2 = temp->next;
        if (temp != NULL) {
            delete temp;
        }
        temp = temp2;
    }
}

unsigned int DoublyLinkedList::size() const {
    return size_;
}

unsigned int DoublyLinkedList::capacity() const {
    return CAPACITY;
}

bool DoublyLinkedList::empty() const {
    return size_ == 0;
}

bool DoublyLinkedList::full() const {
    return size_ == CAPACITY;
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const {
    if (index > size_-1) {
        cout << "Index out of range. Last element returned" <<endl;
        return tail_->value;
    }
    /*Node* temp = head_;
    for (size_t i = 0; i < size_-1; i++) {
        temp = temp->next;
    }
    //cout << temp->value <<endl;
    DataType target = temp->value;
    return target;
     */
    Node* temp = getNode(index);
    DataType target = temp->value;
    //cout << target << endl;
    return target;
}

unsigned int DoublyLinkedList::search(DataType value) const {
    Node* temp = head_;
    for (size_t i = 0; i < size_; i++) {
        if (temp->value == value) {
            return i;
        }
        temp = temp->next;
    }
    cout << "The value is not found in the list" <<endl;
    return size_;
}

void DoublyLinkedList::print() const {
    cout << "The elements in the doubly linked list are: ";
    Node* temp = head_;
    cout << temp->value << " ";
    for (size_t i = 0; i < size_-1; i++) {
        temp = temp->next;
        cout << temp->value << " ";
    }
    cout << endl;
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const {
    if (index >= size_) {
        cout << "Index out of bound" << endl;
        return NULL;
    }
    Node* temp = head_;
    for (size_t i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp;
}

bool DoublyLinkedList::insert(DataType value, unsigned int index) {
    if (full()) {
        cout << "Sorry. The list is already full.";
        return false;
    }
    if (index == 0) {
        return insert_front(value);
    }
    if (index == size_ ) {
        return insert_back(value);
    }
    Node* temp = new Node(value);
    Node* node_ptr = getNode(index);
    if (node_ptr != NULL) {
        node_ptr->prev->next = temp;
        temp->next = node_ptr;
        temp->prev = node_ptr->prev;
        node_ptr->prev = temp;
        size_++;
        return true;
    }
    else {
        return false;
    }
}

bool DoublyLinkedList::insert_front(DataType value) {
    if (full()) {
        cout << "Sorry. The list is already full.";
        return false;
    }
    Node* temp = new Node(value);
    temp->next = head_;
    temp->prev = NULL;
    if (empty()) {
        tail_ = temp;
    }
    if (head_ != NULL) {
        head_->prev = temp;
    }
    head_ = temp;
    size_++;
    return true;
}

bool DoublyLinkedList::insert_back(DataType value) {
    if (full()) {
        cout << "Sorry. The list is already full.";
        return false;
    }
    Node* temp = new Node(value);
    if (empty()) {
        tail_ = temp;
        head_ = temp;
    }
    else {
        temp->prev = tail_;
        tail_->next = temp;
        tail_ = temp;
    }
    size_++;
    return true;
}

bool DoublyLinkedList::remove(unsigned int index) {
    if (empty()) {
        cout << "Sorry. The list is empty" <<endl;
        return false;
    }
    if (index == 0) {
        return remove_front();
    }
    if (index == size_-1) {
        return remove_back();
    }
    Node* node_ptr = getNode(index);
    if (node_ptr != NULL) {
        node_ptr->prev->next = node_ptr->next;
        node_ptr->next->prev = node_ptr->prev;
        delete node_ptr;
        node_ptr = NULL;
        size_--;
        return true;
    }
    else {
        return false;
    }
}

bool DoublyLinkedList::remove_front() {
    if (empty()) {
        cout << "Sorry. The list is empty" <<endl;
        return false;
    }
    if (size() == 1) {
        delete head_;
        head_ = NULL;
        tail_ = NULL;
    }
    else {
        head_ = head_->next;
        delete head_->prev;
        head_->prev = NULL;
    }
    size_--;
    return true;
}

bool DoublyLinkedList::remove_back() {
    if (empty()) {
        cout << "Sorry. The list is empty" <<endl;
        return false;
    }
    if (size() == 1) {
        delete tail_;
        tail_ = NULL;
        head_ = NULL;
    }
    else {
        tail_ = tail_->prev;
        delete tail_->next;
        tail_->next = NULL;
    }
    size_--;
    return true;
}

bool DoublyLinkedList::replace(unsigned int index, DataType value) {
    Node* node_ptr = getNode(index);
    if (node_ptr != NULL) {
        node_ptr -> value = value;
        return true;
    }
    else {
        return false;
    }
}