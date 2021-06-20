#include "sequential-list.h"

SequentialList::SequentialList (unsigned int cap) {
    data_ = new DataType[cap];
    capacity_ = cap;
    size_ = 0;
}

SequentialList::~SequentialList() {
    delete [] data_;
}

unsigned int SequentialList::size() const {
    return size_;
}

unsigned int SequentialList::capacity() const {
    return capacity_;
}

bool SequentialList::empty() const {
    return (size_ == 0);
}

bool SequentialList::full() const {
    return (size_ == capacity_);
}

SequentialList::DataType SequentialList::select(unsigned int index) const {
    if (index >= size_) {
        cout << "Index out of bound, value of the last element is returned"<< endl;
        return data_[size_-1];
    }
    else {
        return data_[index];
    }
}

unsigned int SequentialList::search(DataType val) const {
    for (unsigned int i = 0; i < size_; i++) {
        if (data_[i] == val) {
            return i;
        }
    }
    cout << "Value is not found. The size of the list is returned" << endl;
    return size_;
}

void SequentialList::print() const {
    cout << "The elements in the sequential list are: " << endl;
    for (size_t i = 0; i < size_; i++) {
        cout << data_[i] << " ";
    }
    cout << endl;
}

bool SequentialList::insert(DataType val, unsigned int index) {
    if (full()) {
        cout << "Sorry. The list is already full.";
        return false;
    }
    else if (index > size_ || index < 0) {
        cout << "Sorry. Index out of bound" << endl;
        return false;
    }
    else {
        if (data_[index] != NULL) {
            for (size_t i = size_; i > index; i--) {
                data_[i] = data_[i-1];
            }
            data_[index] = val;
        }
        else {
            data_[index] = val;
        }
        size_++;
        cout << "Successfully added value at " << index << endl;
        return true;
    }
}

bool SequentialList::insert_front(DataType val) {
    if (full()) {
        cout << "Sorry. The list is already full.";
        return false;
    }
    else {
        for (size_t i = size_; i > 0; i--) {
            data_[i] = data_[i-1];
        }
        data_[0] = val;
        size_++;
        cout << "Successfully added value at the front" << endl;
        return true;
    }
}

bool SequentialList::insert_back(DataType val) {
    if (full()) {
        cout << "Sorry. The list is already full.";
        return false;
    }
    else {
        data_[size_] = val;
        size_++;
        cout << "Successfully added value at the back" << endl;
        return true;
    }
}

bool SequentialList::remove(unsigned int index) {
    if (empty()) {
        cout << "Sorry. The list is empty" <<endl;
        return false;
    }
    else if (index > size_-1) {
        cout << "Sorry. Index out of bound" << endl;
        return false;
    }
    else if (index == size_-1) {
        data_[index] = 0;
        size_--;
        cout << "Successfully removed value at the " << index << endl;
        return true;
    }
    else {
        for (index; index < size_; index++) {
            data_[index] = data_[index + 1];
        }
        size_--;
        cout << "Successfully removed value at the " << index << endl;
        return true;
    }

}

bool SequentialList::remove_front() {
    if (empty()) {
        cout << "Sorry. The list is empty" <<endl;
        return false;
    }
    else {
        for (size_t i = 0; i < size_; i++) {
            data_[i] = data_[i+1];
        }
        size_--;
        cout << "Successfully removed value from the front" << endl;
        return true;
    }
}

bool SequentialList::remove_back() {
    if (empty()) {
        cout << "Sorry. The list is empty" <<endl;
        return false;
    }
    else {
        data_[size_-1] = 0;
        size_--;
        cout << "Successfully removed value from the back " << endl;
        return true;
    }
}

bool SequentialList::replace(unsigned int index, DataType val) {
    if (data_[index] == 0) {
        cout << "No existing value in the index location" << endl;
        return false;
    }
    else {
        data_[index] = val;
        cout << "Successfully replaced value at the " << index << endl;
        return true;
    }
}

