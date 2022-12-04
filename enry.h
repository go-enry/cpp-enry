// enry.h
#pragma once

#include <go-enry.h>

#include <string_view>
#include <string>
#include <tuple>
#include <vector>

namespace {

inline GoString to_GoString(std::string_view str)
{
    GoString go_string = {
        .p = str.data(),
        .n = static_cast<ptrdiff_t>(str.length())
    };
    return go_string;
}

inline GoSlice to_GoByteSlice(std::string_view str)
{
    GoSlice go_slice = {
        .data = const_cast<char*>(str.data()),
        .len = static_cast<GoInt>(str.length()),
        .cap = static_cast<GoInt>(str.length())
    };
    return go_slice;
}

inline std::vector<std::string> from_GoStringSlice(const GoSlice& go_slice)
{
    std::vector<std::string> vec(go_slice.len);
    auto data = static_cast<char**>(go_slice.data);
    for (GoInt i = 0; i < go_slice.len; ++i) {
        vec[i] = data[i];
    }
    return vec;
}

inline GoSlice to_GoStringSlice(const std::initializer_list<std::string>& lst)
{
    const std::size_t lst_size = lst.size();
    GoSlice go_slice = {
        .data = const_cast<char*>(lst.begin()->data()),
        .len = static_cast<GoInt>(lst_size),
        .cap = static_cast<GoInt>(lst_size)
    };
    return go_slice;
}

} // namespace

