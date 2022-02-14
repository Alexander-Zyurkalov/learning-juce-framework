

#include "MainComponent.h"



//==============================================================================
MainComponent::MainComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]
    addAndMakeVisible(blueComponent);
    blueComponent.setBounds(200, 100, 400, 400);

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

}
