cmake_minimum_required(VERSION 3.15)
project(LEARNING_JUCE_FRAMEWORK VERSION 0.0.1 LANGUAGES CXX)
add_subdirectory(libs/JUCE)
juce_add_console_app(learning_juce_framework PRODUCT_NAME "Console App Example")
#add_executable(learning_juce_framework src/main.cpp)
target_sources(learning_juce_framework PRIVATE src/Main.cpp)
target_compile_definitions(learning_juce_framework
        PRIVATE
            JUCE_WEB_BROWSER=0
            JUCE_USE_CURL=0
        )
target_link_libraries(learning_juce_framework
        PRIVATE
            juce::juce_core
        )