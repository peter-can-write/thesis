AnyUnit::AnyUnit()
{
    modDock.setHigherBoundary(1);
    modDock.setLowerBoundary(0);
    modDock.setBaseValue(0.5);
}

void AnyUnit::setAmp(double amp)
{    
    modDock.setBaseValue(amp);
}
