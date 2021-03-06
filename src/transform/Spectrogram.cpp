/**
 * @file Spectrogram.cpp
 *
 * Spectrogram calculation.
 *
 * This file is part of the Aquila DSP library.
 * Aquila is free software, licensed under the MIT/X11 License. A copy of
 * the license is provided with the library in the LICENSE file.
 *
 * @package Aquila
 * @version 3.0.0-dev
 * @author Zbigniew Siciarz
 * @date 2007-2011
 * @license http://www.opensource.org/licenses/mit-license.php MIT
 * @since 3.0.0
 */

#include "Spectrogram.h"
#include "FftFactory.h"
#include "../source/Frame.h"
#include <cstring> // for memset

namespace Aquila
{
    Spectrogram::Spectrogram(FramesCollection& frames):
        m_frameCount(frames.count()),
        m_spectrumSize(frames.getSamplesPerFrame()),
        // the following line converts an auto_ptr<Fft> returned by getFft
        // to a shared_ptr<Fft> stored in m_fft class member
        m_fft(FftFactory::getFft(m_spectrumSize).release()),
        m_data(new SpectrogramDataType(m_frameCount))
    {
        std::size_t i = 0;

        ComplexType* spectrumArray = new ComplexType[m_spectrumSize];
        for (FramesCollection::iterator iFrame = frames.begin(); iFrame != frames.end(); ++iFrame, ++i)
        {
            // a reference to ease typing
            SpectrumType& frameSpectrum = (*m_data)[i];
            std::memset(spectrumArray, 0, m_spectrumSize * sizeof(ComplexType));
            m_fft->fft(iFrame->toArray(), spectrumArray);
            frameSpectrum.assign(spectrumArray, spectrumArray + m_spectrumSize);
        }

        delete [] spectrumArray;
    }
}
