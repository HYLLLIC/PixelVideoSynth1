//
//  PatternEngine.cpp
//  PixelVideoSynth1 - App
//
//  Created by Nate Sparks on 3/16/25.
//

#include "PatternEngine.hpp"

PatternEngine::PatternEngine()
{
    // Initialize OpenGL stuff if needed
}

PatternEngine::~PatternEngine()
{
    // Clean up OpenGL resources
}

void PatternEngine::setSpeed(double newSpeed)
{
    speed = newSpeed;
}

void PatternEngine::setDensity(int newDensity)
{
    density = newDensity;
}

void PatternEngine::render()
{
    // For now, draw a grid of white squares (pixel art style)
    int numCols = density;
    int numRows = density;

    float cellWidth = 2.0f / numCols;  // OpenGL NDC coords: [-1, 1]
    float cellHeight = 2.0f / numRows;

    for (int x = 0; x < numCols; ++x)
    {
        for (int y = 0; y < numRows; ++y)
        {
            float xpos = -1.0f + x * cellWidth;
            float ypos = -1.0f + y * cellHeight;

            // Alternate white/black based on speed + position (simple animation)
            bool on = (std::sin((float)(juce::Time::getMillisecondCounterHiRes() * 0.001 * speed) + x * 0.1 + y * 0.1) > 0);

            juce::OpenGLHelpers::drawRectangle(xpos, ypos, cellWidth, cellHeight, on ? juce::Colours::white : juce::Colours::black);
        }
    }
}
