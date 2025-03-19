#include "MainComponent.h"
#include "PatternEngine.hpp"

//==============================================================================
MainComponent::MainComponent()
{
    addAndMakeVisible(speedSlider);
    speedSlider.setRange(0.0, 10.0, 0.01);
    speedSlider.setValue(1.0);
    speedSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 60, 20);
    
    addAndMakeVisible(densitySlider);
    densitySlider.setRange(1, 100, 1);
    densitySlider.setValue(10);
    densitySlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 60, 20);
    
    openGLContext.setRenderer(this);
    openGLContext.attachTo(*this);
    openGLContext.setContinuousRepainting(true);
    
    patternEngine = std::make_unique<PatternEngine>();
    
    setSize (800, 600);
}

MainComponent::~MainComponent()
{
    openGLContext.detach();
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    /*
     g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setFont (juce::Font (16.0f));
    g.setColour (juce::Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
    */
    g.fillAll (juce::Colours::black);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    auto area = getLocalBounds();
    auto sliderHeight = 50;

    speedSlider.setBounds(area.removeFromBottom(sliderHeight).reduced(10));
    densitySlider.setBounds(area.removeFromBottom(sliderHeight).reduced(10));
}

void MainComponent::newOpenGLContextCreated()
{
    // Load shaders, set up OpenGL here if needed
}

void MainComponent::renderOpenGL()
{
    // Update pattern engine with GUI values
    patternEngine->setSpeed(speedSlider.getValue());
    patternEngine->setDensity(densitySlider.getValue());

    // Clear screen
    juce::OpenGLHelpers::clear(juce::Colours::black);

    // Render the pattern (eventually as a texture)
    patternEngine->render();
}

void MainComponent::openGLContextClosing()
{
    // Clean up OpenGL resources if needed
}
