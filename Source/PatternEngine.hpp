//
//  PatternEngine.hpp
//  PixelVideoSynth1 - App
//
//  Created by Nate Sparks on 3/16/25.
//

#pragma once

#include <JuceHeader.h>

class PatternEngine
{
    public:
        PatternEngine();
        ~PatternEngine();

        void setSpeed(double newSpeed);
        void setDensity(int newDensity);

        void render();

    private:
        double speed = 1.0;
        int density = 10;

        // Later: you can add textures, shaders, framebuffers, etc.
}
