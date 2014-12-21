#include <iostream>

template<class T>
T interpolate(T table [], double index)
{
  long integral = static_cast<long>(index);  // The truncated integral part
  double fractional = index - integral;    // The remaining fractional part
        
  // grab the two items in-between which the actual value lies
  T value1 = table[integral];
  T value2 = table[integral+1];
        
  // interpolate: integer part + (fractional part * difference between value2 and value1)
  T final = value1 + ((value2 - value1) * fractional);
        
  return final;
}

int main(int argc, char * argv [])
{
  int buffer [10];

  for (int i = 0; i < 10; ++i)
  {
    buffer[i] = i;
  }
    
    std::cout << "???" << std::endl;

  std::cout << "Value: " << interpolate(buffer,4.5) << std::endl;
}
