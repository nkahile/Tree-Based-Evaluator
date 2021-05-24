#include <stdexcept>         // for std::out_of_bounds exception
#include <iostream>


//
// Base_Array
//
//

template <typename T>
Base_Array <T>::Base_Array(void)
    :data_(0),
    cur_size_(0),
    max_size_(50)
{
    this->data_ = new T[max_size_];

}

//
// Base_Array (length)
//

template <typename T>
Base_Array <T>::Base_Array(size_t length)
    :data_(0),
    cur_size_(length),
    max_size_(length)
{
    this->data_ = new T[max_size_];
}

//
// Base_Array (lenght, filll)
//

template <typename T>
Base_Array <T>::Base_Array(size_t length, T fill)
    :data_(0),
    cur_size_(length),
    max_size_(length)
{
    this->data_ = new T[max_size_];
    for (size_t i = 0; i < cur_size_; i++) {
        Base_Array<T>::set(i, fill);
        data_[i] = fill;
    }
}

//Copy constructor
// Base_Array (array)
//

template <typename T>
Base_Array <T>::Base_Array(const Base_Array& array)
    :data_(0),
    cur_size_(array.cur_size_),
    max_size_(array.max_size_)
{
    this->data_ = new T[max_size_];
    for (size_t i = 0; i < array.cur_size_; i++) {
        this->data_[i] = array.data_[i];
    }
}

//
// ~Base_Array
//

template <typename T>
Base_Array <T>::~Base_Array(void)
{
    delete[] data_;
}

//
// operator =
//

template <typename T>
const Base_Array <T>& Base_Array <T>::operator = (const Base_Array& rhs)
{
    if (this == &rhs) {
        return *this;
    }

    if (rhs.cur_size_ > cur_size_) {

        T* temp_arr = new T[cur_size_ + rhs.cur_size_];

        T* data_copy = this->data_;
        this->data_ = temp_arr;
        temp_arr = data_copy;

        this->max_size_ = rhs.cur_size_ + cur_size_;
        delete[] temp_arr;
    }

    cur_size_ = rhs.cur_size_;

    for (size_t i = 0; i < this->cur_size_; i++) {
        data_[i] = rhs.data_[i];
    }
    std::cout << "Newly Assigned Object Now Has A Aize Of [" << cur_size_ << "] " << std::endl;
    return *this;
}

//
// operator []
//

template <typename T>
T& Base_Array <T>::operator [] (size_t index)
{
    if (this->max_size_ < index) {
        throw std::out_of_range("Index out of range");
    }
    else {
        //std::cout << "Value at index [" << index << "] is: " << data_[index] << std::endl;
        return this->data_[index];
    }
}

//
// operator []
//

template <typename T>
const T& Base_Array <T>::operator [] (size_t index) const
{
    if (this->max_size_ < index) {
        throw std::out_of_range("Index out of range");
    }
    else {
        return this->data_[index];

    }
}

//
// get
//

template <typename T>
T Base_Array <T>::get(size_t index) const
{
    if (this->max_size_ < index) {
        throw std::out_of_range("Index out of range");
    }
    else {
        std::cout << data_[index];
        return this->data_[index];

    }
}



template <typename T>
void Base_Array <T>::set(size_t index, T value)
{
    if (this->max_size_ < index) {
        throw std::out_of_range("Index out of range");
    }
    else {
        this->data_[index] = value;
    }
}

//
// find (element)
//
template  <typename T>
int Base_Array <T>::find(T element) const
{
    //std::cout << "hello";
    for (size_t i = 0; i < this->cur_size_; i++) {
        if (this->data_[i] == element) {
            std::cout << "Found Character: " << " " << element << " " << std::endl;
            return i;
        }
        else {
            return -1;
        }
    }
}

//
// find (element, size_t)
//
template <typename T>
int Base_Array <T>::find(T element, size_t start) const
{

    if (start > this->cur_size_) {
        throw std::out_of_range("start out of range");
    }


    for (size_t i = start; i < this->cur_size_; i++) {
        if (this->data_[i] == element) {
            std::cout << "=> Found Character: " << " " << element << " " << std::endl;
            return i;
        }
        else if (this->data_[i] != element) {
            return -1;
        }
        else {
            throw std::out_of_range("start out of range");
        }
    }
}

//
// operator ==
//
template <typename T>
bool Base_Array <T>::operator == (const Base_Array& rhs) const
{
    for (size_t i = 0; i < this->cur_size_; i++) {
        for (size_t j = 0; j < rhs.cur_size_; i++) {
            if ((data_[i] == rhs.data_[j]) && (this->cur_size_ == rhs.cur_size_)) {
                std::cout << "True, Arrays Are Equal";
                return true;
            }
            else {
                return false;
            }
        }
    }
}

//
// operator !=
//
template <typename T>
bool Base_Array <T>::operator != (const Base_Array& rhs) const
{
    for (size_t i = 0; i < this->cur_size_; i++) {
        for (size_t j = 0; j < rhs.cur_size_; i++) {
            if ((data_[i] != rhs.data_[j]) || (this->cur_size_ != rhs.cur_size_)) {
                std::cout << "True, Arrays Not Equal";
                return true;
            }
            else {
                return false;
            }
        }
    }
}

//
// fill
//
template <typename T>
void Base_Array <T>::fill(T ch)
{
    for (size_t i = 0; i < cur_size_; i++) {
        this->set(i, ch);
        data_[i] = ch;
    }
}
