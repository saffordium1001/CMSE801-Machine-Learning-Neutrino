import unittest
from neutrino import neutrino

from random import Random
random = Random()

def test_import_BatchDataStorageFloat_h():

    neutrino.BatchDataStorageFactoryFloat()
    neutrino.BatchDataStorageFloat()
    neutrino.BatchDataFloat()
