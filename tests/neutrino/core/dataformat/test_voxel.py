import unittest
from neutrino import neutrino

# Testing Voxel objects:
def test_Voxel_h_Voxel():
    vox1 = neutrino.Voxel()
    vox2 = neutrino.Voxel(0, 0.0)
    vox3 = neutrino.Voxel(10,50.0)

    assert(vox1.id() == neutrino.kINVALID_VOXELID)
    assert(vox2.id() == 0)
    assert(vox3.id() == 10)


    assert(vox1.value() == neutrino.kINVALID_FLOAT)
    assert(vox2.value() == 0.0)
    assert(vox3.value() == 50.)

def test_Voxel_h_VoxelSet():

    vs = neutrino.VoxelSet()

    n_voxels = 10
    for i in range(n_voxels):
        vs.emplace(i, i, False)

    vec = vs.as_vector()

    assert(vec.size() == n_voxels)
    vs.clear_data()

    n_voxels = 11
    for j in range(n_voxels):
        vs.emplace(neutrino.Voxel(i+j, i+j), True)
    assert(vec.size() == n_voxels)



def test_Voxel_h_VoxelSetArray():

    vsa = neutrino.VoxelSetArray()

    n_voxel_sets = 3
    for i in range(n_voxel_sets):
        n_voxels = 10*(i+1)
        vs = neutrino.VoxelSet()
        vs.id(i)
        for j in range(n_voxels):
            vs.emplace(j, j, False)

        vsa.emplace(vs)

    assert(vsa.size() == n_voxel_sets)
    assert(vsa.sum() > 0)
