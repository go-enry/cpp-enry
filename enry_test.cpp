// enry_test.cpp

#include "enry.h"

#define DEBUG
#include <cassert>

#include <algorithm>

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

    auto exts = enry::GetLanguageExtensions("Prolog");
    assert(exts.size() > 0);
    assert(std::count(exts.begin(), exts.end(), ".pl") == 1);
    assert(std::count(exts.begin(), exts.end(), ".pro") == 1);
    assert(std::count(exts.begin(), exts.end(), ".prolog") == 1);

    auto langs = enry::GetLanguagesByModeline("modeline", "/* vim: set syntax=python ft=python filetype=python */", { "Python", "vim" });
    assert(langs.size() > 0);
    assert(langs.at(0).compare("Python") == 0);

    return 0;
}