namespace enry {

std::string GetLanguage(std::string_view filename, std::string_view content)
{
    GoString go_string = GetLanguage(to_GoString(filename), to_GoByteSlice(content));
    return std::string(go_string.p, go_string.n);
}

std::tuple<std::string, bool> GetLanguageByContent(std::string_view filename, std::string_view content)
{
    GetLanguageByContent_return go_return = GetLanguageByContent(to_GoString(filename), to_GoByteSlice(content));
    return std::make_tuple(std::string(go_return.r0.p, go_return.r0.n), bool(go_return.r1));
}

std::tuple<std::string, bool> GetLanguageByEmacsModeline(std::string_view content)
{
    GetLanguageByEmacsModeline_return go_return = GetLanguageByEmacsModeline(to_GoByteSlice(content));
    return std::make_tuple(std::string(go_return.r0.p, go_return.r0.n), bool(go_return.r1));
}

std::tuple<std::string, bool> GetLanguageByExtension(std::string_view filename)
{
    GetLanguageByExtension_return go_return = GetLanguageByExtension(to_GoString(filename));
    return std::make_tuple(std::string(go_return.r0.p, go_return.r0.n), bool(go_return.r1));
}

std::tuple<std::string, bool> GetLanguageByFilename(std::string_view filename)
{
    GetLanguageByFilename_return go_return = GetLanguageByFilename(to_GoString(filename));
    return std::make_tuple(std::string(go_return.r0.p, go_return.r0.n), bool(go_return.r1));
}

std::tuple<std::string, bool> GetLanguageByModeline(std::string_view content)
{
    GetLanguageByModeline_return go_return = GetLanguageByModeline(to_GoByteSlice(content));
    return std::make_tuple(std::string(go_return.r0.p, go_return.r0.n), bool(go_return.r1));
}

std::tuple<std::string, bool> GetLanguageByShebang(std::string_view content)
{
    GetLanguageByShebang_return go_return = GetLanguageByShebang(to_GoByteSlice(content));
    return std::make_tuple(std::string(go_return.r0.p, go_return.r0.n), bool(go_return.r1));
}

std::tuple<std::string, bool> GetLanguageByVimModeline(std::string_view content)
{
    GetLanguageByVimModeline_return go_return = GetLanguageByVimModeline(to_GoByteSlice(content));
    return std::make_tuple(std::string(go_return.r0.p, go_return.r0.n), bool(go_return.r1));
}

std::vector<std::string> GetLanguageExtensions(std::string_view language)
{
    GoSlice go_slice{};
    GetLanguageExtensions(to_GoString(language), &go_slice);
    return from_GoStringSlice(go_slice);
}

std::vector<std::string> GetLanguages(std::string_view filename, std::string_view content)
{
    GoSlice go_slice{};
    GetLanguages(to_GoString(filename), to_GoByteSlice(content), &go_slice);
    return from_GoStringSlice(go_slice);
}

std::vector<std::string> GetLanguagesByContent(std::string_view filename, std::string_view content, const std::initializer_list<std::string>& candidates = {})
{
    GoSlice go_candidates = to_GoStringSlice(candidates);
    GoSlice go_slice{};
    GetLanguagesByContent(to_GoString(filename), to_GoByteSlice(content), go_candidates, &go_slice);
    std::vector<std::string> vec = from_GoStringSlice(go_slice);
    return vec;
}

std::vector<std::string> GetLanguagesByEmacsModeline(std::string_view filename, std::string_view content, const std::initializer_list<std::string>& candidates = {})
{
    GoSlice go_candidates = to_GoStringSlice(candidates);
    GoSlice go_slice{};
    GetLanguagesByEmacsModeline(to_GoString(filename), to_GoByteSlice(content), go_candidates, &go_slice);
    std::vector<std::string> vec = from_GoStringSlice(go_slice);
    return vec;
}

std::vector<std::string> GetLanguagesByExtension(std::string_view filename, std::string_view content, const std::initializer_list<std::string>& candidates = {})
{
    GoSlice go_candidates = to_GoStringSlice(candidates);
    GoSlice go_slice{};
    GetLanguagesByExtension(to_GoString(filename), to_GoByteSlice(content), go_candidates, &go_slice);
    std::vector<std::string> vec = from_GoStringSlice(go_slice);
    return vec;
}

std::vector<std::string> GetLanguagesByFilename(std::string_view filename, std::string_view content, const std::initializer_list<std::string>& candidates = {})
{
    GoSlice go_candidates = to_GoStringSlice(candidates);
    GoSlice go_slice{};
    GetLanguagesByFilename(to_GoString(filename), to_GoByteSlice(content), go_candidates, &go_slice);
    std::vector<std::string> vec = from_GoStringSlice(go_slice);
    return vec;
}

std::vector<std::string> GetLanguagesByModeline(std::string_view filename, std::string_view content, const std::initializer_list<std::string>& candidates = {})
{
    GoSlice go_candidates = to_GoStringSlice(candidates);
    GoSlice go_slice{};
    GetLanguagesByModeline(to_GoString(filename), to_GoByteSlice(content), go_candidates, &go_slice);
    std::vector<std::string> vec = from_GoStringSlice(go_slice);
    return vec;
}

std::vector<std::string> GetLanguagesByShebang(std::string_view filename, std::string_view content, const std::initializer_list<std::string>& candidates = {})
{
    GoSlice go_candidates = to_GoStringSlice(candidates);
    GoSlice go_slice{};
    GetLanguagesByShebang(to_GoString(filename), to_GoByteSlice(content), go_candidates, &go_slice);
    std::vector<std::string> vec = from_GoStringSlice(go_slice);
    return vec;
}

std::vector<std::string> GetLanguagesByVimModeline(std::string_view filename, std::string_view content, const std::initializer_list<std::string>& candidates = {})
{
    GoSlice go_candidates = to_GoStringSlice(candidates);
    GoSlice go_slice{};
    GetLanguagesByVimModeline(to_GoString(filename), to_GoByteSlice(content), go_candidates, &go_slice);
    std::vector<std::string> vec = from_GoStringSlice(go_slice);
    return vec;
}

std::string GetMimeType(std::string_view path, std::string_view language)
{
    GoString go_string = GetMimeType(to_GoString(path), to_GoString(language));
    return std::string(go_string.p, go_string.n);
}

bool IsBinary(const char *data, std::size_t size)
{
    GoSlice go_slice = {
        .data = const_cast<char*>(data),
        .len = static_cast<GoInt>(size),
        .cap = static_cast<GoInt>(size)
    };
    return bool(IsBinary(go_slice));
}

bool IsConfiguration(std::string_view path)
{
    return bool(IsConfiguration(to_GoString(path)));
}

bool IsDocumentation(std::string_view path)
{
    return bool(IsDocumentation(to_GoString(path)));
}

bool IsDotFile(std::string_view path)
{
    return bool(IsDotFile(to_GoString(path)));
}

bool IsImage(std::string_view path)
{
    return bool(IsImage(to_GoString(path)));
}

bool IsVendor(std::string_view path)
{
    return bool(IsVendor(to_GoString(path)));
}

bool IsGenerated(std::string_view path, std::string_view content)
{
    return bool(IsGenerated(to_GoString(path), to_GoByteSlice(content)));
}

std::string GetColor(std::string_view language)
{
    GoString go_string = GetColor(to_GoString(language));
    return std::string(go_string.p, go_string.n);
}

bool IsTest(std::string_view path)
{
    return bool(IsTest(to_GoString(path)));
}

std::string GetLanguageType(std::string_view language)
{
    GoString go_string = GetLanguageType(to_GoString(language));
    return std::string(go_string.p, go_string.n);
}

} // namespace enry
