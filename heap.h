#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()): ary(m), compare(c){

  }

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap(){

  }

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data; 
  void heapify(int idx);
  void trickleUp(int idx);
  //add data member for m-ary number and compare 
  int ary; 
  PComparator compare; 


};


// Add implementation of member functions here
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  data.push_back(item); //pushes item back and then trickup to maintain heap 
  trickleUp(data.size()-1);
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  return data.empty();
}

template <typename T, typename PComparator>
size_t  Heap<T,PComparator>::size() const{
  return data.size();
}

template <typename T, typename PComparator>
void  Heap<T,PComparator>::heapify(int idx){
  int best = idx; //set best to current index 
  for (int i = 1; i <=ary; i++){ //goes through every child and see if it's better than current index 
    size_t child = ary*idx+i;
    if (child>=size()){
      break; //breks if child is bigger than data size 
    }
    //cout <<"current child" << data[child] << endl;
    if(compare(data[child], data[best])){ //compare child to best using compare operator 
      best = child; 
      //cout << "current best" << best << endl;
    }
  }
  //cout << "current best" << best << endl;
  if (best!=idx){ //switch if current best is different from index 
    std::swap(data[best], data[idx]);
    heapify(best); //call recursion to heapify best 
  }
}

template <typename T, typename PComparator>
void  Heap<T,PComparator>::trickleUp(int idx){
  /*int parent = idx/2;
  while (parent>=1 && data[idx]<data[parent]){
    swap(data[parent], data[idx]);
    idx = parent; 
    parent = idx/2;
  }*/
  //int parent = ((idx-1)/ary);
  while (idx>0){ 
    int parent = (idx-1)/ary;
    //cout << "this is the parent" << data[parent] <<endl;
    if (compare(data[idx], data[parent])){ //compares index with parent 
      std::swap(data[parent], data[idx]); //switch if greater/less than parent 
      idx = parent; //move on to parent 
    }
    else{
      break; //stop when nth happens 
    }
  }
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::out_of_range("Tried to access top of empty heap");


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  //cout << size() << endl;
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::out_of_range("Tried to pop an empty heap");
  }
  if (data.size()==1){
    data.pop_back();
    return;
  }
  else{
    std::swap(data[0], data[data.size()-1]); //swap first value with last and pop last value 
    data.pop_back();
    heapify(0); //heapify from first value 
  }
}



#endif

