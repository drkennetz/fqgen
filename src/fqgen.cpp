//------------------------------------------------------
//
// fqgen - a simple library to generate fq's for testing
//         generates single or paired reads
//
// Author: Dennis Kennetz
//
// Copyright 2023 Dennis Kennetz
//
//------------------------------------------------------

#include <iostream>
#include <vector>
#include "read.hpp"

int main() {
    std::vector<FastqRead> reads;

    // Create a sample Fastq read and add it
    FastqRead read1("read1", "AATTCCGG", "+", "FFFFFFFF");

    reads.push_back(read1);

    // Print them
    for (const auto& read : reads) {
        std::cout << read.readname << std::endl;
        std::cout << read.sequence << std::endl;
        std::cout << read.plusline << std::endl;
        std::cout << read.quality << std::endl;
    } 
    return 0;
}