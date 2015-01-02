#ifndef __Anthem__Wavefile__
#define __Anthem__Wavefile__

#include <fstream>
#include <string>
#include <deque>
#include <memory>

class Sample;

class Wavefile
{
    
public:
    
    Wavefile(const std::string& fname = std::string(),
             unsigned short channels = 2);
    
    Wavefile(const Wavefile& other);
    
    Wavefile& operator= (const Wavefile& other);
    
    void setChannels(unsigned short channels);
    
    void open(const std::string& fname);
    
    void close();
    
    void process(const Sample& sample);

    void write();
    
    void flush();
    
private:
    
    /*! Wavefile header */
    struct
    {
        uint8_t riffId[4]; // 'R' 'I' 'F' 'F'
        
        uint32_t riffSize; // chunks size in bytes
        
        uint8_t wavetype[4]; // 'W' 'A' 'V' 'E'
        
        uint8_t fmtId[4]; // 'f' 'm' 't' ''
        
        uint32_t fmtSize;
        
        uint16_t fmtCode; // 1 = pulse code modulation
        
        uint16_t channels;
        
        uint32_t samplerate;
        
        uint32_t byterate; // bytes per second
        
        uint16_t align; // bytes per sample * channel
        
        uint16_t bits; // one byte per channel, so 16 bits per sample
        
        uint8_t waveId[4]; // 'd' 'a' 't' 'a'
        
        uint32_t waveSize; // byte total
        
    } header_;
    
    /*! The sample buffer */
    std::deque<std::unique_ptr<Sample>> buffer_;
    
    /*! The file name */
    std::string fname_;
    
    /*! Wavefile stream object */
    std::ofstream file_;
};

#endif