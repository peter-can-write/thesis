double* ramp(const unsigned int period)
{
    // the sample buffer
    double * buffer = new double [period];
    
    // index incrementor
    double incr = 2.0 / period;
    
    double value = -1;
    
    for (int n = 0; n < period; n++)
    {
        buffer[n] = value;
        
        value += incr;
    }
    
    return buffer;
}