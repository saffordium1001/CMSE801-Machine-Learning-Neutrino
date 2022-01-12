import unittest

def test_fake():
    import os
    print(os.environ)
    import neutrino
    print(os.environ)
    return False

def test_import():
    import neutrino
    from neutrino import neutrino
