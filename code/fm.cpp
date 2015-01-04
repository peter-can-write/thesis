double FM::modulate_(index_t carrier, double value)
{
    ops_[carrier]->modulateFrequency(value);
    
    return ops_[carrier]->tick();
}

double FM::add_(index_t carrier, double value)
{
    return ops_[carrier]->tick() + value;
}

double FM::tick()
{
    const double aTick = tickIfActive_(A);
    
    switch (alg_)
    {
        case 0:
            return modulate_(D, modulate_(C, modulate_(B, aTick)));
            
        case 1:
            return modulate_(D, modulate_(C, add_(B, aTick)));
            
        case 2:
            return modulate_(D, add_(C, modulate_(B, aTick)));
            
        case 3:
            return modulate_(D, modulate_(B, aTick) + modulate_(C, aTick));
            
        case 4:
        {
            double temp = modulate_(B, aTick);
            
            return modulate_(D, temp) + modulate_(C, temp);
        }
            
        case 5:
            return add_(D, modulate_(C, modulate_(B, aTick)));
            
        case 6:
        {
            double bTick = tickIfActive_(B);
            
            return modulate_(D, add_(C, aTick + bTick));
        }
            
        case 7:
        {
            double bTick = tickIfActive_(B);
            
            return modulate_(C, aTick) + modulate_(D, bTick);
        }
            
        case 8:
            return modulate_(D, aTick) + modulate_(C, aTick) + modulate_(B, aTick);
            
        case 9:
            return add_(D, add_(C, modulate_(B, aTick)));
            
        case 10:
            return add_(D, modulate_(C, aTick) + modulate_(B, aTick));
            
        case 11:
        default:
            return add_(D, add_(C, add_(B, aTick)));
    }
}