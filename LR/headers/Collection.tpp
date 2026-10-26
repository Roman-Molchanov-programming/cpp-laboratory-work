#pragma once

template <typename T> Collection<T>::Collection(std::initializer_list<T> init) : items(init) {
}

template <typename T> void Collection<T>::add(const T &item) {
    items.push_back(item);
}

template <typename T> void Collection<T>::add(T &&item) {
    items.push_back(std::move(item));
}

template <typename T> bool Collection<T>::removeAt(std::size_t index) {
    if (index >= items.size()) {
        return false;
    }
    items.erase(items.begin() + static_cast<std::ptrdiff_t>(index));
    return true;
}

template <typename T> bool Collection<T>::remove(const T &item) {
    auto it = std::find(items.begin(), items.end(), item);
    if (it == items.end()) {
        return false;
    }
    items.erase(it);
    return true;
}

template <typename T> template <typename Pred> std::size_t Collection<T>::removeIf(Pred pred) {
    auto it = std::remove_if(items.begin(), items.end(), pred);
    auto removed = static_cast<std::size_t>(std::distance(it, items.end()));
    items.erase(it, items.end());
    return removed;
}

template <typename T> T &Collection<T>::at(std::size_t index) {
    if (index >= items.size()) {
        throw std::out_of_range("Collection: индекс вне диапазона");
    }
    return items[index];
}

template <typename T> const T &Collection<T>::at(std::size_t index) const {
    if (index >= items.size()) {
        throw std::out_of_range("Collection: индекс вне диапазона");
    }
    return items[index];
}

template <typename T> T &Collection<T>::operator[](std::size_t index) {
    return items[index];
}

template <typename T> const T &Collection<T>::operator[](std::size_t index) const {
    return items[index];
}

template <typename T>
template <typename Pred>
std::optional<std::size_t> Collection<T>::findIndex(Pred pred) const {
    auto it = std::find_if(items.begin(), items.end(), pred);
    if (it == items.end()) {
        return std::nullopt;
    }
    return static_cast<std::size_t>(std::distance(items.begin(), it));
}

template <typename T> template <typename Pred> const T *Collection<T>::findIf(Pred pred) const {
    auto it = std::find_if(items.begin(), items.end(), pred);
    return it == items.end() ? nullptr : &*it;
}

template <typename T> std::size_t Collection<T>::size() const {
    return items.size();
}

template <typename T> bool Collection<T>::empty() const {
    return items.empty();
}

template <typename T> void Collection<T>::clear() {
    items.clear();
}

template <typename T> typename Collection<T>::iterator Collection<T>::begin() {
    return items.begin();
}

template <typename T> typename Collection<T>::iterator Collection<T>::end() {
    return items.end();
}

template <typename T> typename Collection<T>::const_iterator Collection<T>::begin() const {
    return items.begin();
}

template <typename T> typename Collection<T>::const_iterator Collection<T>::end() const {
    return items.end();
}

template <typename T>
void Collection<T>::print(std::ostream &os, std::string_view separator) const {
    bool first = true;
    for (const auto &item : items) {
        if (!first) {
            os << separator;
        }
        detail::printItem(os, item);
        first = false;
    }
}

template <typename T, typename Pred> Collection<T> filter(const Collection<T> &source, Pred pred) {
    Collection<T> result;
    for (const auto &item : source) {
        if (pred(item)) {
            result.add(item);
        }
    }
    return result;
}

template <typename T, typename Pred> std::size_t countIf(const Collection<T> &source, Pred pred) {
    std::size_t count = 0;
    for (const auto &item : source) {
        if (pred(item)) {
            ++count;
        }
    }
    return count;
}

template <typename T, typename KeyFunc> const T *maxBy(const Collection<T> &source, KeyFunc key) {
    if (source.empty()) {
        return nullptr;
    }
    const T *best = &source[0];
    for (const auto &item : source) {
        if (key(item) > key(*best)) {
            best = &item;
        }
    }
    return best;
}

template <typename T, typename Compare> void sortBy(Collection<T> &target, Compare comp) {
    std::sort(target.begin(), target.end(), comp);
}