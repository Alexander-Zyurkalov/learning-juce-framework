

#include "MainComponent.h"



//==============================================================================
MainComponent::MainComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]
    addAndMakeVisible(blueComponent);
    setSize (600, 400);

}

MainComponent::~MainComponent() {
}
//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
}

void MainComponent::resized()
{
    blueComponent.setBounds(0, 0, this->getWidth(), this->getHeight()/2);
}
