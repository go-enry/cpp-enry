# cpp-enry
C++ bindings for enry

### Build

- Clone the respository with submodule go-enry v2.8.3
```sh
git clone --recurse-submodules -j8 -b init-impl https://github.com/go-enry/cpp-enry.git

# ... or manually clone go-enry
# git clone -b v2.8.3 https://github.com/go-enry/go-enry.git
```

- Build go-enry as a (static) C library
```sh
cd go-enry
go build -buildmode=c-archive -o go-enry.a ./shared/enry.go
cd ..
```

- Compile your project with C++ bindings (`enry.h`)

```c++
// main.cpp
#include "enry.h"
// ...
int main()
{
    // ...
    std::string lang = enry::GetLanguage("main.cpp", "auto main() -> int { return 0; }"); // C++

    std::string type = enry::GetMimeType("enry.pl", "Perl"); // text/x-perl

    type = enry::GetLanguageType("HTML"); // markup

    bool safe;
    std::tie(lang, safe) = enry::GetLanguageByExtension("enry.h"); // C false

    auto v = enry::GetLanguagesByExtension("enry.pl", "", {});
    for (const auto& it : v) {
        // Perl
        // Prolog
        // Raku
    }

    return 0;
}
```

```sh
g++ main.cpp ./go-enry/go-enry.a \
    --std=c++17 \
    -O2 -Wall \
    -I. -I./go-enry \
    -lpthread
```
