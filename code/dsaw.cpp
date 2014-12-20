double* sawtooth(const unsigned int period)
{
    // the sample buffer
    double * buffer = new double [period];
    
    // how much we must decrement the
    // index by at each iteration
    double incr = -2.0 / period;
    
    double value = 1;
    
    for (int n = 0; n < period; n++)
    {
        buffer[n] = value;
        
        value += incr;
    }
    
    return buffer;
}