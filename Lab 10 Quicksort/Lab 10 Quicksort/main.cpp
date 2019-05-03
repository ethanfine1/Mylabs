#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "QuickSort.h"
using namespace std;

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK;
#endif

int main(int argc, char* argv[])
{
   VS_MEM_CHECK;
   ifstream in(argv[1]);
   ofstream out;
   out.open(argv[2]);
   string line, command;
   size_t inputNum;
   QuickSort<int> arrayToSort;
   while (getline(in, line))
   {
      istringstream iss(line);
      iss >> command;

      if (command == "QuickSort")
      {
         iss >> inputNum;
         out << command << " " << inputNum;
         (arrayToSort.createArray(inputNum)) ? out << " OK" << endl : out << " ERROR" << endl;
      }
      if (command == "Capacity")
      {
         out << command << " " << arrayToSort.capacity() << endl;
         
      }
      if (command == "Clear")
      {
         out << command << " ";
        (arrayToSort.clear()) ? out << "OK" << endl : out << " ERROR" << endl;
      }
      if (command == "AddToArray")
      {
         int arrayInput;
         out << command << "  ";
         iss >> arrayInput;
         out << arrayInput;
         arrayToSort.addElement(arrayInput);
         while (iss >> arrayInput)
         {
            arrayToSort.addElement(arrayInput);
            out << "," << arrayInput;
         }
         out << " OK" << endl;
      }
      if (command == "Size")
      {
         out << command << " " << arrayToSort.size() << endl;
      }
      if (command == "PrintArray")
      {
         out << command << " " << arrayToSort << endl;
      }
      if (command == "MedianOfThree")
      {
         int left = 0;
         int right = 0;
         iss >> left;
         iss >> right;
         out << command << " " << left << "," << right
            << " = " << arrayToSort.medianOfThree(left, right) << endl;
      }
      if (command == "Partition")
      {
         int left = 0;
         int right = 0; 
         int pivot = 0;
         iss >> left;
         iss >> right;
         iss >> pivot;
         out << command << " " << left << "," << right << "," << pivot;
         out << " = " << arrayToSort.partition(left, right, pivot) << endl;
      }
      if (command == "SortAll")
      {
         out << command;
         (arrayToSort.sortAll()) ? out << " OK" << endl : out << " ERROR" << endl;
      }
      if (command == "Sort")
      {
         int left = 0;
         int right = 0;
         iss >> left;
         iss >> right;
         out << command << " " << left << "," << right;
         (arrayToSort.sort(left, right)) ? out << " OK" << endl : out << " ERROR" << endl;
      }
   }
   return 0;
}