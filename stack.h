#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack: private std::vector<T>
{
public:
    Stack(){

    }
    ~Stack(){
        
    }
    
    bool empty() const{
        return std::vector<T>::empty(); //return empty
    }
    size_t size() const{
        return std::vector<T>::size(); //return size
    }
    void push(const T& item){
        std::vector<T>::push_back(item);
    }
    void pop(){
        if(empty()){
            throw std::underflow_error("Cannot access if empty");
        }
        std::vector<T>::pop_back(); //pop backs and throw error if empty 

    }  // throws std::underflow_error if empty
    const T& top() const{
        if (std::vector<T>::empty()){
            throw std::underflow_error("Cannot access if empty");
        }
        return std::vector<T>::back(); //reuturn back and throw error if empty 
    } // throws std::underflow_error if empty
    // Add other members only if necessary
};


#endif