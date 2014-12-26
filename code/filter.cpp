double Filter::process(double sample)
{
    double temp = sample
    - (coefA1_ * delayA_)
    - (coefA2_ * delayB_);
    
    double output = (coefB0_ * temp)
    + (coefB1_ * delayA_)
    + (coefB2_ * delayB_);
    
    
    // Store values into delay line
    delayB_ = delayA_;
    delayA_ = temp;
    
    return output;
}