// Define target cpu frequence.
#define F_CPU 8000000

#include <zhele/iopins.h>

using namespace Zhele::IO;

// Connect LED on A4 for this example (or edit example code, it's simple).
int main()
{
    Pa4::Port::Enable();
    Pa4::SetConfiguration(Pa4::Configuration::Out);
    Pa4::SetDriverType(Pa4::DriverType::PushPull);
    Pa4::Clear();

    for (;;)
    {
    }
}