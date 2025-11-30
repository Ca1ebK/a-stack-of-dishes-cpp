#include <iostream>
#include "dish.hpp"

const int MAX_SIZE = 5;

class DishStack
{
private:
  Dish arr[MAX_SIZE];
  int topIndex;

public:
  DishStack() : arr{Dish(""), Dish(""), Dish(""), Dish(""), Dish("")}, topIndex(0)
  {
  }

  bool isEmpty()
  {
    return (topIndex == 0);
  }

  bool isFull()
  {
    return (topIndex == MAX_SIZE);
  }

  void push(Dish element)
  {
    if (isFull())
    {
      std::cout << "Stack is full. Cannot push element.\n";
    }
    else
    {
      arr[topIndex] = element;
      topIndex += 1;
      std::cout << "Pushed element: " << element.get_description() << " onto the stack.\n";
    }
  }

  Dish pop()
  {
    if (isEmpty())
    {
      std::cout << "Stack is empty. Cannot pop from an empty stack.\n";
      return Dish("");
    }
    else
    {
      topIndex--;
      Dish poppedElement = arr[topIndex];
      std::cout << "Popped element: " << poppedElement.get_description() << " from the stack.\n";
      return poppedElement;
    }
  }

  Dish peek()
  {
    if (isEmpty())
    {
      std::cout << "Stack is empty. Cannot peek at an empty stack.\n";
      return Dish("");
    }
    else
    {
      Dish peekedElement = arr[topIndex - 1];
      std::cout << "Peeked at element: " << peekedElement.get_description() << " at the top of the stack.\n";
      return peekedElement;
    }
  }

  int size()
  {
    return topIndex;
  }
};

