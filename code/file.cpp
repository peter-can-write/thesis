#include <fstream>
#include <stdexcept>

double* readWavetable(const std::string &fname)
{
  std::ifstream file(fname);
    
  if (! file.is_open())
  { throw std::runtime_error("Could not find wavetable file: " + fname); }
    
  if (! file.good())
  { throw std::runtime_error("Error opening wavetable: " + fname); }
    
  char signature[6];
    
  file.read(signature, 6);
    
  if (strncmp(signature, "ANTHEM", 6))
  { throw std::runtime_error("Invalid signature for Anthem file!"); }
    
  int len = 4096;
  int size = len * sizeof(double);
    
  double * wt = new double [len];
    
  file.read(reinterpret_cast<char*>(wt), size);
    
  return wt;
}
