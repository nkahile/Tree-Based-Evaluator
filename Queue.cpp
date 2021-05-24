#include <iostream>
#include <string>
#include "Queue.h"

//the Queue constructor
template <typename T>
Queue <T>::Queue(void)
    :queue_data_(50),
    queue_size_(0),
    front_(0),
    rear_(0)
{

}


template <typename T>
Queue <T>::~Queue(void)
{
    //no pointers to delete here
}


//changed the code so instead of using unnecessary temp arrays and memory alocation
//a simple check for self assignment is made, if the check is false, we start
//assigning the data to the rhs data, the size to the rhs size, front to rhs front,
//and finaly rear to rhs rear
template <typename T>
const Queue <T>& Queue <T>::operator = (const Queue& rhs)
{
    if (this != &rhs) {
        this->queue_data_ = rhs.queue_data_;
        this->queue_size_ = rhs.queue_size_;
        this->front_ = rhs.front_;
        this->rear_ = rhs.rear;
    }
    return *this;
}


//The Queue copy constructor
template <typename T>
Queue<T>::Queue(const Queue& s)
    :queue_data_(s.queue_data_),
    queue_size_(s.queue_size_),
    front_(s.front_),
    rear_(s.rear_)
    
{

}


template <typename T>
void Queue <T>::enqueue(T element)
{ 
    // COMMENT You are increasing the size of the queue, not you are not
    // adding the value to the queue.
    //=>Fixed it so it can change the size of the queue in real time while the
    //the values enter the queue

    ++this->rear_;
    ++this->queue_size_;

    this->queue_data_.resize(this->rear_);
    this->queue_data_.set(this->rear_-1 , element);

}

/*---------------
this is the front of the queue  =>  10 | 20 |30 | <= this is the rear of the queue
                                  ---------------*/

template <typename T>
T Queue<T>::dequeue(void)
{
    // COMMENT You are not returning the element removed from the queue.
    //=> fixed it so it can dequeue and return the dequeued element
    if (is_empty()) {
        throw Queue<T>::empty_exception();
    }
    else {
        ++this->front_;
        --this->queue_size_;
        std::cout << (this->queue_data_.get(this->front_ - 1)) << std::endl;
        return (this->queue_data_.get(this->front_ - 1));
    }
}

//check if the Queue is Empty
template <typename T>
bool Queue <T>::is_empty(void) const
{
    if (this->rear_ == this->front_) {
        std::cout << "Queue is empty" << std::endl;
        return true;
    }
    else {
        std::cout << "Queue has " << this->queue_size_ << " values" << std::endl;
        return false;
    }
}


//retrieve the values in the Queue
template<typename T>
size_t Queue<T>::size(void) const
{
    std::cout << this->queue_size_;
    return this->queue_size_;

}

//Clear the values in the Queue
template <typename T>
void Queue <T>::clear(void)
{
    this->rear_ = this->front_;

}

//this method is to show the contents of the Queue
template <typename T>
void Queue <T>::show(void)
{
    if (is_empty()) {
        throw Queue<T>::empty_exception();
    }
    else {
        for (size_t i = front_; i < rear_; i++) {
            std::cout << this->queue_data_[i];
        }
    }
}
