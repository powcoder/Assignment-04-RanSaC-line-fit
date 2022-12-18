# Assignment 04: RanSaC line fit

## Summary

This assignment continues, and builds from, the work in the previous assignment.
In `Assignment 03 - Problem 1` you have implemented the classes `Point`, `Line`,
and `LineLsq`. In this assignment, you have to reuse those implementations and
add the code for `LineRansac`, a class similar to `LineLsq` in the sense that
it also estimates a 2-dimensional line from a set of 2-dimensional points.

The [RanSaC](https://en.wikipedia.org/wiki/Random_sample_consensus)
(Random Sample Consensus) algorithm differs from a least squares line fit 
in that the former is "robust" to outliers and the latter is not. That means, 
the input set of points may include points which belong to the line, and points
which are not part of this line. For example, points from some other line, 
or maybe just random noise. The RanSaC algorithm, given the correct parameters, 
will succeed on identifying which points actually belong to the line 
(i.e. "inlier points") and which ones do not belong to this line 
(i.e. "outlier points"). Once the inliers have been identified, 
a least squares line fit is used on the inlier points.

In the last assignment, we used C-style arrays to collect our points and
pass them to functions. In this assignment, we will implement our own `Vector`
class using C++ templates, and use it for storing the points and point indices.

As usual, the goal of the assignment is to practice implementing in C++ the
requested functionality and classes, in order to practice the topics covered
in the lectures. In this assignment, we want to implement our own `Vector` 
class from scratch. Please be cautious on using functions, classes, and other 
concepts not covered in the lectures and lecture's materials. When in doubt ask, 
or just implement what you need with simple C++ concepts (e.g. conditionals, 
loops, and basic math).

## Topics

In this assignment we will:
- Practice writing class templates
- Implement a `Vector` class similar to `std::vector`
- Use our `Vector` class for holding points and passing them to functions
- Use the standard library random number generator and distributions
- Implement a robust line fit algorithm

## Grading
The assignment grade is based on automatic testing results, adherence to 
the assignment rules, and specific details of the implemented solution.

A file named `NOTES.txt` is included in this repository. Students may use
this file to write any comment about the assignment and its solution.

In this particular case, 50% of the grade corresponds to the implementation
of the `Vector` class, 45% corresponds to the implementation of `LineRansac`
class, and 5% to the implementation of the `linefit_ransac` program.

## General Instructions
 1. Download the starter code using `git clone <your repository url>`.
 2. Open a command line shell and execute `./build.sh` or `build.bat` to 
 generate the project files using `CMake` and to compile the provided code.
 3. Open any file you want edit with a text editor or C++ development 
 environment (e.g. Visual Studio, Xcode) and add your code to them.
 4. Compile your code again with `./build.sh` or `build.bat`, or using the 
 development environment.
 5. Execute the programs and verify they work as expected based on the 
 specific instructions for each problem.
 6. Repeat steps 3-5 as many times as desired.
 7. Once you are satisfied with the result, save your changes using a 
 `git commit` command. For example `git commit -a -m "Complete assignment"`.
 8. Upload your assignment using `git push`.

 You can use `git commit` and/or `git push` as many times as desired. For 
 instance, to save work in progress.

## Before you start

This assignment continues the work from `Assignment 03 - Problem 1`. In order
to solve this assignment you need working versions of the `Point`, `Line`, and
`LineLsq` classes. You need to take those from your own Assignment 03 solution.

Before you start, go ahead and copy the files:
 - prob1/Point.hpp
 - prob1/Point.cpp
 - prob1/Line.hpp
 - prob1/Line.cpp
 - prob1/LineLsq.hpp
 - prob1/LineLsq.cpp


 and overwrite the versions provided here. 

 Please be careful about not copying `CMakeLists.txt`.

## Problem 1 Part 1: Vector class

Implement a Vector class capable of holding elements of arbitrary types using
C++ templates. A skeleton header file is provided. Specific instructions about
which features this class must support are included in such file.

Once implemented, code like the following must work as expected:


    {
      course::Vector<int> v1;
      v1.push_back(1);
      v1.push_back(2);
      int sum{ 0 };
      for (int i = 0; i < v1.size(); ++i)
      {
        sum += v1[i];
      }
      std::cout "sum = " << sum << std::endl; //displays "sum = 3"
    }

    {
      course::Vector<course::Point> v1;
      v1.push_back({1, 2});
      v1.push_back({3, 4});
      course::Point centroid;
      for (int i = 0; i < v1.size(); ++i)
      {
        centroid = centroid + v1[i];
      }
      centroid = centroid / static_cast<double>(v1.size());
      std::cout "centroid = (" << centroid.x() << ", " << centroid.y() << ")"
        << std::endl; //displays "centroid = (2, 3)"
    }

The complete implementation must be written in the file `prob1/Vector.hpp`. 
Remember that template classes must be completely contained in header files,
as opposed to regular classes that we split in header and source files.

Refer to the slides and material covered in lecture for additional details 
about C++ templates and the vector data structure.

## Problem 1 Part 2: RanSaC line fit

`linefit_ransac` is a command-line application which takes a list of points, 
and estimates the line that best fits them with the RanSaC algorithm. A plot
showing the input points and fitted line is also created. The first two 
arguments to this program are the number of iterations and the inliers distance
threshold. The following arguments are point coordinates.

### Example

    $ ./build/prob1/Release/linefit_ransac.exe 30 0.2 -5 5.1 -3.6 4.98 -3.4 4.95 -1.9 5 -0.6 5 0.4 0.06 0.5 4.94 1.5 0.05 1.8 0.04 2.6 0.05
    NumIter: 30
    DistThreshold: 0.2
    0 Point{x=-5,y=5.1}
    1 Point{x=-3.6,y=4.98}
    2 Point{x=-3.4,y=4.95}
    3 Point{x=-1.9,y=5}
    4 Point{x=-0.6,y=5}
    5 Point{x=0.4,y=0.06}
    6 Point{x=0.5,y=4.94}
    7 Point{x=1.5,y=0.05}
    8 Point{x=1.8,y=0.04}
    9 Point{x=2.6,y=0.05}
    Line{a=0.0169941,b=0.999856,c=-4.95463}
    RMSE 0.0413627
    NumPts 10
    Inliers 6
    Saved: lineplot_ransac.svg

![Example linefit_ransac plot](example-lineplot_ransac.svg "Example linefit_ransac plot")

In the plot, outlier points are shown in red.

### RanSaC algorithm

RanSaC was discussed in lecture, please review that material and make sure you 
understand how the algorithm works prior to starting writing your code.

Implement RanSaC in two parts:
  1. Identify inlier points.
  2. Fit a line to the inlier points with the least squares method.

#### Identify inlier points

Inlier points are those we determine belong to the line. On the contrary,
outlier points are those we determine do not belong to the line. The first
part of the algorithm consists of splitting the input points into inliers 
and outliers.

This part of the algorithm is iterative. We repeat the same process as many
times as specified by the `numIter` argument in the `solve` member function.

At each iteration we do the following:
  1. Pick two points randomly: `p1` and `p2`
  2. Construct a line passing through `p1` and `p2`: `Line line{p1,p2}`
  3. Determine which points are inliers to this candidate line.
     For each point `p` in `points` do:

     a. Compute distance to current candidate line: `dist(line,p)`

     b. If the distance is less than `distThreshold` then this point is an
        inlier. The value of `distThreshold` is an input argument of `solve`.
  4. If this candidate line has more inliers than previous candidate lines, 
     then keep this set of inliers as the current "best" set. Otherwise, 
     abandon this candidate and continue to the next iteration.

After executing all iterations, we have one set of inlier points corresponding
to the best candidate line produced by the random sampling algorithm. The set 
of inliers is the result of this step.

#### Least squares line fit

Take the inlier points produced in the last step and fit a line to them using
the implementation of `LineLsq` from previous assignment. The result line and
corresponding RMSE value are the results of the RanSaC line fit.

#### Random sampling

In order to pick points randomly use a uniform distribution. You can use code
similar to the following:

    std::mt19937 gen{ 12345 };
    std::uniform_int_distribution distrib(0, numPts - 1);

where the number `12345` is the seed of the random number generator and can
replaced by any other number of choice, and `numPts` is the number of input
points.

Then, each time you need to pick a point at random, you can do this:

    int index{ distrib(gen) }; //generates a number in [0, numPts-1]
    const Point& p{ points[index] };

Make sure of selecting two different points each time you need to make a new
line candidate. You can do that in several ways. For instance, generate two 
indices, check if they are different, and discard them and generate new ones 
when they are not.

### Program linefit_ransac

`linefit_ransac` is a command-line program that fits a line using RanSaC and
makes a plot of the line and points. The application takes several arguments
being the first two the parameters `numIter` and `distThreshold` corresponding
to the number of iterations and inlier distance threshold required by RanSaC.
The following arguments are the coordinates of the input points.

    linefit_ransac numIter distThreshold x1 y1 x2 y2 x3 y3 ...

Consider the following:
 - `numIter` is a positive number
 - `distThreshold` is a non-negative floating point number
 - each `(x, y)` pair corresponds to one point
 - at least two different points are required to successfully fit a line
 - the program must display `ERROR` and some error message on error situations.


The program must place the input points in a `Vector` object and call your
own implementation of `LineRansac` to fit a line. On success, display the
line, RMSE, number of inliers and call the function `makePlot` to create
a plot. On failure, display an error message. 
 
The program must always return 0.

Refer to the example execution above for reference of how to call this program
and possible result.

## Assignment requirements

Complete the requested implementations by following both the instructions in
this page and in the source code files.

In this assignment the same conventions as previous ones were used for naming 
files and classes. For instance, the class `LineRansac` is given in the files 
`LineRansac.hpp` and `lineRansac.cpp`.

Use your code to write the implementations and only use standard library 
functions for things that are usually allowed such as math operations. 

For random number generation the standard library should be used. 

## References

- [uniform_int_distribution](https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution)
# Assignment 04 RanSaC line fit代写
# 加微信 powcoder

# [代做各类CS相关课程和程序语言](https://powcoder.com/)

# Programming Help Add Wechat powcoder

# Email: powcoder@163.com

[成功案例](https://powcoder.com/tag/成功案例/)

[java代写](https://powcoder.com/tag/java/) [c/c++代写](https://powcoder.com/tag/c/) [python代写](https://powcoder.com/tag/python/) [drracket代写](https://powcoder.com/tag/drracket/) [MIPS汇编代写](https://powcoder.com/tag/MIPS/) [matlab代写](https://powcoder.com/tag/matlab/) [R语言代写](https://powcoder.com/tag/r/) [javascript代写](https://powcoder.com/tag/javascript/)

[prolog代写](https://powcoder.com/tag/prolog/) [haskell代写](https://powcoder.com/tag/haskell/) [processing代写](https://powcoder.com/tag/processing/) [ruby代写](https://powcoder.com/tag/ruby/) [scheme代写](https://powcoder.com/tag/drracket/) [ocaml代写](https://powcoder.com/tag/ocaml/) [lisp代写](https://powcoder.com/tag/lisp/)

- [数据结构算法 data structure algorithm 代写](https://powcoder.com/category/data-structure-algorithm/)
- [计算机网络 套接字编程 computer network socket programming 代写](https://powcoder.com/category/network-socket/)
- [数据库 DB Database SQL 代写](https://powcoder.com/category/database-db-sql/)
- [机器学习 machine learning 代写](https://powcoder.com/category/machine-learning/)
- [编译器原理 Compiler 代写](https://powcoder.com/category/compiler/)
- [操作系统OS(Operating System) 代写](https://powcoder.com/category/操作系统osoperating-system/)
- [计算机图形学 Computer Graphics opengl webgl 代写](https://powcoder.com/category/computer-graphics-opengl-webgl/)
- [人工智能 AI Artificial Intelligence 代写](https://powcoder.com/category/人工智能-ai-artificial-intelligence/)
- [大数据 Hadoop Map Reduce Spark HBase 代写](https://powcoder.com/category/hadoop-map-reduce-spark-hbase/)
- [系统编程 System programming 代写](https://powcoder.com/category/sys-programming/)
- [网页应用 Web Application 代写](https://powcoder.com/category/web/)
- [自然语言处理 NLP natural language processing 代写](https://powcoder.com/category/nlp/)
- [计算机体系结构 Computer Architecture 代写](https://powcoder.com/category/computer-architecture/)
- [计算机安全密码学computer security cryptography 代写](https://powcoder.com/category/computer-security/)
- [计算机理论 Computation Theory 代写](https://powcoder.com/category/computation-theory/)
- [计算机视觉(Compute Vision) 代写](https://powcoder.com/category/计算机视觉compute-vision/)

# Assignment 04 RanSaC line fit
# 加微信 powcoder

# QQ 1823890830

# Programming Help Add Wechat powcoder

# Email: powcoder@163.com

