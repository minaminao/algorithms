# Algorithms and Data Structures
Implementations of algorithms and data structures, code snippets, etc. These algorithms and data structures can be used for everyday programming and competitive programming.
The implementation of the algorithms in Rust language has been moved to [minaminao/algo-rs](https://github.com/minaminao/algo-rs).

If you getting the message "Sorry, something went wrong. Reload?" when viewing a Jupyter notebook, try to see [nbviewer](https://nbviewer.jupyter.org/github/minaminao/algorithms/tree/master/).

## Combinatorics
| Algorithm                     | Implementation                                       | Note |
| ----------------------------- | ---------------------------------------------------- | ---- |
| Combinatorics                 | [C++](Combinatorics/Combinatorics.cpp)               |      |
| Factorial                     | [C++](Combinatorics/Factorial.cpp)                   |      |
| Inclusion–Exclusion Principle | [C++](Combinatorics/InclusionExclusionPrinciple.cpp) |      |
| Montmort Numbers              | [C++](Combinatorics/MontmortNumbers.cpp)             |      |
| Number of Subsequences        | [C++](Combinatorics/NumberOfSubsequences.cpp)        |      |
| Partition Numbers             | [C++](Combinatorics/PartitionNumbers.cpp)            |      |
| Stirling Numbers              | [C++](Combinatorics/StirlingNumbers.cpp)             |      |

## Cryptography 
*These implementations are not secure.*

| Algorithm | Implementation                    | Note |
| --------- | --------------------------------- | ---- |
| ElGamal   | [C++](Cryptography/ElGamal.ipynb) |      |
| RSA       | [C++](Cryptography/RSA.ipynb)     |      |

## Data Structures 
| Algorithm                   | Implementation                                                                           | Note |
| --------------------------- | ---------------------------------------------------------------------------------------- | ---- |
| Segment Tree                |                                                                                          |      |
| - Range Add Query           | [C++](DataStructures/SegmentTree/RangeAddQuery.cpp)                                      |      |
| - Range Minimum Query       | [C++](DataStructures/SegmentTree/RangeMinimumQuery.cpp)                                  |      |
| - Range Update Query        | [C++](DataStructures/SegmentTree/RangeUpdateQuery.cpp)                                   |      |
| Square Root Decomposition   |                                                                                          |      |
| - Range Add Query           | [C++](DataStructures/SquareRootDecomposition/RangeAddQuery.cpp)                          |      |
| - Range Minimum Query       | [C++](DataStructures/SquareRootDecomposition/RangeAddQuery.cpp)                          |      |
| - Range Sum Query           | [C++](DataStructures/SquareRootDecomposition/RangeSumQuery.cpp)                          |      |
| - Range Update Query        | [C++](DataStructures/SquareRootDecomposition/RangeUpdateQuery.cpp)                       |      |
| - RMQ and RUQ               | [C++](DataStructures/SquareRootDecomposition/RMQandRUQ.cpp)                              |      |
| - RSQ and RAQ               | [C++](DataStructures/SquareRootDecomposition/RSQandRAQ.cpp)                              |      |
| - Square Root Decomposition | [C++](DataStructures/SquareRootDecomposition/SquareRootDecomposition.cpp)                |      |
| Binary Heap                 | [C++](DataStructures/BinaryHeap.cpp)                                                     |      |
| Binary Indexed Tree         | [C++](DataStructures/BinaryIndexedTree.cpp), [Rust](DataStructures/BinaryIndexedTree.rs) |      |
| Compression                 | [C++](DataStructures/Compression.cpp)                                                    |      |
| k-d Tree                    | [C++](DataStructures/KdTree.cpp)                                                         |      |
| Leftist Heap                | [C++](DataStructures/LeftistHeap.cpp)                                                    |      |
| Sparse Table                | [C++](DataStructures/SparseTable.cpp)                                                    |      |
| Treap                       | [C++](DataStructures/Treap.cpp)                                                          |      |
| Union–Find                  | [C++](DataStructures/UnionFind.cpp), [Rust](DataStructures/UnionFind.rs)                 |      |

## Dynamic Optimization
| Algorithm                      | Implementation                                              | Note |
| ------------------------------ | ----------------------------------------------------------- | ---- |
| Digit DP                       | [C++](DynamicOptimization/DigitDP.cpp)                      |      |
| Dynamic Optimization           | [C++](DynamicOptimization/DynamicOptimization.cpp)          |      |
| Game Theory                    | [C++](DynamicOptimization/GameTheory.cpp)                   |      |
| Largest Rectangle              | [C++](DynamicOptimization/LargestRectangle.cpp)             |      |
| Largest Square                 | [C++](DynamicOptimization/LargestSquare.cpp)                |      |
| Longest Increasing Subsequance | [C++](DynamicOptimization/LongestIncreasingSubsequence.cpp) |      |
| Matrix Chain Multiplication    | [C++](DynamicOptimization/MatrixChainMultiplication.cpp)    |      |
| Traveling Salesman Problem     | [C++](DynamicOptimization/TravelingSalesmanProblem.cpp)     |      |

## Geometry
| Algorithm                    | Implementation                                 | Note |
| ---------------------------- | ---------------------------------------------- | ---- |
| Bounding Sphere              | [C++](Geometry/BoundingSphere.cpp)             |      |
| Geometry                     | [C++](Geometry/Geometry.cpp)                   |      |
| Geometry 3D                  | [C++](Geometry/Geometry3D.cpp)                 |      |
| Minimum-Weight Triangulation | [C++](Geometry/MinimumWeightTriangulation.cpp) |      |

## Graph Theory 
| Algorithm                              | Implementation                                                     | Note |
| -------------------------------------- | ------------------------------------------------------------------ | ---- |
| Matching                               |                                                                    |      |
| - Bipartite Matching                   | [C++](GraphTheory/Matching/BipartiteMatching.cpp)                  |      |
| - Hopcroft–Karp Algorithm              | [C++](GraphTheory/Matching/HopcroftKarp.cpp)                       |      |
| - Lexicographically Bipartite Matching | [C++](GraphTheory/Matching/LexicographicallyBipartiteMatching.cpp) |      |
| - Stable Matching                      | [C++](GraphTheory/Matching/StableMatching.cpp)                     |      |
| Shortest Path                          |                                                                    |      |
| - 0-1 BFS                              | [C++](GraphTheory/ShortestPath/0-1BFS.cpp)                         |      |
| - All Pairs Shortest Paths             | [C++](GraphTheory/ShortestPath/AllPairsShortestPaths.cpp)          |      |
| - BFS                                  | [C++](GraphTheory/ShortestPath/BFS.cpp)                            |      |
| - Bellman–Ford Algorithm               | [C++](GraphTheory/ShortestPath/BellmanFord.cpp)                    |      |
| - Build DAG                            | [C++](GraphTheory/ShortestPath/BuilldDAG.cpp)                      |      |
| - Dijkstra's Algorithm                 | [C++](GraphTheory/ShortestPath/Dijkstra.cpp)                       |      |
| - Get Path                             | [C++](GraphTheory/ShortestPath/GetPath.cpp)                        |      |
| Tree                                   |                                                                    |      |
| - Lowest Common Ancestors              | [C++](GraphTheory/Tree/LowestCommonAncestors.cpp)                  |      |
| - Tree                                 | [C++](GraphTheory/Tree/Tree.cpp)                                   |      |
| All Pairs Widest Paths                 | [C++](GraphTheory/AllPairsWidestPaths.cpp)                         |      |
| BFS                                    | [C++](GraphTheory/BFS.cpp)                                         |      |
| Bipartite Graph                        | [C++](GraphTheory/BipartiteGraph.cpp)                              |      |
| Chromatic Polynomial                   | [C++](GraphTheory/ChromaticPolynomial.cpp)                         |      |
| Cycle Detection                        | [C++](GraphTheory/CycleDetection.cpp)                              |      |
| Diameter                               | [C++](GraphTheory/Diameter.cpp)                                    |      |
| DFS                                    | [C++](GraphTheory/DFS.cpp)                                         |      |
| Eulerian Path                          | [C++](GraphTheory/EulerianPath.cpp)                                |      |
| Graph                                  | [C++](GraphTheory/Graph.cpp)                                       |      |
| Low-link                               | [C++](GraphTheory/LowLink.cpp)                                     |      |
| Minimum Spanning Arborescence          | [C++](GraphTheory/MinimumSpanningArborescence.cpp)                 |      |
| Minimum Spanning Tree                  | [C++](GraphTheory/MinimumSpanningTree.cpp)                         |      |
| Strongly Connected Components          | [C++](GraphTheory/StronglyConnectedComponents.cpp)                 |      |
| Topological Sort                       | [C++](GraphTheory/TopologicalSort.cpp)                             |      |

## Greedy 
| Algorithm                  | Implementation                             | Note |
| -------------------------- | ------------------------------------------ | ---- |
| Activity Selection Problem | [C++](Greedy/ActivitySelectionProblem.cpp) |      |

## Linear Algebra 
| Algorithm                        | Implementation                               | Note |
| -------------------------------- | -------------------------------------------- | ---- |
| Gauss Elimination                | [C++](LinearAlgebra/GaussElimination.cpp)    |      |
| Gauss Elimination Modulo A Prime | [C++](LinearAlgebra/GaussEliminationMod.cpp) |      |
| Gram–Schmidt Process             | [C++](LinearAlgebra/GramSchmidtProcess.cpp)  |      |
| Matrix                           | [C++](LinearAlgebra/Matrix.cpp)              |      |

## Machine Learning 
| Algorithm     | Implementation                         | Note |
| ------------- | -------------------------------------- | ---- |
| Least Squares | [C++](MachineLearning/LeastSquares.py) |      |

## Number Theory 
| Algorithm                                | Implementation                                                                                      | Note |
| ---------------------------------------- | --------------------------------------------------------------------------------------------------- | ---- |
| Bernoulli Numbers                        | [C++](NumberTheory/BernoulliNumbers.cpp)                                                            |      |
| Binomial Coefficient                     | [C++](NumberTheory/BinomialCoefficient.cpp)                                                         |      |
| Chinese Remainder Theorem                | [C++](NumberTheory/ChineseRemainderTheorem.cpp), [Python3](NumberTheory/ChineseRemainderTheorem.py) |      |
| Divisors                                 | [C++](NumberTheory/Divisors.cpp)                                                                    |      |
| Extended Euclidean Algorithm             | [C++](NumberTheory/ExtendedGCD_Inverse.cpp), [Python3](NumberTheory/ExtendedGCD.py)                 |      |
| Euler's Totient Function                 | [C++](NumberTheory/EulerTotientFunction.cpp)                                                        |      |
| GCD, LCM                                 | [C++](NumberTheory/ExtendedGCD_Inverse.cpp), [Rust](NumberTheory/GCD_LCM.rs)                        |      |
| Inverse Element                          | [C++](NumberTheory/ExtendedGCD_Inverse.cpp), [Python3](NumberTheory/Inverse.py)                     |      |
| Legendre's Formula                       | [C++](NumberTheory/LegendreFormula.cpp)                                                             |      |
| Log Factorial (Stirling's Approximation) | [C++](NumberTheory/LogFactorial.cpp)                                                                |      |
| ModInt                                   | [C++](NumberTheory/ModInt.cpp)                                                                      |      |
| Modular Arithmetic                       | [C++](NumberTheory/ModularArithmetic.cpp)                                                           |      |
| Number Theory                            | [C++](NumberTheory/NumberTheory.cpp)                                                                |      |
| Polynomial                               | [C++](NumericalAnalysis/Polynomial.cpp)                                                             |      |
| Primality Test                           | [C++](NumberTheory/PrimalityTest.cpp)                                                               |      |
| Prime                                    | [C++](NumberTheory/Prime.cpp)                                                                       |      |
| Prime Factorization                      | [C++](NumberTheory/PrimeFactorization.cpp)                                                          |      |
| Quadratic Residue                        | [C++](NumberTheory/QuadraticResidue.cpp)                                                            |      |
| Radix                                    | [C++](NumberTheory/Radix.cpp)                                                                       |      |
| Sum Of Powers                            | [C++](NumberTheory/SumOfPowers.cpp)                                                                 |      |

## Numerical Analysis
| Algorithm              | Implementation                                     | Note |
| ---------------------- | -------------------------------------------------- | ---- |
| Bisection Method       | [C++](NumericalAnalysis/BisectionMethod.cpp)       |      |
| Cubic Equation         | [C++](NumericalAnalysis/CubicEquation.cpp)         |      |
| Lagrange Interpolation | [C++](NumericalAnalysis/LagrangeInterpolation.cpp) |      |
| Numerical Analysis     | [C++](NumericalAnalysis/NumericalAnalysis.cpp)     |      |
| Quadratic Equation     | [C++](NumericalAnalysis/QuadraticEquation.cpp)     |      |

## Quantum 
| Algorithm                    | Implementation                            | Note |
| ---------------------------- | ----------------------------------------- | ---- |
| Adder                        | [C++](Quantum/Adder.ipynb)                |      |
| Bell State                   | [C++](Quantum/BellState.ipynb)            |      |
| Bernstein–Vazirani Algorithm | [C++](Quantum/BernsteinVazirani.ipynb)    |      |
| Deutsch's Algorithm          | [C++](Quantum/Deutsch.ipynb)              |      |
| Deutsch–Jozsa Algorithm      | [C++](Quantum/DeutschJozsa.ipynb)         |      |
| Entanglement                 | [C++](Quantum/Entanglement.ipynb)         |      |
| GHZ State                    | [C++](Quantum/GHZState.ipynb)             |      |
| n-CNOT                       | [C++](Quantum/n-CNOT.ipynb)               |      |
| Oracle                       | [C++](Quantum/Oracle.ipynb)               |      |
| Plus State, Minus State      | [C++](Quantum/PlusState_MinusState.ipynb) |      |
| Simon's Algorithm            | [C++](Quantum/Simon.ipynb)                |      |

## Signal Processing
| Algorithm              | Implementation                                   | Note |
| ---------------------- | ------------------------------------------------ | ---- |
| Fast Fourier Transform | [C++](SignalProcessing/FastFourierTransform.cpp) |      |

## Sort
| Algorithm                | Implementation                       | Note |
| ------------------------ | ------------------------------------ | ---- |
| Bubble Sort              | [C++](Sort/BubbleSort.cpp)           |      |
| Counting Sort            | [C++](Sort/CountingSort.cpp)         |      |
| Insertion Sort           | [C++](Sort/InsertionSort.cpp)        |      |
| Inversion Number         | [C++](Sort/InversionNumber.cpp)      |      |
| Merge Sort               | [C++](Sort/MergeSort.cpp)            |      |
| Minimum Cost Sort        | [C++](Sort/MinimumCostSort.cpp)      |      |
| Minimum Numbers Of Swaps | [C++](Sort/MinimumNumbersOfSwap.cpp) |      |
| Quick Sort               | [C++](Sort/QuickSort.cpp)            |      |
| Sort                     | [C++](Sort/Sort.cpp)                 |      |

## String 
| Algorithm              | Implementation                                            | Note |
| ---------------------- | --------------------------------------------------------- | ---- |
| Distance               | [C++](String/Distance.cpp), [Python3](String/Distance.py) |      |
| Fill                   | [C++](String/Fill.cpp)                                    |      |
| Manacher's Algorithm   | [C++](String/Manacher.cpp)                                |      |
| Morris–Pratt Algorithm | [C++](String/MorrisPratt.cpp)                             |      |
| Parser                 | [C++](String/Parser.cpp)                                  |      |
| Replace                | [C++](String/Replace.cpp)                                 |      |
| Rolling Hash           | [C++](String/RollingHash.cpp)                             |      |
| Split, Join            | [C++](String/Split_Join.cpp)                              |      |
| Suffix Array           | [C++](String/SuffixArray.cpp)                             |      |
| Z Algorithm            | [C++](String/ZAlgorithm.cpp)                              |      |

## Others
| Algorithm           | Implementation                                                    | Note |
| ------------------- | ----------------------------------------------------------------- | ---- |
| Binary Search       | [C++](Others/BinarySearch.cpp), [Python3](Others/BinarySearch.py) |      |
| Gray Code           | [C++](Others/GrayCode.py)                                         |      |
| Interactive Problem | [C++](Others/InteractiveProblem.cpp)                              |      |
| Normal Distribution | [C++](Others/NormalDistribution.js)                               |      |
| Number To String    | [C++](Others/NumberToString.py)                                   |      |
| Number To Words     | [C++](Others/NumberToWords.py)                                    |      |
| Others              | [C++](Others/Others.cpp)                                          |      |
| Pop Count           | [C++](Others/PopCount.cpp)                                        |      |
| Sliding Windows     | [C++](Others/SlidingWindows.cpp)                                  |      |
| String To Number    | [C++](Others/StringToNumber.py)                                   |      |
| Sum                 | [C++](Others/Sum.cpp)                                             |      |
| Ternary Search      | [C++](Others/TernarySearch.cpp)                                   |      |

