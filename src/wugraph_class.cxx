#include "wugraph_class.hxx"

#include <cmath>

const WU_graph::weight_t WU_graph::no_edge = INFINITY;

WU_graph::WU_graph(size_t size)
        : n_vertices_(size)
        , edge_weights_(size * size, no_edge)
{ }

void WU_graph::set_weight(vertex_t u, vertex_t v, weight_t w)
{
    edge_weights_[index_(u, v)] = w;
}

void WU_graph::remove_edge(vertex_t u, vertex_t v)
{
    set_weight(u, v, no_edge);
}

size_t WU_graph::size() const
{
    return n_vertices_;
}

WU_graph::weight_t
WU_graph::get_weight(vertex_t u, vertex_t v) const
{
    return edge_weights_[index_(u, v)];
}

bool WU_graph::has_edge(vertex_t u, vertex_t v) const
{
    return get_weight(u, v) != no_edge;
}

std::vector<WU_graph::vertex_t>
WU_graph::get_neighbors(vertex_t u) const
{
    std::vector<vertex_t> result;

    for (vertex_t v = 0; v < n_vertices_; ++v) {
        if (has_edge(u, v)) {
            result.push_back(v);
        }
    }

    return result;
}

std::size_t WU_graph::index_(vertex_t u, vertex_t v) const
{
    return n_vertices_ * u + v;
}

