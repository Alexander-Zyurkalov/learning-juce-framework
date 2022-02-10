//
// Created by Alexandr Zyurkalov on 09.02.22.
//
#include "juce_core/juce_core.h"
#include "juce_gui_basics/juce_gui_basics.h"

//==============================================================================
class MainWindowTutorialApplication  : public juce::JUCEApplication
{
public:
    //...
    const juce::String getApplicationName() override       { return JUCE_APPLICATION_NAME_STRING; }
    const juce::String getApplicationVersion() override    { return HELLO_1; }
    //==============================================================================
    class MainWindow    : public juce::DocumentWindow
    {
    public:
        MainWindow (juce::String name)  : DocumentWindow (name,
                                                          juce::Colours::lightgrey,
                                                          DocumentWindow::allButtons)
        {
            centreWithSize (300, 200);
            setVisible (true);
        }

        void closeButtonPressed() override
        {
            juce::JUCEApplication::getInstance()->systemRequestedQuit();
        }

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
    };
    void initialise (const juce::String& commandLine) override
    {
        mainWindow.reset (new MainWindow (getApplicationName()));
    }

    void shutdown() override
    {
        mainWindow = nullptr;
    }

private:
    std::unique_ptr<MainWindow> mainWindow;
};


START_JUCE_APPLICATION (MainWindowTutorialApplication)