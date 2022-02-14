//
// Created by Alexandr Zyurkalov on 14.02.22.
//

#include "BlueComponent.h"
#include <iostream>

BlueComponent::~BlueComponent() = default;

BlueComponent::BlueComponent() = default;

void BlueComponent::paint(juce::Graphics &g) {
    g.fillAll(juce::Colours::blue);
}

void BlueComponent::resized() {
    Component::resized();
}
