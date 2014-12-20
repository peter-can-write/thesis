double* triangle(const unsigned int period) const
{
    double* buffer = new double[period];
    
    double value = -1;
    
    // 4.0 because we're incrementing/decrementing
    // half the period and the range is 2, so it's
    // actually 2 / period / 2.
    double incr = 4.0 / period;
    
    // Boolean to indicate direction
    bool reachedMid = false;
    
    for (unsigned int n = 0; n < period; n++)
    {
        wt[n] = value;
        
        // Increment or decrement depending
        // on the current direction
        value += (reachedMid) ? -incr : incr;
        
        // Change direction every time
        // the value hits a maximum
        if (value >= 1 || value <= -1)
        { reachedMid = !reachedMid; }
    }
    
    return buffer;
}