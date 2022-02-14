#pragma once

#include "juce_core/juce_core.h"
#include "juce_gui_basics/juce_gui_basics.h"
#include "BlueComponent.h"



class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent ();
    ~MainComponent() override;

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    BlueComponent blueComponent;
    juce::Slider slider1;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};


