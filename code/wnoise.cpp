#include <random>
#include <ctime>

class Noise
{
    Noise()
    : dist_(-1,1)
    {
        // Seed random number generator
        rgen_.seed((unsigned)time(0));
    }
    
    double tick()
    {
        // Return noise sample
        return dist_(rgen_);
    }
    
private:
    
    /*! Mersenne-twister random number generator */
    std::mt19937 rgen_;
    
    /*! Random number distribution (uniform) */
    std::uniform_real_distribution<double> dist_;
};
