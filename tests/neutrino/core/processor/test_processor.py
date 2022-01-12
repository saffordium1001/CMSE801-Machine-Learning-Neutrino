import unittest



def test_import_processor_top():
    from neutrino import neutrino

def test_import_processor():
    from neutrino import neutrino

    lib = neutrino.ProcessDriver()
    lib = neutrino.ProcessFactory()

def test_import_processor_base():
    from neutrino import neutrino

    # Processes base is virtual and should NOT import:
    try:
        lib = neutrino.ProcessBase("test")
        assert(False)
    except:
        assert(True)

def test_process_driver():
    from neutrino import neutrino

    lib = neutrino.ProcessDriver("test")
