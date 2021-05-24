#ifndef _CS507_QUEUE_H_
#define _CS507_QUEUE_H_
#include <exception>
#include "Array.h"


/*Constant time or O(1) run time*/

template <typename T>
class Queue
{
public:
    /// Type definition of the type.
    typedef T type;

    /**
     * @class empty_exception
     *
     * Exception thrown to indicate the Queue is empty.
     */
    class empty_exception : public std::exception
    {
    public:
        // Default constructor.
        empty_exception(void)
            : std::exception() { }

        
         //Initializing constructor.

         //@param[in]      msg         Error message.
         
        empty_exception(const char* msg)
            : std::exception(msg) { }
    };


    /// Default constructor.
    Queue(void);


    /// Copy constructor.
    Queue(const Queue& q);


    //Queue Destructor~
    ~Queue(void);


    // Assigment operator for the queue
    const Queue& operator = (const Queue& rhs);


    //Adds the element to the end of the list;
    void enqueue(T element);


    //removes the element at the front of the list.If there are not elements in the queue,
    //an empty_exception will be thrown,
    T dequeue(void);


    //This method returns true if queue is empty || false if queue is full
    bool is_empty(void) const;


    //returns the number of elements in the queue
    size_t size(void) const;


    //clear contents of the Queue
    void clear(void);

    //show the contents of the Queue
    void show(void);

private:
    Array<T> queue_data_;
    
    size_t queue_size_;

    size_t front_;

    size_t rear_;

};

#include"Queue.cpp"

#endif

