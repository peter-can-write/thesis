template <class PartItr>
double* additive(PartItr start,
                 PartItr end,
                 unsigned long length,
                 double masterAmp = 1,
                 bool sigmaAprox = false,
                 unsigned int bitWidth = 16)
{
    static const double pi = 3.141592653589793;
    
    static const double twoPi = 6.28318530717958;
    
    // calculate number of partials
    unsigned long partNum = end - start;
    
    double * buffer = new double [length];
    
    double * amp = new double [partNum];        // the amplitudes
    double * phase = new double [partNum];      // the current phase
    double * phaseIncr = new double [partNum];  // the phase increments
    
    // constant sigma constant part
    double sigmaK = pi / partNum;
    
    // variable part
    double sigmaV;
    
    // convert the bit number to decimal
    bitWidth = pow(2, bitWidth);
    
    // the fundamental increment of one period
    // in radians
    static double fundIncr = twoPi / length;
    
    // fill the arrays with the respective partial values
    for (unsigned long p = 0; start != end; ++p, ++start)
    {
        // initial phase
        phase[p] = start->phaseOffs;
        
        // fundIncr is two π / tablelength
        phaseIncr[p] = fundIncr * start->num;
        
        // reduce amplitude if necessary
        amp[p] = start->amp * masterAmp;
        
        // apply sigma approximation conditionally
        if (sigmaAprox)
        {
            // following the formula
            sigmaV = sigmaK * start->num;
            
            amp[p] *= sin(sigmaV) / sigmaV;
        }
    }
    
    
