// fill the wavetable
for (unsigned int n = 0; n < length; n++)
{
    double value = 0;
    
    // do additive magic
    for (unsigned short p = 0; p < partNum; p++)
    {
        value += sin(phase[p]) * amp[p];
        
        phase[p] += phaseIncr[p];
        
        if (phase[p] >= twoPi)
        { phase[p] -= twoPi; }
    
    // round if necessary
    if (bitWidth < 65536)
    {
        Util::round(value, bitWidth);
    }
    
    buffer[n] = value;
}

delete [] phase;
delete [] phaseIncr;
delete [] amp;

return buffer;
}