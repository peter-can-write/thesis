#include <cmath>
#include <stdexcept>

class EnvSeg
{
    
public:

    typedef unsigned long len_t;
    
    EnvSeg(double startLevel = 0,
           double endLevel = 0,
           len_t len = 0,
           double rate = 1)
    
    : startLevel_(startLevel), endLevel_(endLevel),
    rate_(rate), curr_(0),len_(len)
    
    {
        calcRange_();
        calcIncr_();
    }
    
    double tick()
    {
        // If the segment is still supposed to
        // tick after reaching the end amplitude
        // just return the end amplitude
        
        if (curr_ >= 1 || ! len_) return endLevel_;
        
        return range_ * pow(curr_,rate_) + startLevel_;
    }
    
    void update()
    {
        // Increment curr_
        curr_ += incr_;
    }
    
    void setLen(len_t sampleLen)
    {
        len_ = sampleLen;
        
        calcIncr_();
    }
    
    len_t getLen() const
    {
        return len_;
    }
    
    void setRate(double rate)
    {
        if (rate > 10 || rate < 0)
        { throw std::invalid_argument("Rate must be between 0 and 10"); }
        
        rate_ = rate;
    }
    
    double getRate() const
    {
        return rate_;
    }
    
    void setEndLevel(double lv)
    {
        if (lv > 1 || lv < 0)
        { throw std::invalid_argument("Level must be between 0 and 1"); }
        
        endLevel_ = lv;
        
        calcRange_();
    }
    
    double getEndLevel() const
    {
        return endLevel_;
    }
    
    void setStartLevel(double lv)
    {
        if (lv > 1 || lv < 0)
        { throw std::invalid_argument("Level must be between 0 and 1"); }
        
        startLevel_ = lv;
        
        calcRange_();
    }
    
    double getStartLevel() const
    {
        return startLevel_;
    }
    
    void reset()
    {
        curr_ = 0;
    }
    
private:
    
    /*! Calculates the amplitude range and assigns it to range_ */
    void calcRange_()
    {
        // The range between start and end
        range_ = endLevel_ - startLevel_;
    }
    
    /*! Calculates the increment for curr_ and assigns it to incr_ */
    void calcIncr_()
    {
        incr_ = (len_) ? 1.0/len_ : 0;
    }
    
    /*! The rate determining the type (lin,log,exp) */
    double rate_;
    
    /*! Starting amplitude */
    double startLevel_;
    
    /*! End amplitude */
    double endLevel_;
    
    /*! Difference between end and start amplitude */
    double range_;
    
    /*! Current segment value */
    double curr_;
    
    /*! Increment value for curr_ */
    double incr_;
    
    /*! Length of segment in samples */
    len_t len_;
};
