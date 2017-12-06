#pragma once

#include <cstdint>

namespace Sound
{
    void init(unsigned sampleRate);
    void playRaw(int8_t *samples, unsigned bufferSizeInBytes);
};