void Operator::modulateFrequency(double value)
{
    modOffset_ = Global::tableIncr * value;
}

void Operator::update()
{
    // Normal frequency index increment +
    // Index increment for frequency modulation value
    increment_(indIncr_ + modOffset_);
}