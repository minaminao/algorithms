# Algorithms and Data Structures

C++, Python などによるアルゴリズムとデータ構造の実装・説明・スニペット。

GitHub 上で Jupyter Notebook のファイルが

> Sorry, something went wrong. Reload?

となる場合は、[nbviewer](https://nbviewer.jupyter.org/github/minaminao/algorithms/tree/master/) で見れる。

## Combinatorics / 組合せ数学
- [Combinatorics](Combinatorics/Combinatorics.cpp)
- [Factorial](Combinatorics/Factorial.cpp)
- [Inclusion–Exclusion Principle](Combinatorics/InclusionExclusionPrinciple.cpp)
- [Partition Numbers](Combinatorics/PartitionNumbers.cpp)
- [Stirling Numbers](Combinatorics/StirlingNumbers.cpp)

## Cryptography / 暗号理論
- [ElGamal](Cryptography/ElGamal.ipynb)
- [RSA](Cryptography/RSA.ipynb)
- These implementations are not secure.

## Data Structures / データ構造
- [Segment Tree](DataStructures/SegmentTree)
  - [Range Add Query](DataStructures/SegmentTree/RangeAddQuery.cpp)
  - [Range Minimum Query](DataStructures/SegmentTree/RangeMinimumQuery.cpp)
  - [Range Update Query](DataStructures/SegmentTree/RangeUpdateQuery.cpp)
- [Square Root Decomposition](DataStructures/SquareRootDecomposition)
  - [Range Add Query](DataStructures/SquareRootDecomposition/RangeAddQuery.cpp)
  - [Range Minimum Query](DataStructures/SquareRootDecomposition/RangeAddQuery.cpp)
  - [Range Sum Query](DataStructures/SquareRootDecomposition/RangeSumQuery.cpp)
  - [Range Update Query](DataStructures/SquareRootDecomposition/RangeUpdateQuery.cpp)
  - [RMQ and RUQ](DataStructures/SquareRootDecomposition/RMQandRUQ.cpp)
  - [RSQ and RAQ](DataStructures/SquareRootDecomposition/RSQandRAQ.cpp)
  - [Square Root Decomposition](DataStructures/SquareRootDecomposition/SquareRootDecomposition.cpp)
- [Binary Indexed Tree](DataStructures/BinaryIndexedTree.cpp)
- [Compression](DataStructures/Compression.cpp)
- [k-d Tree](DataStructures/KdTree.cpp)
- [Treap](DataStructures/Treap.cpp)
- [Union–Find](DataStructures/UnionFind.cpp)

## Dynamic Optimization / 動的最適化
- [Digit DP](DynamicOptimization/DigitDP.cpp)
- [Dynamic Optimization](DynamicOptimization/DynamicOptimization.cpp)
- [Largest Rectangle](DynamicOptimization/LargestRectangle.cpp)
- [Largest Square](DynamicOptimization/LargestSquare.cpp)
- [Longest Increasing Subsequance](DynamicOptimization/LongestIncreasingSubsequence.cpp)
- [Traveling Salesman Problem](DynamicOptimization/TravelingSalesmanProblem.cpp)

## Geometry / 幾何学
- [Bounding Sphere](Geometry/BoundingSphere.cpp)
- [Geometry](Geometry/Geometry.cpp)
- [Geometry 3D](Geometry/Geometry3D.cpp)
- [Minimum-Weight Triangulation](Geometry/MinimumWeightTriangulation.cpp)

## Graph Theory / グラフ理論
- [Matching](GraphTheory/Matching)
  - [Bipartite Matching](GraphTheory/Matching/BipartiteMatching.cpp)
  - [Hopcroft–Karp Algorithm](GraphTheory/Matching/HopcroftKarp.cpp)
  - [Lexicographically Bipartite Matching](GraphTheory/Matching/LexicographicallyBipartiteMatching.cpp)
  - [Stable Matching](GraphTheory/Matching/StableMatching.cpp)
- [Shortest Path](GraphTheory/ShortestPath)
  - [0-1 BFS](GraphTheory/ShortestPath/0-1BFS.cpp)
  - [All Pairs Shortest Paths, Warshall–Floyd Algorithm](GraphTheory/ShortestPath/AllPairsShortestPaths.cpp)
  - [BFS](GraphTheory/ShortestPath/BFS.cpp)
  - [Bellman–Ford Algorithm](GraphTheory/ShortestPath/BellmanFord.cpp)
  - [Build DAG](GraphTheory/ShortestPath/BuilldDAG.cpp)
  - [Dijkstra's Algorithm](GraphTheory/ShortestPath/Dijkstra.cpp)
  - [Get Path](GraphTheory/ShortestPath/GetPath.cpp)
- [Tree](GraphTheory/Tree)
  - [Lowest Common Ancestors](GraphTheory/Tree/LowestCommonAncestors.cpp)
  - [Tree](GraphTheory/Tree/Tree.cpp)
- [All Pairs Widest Paths](GraphTheory/AllPairsWidestPaths.cpp)
- [BFS](GraphTheory/BFS.cpp)
- [Bipartite Graph](GraphTheory/BipartiteGraph.cpp)
- [Chromatic Polynomial](GraphTheory/ChromaticPolynomial.cpp)
- [Cycle Detection](GraphTheory/CycleDetection.cpp)
- [DFS](GraphTheory/DFS.cpp)
- [Eulerian Path](GraphTheory/EulerianPath.cpp)
- [Graph](GraphTheory/Graph.cpp)
- [Low-link](GraphTheory/LowLink.cpp)
- [Minimum Spanning Arborescence](GraphTheory/MinimumSpanningArborescence.cpp)
- [Minimum Spanning Tree](GraphTheory/MinimumSpanningTree.cpp)
- [Strongly Connected Components](GraphTheory/StronglyConnectedComponents.cpp)
- [Topological Sort](GraphTheory/TopologicalSort.cpp)

## Linear Algebra / 線形代数学
- [Gauss Elimination](LinearAlgebra/GaussElimination.cpp)
- [Gauss Elimination Modulo A Prime](LinearAlgebra/GaussEliminationMod.cpp)

## Number Theory / 数論
- [Binomial Coefficient](NumberTheory/BinomialCoefficient.cpp)
- [Chinese Remainder Theorem](NumberTheory/ChineseRemainderTheorem.py)
- [Divisors](NumberTheory/Divisors.cpp)
- Extended Euclidean Algorithm ([C++](NumberTheory/ExtendedGCD_Inverse.cpp), [Python3](NumberTheory/ExtendedGCD.py))
- [GCD, LCM](NumberTheory/ExtendedGCD_Inverse.cpp)
- Inverse Element ([C++](NumberTheory/ExtendedGCD_Inverse.cpp), [Python3](NumberTheory/Inverse.py))
- [ModInt](NumberTheory/ModInt.cpp)
- [Modular Arithmetic](NumberTheory/ModularArithmetic.cpp)
- [Number Theory](NumberTheory/NumberTheory.cpp)
- [Primality Test](NumberTheory/PrimalityTest.cpp)
- [Prime](NumberTheory/Prime.cpp)
- [Prime Factorization](NumberTheory/PrimeFactorization.cpp)
- [Quadratic Residue](NumberTheory/QuadraticResidue.cpp)
- [Radix](NumberTheory/Radix.cpp)

## Numerical Analysis / 数値解析
- [Bisection Method](NumericalAnalysis/BisectionMethod.cpp)
- [Cubic Equation](NumericalAnalysis/CubicEquation.cpp)
- [Numerical Analysis](NumericalAnalysis/NumericalAnalysis.cpp)
- [Quadratic Equation](NumericalAnalysis/QuadraticEquation.cpp)

## Quantum / 量子アルゴリズム
- [Adder](Quantum/Adder.ipynb)
- [Bell State](Quantum/BellState.ipynb)
- [Bernstein–Vazirani Algorithm](Quantum/BernsteinVazirani.ipynb)
- [Deutsch's Algorithm](Quantum/Deutsch.ipynb)
- [Deutsch–Jozsa Algorithm](Quantum/DeutschJozsa.ipynb)
- [Entanglement](Quantum/Entanglement.ipynb)
- [GHZ State](Quantum/GHZState.ipynb)
- [n-CNOT](Quantum/n-CNOT.ipynb)
- [Oracle](Quantum/Oracle.ipynb)
- [Plus State, Minus State](Quantum/PlusState_MinusState.ipynb)
- [Simon's Algorithm](Quantum/Simon.ipynb)

## Sort / ソートアルゴリズム
- [Bubble Sort](Sort/BubbleSort.cpp)
- [Counting Sort](Sort/CountingSort.cpp)
- [Insertion Sort](Sort/InsertionSort.cpp)
- [Inversion Number](Sort/InversionNumber.cpp)
- [Merge Sort](Sort/MergeSort.cpp)
- [Quick Sort](Sort/QuickSort.cpp)
- [Sort](Sort/Sort.cpp)

## String / 文字列アルゴリズム
- [Distance](String/Distance.cpp)
- [Fill](String/Fill.cpp)
- [Manacher's Algorithm](String/Manacher.cpp)
- [Morris–Pratt Algorithm](String/MorrisPratt.cpp)
- [Parser](String/Parser.cpp)
- [Replace](String/Replace.cpp)
- [Rolling Hash](String/RollingHash.cpp)
- [Split, Join](String/Split_Join.cpp)
- [Suffix Array](String/SuffixArray.cpp)
- [Z Algorithm](String/ZAlgorithm.cpp)

## Others / その他
- Binary Search ([C++](Others/BinarySearch.cpp), [Python3](Others/BinarySearch.py))
- [Gray Code](Others/GrayCode.py)
- [Number To String](Others/NumberToString.py)
- [Others](Others/Others.cpp)
- [Pop Count](Others/PopCount.cpp)
- [Sliding Windows](Others/SlidingWindows.cpp)
- [String To Number](Others/StringToNumber.py)
- [Sum](Others/Sum.cpp)
- [Ternary Search](Others/TernarySearch.cpp)

## Debug / デバッグ用
デバッグ用のコードとテンプレート