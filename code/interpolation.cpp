template<class T>
double interpolate(T table [], double index)
{
    long integral = static_cast<long>(index);  // The truncated integral part
    double fractional = index - integral;    // The remaining fractional part
    
    // grab the two items in-between which the actual value lies
    T value1 = table[integral];
    T value2 = table[integral+1];
    
    // interpolate: integer part + (fractional part * difference between value2 and value1)
    double final = value1 + ((value2 - value1) * fractional);
    
    return final;
}