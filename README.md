

# Neutrino Machine Learning Package - CMSE 801 (Computational Methods)
This was a software framework developed to meet the requirements for the Computational Methods course in Python. The package consists of support for 2D and 3D dataset processing with application program interfaces (API) for deep neural networks. This code was written extensively using predefined header files and functions in C++ with extensive Python supports to wrap up the program. The goal was to develop a generic tool to handle 2D-projected images and 3D-voxelized data produced, sampled, or simulated by high-energy particle experiments. Ideally, this would be suitable for sparse data processing (which I tailored more so to analyzing neutrino events based on hierarchy).

This package was inspired by fellow research colleagues within my research group. They provided useful tutelage in how to develop software packages for use in particle physics based on dependencies on software such as ROOT CERN (used in high-energy physics to deal with big data processing, statistical analysis, visualisation and storage) which is built almost exclusively in C++ but has integration with Python and R (Python was required for the course). For reference to how they implemented packages which utilized dependencies on ROOT CERN, see:

NUISANCE Monte Carlo - software with the goal of providing a coherent framework for comparing neutrino generators to external data and tuning to cross-section parameters. (https://github.com/NUISANCEMC/nuisance)

NuWro  - a Monte Carlo neutrino event generator. (https://github.com/NuWro/nuwro)

GENIE-MC  - an international collaboration of scientists developing a popular suite of products (Generator, Comparisons, Tuning, Reweight) for the neutrino community for simulation, tuning, and comparison (https://github.com/GENIE-MC)

## Process of Installation

### Package Dependencies

Based on some guidance I obtained from textbooks (see sources), from research colleagues, a game plan for what I wanted my small package to do (it needs to function only as an input-output machine learning parser based on datasets), and some software analysis packages combined with some libraries I am familiar with, I moved forward implementing the following based on using the High Performance Computing Cluster (HPCC) and on my own local machine using Linux (Ubuntu subsystem on a Windows partition for my home system) before implementing this on the JupyterHub. My own laptop specifications can be found here:

HP Omen 15 - Specifications (https://support.hp.com/us-en/document/c05411382)

* Python

This was for a course implementing Python, after all. Python constitutes approximately 12.3% of the code, but function as the wrappers. The package is setup and built with a Python script (setup.py), much of the functionality testing and implementation options use Python (i.e. neutrino_writer.py in the neutrino subdirectory is used for writing data as neutrino objects to files), and is used to take in data and return the number of events.

On my own system, I used Python 3.6 while building and testing out my package which didn't give me too much cause for concern. It will take importing the modules within each Python file as need be. The most important module to have is NumPy since most if not all of the calculations depend on it.

* C++

Much of the code is written using C++ for the libraries and headers needed for data analysis. This was an important consideration going forward since ROOT CERN is software based in C++ but can be integrated with the aforementioned Python wrappers. For my compiler, I used gcc on the HPCC. Most of the needed defined libaries and header files take care of the tasks of importing, formatting, analyzing, filtering, and/or modifying image data from the input files.

* ROOT CERN

ROOT CERN is a modular scientific software toolkit. It provides all the functionalities needed to deal with big data processing, statistical analysis, visualization and storage. It is mainly written in C++ but integrated with other languages such as Python and R. ROOT CERN, amongst other things, can:


Save data in a compressed binary form in a ROOT file which are orders of magnitude faster than other file formats.

Mine data using powerful mathematical and statistical tools.

Display results with histograms, scatter plots, fitting functions. ROOT graphics may be adjusted real-time by few mouse clicks. Publication-quality figures can be saved in PDF or other formats.

Run interactively or build your own application (which is why I chose this route).

Use ROOT within other languages (perfect for implementing both Python and C++ without having to learn Cython).

ROOT CERN documentation can be seen here. I am utilizing version 6.16 on both my local machine and on my remote account on the HPCC.

https://root.cern.ch/guides/reference-guide


* SWIG (for the Python bindings)

SWIG (Simplified Wrapper and Interface Generator) is a software development tool that allows the user to connect code and software programs written in C/C++ to a variety of target languages which includes Python. SWIG can be used to create high-level interpreted or compiled programming environments, user interfaces, and as a tool for testing and prototyping C/C++ software which comes in handy for those creating software for scientific computing and analysis. SWIG is typically used to parse the C/C++ interfaces and generate the 'glue code' required for Python to call into the C/C++ code. More information about SWIG can be read here:

http://www.swig.org/Doc3.0/index.html

What proved useful for me as I started to use and implement SWIG for Python can be seen here:

http://www.swig.org/tutorial.html

https://github.com/swig/swig/wiki/FAQ#shared-libraries

On my local machine, I have SWIG Version 3.0.12 compiled with g++ [x86_64-pc-linux-gnu].

* HDF5 (for I/O)

Hierarchical Data Format (HDF) is a set of file formats designed to store and organize large amounts of data in n-dimensions - whether the elements
in those sets are simple objects or complex objects. The '5' in this case corresponds to the version I have implemented.

HDF is a software library that runs on a range of computational platforms and implements a high-level API with C, C++ (utilized here in this case), Fortran 90, and Java interfaces. HDF's high-performance I/O with a rich set of integrated performance features will shave a significant amount of access time and storage space optimizations which is perfect for big data (common in machine learning and for scientific computing). My experience of HDF is, again, through utilizing it as a dependent library for particle simulation software. For more information on HDF, see:

https://portal.hdfgroup.org/display/HDF5/Learning+HDF5

https://bitbucket.hdfgroup.org/pages/HDFFV/hdf5doc/master/browse/html/UG/HDF5_Users_Guide-Responsive%20HTML5/table_of_contents.htm


* CMake (for building the project)

As a part of Kitware's open-source platforms for software development, CMake is an open-source, cross-platform family of tools designed to build, test and package software. This, of course, is a necessary requirement to build packages for scientific simulations and computational methods.

The documentation for CMake can be found here: https://cmake.org/cmake/help/v3.16/

The tutorial guide that assisted with writing my CMake files can be seen here: https://cmake.org/cmake/help/latest/guide/tutorial/index.html


* mpi4py (Message Passing Interface)

MPI is a message-passing system designed to function in parallel computing. The standard defines the syntax and semantics of library routines and allows users to write portable programs in my case the main language, C++. In this case, we are utilizing Python's mpi4py.

Documentation and tutorials on MPI can be found here: https://mpi4py.readthedocs.io/en/stable/intro.html#what-is-mpi

Useful set of tutorials from Lawrence Livermore National Laboratory: https://computing.llnl.gov/tutorials/mpi/

* scikit-build (for installation)

scikit-build is an improved build system generator for CPython C/C++/Fortran/Cython extensions. It facilitates support for additional compilers, build systems, cross compilation, and locating dependencies and their associated build requirements.

For examples of usage, see: https://scikit-build.readthedocs.io/en/latest/usage.html#basic-usage

For advanced tutorials which were more helpful: https://scikit-build.readthedocs.io/en/latest/usage.html#advanced-usage

Installation instructions can be found here: https://scikit-build.readthedocs.io/en/latest/installation.html


* pytest (for continuous integration)

pytest is a Python testing tool for writing and building scalable tests for computer programs in a more 'humanlike' language. pytest is available on Python 3.5+. Installation guide and tutorial can be found here:

https://docs.pytest.org/en/latest/getting-started.html

https://media.readthedocs.org/pdf/pytest/latest/pytest.pdf

### Installing and Updating Packages (on the JupyterHub)

* Python by default is installed on the MSU Engineering JupyterHub notebook server. It is found in the directory: /opt/anaconda3/bin/python

* C++ is also installed by default on the MSU Engineering JupyterHub notebook server. it is found in the directory: /usr/bin/c++

These next steps are all dependent upon having CMake installed on your machine. Thankfully, the HPCC does have CMake.

* Installation of ROOT CERN:

Installing and building ROOT CERN will follow a process that assumes no administrative rights on the machine being used (as is the case for myself and other students). For reference, I used the instructions I used on the HPCC when installing these packages for the first time since there is a very limited amount of space to work with on the JupyterHub notebook server. We will be downloading and building ROOT CERN from the official Github repository which can be found here:

https://github.com/root-project/root

First, let's pull up a new terminal and download the distribution (I am using version 6.16 and I am not sure how well earlier versions will work) using one of these commands (the following instructions will assume you downloaded it from the source page):
```
git clone https://github.com/root-project/root

wget https://root.cern/download/root_v6.16.00.Linux-ubuntu14-x86_64-gcc4.8.tar.gz
```

This should pull the download into the current working directory where you placed it. We can then unzip this into a new folder called 'root' using the command:
```
tar -zxvf root_v6.16.00.Linux-ubuntu14-x86_64-gcc4.8.tar.gz
```
Next, you will want to create a directory for containing your particular build of ROOT CERN. Generally, you should follow these instructions:
```
$ mkdir <builddir>
$ cd <builddir>
```
 Next, execute the cmake command and point to the source folder where the extracted ROOT CERN contents are:

```
 $ cmake path/to/source
```

After CMake has finished running, proceed to use IDE project files or start the build from the build directory:

On Unix systems (with make or ninja) you can speedup the build with cmake --build . -- -jN where N is the number of available cores. I
can use -j8 since my local machine has eight cores.

Setup the environment to run via:
```
$ source /path/to/install-or-build/dir/bin/thisroot.sh
```
Finally, check if it has installed properly by using the command:

```
root
```
You should see a ROOT CERN session initiate.

Advanced setup options can be seen here: https://root.cern.ch/building-root


* Installation of SWIG:

To build SWIG (assuming no administrative rights) using a tarball (version number pending but SWIG 3.0 is compatible with this package so anything above should be fine), first find that tarball on the source page.
```
http://www.swig.org/download.html
```
Follow these steps to make and build:

```
tar -zxf swig-4.0.0.tar.gz
cd swig-4.0.0
./configure && make
```

* Installation of HDF:

Create a working directory for the build of HDF. Uncompress the HDF5 CMake source code file in the working directory (unzip the HDF files into this directory). It will contain a CMake-hdf5-1.10.N directory (where N is the release version).

On Linux, execute:
```
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE:STRING=Release -DBUILD_SHARED_LIBS:BOOL=OFF -DBUILD_TESTING:BOOL=ON -DHDF5_BUILD_TOOLS:BOOL=ON ../hdf5-1.10."X"
```

Build the C library, tools and tests with this command:
```
cmake --build . --config Release
```
Test the C library and tools with this command:
```
ctest . -C Release
```
Create an install image with this command:
```
cpack -C Release CPackConfig.cmake
```

On Linux, change to the install destination directory (create if doesn't exist) and execute:
```
<path-to>/myhdfstuff/build/HDF5-1.10."X"-Linux.sh
```
After accepting the license, the script will prompt:
```
By default the HDF5 will be installed in:
    "<current directory>/HDF5-1.10."X"-Linux"
    Do you want to include the subdirectory HDF5-1.10."X"-Linux?
    Saying no will install in: "<current directory>" [Y/N]
```

* Installation of scikit-build:

To install scikit-build based on the latest build and using pip install, you would execute:

```
$ git clone https://github.com/scikit-build/scikit-build
$ cd scikit-build
```
or utilize:


then install with (one of two options):

```
$ pip install .
$ pip install -e .
```

* Installation of mpi4py:

To install from source, the following command with wget will grab that particular version number:

```
wget https://bitbucket.org/mpi4py/mpi4py/downloads/mpi4py-X.Y.tar.gz
```
Now, unzip and cd into the created directory:

```
$ tar -zxf mpi4py-X.Y.tar.gz
$ cd mpi4py-X.Y
```

Without root privileges or you want to install MPI for Python for your private use, just do:

```
$ python setup.py install --user
```

* Installation of pytest:

This one was a bit simpler on my machine.
```
pip install -U pytest
```

### Setup

I wanted to make setting up the package as easy as possible. First, cd into the project directory. At the highest level, you should see the 'setup.py' script. To run that script and by extension build and install the package, you can follow the directions below:

```
python setup.py build [-jN] (N corresponds to the number of cores you can use)
python setup.py install --user (needed user aspect since Python 3 library gave me issues)
```
Hopefully, if all dependencies are in place, this should be an easy task.
