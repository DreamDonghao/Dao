//
// Created by donghao on 25-12-12.
//
#ifndef BUTTON_STYLE_HPP
#define BUTTON_STYLE_HPP
#include "button.hpp"
#include "drawable.hpp"

namespace dao {
    class ButtonStyle : Drawable {
    public:
        ~ButtonStyle() override = default;

        void writeToBatch(VertexBatchBuilder &builder) const override = 0;

        virtual void bindButton(Button *button) = 0;
    };
}
#endif //BUTTON_STYLE_HPP
