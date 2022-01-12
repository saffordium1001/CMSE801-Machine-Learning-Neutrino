import unittest


def test_import_base_full():
    from neutrino import neutrino
    lib = neutrino.logger()
    lib = neutrino.neutrino_base()
    lib = neutrino.PSet("test")
    lib = neutrino.Watch()
    # Config manager is deliberately excluded:
    # lib = base.ConfigManager()
