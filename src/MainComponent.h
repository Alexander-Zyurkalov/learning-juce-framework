#pragma once

#include "juce_core/juce_core.h"
#include "juce_gui_basics/juce_gui_basics.h"
#include "juce_audio_utils/juce_audio_utils.h"
#include "BlueComponent.h"



class MainComponent  : public juce::AudioAppComponent
{
public:
    //==============================================================================
    MainComponent ();
    ~MainComponent() override;

    void paint (juce::Graphics& g) override;
    void resized() override;

    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;

    void getNextAudioBlock(const juce::AudioSourceChannelInfo &bufferToFill) override;

    void releaseResources() override;

private:
    BlueComponent blueComponent;
    juce::Slider slider1;
    juce::Random random;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};


