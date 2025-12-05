//
// Created by donghao on 25-11-28.
//
#ifndef IMAGE_HPP
#define IMAGE_HPP
#include "atlas_region_data.hpp"
#include "mapped_region.hpp"

namespace dao {
    /// @brief 图集纹理。
    /// @details 表示纹理图集中的一个纹理区域。
    /// 本类型本身不持有实际纹理数据，只保存纹理名称的枚举值。
    /// 可通过 getAtlasRegion() 获取其所在图集及在图集中的区域数据。
    class AtlasTexture {
    public:
        AtlasTexture() = default;

        /// @brief 构造函数
        /// @param textureName
        /// @param left
        /// @param up
        /// @param right
        /// @param down
        AtlasTexture(const TextureEnum textureName,
                     const float left, const float up, const float right, const float down)
            : m_textureName(textureName), m_boundingBox(left, up, right, down) {
        }

        [[nodiscard]] const TextureEnum &getName() const {
            return m_textureName;
        }

        [[nodiscard]] const BoundingBox &getBoundingBox() const {
            return m_boundingBox;
        }

    private:
        TextureEnum m_textureName = TextureEnum::EmptyTexture;
        BoundingBox m_boundingBox; ///< 纹理要显示的位置
    };
}


#endif //IMAGE_HPP
