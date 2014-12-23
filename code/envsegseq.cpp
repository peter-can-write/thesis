void EnvSegSeq::update()
{
    currSample_++;
    currSeg_->update();
}

double EnvSegSeq::tick()
{
    if (currSample_ >= currSeg_->getLen())
    {
        // Increment segment
        currSeg_++;
        
        // Check if we need to reset the loop
        if (currSeg_ == loopEnd_ && (loopInf_ || loopCount_ < loopMax_))
        { resetLoop_(); }
        
        // If we've reached the end, go back to last segment
        // which will continue to tick its end amplitude value
        else if (currSeg_ == segs_.end()) currSeg_--;
        
        // else change
        else changeSeg_(currSeg_);
    }
    
    return currSeg_->tick();
}