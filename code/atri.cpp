std::vector<Partial> vec;

double amp = -1;

for(int i = 1; i <= 128; i += 2)
{
  amp = (amp > 0) ? (-1.0/(i*i)) : (1.0/(i*i));

  vec.push_back(Partial(i,amp));
}

double* buffer = additive(vec.begin(), vec.end(), 48000);
