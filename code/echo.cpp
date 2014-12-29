double Echo::process(double sample)
{
    double output = sample + Delay::process(sample);
    
    return dryWet_(sample, output);
}