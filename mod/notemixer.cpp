#include "mod/notemixer.hpp"
#include "mod/note.hpp"
#include "mod/song.hpp"

#include "wordreader.hpp"

#include <iostream>

unsigned NoteMixer::playRate = 0;

NoteMixer NoteMixer::Create(Song& from, uint32_t data)
{
    Note n(data);
    return NoteMixer(from.getInstrument(n.index()), n.sampleRate() / static_cast<double>(NoteMixer::playRate));
}

////////////////////////////////////////////////////////////////////////////////
// NoteMixer function definitions.
////////////////////////////////////////////////////////////////////////////////

uint8_t NoteMixer::at(size_t index) const
{
    size_t scaledIndex = index * m_scaleFactor;

    if (scaledIndex < NoteMixer::size())
    {
        return m_sample.sampleData.at(scaledIndex);
    }
    else // We need to look at where to jump to because we've been asked for a value
        // outside of the sample's actual indices.
    {
        size_t idx = (scaledIndex % m_jumpPosition) + m_jumpPosition;

        return m_sample.sampleData.at(idx);
    }
}

uint8_t NoteMixer::next() 
{
    return NoteMixer::at(m_index++);
}
