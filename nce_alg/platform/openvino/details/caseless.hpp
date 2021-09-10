// Copyright (C) 2018-2020 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

/**
 * @file
 */

#pragma once
#include <algorithm>
#include <cctype>
#include <functional>
#include <map>
#include <set>
#include <unordered_map>

namespace InferenceEngine {
namespace details {

/**
 * @brief Provides caseless comparison for STL algorithms
 * 
 * @tparam Key type, usually std::string
 */
template <class Key>
class CaselessLess  {
public:
    bool operator()(const Key& a, const Key& b) const noexcept {
        return std::lexicographical_compare(std::begin(a), std::end(a), std::begin(b), std::end(b),
                                            [](const char& cha, const char& chb) {
                                                return std::tolower(cha) < std::tolower(chb);
                                            });
    }
};

/**
 * provides caseless eq for stl algorithms
 * @tparam Key
 */
template <class Key>
class CaselessEq {
public:
    bool operator()(const Key& a, const Key& b) const noexcept {
        return a.size() == b.size() &&
               std::equal(std::begin(a), std::end(a), std::begin(b), [](const char& cha, const char& chb) {
                   return std::tolower(cha) == std::tolower(chb);
               });
    }
};

/**
 * To hash caseless
 */
template <class T>
class CaselessHash : public std::hash<T> {
public:
    size_t operator()(T __val) const noexcept {
        T lc;
        std::transform(std::begin(__val), std::end(__val), std::back_inserter(lc), [](typename T::value_type ch) {
            return std::tolower(ch);
        });
        return std::hash<T>()(lc);
    }
};

template <class Key, class Value>
using caseless_unordered_map = std::unordered_map<Key, Value, CaselessHash<Key>, CaselessEq<Key>>;

template <class Key, class Value>
using caseless_unordered_multimap = std::unordered_multimap<Key, Value, CaselessHash<Key>, CaselessEq<Key>>;

template <class Key, class Value>
using caseless_map = std::map<Key, Value, CaselessLess<Key>>;

template <class Key>
using caseless_set = std::set<Key, CaselessLess<Key>>;

}  // namespace details
}  // namespace InferenceEngine
