//
// Created by donghao on 25-12-8.
//
#include "../include/test_page.hpp"
#include <component/rectangle.hpp>

std::vector<uint32_t> TestPage::registerTexture() const {
    std::vector registerTexture{
        texture::food_apple,
        texture::food_banana,
    };
    return registerTexture;
}

void TestPage::update() {
    m_atlasVertexBatchBuilder.clearDrawBatches();

    m_atlasVertexBatchBuilder.addToBatch(appleImg);

    m_atlasVertexBatchBuilder.addToBatch(bananaImg);

    rectangle2.writeToBatch(m_atlasVertexBatchBuilder);

    rectangle3.writeToBatch(m_atlasVertexBatchBuilder);

    for (int i = 0; i < 10000; ++i) {
        rectangle.writeToBatch(m_atlasVertexBatchBuilder);
    }
}

const std::vector<dao::AtlasDrawBatch> &TestPage::getDrawBatches() const {
    return m_atlasVertexBatchBuilder.getDrawBatches();
}
