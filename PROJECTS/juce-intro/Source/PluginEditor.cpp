/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
JuceIntroAudioProcessorEditor::JuceIntroAudioProcessorEditor (JuceIntroAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 200);
    
    crumble.setSliderStyle (juce::Slider::LinearBarVertical);
    crumble.setRange (1, 50, 1);
    crumble.setTextBoxStyle (juce::Slider::NoTextBox, false, 90, 0);
    crumble.setPopupDisplayEnabled (true, false, this);
    crumble.setTextValueSuffix (" crumble");
    crumble.setValue(5);
     
    addAndMakeVisible (&crumble);
    
    crumble.addListener(this);
}

void JuceIntroAudioProcessorEditor::sliderValueChanged (juce::Slider* slider)
{
    audioProcessor.crumbleVal = crumble.getValue();
}

JuceIntroAudioProcessorEditor::~JuceIntroAudioProcessorEditor()
{
}

//==============================================================================
void JuceIntroAudioProcessorEditor::paint (juce::Graphics& g)
{
    // fill the whole window white
    g.fillAll (juce::Colours::white);
 
    // set the current drawing colour to black
    g.setColour (juce::Colours::black);
 
    // set the font size and draw text to the screen
    g.setFont (15.0f);
 
    g.drawFittedText ("how much crust u want?", 0, 0, getWidth(), 30, juce::Justification::centred, 1);
}

void JuceIntroAudioProcessorEditor::resized()
{
    crumble.setBounds (40, 30, 20, getHeight() - 60);
}
