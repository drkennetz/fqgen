#include "read.h"

// Constuctor impl
FastqRead::FastqRead(const std::string& name,
                     const std::string& seq,
                     const std::string& plus,
                     const std::string& qual)
    : readname(name)
    , sequence(seq)
    , plusline(plus)
    , quality(qual)
{
}
