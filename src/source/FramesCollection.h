/**
 * @file FramesCollection.h
 *
 * A lightweight wrapper for a vector of Frames.
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

#ifndef FRAMESCOLLECTION_H
#define FRAMESCOLLECTION_H

#include "../global.h"
#include "Frame.h"
#include "SignalSource.h"
#include <cstddef>
#include <vector>

namespace Aquila
{
    /**
     * A lightweight wrapper for a vector of Frames.
     *
     * This class is neccessary to perform signal division into frames,
     * which are then stored in container (currently std::vector). The frame
     * objects are stored by value as they are very light and cheap to copy.
     *
     * The reason this wrapper was created is to create some abstraction for
     * groups of frames, which can by saved or processed together. For example,
     * a spectrogram is an array of spectra calculated individually for each
     * frame. Sometimes the calculation doesn't involve the whole signal,
     * so a part of it is divided into frames, stored in a FramesCollection
     * and then processed.
     *
     * Individual frame objects can by accessed by iterating over the collection
     * using begin() and end() methods. These calls simply return iterators
     * pointing to the underlying container.
     */
    class AQUILA_EXPORT FramesCollection
    {
        /**
         * Internal storage type.
         */
        typedef std::vector<Frame> Container;

    public:
        /**
         * An iterator for the collection.
         */
        typedef Container::iterator iterator;

        /**
         * A const iterator for the collection.
         */
        typedef Container::const_iterator const_iterator;

        FramesCollection();
        FramesCollection(const SignalSource& source,
                         unsigned int samplesPerFrame,
                         unsigned int samplesPerOverlap = 0);
        ~FramesCollection();

        void divideFrames(const SignalSource& source,
                          unsigned int samplesPerFrame,
                          unsigned int samplesPerOverlap = 0);
        void clear();

        /**
         * Returns number of frames in the collection.
         *
         * @return frames' container size
         */
        std::size_t count() const
        {
            return m_frames.size();
        }

        /**
         * Returns number of samples in each frame.
         *
         * @return frame size in samples
         */
        unsigned int getSamplesPerFrame() const
        {
            return m_samplesPerFrame;
        }

        /**
         * Returns an iterator pointing to the first frame.
         *
         * @return iterator
         */
        iterator begin()
        {
            return m_frames.begin();
        }

        /**
         * Returns a const iterator pointing to the first frame.
         *
         * @return iterator
         */
        const_iterator begin() const
        {
            return m_frames.begin();
        }

        /**
         * Returns an iterator pointing one-past-last frame.
         *
         * @return iterator
         */
        iterator end()
        {
            return m_frames.end();
        }

        /**
         * Returns a const iterator pointing one-past-last frame.
         *
         * @return iterator
         */
        const_iterator end() const
        {
            return m_frames.end();
        }

    private:
        /**
         * Frames container.
         */
        Container m_frames;

        /**
         * Number of samples in each frame.
         */
        unsigned int m_samplesPerFrame;
    };
}

#endif // FRAMESCOLLECTION_H
