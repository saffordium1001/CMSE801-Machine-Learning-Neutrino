import unittest

from neutrino import neutrino

from random import Random
random = Random()


# Testing import of Point.h objects:
def test_import_Point_h():
    pt = neutrino.Point2D()
    pt = neutrino.Point3D()

def test_import_BBox_h():
    bb = neutrino.BBox2D()
    bb = neutrino.BBox3D()


# Testing import of Vertex.h objects:
def test_import_Vertex_h():
    vert1 = neutrino.Vertex()
    vert2 = neutrino.Vertex(1,2,3,4)
    assert(vert1 != vert2)
    assert(vert1 < vert2)
    vert2.reset()
    assert(vert1 == vert2)

# Testing import of Particle.h objects:
def test_import_Particle_h():
    part1 = neutrino.Particle()

# Testing import of Voxel.h objects:
def test_import_Voxel_h_Voxel():

    v = neutrino.Voxel()

def test_import_Voxel_h_VoxelSet():

    vs = neutrino.VoxelSet()

def test_import_Voxel_h_VoxelSetArray():

    vsa = neutrino.VoxelSetArray()

def test_import_ImageMeta_h():

    im = neutrino.ImageMeta2D()
    im = neutrino.ImageMeta3D()

def test_import_EventID_h():

    im = neutrino.EventID()

# Event Base is abstract and therefore should NOT import:
def test_import_EventBase_h():

    try:
        eb = neutrino.EventBase()
        assert(False)
    except:
        assert(True)

def test_import_DataProductFactory_h():
    # dfb = neutrino.DataProductFactoryBase()
    df = neutrino.DataProductFactory()

def test_import_IOManager_h():
    io = neutrino.IOManager()

def test_import_EventParticle_h():
    ep = neutrino.EventParticle()


def test_vector_double():
    vec = neutrino.VectorOfDouble()
    vec.push_back(random.uniform(-1e5, 1e5))

def test_vector_sizet():
    vec = neutrino.VectorOfSizet()
    vec.push_back(random.randint(1, 2e4))
