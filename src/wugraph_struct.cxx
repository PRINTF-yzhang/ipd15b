#include "wugraph_struct.hxx"

#include <cmath>

const WU_graph::weight_t WU_graph::no_edge = INFINITY;

WU_graph::WU_graph(size_t size)
        : n_vertices(size)
        , edge_weights(size * size, no_edge)
{ }

void WU_graph::set_weight(vertex_t u, vertex_t v, weight_t w)
{
    edge_weights[index(u, v)] = w;
    edge_weights[index(v, u)] = w;
}

void WU_graph::remove_edge(vertex_t u, vertex_t v)
{
    set_weight(u, v, no_edge);
}

size_t WU_graph::size() const
{
    return n_vertices;
}

WU_graph::weight_t
WU_graph::get_weight(vertex_t u, vertex_t v) const
{
    return edge_weights[index(u, v)];
}

bool WU_graph::has_edge(vertex_t u, vertex_t v) const
{
    return get_weight(u, v) != no_edge;
}

std::vector<WU_graph::vertex_t>
WU_graph::get_neighbors(vertex_t u) const
{
    std::vector<vertex_t> result;

    for (vertex_t v = 0; v < n_vertices; ++v) {
        if (has_edge(u, v)) {
            result.push_back(v);
        }
    }

    return result;
}

std::size_t WU_graph::index(vertex_t u, vertex_t v) const
{
    return n_vertices * u + v;
}

/*
 * 15.b.2
 * member access control
 * pubic member are visible to the client code
 * Class members declared as public can be used by any function.
 *
 * Class members declared as private can be used only by member functions and friends
 * (classes or functions) of the class.
 *
 * The default access is private in a class, and public in a struct or union.
 * make data members private so the client code can't access them directly
 * don't give client code the access to the operations that might violates the invariant
 */
