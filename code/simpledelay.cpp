class Delay
{
public:
    
    typedef unsigned long index_t;
    
    Delay(index_t length)
    : line_(new double [length]()),
      length_(length)
    { }
    
    ~Delay()
    {
        delete [] line_;
    }

    double process(double sample)
    {
        // Retrieve output sample
        double output = line_[0];
        
        // Move all elements forward by one
        for (index_t i = 0, j = 1; j < length_; ++i, ++j)
        {
            line_[i] = line_[j];
        }
        
        // Push the new sample into
        // into the delay line
        line_[length_ - 1] = sample;
        
        return output;
    }
    
private:
    
    index_t length_;
    
    double* line_;
};