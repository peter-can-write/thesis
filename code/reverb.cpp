Reverb::Reverb(double reverbTime, double reverbRate, double dryWet)
: delays_(new Delay[4]),
  allPasses_(new AllPassDelay [2])
{
    
    delays_[0].setDelayTime(0.0437);
    delays_[1].setDelayTime(0.0411);
    delays_[2].setDelayTime(0.0371);
    delays_[3].setDelayTime(0.0297);
    
    allPasses_[0].setDecayTime(0.0050);
    allPasses_[0].setDelayTime(0.09638);
    
    allPasses_[1].setDecayTime(0.0017);
    allPasses_[1].setDelayTime(0.03292);
    
    setReverbTime(reverbTime);
    setReverbRate(reverbRate);
}

double Reverb::process(double sample)
{
    double output = 0;
    
    for (unsigned short i = 0; i < 4; ++i)
    {
        output += delays_[i].process(sample);
    }
    
    output = allPasses_[1].process(allPasses_[0].process(output));
    
    return dryWet_(sample, output);
}

void Reverb::setReverbRate(double reverbRate)
{
    for (unsigned short i = 0; i < 4; ++i)
    {
        delays_[i].setDecayRate(reverbRate);
    }
}

void Reverb::setReverbTime(double reverbTime)
{
    for (unsigned short i = 0; i < 4; ++i)
    {
        delays_[i].setDecayTime(reverbTime);
    }
}