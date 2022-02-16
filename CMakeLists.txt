cmake_minimum_required(VERSION 3.15)
project(LEARNING_JUCE_FRAMEWORK VERSION 0.0.1 LANGUAGES CXX)
add_subdirectory(libs/JUCE)
juce_add_gui_app(learning_juce_framework PRODUCT_NAME "Gui App Example")
target_sources(learning_juce_framework PRIVATE src/Main.cpp src/MainComponent.cpp src/BlueComponent.cpp)
target_compile_definitions(learning_juce_framework
        PRIVATE
            JUCE_WEB_BROWSER=0
            JUCE_USE_CURL=0
            JUCE_APPLICATION_NAME_STRING="hello world"
            HELLO_1="hello 1"
        )
target_link_libraries(learning_juce_framework
        PRIVATE
            juce::juce_audio_utils
            juce::juce_gui_basics
        )