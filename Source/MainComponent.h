#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class PatternEngine;

class MainComponent  : public juce::Component, private juce::OpenGLRenderer
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...
    juce::Slider speedSlider;
    juce::Slider densitySlider;
    
    juce::OpenGLContext openGLContext;
    
    std::unique_ptr<PatternEngine> patternEngine;
    
    void newOpenGLContextCreated() override;
    void renderOpenGL() override;
    void openGLContextClosing() override;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
