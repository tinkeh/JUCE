#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "ComponentCpp11.h"

// C++14 - make_unique() - needs enabling in the Xcode settings - default in MSVC 2015

class MainContentComponent   : public ComponentCpp11
{
public:
    //==============================================================================
    MainContentComponent()
    {
        slider1 = addAndMakeVisible (std::make_unique<Slider>());
        slider2 = addAndMakeVisible (std::make_unique<Slider>());
        button1 = addAndMakeVisible (std::make_unique<TextButton> ("Button 1"));
        button2 = addAndMakeVisible (std::make_unique<TextButton> ("Button 2"));
        
        setSize (400, 300);
    }
    
    ~MainContentComponent()
    {
    }

    void paint (Graphics& g) override
    {
        g.setColour (Colours::wheat);
        g.fillRect (getLocalBounds());
    }
    
    void resized() override
    {
        Rectangle<int> area (getLocalBounds().reduced (8));
        
        slider1->setBounds (area.removeFromTop (30).reduced (2));
        slider2->setBounds (area.removeFromTop (30).reduced (2));
        button1->setBounds (area.removeFromTop (30).reduced (2));
        button2->setBounds (area.removeFromTop (30).reduced (2));
    }

private:
    std::unique_ptr<Slider>     slider1;
    std::unique_ptr<Slider>     slider2;
    std::unique_ptr<TextButton> button1;
    std::unique_ptr<TextButton> button2;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED
