import unittest



def test_neut():
    from neutrino import neutrino
    lib = neutrino.neut()
    # Config manager is deliberately excluded:
    # lib = base.ConfigManager()

def test_neut_exception():
    from neutrino import neutrino
    # Creating a PSet object without a name will cause an exception.
    # We can catch that and verify we're getting a neut exception:
    try:
        pset = neutrino.PSet()
        return False
    except:
        return True
