void LFOSeq::setRate(double Hz)
{
    if (Hz < 0 || Hz > 10)
    { throw std::invalid_argument("Rate cannot be less than zero or greater 10!"); }
    
    rate_ = Hz;
    
    resizeSegsFromRate_(rate_);
}

void LFOSeq::resizeSegsFromRate_(double rate)
{
    // get the period, divide up into _segNum pieces
    segLen_ = (Global::samplerate / rate) / segs_.size();
    
    // Set all segments' lengths
    for (int i = 0; i < segs_.size(); i++)
    {
        segs_[i].setLen(segLen_);
        
        // Scale frequency of mods according to length
        setScaledModFreq_(i);
    }
}

void LFOSeq::setScaledModFreq_(seg_t seg)
{
    // Set scaled frequency to frequency of lfo
    lfos_[seg].lfo.setFrequency(getScaledModFreqValue(lfos_[seg].freq));
}

double LFOSeq::getScaledModFreqValue(double freq) const
{
    // Since the rate is in cycles per segment
    // and not cycles per second, we get the
    // "period" of the segment and multiply that
    // by the rate, giving the mod wave's frequency.
    
    if (! segLen_) return 0;
    
    // To go from samples to Hertz, simply
    // divide the samplerate by the length
    // in samples e.g. 44100 / 22050 = 2 Hz
    double temp = Global::samplerate / static_cast<double>(segLen_);
    
    // Multiply by wanted frequency
    return freq * temp;
}