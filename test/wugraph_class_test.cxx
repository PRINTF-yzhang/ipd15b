#include "wugraph_class.hxx"

#include <catch.hxx>

using vertex_t = WU_graph::vertex_t;
using weight_t = WU_graph::weight_t;

// a short name for WU_graph::no_edge, just for testing
const weight_t NE = WU_graph::no_edge;

TEST_CASE("Constructor")
{
    WU_graph(1);
    WU_graph(3);
    WU_graph(10);
}

TEST_CASE("WU_graph::size()")
{
    CHECK(WU_graph(1).size() == 1);
    CHECK(WU_graph(3).size() == 3);
    CHECK(WU_graph(10).size() == 10);
}

TEST_CASE("WU_graph::get_weight()")
{
    WU_graph g3(3);
    CHECK(g3.get_weight(0, 0) == NE);
    CHECK(g3.get_weight(2, 1) == NE);
}

TEST_CASE("WU_graph::set_weight() and get_weight()")
{
    WU_graph g3(3);

    g3.set_weight(0, 1, 15);

    CHECK(g3.get_weight(0, 0) == NE);
    CHECK(g3.get_weight(1, 1) == NE);
    CHECK(g3.get_weight(2, 2) == NE);
    CHECK(g3.get_weight(0, 1) == 15);
    CHECK(g3.get_weight(0, 2) == NE);
    CHECK(g3.get_weight(1, 2) == NE);

    g3.set_weight(1, 2, 1.25e-8);

    CHECK(g3.get_weight(0, 0) == NE);
    CHECK(g3.get_weight(1, 1) == NE);
    CHECK(g3.get_weight(2, 2) == NE);
    CHECK(g3.get_weight(0, 1) == 15);
    CHECK(g3.get_weight(0, 2) == NE);
    CHECK(g3.get_weight(1, 2) == 1.25e-8);

    g3.set_weight(0, 0, 0);

    CHECK(g3.get_weight(0, 0) == 0);
    CHECK(g3.get_weight(1, 1) == NE);
    CHECK(g3.get_weight(2, 2) == NE);
    CHECK(g3.get_weight(0, 1) == 15);
    CHECK(g3.get_weight(0, 2) == NE);
    CHECK(g3.get_weight(1, 2) == 1.25e-8);

    g3.set_weight(1, 2, 3);

    CHECK(g3.get_weight(0, 0) == 0);
    CHECK(g3.get_weight(1, 1) == NE);
    CHECK(g3.get_weight(2, 2) == NE);
    CHECK(g3.get_weight(0, 1) == 15);
    CHECK(g3.get_weight(0, 2) == NE);
    CHECK(g3.get_weight(1, 2) == 3);

    g3.set_weight(1, 2, NE);

    CHECK(g3.get_weight(0, 0) == 0);
    CHECK(g3.get_weight(1, 1) == NE);
    CHECK(g3.get_weight(2, 2) == NE);
    CHECK(g3.get_weight(0, 1) == 15);
    CHECK(g3.get_weight(0, 2) == NE);
    CHECK(g3.get_weight(1, 2) == NE);
}

TEST_CASE("WU_graph::has_edge() and remove_edge()")
{
    WU_graph g3(3);

    for (vertex_t u = 0; u < 3; ++u) {
        for (vertex_t v = 0; v < 3; ++v) {
            g3.set_weight(u, v, 1.0);
        }
    }

    CHECK(g3.has_edge(0, 0));
    CHECK(g3.has_edge(0, 1));
    CHECK(g3.has_edge(1, 2));

    g3.remove_edge(0, 0);

    CHECK(!g3.has_edge(0, 0));
    CHECK(g3.has_edge(0, 1));
    CHECK(g3.has_edge(1, 2));

    g3.remove_edge(0, 1);

    CHECK(!g3.has_edge(0, 0));
    CHECK(!g3.has_edge(0, 1));
    CHECK(g3.has_edge(1, 2));
}

TEST_CASE("WU_graph::get_neighbors")
{
    using vertices_t = std::vector<vertex_t>;

    WU_graph g6(6);

    g6.set_weight(1, 2, 10);
    g6.set_weight(1, 3, 10);
    g6.set_weight(1, 4, 10);

    CHECK(g6.get_neighbors(0) == vertices_t{});
    CHECK(g6.get_neighbors(1) == vertices_t{2, 3, 4});

    g6.set_weight(1, 3, NE);

    CHECK(g6.get_neighbors(1) == vertices_t{2, 4});

    g6.set_weight(1, 5, 10);

    CHECK(g6.get_neighbors(1) == vertices_t{2, 4, 5});

    for (vertex_t u = 0; u < g6.size(); ++u) {
        g6.set_weight(0, u, 10);
    }

    CHECK(g6.get_neighbors(0) == vertices_t{0, 1, 2, 3, 4, 5});
}
