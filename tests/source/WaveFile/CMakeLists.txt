################################################################################
#
# Unit tests for WaveFile class.
#
################################################################################


# .wav files
set(Aquila_TEST_WAVEFILE_8B_MONO "${Aquila_TEST_DATA_PATH}/8b_mono.wav")
set(Aquila_TEST_WAVEFILE_8B_STEREO "${Aquila_TEST_DATA_PATH}/8b_stereo.wav")
set(Aquila_TEST_WAVEFILE_16B_MONO "${Aquila_TEST_DATA_PATH}/16b_mono.wav")
set(Aquila_TEST_WAVEFILE_16B_STEREO "${Aquila_TEST_DATA_PATH}/16b_stereo.wav")


# bits per sample
aquila_test(bits_per_sample)

add_test(bits_per_sample_run bits_per_sample ${Aquila_TEST_WAVEFILE_8B_MONO})
add_test(bits_per_sample_8b bits_per_sample ${Aquila_TEST_WAVEFILE_8B_MONO})
set_tests_properties(bits_per_sample_8b
    PROPERTIES PASS_REGULAR_EXPRESSION "8")
add_test(bits_per_sample_16b bits_per_sample ${Aquila_TEST_WAVEFILE_16B_MONO})
set_tests_properties(bits_per_sample_16b
    PROPERTIES PASS_REGULAR_EXPRESSION "16")


# number of channels
aquila_test(channels)

add_test(channels_run channels ${Aquila_TEST_WAVEFILE_8B_MONO})
add_test(channels_mono channels ${Aquila_TEST_WAVEFILE_16B_MONO})
set_tests_properties(channels_mono
    PROPERTIES PASS_REGULAR_EXPRESSION "1")
add_test(channels_stereo channels ${Aquila_TEST_WAVEFILE_16B_STEREO})
set_tests_properties(channels_stereo
    PROPERTIES PASS_REGULAR_EXPRESSION "2")


# sample frequency
aquila_test(sample_frequency)

add_test(sample_frequency_run sample_frequency ${Aquila_TEST_WAVEFILE_8B_MONO})
add_test(sample_frequency_read sample_frequency ${Aquila_TEST_WAVEFILE_8B_MONO})
set_tests_properties(sample_frequency_read
    PROPERTIES PASS_REGULAR_EXPRESSION "44100")


# wave size
aquila_test(wave_size)

add_test(wave_size_run wave_size ${Aquila_TEST_WAVEFILE_8B_MONO})
add_test(wave_size_8b_mono wave_size ${Aquila_TEST_WAVEFILE_8B_MONO})
set_tests_properties(wave_size_8b_mono
    PROPERTIES PASS_REGULAR_EXPRESSION "4552")

add_test(wave_size_16b_stereo wave_size ${Aquila_TEST_WAVEFILE_16B_STEREO})
set_tests_properties(wave_size_16b_stereo
    PROPERTIES PASS_REGULAR_EXPRESSION "18208")


# samples count
aquila_test(samples_count)

add_test(samples_count_run samples_count ${Aquila_TEST_WAVEFILE_8B_MONO})
add_test(samples_count_8b_mono samples_count ${Aquila_TEST_WAVEFILE_8B_MONO})
set_tests_properties(samples_count_8b_mono
    PROPERTIES PASS_REGULAR_EXPRESSION "4552")

add_test(samples_count_16b_stereo samples_count ${Aquila_TEST_WAVEFILE_16B_STEREO})
set_tests_properties(samples_count_16b_stereo
    PROPERTIES PASS_REGULAR_EXPRESSION "4552")


# audio length
aquila_test(audio_length)

add_test(audio_length_run audio_length ${Aquila_TEST_WAVEFILE_8B_MONO})
add_test(audio_length_read audio_length ${Aquila_TEST_WAVEFILE_8B_MONO})
set_tests_properties(audio_length_read
    PROPERTIES PASS_REGULAR_EXPRESSION "103")


# frames count
aquila_test(frames_count)

add_test(frames_count_run frames_count ${Aquila_TEST_WAVEFILE_8B_MONO})
add_test(frames_count_0_0 frames_count ${Aquila_TEST_WAVEFILE_8B_MONO})
set_tests_properties(frames_count_0_0
    PROPERTIES PASS_REGULAR_EXPRESSION "0")

add_test(frames_count_10_0 frames_count ${Aquila_TEST_WAVEFILE_8B_MONO} 10)
set_tests_properties(frames_count_10_0
    PROPERTIES PASS_REGULAR_EXPRESSION "10")

add_test(frames_count_20_0 frames_count ${Aquila_TEST_WAVEFILE_8B_MONO} 20)
set_tests_properties(frames_count_20_0
    PROPERTIES PASS_REGULAR_EXPRESSION "5")

add_test(frames_count_0_05 frames_count ${Aquila_TEST_WAVEFILE_8B_MONO} 0 0.5)
set_tests_properties(frames_count_0_05
    PROPERTIES PASS_REGULAR_EXPRESSION "0")

add_test(frames_count_10_05 frames_count ${Aquila_TEST_WAVEFILE_8B_MONO} 10 0.5)
set_tests_properties(frames_count_10_05
    PROPERTIES PASS_REGULAR_EXPRESSION "19")

add_test(frames_count_20_066 frames_count ${Aquila_TEST_WAVEFILE_8B_MONO} 20 0.66)
set_tests_properties(frames_count_20_066
    PROPERTIES PASS_REGULAR_EXPRESSION "13")
