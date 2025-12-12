//
// Created by donghao on 25-12-12.
//
#ifndef BUTTON_HPP
#define BUTTON_HPP
#include <SDL3/SDL_events.h>

namespace dao {
    /// @brief 按钮状态
    enum class ButtonStatus {
        Disabled, ///< 禁用
        Normal,   ///< 自然
        Hover,    ///< 悬停
        Pressed,  ///< 按下
    };

    class Button {
    public:
        virtual ~Button() = default ;

        virtual void update(const SDL_Event &event) = 0;

        [[nodiscard]] virtual ButtonStatus getStatus() const = 0;
    };
}
#endif //BUTTON_HPP
