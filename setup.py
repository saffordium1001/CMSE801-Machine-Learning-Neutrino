from skbuild import setup  # This line replaces 'from setuptools import setup'
import argparse

#import the operatins system, input/output, etc.
from os import path
import io 
#grab the absolute path to the download for the software package (advised to extract this package to its own directory)
this_directory = path.abspath(path.dirname(__file__))
with io.open(path.join(this_directory, 'README.md'), encoding='utf-8') as f:
    long_description = f.read()


#setup parameters - this describes the package name, package number, where the directory is to make the package (I defaulted to the source directory since that is where the CMake files are and where most of the work will be happening, etc.)
setup(
    name="Neutrino Machine Learning", #named arbitrarily based on what I wanted to model
    version="0.5.0", #yeah - I didn't intend for this to be a public release. I simply by coding came to version 0.5.0
    cmake_source_dir='src/',
    cmake_args=[
        '-DCMAKE_OSX_DEPLOYMENT_TARGET:STRING=10.9',
        '-DCMAKE_NO_SWIG=False', 
        '-DMPI:BOOL=OFF',
        '-DOPENMP:BOOL=OFF',
    ],
    include_package_data=True,
    author=['Twymun K. Safford'], #include the author name here
    description=['C++ I/O and Preprocessing package for parsing neutrino data, implementing a machine learning algorithm'], #short description - what you see is what you get
    scripts=['bin/merge_neutrino_implement_files.py', 'bin/run_processor.py'], #if you want to run your own data, use these scripts to 
    packages=['neutrino'], #default name of the highest directory package
    install_requires=[
        'numpy', #requires these packages from Python by default
        'scikit-build',
    ],
    long_description=long_description,
    long_description_content_type='text/markdown',
)
