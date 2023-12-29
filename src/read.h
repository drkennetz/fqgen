//------------------------------------------------------
//
// read.hpp - module for fastq reads
//
// Author: Dennis Kennetz
//
// Copyright 2023 Dennis Kennetz
//
//------------------------------------------------------

#ifndef READ_H
#define READ_H

#include <string>

//------------------------------------------------------
// FastqRead represents a fastq read
class FastqRead
{
public:
    std::string readname;  // the read name
    std::string sequence;  // the sequence
    std::string plusline;  // the + line (?)
    std::string quality;   // quality score line

    // Constructor
    FastqRead(const std::string& name,
              const std::string& seq,
              const std::string& plus,
              const std::string& qual);

    // Destructor
    virtual ~FastqRead() {};
};

#endif
