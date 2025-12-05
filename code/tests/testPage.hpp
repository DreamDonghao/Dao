//
// Created by donghao on 25-11-28.
//
#ifndef TESTPAGE_HPP
#define TESTPAGE_HPP
#include "page.hpp"

namespace name_ {
    class TestPage final : public Page {
        AtlasVertexBatchBuilder m_atlasVertexBatchBuilder;
        TextureData im{TextureEnum::food_apple, 0, 0, 100, 100};
        TextureData im1{TextureEnum::food_banana, 100, 0, 200, 100};

    public:
        explicit TestPage(std::string title): Page(std::move(title)) {
        }

        std::vector<TextureEnum> registerTexture() const override {
            std::vector registerTexture{
                TextureEnum::food_apple,
                TextureEnum::food_banana,
            };
            return registerTexture;
        }

        void update() override {
            m_atlasVertexBatchBuilder.clearDrawBatches();
            for (int i = 0; i < 30; ++i) {
                for (int j = 0; j < 200; ++j) {
                    m_atlasVertexBatchBuilder.addToBatch(im);
                }
                for (int j = 0; j < 200; ++j) {
                    m_atlasVertexBatchBuilder.addToBatch(im1);
                }
            }
        }

        [[nodiscard]] const std::vector<AtlasDrawBatch> &getDrawBatches() const override {
            return m_atlasVertexBatchBuilder.getDrawBatches();
        }

    private:
    };
}

#endif //TESTPAGE_HPP
