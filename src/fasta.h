#include <mutex>
#include <stdexcept>
#include <string>

#include "htslib/faidx.h"

/// @brief Class for loading fasta files and getting fetching region specific seqs.
class Fasta
{
public:
    explicit Fasta(const std::string& fastaFile)
    {
        faidx_ = fai_load(fastaFile.c_str());
        if (faidx_ == nullptr)
        {
            throw std::runtime_error("Unable to load fasta file: " +
                                     fastaFile.c_str());
        }
    }
    ~Fasta() { fai_destroy(faidx_) };

    /// @brief Fetches sequence given chromosome, start and stop.
    /// @in chrom The input chromosome / region name.
    /// @in start The start position (0-based).
    /// @in stop  The stop position (0-based).
    /// @return the sequence.
    std::string FetchSeq(const std::string& chrom, int start, int stop) const;

private:
    faidx_t* faidx_;
    std::mutex faMutex_;
};
