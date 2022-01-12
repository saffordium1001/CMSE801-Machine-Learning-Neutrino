import unittest
import numpy
import pytest

from random import Random
random = Random()

N_CHECKS = 1

@pytest.mark.parametrize('dimension', [2,3])
def test_import(dimension):
    from neutrino import neutrino
    if dimension == 2:
        pt = neutrino.Point2D()
    elif dimension == 3:
        pt = neutrino.Point3D()
    else:
        assert False
