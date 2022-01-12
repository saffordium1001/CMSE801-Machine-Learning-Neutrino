#Makes Python treat this directory as a Python package directory (i..e, this makes it treat neutrino as a module)

#from . import neutrino

import os

def get_includes(): #gets all of the header files in this folder and the usr/include directory for C compilers
    return os.path.dirname(__file__) + "/include/"

def get_lib_dir(): #gets all of the shared objects (.so) on the system (needed for ROOT, Python, etc.)
    return os.path.dirname(__file__) + "/lib/"
