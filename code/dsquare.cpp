double* square(const unsigned int period)
{
    // the sample buffer
    double * buffer = new double [period + 1];
    
    // time for one sample
    double sampleTime = 1.0 / period;
    
    // the midpoint of the period
    double mid = 0.5;
    
    double value = 0;
    
    // fill the sample buffer
    for (int n = 0; n < period; n++)
    {
        buffer[n] = (value < mid) ? -1 : 1;
        
        value += sampleTime;
    }
    
    return buffer;
}