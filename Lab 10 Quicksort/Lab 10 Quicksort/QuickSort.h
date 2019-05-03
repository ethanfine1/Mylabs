#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include "QSinterface.h"
#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
class QuickSort : public QSInterface<T>
{
private:
   T* QSarray = NULL;
   size_t arraySize = 0;
   size_t arrayCapacity = 0;
public:
   QuickSort() : arrayCapacity(0), arraySize(0), QSarray(NULL)
   {
   }
   virtual ~QuickSort()
   {
      delete[] QSarray;
   }

   virtual bool createArray(size_t capacity = 0)
   {
      arraySize = 0;
      arrayCapacity = capacity;
      if (QSarray != NULL)
      {
         delete[] QSarray;
         QSarray = NULL;
      }
      if (QSarray = new T[capacity])
      {
         return true;
      }
      cout << "Return False" << endl;
      return false;
   }

   void resize()
   {
      arrayCapacity *= 2;
      T* temp = QSarray;
      QSarray = new T[arrayCapacity];
      for (size_t i = 0; i < arraySize; ++i)
      {
         QSarray[i] = temp[i];
      }
      delete[] temp;
   }

   virtual bool addElement(T element = NULL)
   {
      if (arraySize == arrayCapacity)
      {
         resize();
      }
      QSarray[arraySize] = element;
      ++arraySize;
      return true;
   }

   virtual bool sort(size_t left = 0, size_t right = 0)
   {
      size_t newLeft = left;
      size_t newRight = right;
      if (newLeft == newRight)
      {
         return true;
      }
      int pivot = medianOfThree(newLeft, newRight);
      if (pivot < 0)
      {
         return false;
      }
      int newPivot = partition(newLeft, newRight, pivot);
      if (newPivot < 0)
      {
         return false;
      }
      sort(newLeft, newPivot);
      sort(newPivot + 1, newRight);
      return true;
   }

   virtual bool sortAll()
   {
      size_t left = 0;
      size_t right = arraySize;
      return sort(left, right);
   }

   virtual bool clear()
   {
      arraySize = 0;
      return true;
   }

   virtual size_t capacity() const
   {
      return arrayCapacity;
   }

   virtual size_t size() const
   {
      return arraySize;
   }

   virtual int medianOfThree(size_t left = 0, size_t right = 0)
   {
      int middle = 0;
      if (left > right)
      {
         return -1;
      }
      middle = ((left + right) / 2);
      if (QSarray[left] > QSarray[middle])
      {
         swap(QSarray[left], QSarray[middle]);
      }

      if (QSarray[middle] > QSarray[right - 1])
      {
         swap(QSarray[middle], QSarray[right - 1]);
      }

      if (QSarray[left] > QSarray[middle])
      {
         swap(QSarray[left], QSarray[middle]);
      }
      if (middle < 0)
      {
         cout << "Negative" << endl;
      }
      return middle;
   }

   virtual int partition(size_t left = 0, size_t right = 0, size_t pivotIndex = 0)
   {
      size_t newLeft = left;
      size_t newRight = right;
      size_t pivot = pivotIndex;
      int negChecker = left;
      if (pivot >= newRight)
      {
         return -1;
      }
      if (newRight - 1 > arraySize)
      {
         return -1;
      }
      if (negChecker < 0)
      {
         return -1;
      }
      swap(QSarray[newLeft], QSarray[pivot]);
      // Start up and down at either end of the sequence with first as pivot
      size_t up = (newLeft + 1);
      size_t down = (newRight - 1);
      do
      {
         while ((up < (right - 1)) && !(QSarray[newLeft] < QSarray[up]))
         {
               ++up;
         }
         // Assert: up equals last - 1 or table[up] > table[first].
         while ((down > newLeft) && QSarray[newLeft] < QSarray[down]) --down;
         // Assert: down equals first or table[down] <= table[first].
         // if up is to the left of down, exchange table[up] and table[down].
         if (up < down) swap(QSarray[up], QSarray[down]);
      } while (up < down);
      // Exchange table[first] and table[down] thus putting the pivot value where it belongs.
      swap(QSarray[newLeft], QSarray[down]);
      return down;   // Return position of pivot.
   }

   virtual std::string toString() const
   {
      ostringstream out;
      for (size_t i = 0; i < (arraySize); ++i)
      {
         out << QSarray[i] << ",";
      }
      string myString = out.str();
      if (myString == "")
      {
         return "Empty";
      }
      return myString.substr(0, (myString.size() - 1));
   }

   friend ostream& operator<< (ostream& os, const QuickSort& iter)
   {
      os << iter.toString();
      return os;
   }
};


#endif
