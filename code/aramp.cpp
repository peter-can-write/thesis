std::vector<Partial> vec;
     
for (int i = 1; i < 64; ++i)
{
  vec.push_back(Partial(i, -1.0/i));
}

double* buffer = additive(vec.begin(), vec.end(), 48000)
