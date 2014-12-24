double Envelope::modulate(double sample, double depth, double)
{
   return sample * tick_() * depth * amp_;
}
