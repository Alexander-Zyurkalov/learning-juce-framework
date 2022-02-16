

#include "MainComponent.h"



//==============================================================================
MainComponent::MainComponent ()
{
    addAndMakeVisible(blueComponent);
    slider1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider1.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    slider1.setRange(0.0f, 1.0f);
    slider1.setValue(0.5f);
    addAndMakeVisible(slider1);
    setSize (600, 400);
    setAudioChannels (0, 2);
}

MainComponent::~MainComponent() {
    shutdownAudio();
}
//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
}

void MainComponent::resized()
{
    blueComponent.setBounds(0, 0, this->getWidth(), this->getHeight()/2);
    slider1.setBounds(getWidth() / 2 - 200, getHeight() / 2 - 100, 400, 200);
}

void MainComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate) {}

void MainComponent::getNextAudioBlock(const juce::AudioSourceChannelInfo &bufferToFill) {
    auto level = (float) slider1.getValue();
}

void MainComponent::releaseResources() {}
