

#include "MainComponent.h"
#include <math.h>


//==============================================================================
MainComponent::MainComponent ()
{
    addAndMakeVisible(blueComponent);
    slider1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider1.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    slider1.setRange(50.0,5000.0, 0.1f);
    slider1.setValue(50.0);
    slider1.setSkewFactorFromMidPoint(500.0);
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

void MainComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate) {
    juce::String message;
    message << "Preparing to play audio...\n";
    message << " samplesPerBlockExpected = " << samplesPerBlockExpected << "\n";
    message << " sampleRate = " << sampleRate;
    juce::Logger::getCurrentLogger()->writeToLog (message);
    currentSampleRate = sampleRate;
    updateAngleDelta();
    slider1.onValueChange = [this]
    {
        if (currentSampleRate > 0.0) {
            updateAngleDelta();
        }
    };
}

void MainComponent::getNextAudioBlock(const juce::AudioSourceChannelInfo &bufferToFill) {
    auto level = 0.125f;
    auto *leftBuffer = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
    auto *rightBuffer = bufferToFill.buffer->getWritePointer(1, bufferToFill.startSample);
    for (auto sampleNum = 0; sampleNum < bufferToFill.numSamples; ++sampleNum) {
        auto currentSampleValue = (float) std::sin(currentAngle);
        currentAngle+=angleDelta;
        leftBuffer[sampleNum] = currentSampleValue * level;
        rightBuffer[sampleNum] = currentSampleValue * level;
    }
}

void MainComponent::releaseResources() {}

void MainComponent::updateAngleDelta() {
    auto cyclesPerSample = slider1.getValue() / currentSampleRate;
    angleDelta = cyclesPerSample * 2.0 * juce::MathConstants<double>::pi;

}
