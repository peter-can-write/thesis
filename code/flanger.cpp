double Flanger::process(double sample)
{
    double output = sample;
    
    // Check for feedback
    if (feedback_)
    {
        output -= delay_->offset(center_) * feedback_;
    }
    
    // Calculate new length by modulation. Modulation
    // depth and maximum are 1 because the LFO's amplitude
    // is the delay depth value
    double length = lfo_->modulate(center_, 1, 1);
    
    // Increment LFO
    lfo_->update();
    
    // Set the new length
    delay_->setDelayTime(length);
    
    // Retrieve new sample
    output += delay_->process(output);
    
    // Apply dry/wet
    return dryWet_(sample, output);
}