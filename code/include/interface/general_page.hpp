//
// Created by donghao on 25-12-20.
//
#ifndef GENERAL_PAGE_HPP
#define GENERAL_PAGE_HPP
#include "page.hpp"
#include <utility>

namespace dao {
    class GeneralPage : public Page {
    public:
        explicit GeneralPage(std::string title): m_title(std::move(title)) {
        }

        [[nodiscard]] const std::vector<AtlasDrawBatch> &getDrawBatches() const override {
            return m_vertexBatch.getDrawBatches();
        }

        GlyphAtlas &getGlyphAtlas() override {
            return m_vertexBatch.getGlyphAtlas();
        }

        PageCmdQueue &getEvent() override {
            return m_event;
        }

        [[nodiscard]] const std::string &getTitle() const override {
            return m_title;
        }

    protected:
        std::string m_title;
        PageCmdQueue m_event;
        VertexBatchBuilder m_vertexBatch{"zh-cn.ttf", 64, 1024};
    };
}
#endif //GENERAL_PAGE_HPP
