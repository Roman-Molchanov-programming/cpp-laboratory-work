#pragma once

#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <optional>
#include <stdexcept>
#include <string_view>
#include <utility>
#include <vector>

namespace detail {

template <typename T> void printItem(std::ostream &os, const T &item) {
    if constexpr (requires { *item; }) {
        if (item) {
            os << *item;
        } else {
            os << "(пусто)";
        }
    } else {
        os << item;
    }
}

} // namespace detail

template <typename T> class Collection {
  public:
    using value_type = T;
    using iterator = typename std::vector<T>::iterator;
    using const_iterator = typename std::vector<T>::const_iterator;

  private:
    std::vector<T> items;

  public:
    Collection() = default;
    Collection(std::initializer_list<T> init);

    void add(const T &item);
    void add(T &&item);

    bool removeAt(std::size_t index);
    bool remove(const T &item);
    template <typename Pred> std::size_t removeIf(Pred pred);

    T &at(std::size_t index);
    const T &at(std::size_t index) const;
    T &operator[](std::size_t index);
    const T &operator[](std::size_t index) const;

    template <typename Pred> std::optional<std::size_t> findIndex(Pred pred) const;
    template <typename Pred> const T *findIf(Pred pred) const;

    std::size_t size() const;
    bool empty() const;
    void clear();

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    void print(std::ostream &os = std::cout, std::string_view separator = "\n") const;

    friend std::ostream &operator<<(std::ostream &os, const Collection &collection) {
        collection.print(os);
        return os;
    }
};

template <typename T, typename Pred> Collection<T> filter(const Collection<T> &source, Pred pred);
template <typename T, typename Pred> std::size_t countIf(const Collection<T> &source, Pred pred);
template <typename T, typename KeyFunc> const T *maxBy(const Collection<T> &source, KeyFunc key);
template <typename T, typename Compare> void sortBy(Collection<T> &target, Compare comp);

#include "Collection.tpp"