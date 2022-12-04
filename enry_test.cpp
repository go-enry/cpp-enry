// enry_test.cpp

#include "enry.h"

#define DEBUG
#include <cassert>

int main()
{
    std::string lang = enry::GetLanguage("main.cpp", "auto main() -> int { return 0; }"); // C++
    assert(lang.compare("C++") == 0);

    std::string type = enry::GetMimeType("enry.pl", "Perl"); // text/x-perl
    assert(type.compare("text/x-perl") == 0);

    type = enry::GetLanguageType("HTML"); // markup
    assert(type.compare("markup") == 0);

    bool safe;
    std::tie(lang, safe) = enry::GetLanguageByExtension("enry.h"); // C false
    assert(!safe && lang.compare("C") == 0);

    return 0;
}
