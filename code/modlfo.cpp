double LFO::modulate(double sample, double depth, double maximum)
{
  return sample + (maximum * Oscillator::tick() * depth * amp_);
}
