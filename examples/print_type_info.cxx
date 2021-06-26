
#include <iostream>
#include <typeinfo>
#include <limits>

void PrintTypeInfoTitle()
{
    std::cout<<"Name\tBytes\tmin\tmax\n";
}

// Template function to print information about any primitive data type
template <typename T>
void PrintTypeInfo(T type)
{
   std::cout << typeid(type).name()<<"\t";
   std::cout << sizeof (type) << "\t";
   std::cout << (double)std::numeric_limits<T>::lowest() << "\t";
   std::cout << (double)std::numeric_limits<T>::max() << "\t";
   std::cout <<"\n";
}

int main()
{
   PrintTypeInfoTitle();
   
   bool a = true;
   PrintTypeInfo(a);
   char b = 'b';
   PrintTypeInfo(b);
   int c = 5;
   PrintTypeInfo(c);
   unsigned int d = 4;
   PrintTypeInfo(d);
   float e = 5.5;
   PrintTypeInfo(e);
   double f = 6.6;
   PrintTypeInfo(f);

}