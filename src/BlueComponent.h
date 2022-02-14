//
// Created by Alexandr Zyurkalov on 14.02.22.
//
#pragma once

#include "juce_core/juce_core.h"
#include "juce_gui_basics/juce_gui_basics.h"


class BlueComponent : public juce::Component {
public:
    BlueComponent();
    ~BlueComponent() override;

    void resized() override;

    void paint(juce::Graphics &g) override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BlueComponent)
};


