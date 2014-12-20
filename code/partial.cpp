struct Partial
{
  Partial(unsigned short number, double ampl, double phsOffs = 0)
    : num(number), amp(ampl), phaseOffs(phsOffs)
  { }
    
  /*! The Partial's number, stays const. */
  const unsigned short num;
    
  /*! The amplitude value. */
  double amp;
    
  /*! A phase offset */
  double phaseOffs;
};
