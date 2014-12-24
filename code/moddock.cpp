double ModDock::modulate(double sample)
{
    // If ModDock is not in use, return original sample immediately
    if (! inUse()) return sample;
    
    // Sidechaining
    
    // For every non-master
    for (indexVecItr nonMasterItr = nonMasterItems_.begin(), nonMasterEnd = nonMasterItems_.end();
         nonMasterItr != nonMasterEnd;
         ++nonMasterItr)
    {
        // If it isn't a slave, nothing to do
        if (! isSlave(*nonMasterItr)) continue;
        
        ModItem& nonMaster = modItems_[*nonMasterItr];
        
        // Set to zero initially
        nonMaster.depth = 0;
        
        // Then sum up the depth from all masters
        for (indexVecItr_const masterItr = nonMaster.masters.begin(), masterEnd = nonMaster.masters.end();
             masterItr != masterEnd;
             ++masterItr)
        {
            ModItem& master = modItems_[*masterItr];
            
            // Using the baseDepth as the base value and the master's depth as
            // the depth for modulation and 1 as the maximum boundary
            nonMaster.depth += master.mod->modulate(nonMaster.baseDepth, master.depth, 1);
        }
        
        // Average the depth
        nonMaster.depth /= nonMaster.masters.size();
    }
    
    // Modulation
    
    double temp = 0;
    
    // Get modulation from all non-master items
    for(indexVecItr_const itr = nonMasterItems_.begin(), end = nonMasterItems_.end();
        itr != end;
        ++itr)
    {
        // Add to result so we can average later
        // Use the sample as base, the modItem's depth as depth and the
        // higherBoundary as maximum
        temp += modItems_[*itr].mod->modulate(sample,
                                              modItems_[*itr].depth,
                                              higherBoundary_);
    }
    
    // Average
    sample = temp / nonMasterItems_.size();
    
    // Boundary checking
    if (sample > higherBoundary_) { sample = higherBoundary_; }
    
    else if (sample < lowerBoundary_) { sample = lowerBoundary_; }
    
    return sample;
}