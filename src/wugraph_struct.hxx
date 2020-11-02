#pragma once

#include <vector>

// Represents a weighted, undirected graph
struct WU_graph
{
    ///
    /// TYPE MEMBERS
    ///

    using vertex_t = std::size_t;
    using weight_t = double;

    ///
    /// CONSTANTS (static data members)
    ///

    // Weight value used by member functions to represent the absence
    // of an edge:
    static const weight_t no_edge; // = INFINITY

    ///
    /// CONSTRUCTORS
    ///

    // Constructs a graph with room for `size` vertices.
    explicit WU_graph(size_t size);

    ///
    /// MEMBER FUNCTIONS
    ///

    // Sets the weight of the edge between u and v to w. Providing
    // `WU_graph::no_edge` for w will delete the edge.
    void set_weight(vertex_t u, vertex_t v, weight_t w);

    // Removes the edge between u and v from this graph.
    void remove_edge(vertex_t u, vertex_t v);

    // Returns the number of vertices.
    size_t size() const;

    // Returns the weight of the edge between u and v, which will be
    // WU_graph::no_edge if there is no such edge.
    weight_t get_weight(vertex_t u, vertex_t v) const;

    // Returns whether this graph has an edge between u and v.
    bool has_edge(vertex_t u, vertex_t v) const;

    // Returns the neighbors of u in ascending order in a vector.
    std::vector<vertex_t> get_neighbors(vertex_t u) const;

    /////
    ///// ^^^^^^^^^^ INTERFACE
    ///// IMPLEMENTATION vvvvv
    /////

    ///
    /// A MEMBER FUNCTION INTENDED AS A HELPER
    ///

    std::size_t index(vertex_t u, vertex_t v) const;

    ///
    /// DATA MEMBERS
    ///

    std::size_t           n_vertices;
    std::vector<weight_t> edge_weights;

    // INVARIANT:
    //  - edge_weights.size() == n_vertices * n_vertices
    //  - for all vertex_t u < n_vertices,
    //        edge_weight[index(u, v)] == edge_weight[index(v, u)]
};
