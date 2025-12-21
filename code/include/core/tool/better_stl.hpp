//
// Created by donghao on 25-12-9.
//
#ifndef BETTER_STL_HPP
#define BETTER_STL_HPP
#include <cstdint>
#include <algorithm>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <utf8cpp/utf8/checked.h>

namespace dao {
    using int8 = int8_t;
    using int16 = int16_t;
    using int32 = int32_t;
    using int64 = int64_t;
    using uint8 = uint8_t;
    using uint16 = uint16_t;
    using uint32 = uint32_t;
    using uint64 = uint64_t;
    using float32 = float;

    template<typename K, typename V>
    using hash_map = std::unordered_map<K, V>;

    template<typename Container>
    void sort(Container &container) {
        std::sort(container.begin(), container.end());
    }

    inline void detectionError(const bool pass, const std::string_view &message) {
        if (!pass) {
            std::cerr << message << std::endl;
        }
    }

    inline void pop_utf8(std::string &input) {
        std::u32string u32;
        utf8::utf8to32(input.begin(), input.end(), std::back_inserter(u32));
        if (!u32.empty()) {
            u32.pop_back();
        }
        std::string out;
        utf8::utf32to8(u32.begin(), u32.end(), std::back_inserter(out));
        input = std::move(out);
    }

    /// @brief 结果为浮点数的除法
    template<typename T>
        requires std::is_arithmetic_v<T> // 约束为整数或浮点类型
    float32 ratio(T a, T b) {
        return static_cast<float32>(a) / static_cast<float32>(b);
    }

    /// @brief 可控删除器
    /// @details 可以为std::unique_ptr 提供一个删除器，使其可以有观察者与管理者两种状态
    template<typename T>
    class SwitchDeleter {
    public:
        enum Mode { Observe, Manage };

        explicit SwitchDeleter(const Mode m = Manage) : mode(m) {
        }

        void operator()(const T *ptr) const noexcept {
            if (mode == Manage) {
                delete ptr;
            }
        }

        void setMode(Mode m) { mode = m; }
        Mode getMode() const { return mode; }

    private:
        Mode mode;
    };

    /// @brief 观察者构建器
    template<typename T>
    auto makeObserver(T *ptr) {
        return std::unique_ptr<T, SwitchDeleter<T> >(
            ptr, SwitchDeleter<T>(SwitchDeleter<T>::Observe)
        );
    }

    /// @brief 管理者构建器
    template<typename T>
    auto makeManage(T *ptr) {
        return std::unique_ptr<T, SwitchDeleter<T> >(
            ptr, SwitchDeleter<T>(SwitchDeleter<T>::Manage)
        );
    }
}
#endif //BETTER_STL_HPP
