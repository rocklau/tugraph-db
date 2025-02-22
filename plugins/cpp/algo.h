/* Copyright (c) 2022 AntGroup. All Rights Reserved. */

#pragma once

#include "lgraph/lgraph_olap.h"

using namespace lgraph_api;
using namespace lgraph_api::olap;

/**
 * \brief   Perform a BFS from root vertex.
 *
 * \param               graph    The graph to compute on.
 * \param               root_vid    The root vertex id to start bfs from.
 * \param   [in,out]    parent    The ParallelVector to judge whether have visited.
 *
 * \return  The number of visited vertices of graph.
 */
size_t BFSCore(Graph<Empty>& graph, size_t root_vid, ParallelVector<size_t>& parent);

/**
 * \brief   Compute the PageRank value.
 *
 * \param               graph    The graph to compute on.
 * \param               num_iterations  The number of iterations.
 * \param   [in,out]    curr     The ParallelVector to store pr value.
 *
 */
void PageRankCore(Graph<Empty>& graph, int num_iterations, ParallelVector<double>& curr);

/**
 * \brief   Perform a SSSP from root vertex and return the result.
 *
 * \param               graph    The graph to compute on.
 * \param               root    The root vertex id to start sssp from.
 * \param   [in,out]    distance   The ParallelVector to store distance.
 */
void SSSPCore(Graph<double>& graph, size_t root, ParallelVector<double>& distance);

/**
 * \brief   Compute the weakly connected components.
 *
 * \param               graph   The graph to compute on, should be an *undirected* graph.
 * \param   [in,out]    label   the ParallelVector to store wcc_label.
 */
void WCCCore(Graph<Empty>& graph, ParallelVector<size_t>& label);

/**
 * \brief    Comoute the clustering coefficient of all vertices in the graph.
 *
 * \param    graph    The graph to compute on.
 * \param    score    The vector to store clustering coefficient.
 *
 * \return    return the clustering coefficient of graph.
 */
double LCCCore(Graph<Empty>& graph, ParallelVector<double>& score);

/**
 * \brief    Comoute the label propagation algorithm.
 *
 * \param    graph    The graph to compute on.
 * \param    num_iterations    The iterations of label propagation algorithm.
 * \param    sync_flag    synchronous mode -> 1, Asynchronous mode -> 0.
 *
 * \return    The value of modularity.
 */
double LPACore(Graph<Empty>& graph, int num_iterations, bool sync_flag);

