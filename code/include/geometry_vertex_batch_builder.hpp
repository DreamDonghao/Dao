//
// Created by donghao on 25-12-5.
//
#ifndef GEOMETRY_VERTEX_BATCH_BUILDER_HPP
#define GEOMETRY_VERTEX_BATCH_BUILDER_HPP
#include <SDL3/SDL.h>
#include <vector>

namespace dao {
    class GeometryVertexBatchBuilder {
    public:
        void addToBatch(std::vector<SDL_Vertex> &vertices) {
            m_vertices.reserve(m_vertices.size() + vertices.size());
            m_vertices.insert(m_vertices.end(), vertices.begin(), vertices.end());
        }

    private:
        std::vector<SDL_Vertex> m_vertices;
    };
} // dao

#endif //GEOMETRY_VERTEX_BATCH_BUILDER_HPP
