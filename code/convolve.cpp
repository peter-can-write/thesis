#include <vector>

std::vector<double> convolve(const std::vector<double>& signal,
                             const std::vector<double>& impulseResponse)
{
    std::vector<double> output(signal.size(),0);
    
    for(std::vector<double>::size_type i = 0, endI = signal.size();
        i < endI;
        ++i)
    {
        for(std::vector<double>::size_type j = 0, endJ = impulseResponse.size();
            j < endJ;
            ++j)
        {
            output[i + j] += signal[i] * impulseResponse[j];
        }
    }
    
    return output;
}