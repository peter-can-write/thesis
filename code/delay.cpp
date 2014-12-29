double Delay::dryWet_(double originalSample, double processedSample)
{
    return (originalSample * (1 - dw_)) + (processedSample * dw_);
}

void Delay::writeAndIncrement_(double sample)
{
    *write_ = sample;
    
    if (++write_ >= buffer_.end())
    {
        write_ -= buffer_.size();
    }
}

double Delay::process(double sample)
{
    const_iterator read = write_ - readIntegral_;
    
    if (read < buffer_.begin())
    {
        read += buffer_.size();
    }
    
    if (! readIntegral_)
    {
        writeAndIncrement_(sample);
    }
    
    double output = *read;
    
    if (--read < buffer_.begin())
    {
        read += buffer_.size();
    }
    
    output += (*read - output) * readFractional_;
    
    output *= decayValue_;
    
    if (readIntegral_)
    {
        writeAndIncrement_(sample + (output * feedback_));
    }
    
    return dryWet_(sample, output);
}