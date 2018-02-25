#pragma once

#include "mod/sample.hpp"

class NoteMixer
{
    Sample& m_sample; // The sample object we interpolate on.
    size_t m_startOffset = 0; // Where in the sample data should we start?
    double m_scaleFactor = 1.0; // How much are we warping its play speed by?

    public:
    NoteMixer(Sample& s, double sf = 1.0, size_t startOffset = 0) : 
        m_sample(s),
        m_startOffset(startOffset),
        m_scaleFactor(sf) {}

    uint8_t at(size_t index) const; // TODO: Consider templating this for the return type.
    size_t size() const { return m_sample.sampleData.size() / m_scaleFactor; }

};

