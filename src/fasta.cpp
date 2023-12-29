#include "fasta.h"

std::string Fasta::FetchSeq(const std::string& chrom, int start, int stop) const
{
    std::lock_guard<std::mutex> lock(faMutex_);
    int length = 0;
    char* sequence = faidx_fetch_seq(faidx_, chrom.c_str(), start, stop, length);
    if (seq == nullptr)
    {
        throw std::runtime_error(
            "Unable to fetch seq at region: " + chrom.c_str() +
            " start: " + std::string(start) + " stop: " + std::string(stop));
    }
    /**
     * From HTSLib Documentation:
     * The returned sequence is allocated by `malloc()`
     * family and should be destroyed by end users by
     * calling `free()` on it.
     **/
    std::string result(seq);
    free(seq);

    return result;
}
