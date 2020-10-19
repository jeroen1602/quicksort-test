# Quicksort in c++

This is part of a project for testing the speed of quicksort between java and c++.
This is the c++ part.

## Building

This project uses cmake as a build system. Before you start make sure you have cmake installed and any c++ compiler. This project uses C++17 so make sure your compiler is compatible with this version.

First make sure you're in the `sort-cpp` folder

```bash
cd sort-cpp
```

After that create a build folder and cd into it.

```bash
mkdir build
cd build
```

Now create the cmake files. To get the best speed make sure that you use the `Release` version for the best case scenario.

```bash
cmake ../ -DCMAKE_BIULD_TYPE=Release
```

Now just make the project

```bash
make
```

This should generate an executable named `sort_cpp`.

## Running the test

To run the test make sure the pc is not busy with other work to give the test the best possible scenario.

To run the test just run the newly created executable. (make sure you're still in the build folder.)

```bash
./sort_cpp
```

Now wait for the tests to finish, there should be a percentage in the terminal for the current test.

After the tests are done there should be a few csv files with the test results.
