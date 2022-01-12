
#ifndef __PARENTPARTICLESEG_H__
#define __PARENTPARTICLESEG_H__

#include "neutrino_implement/core/processor/ProcessBase.h"
#include "neutrino_implement/core/processor/ProcessFactory.h"
#include "neutrino_implement/core/dataformat/Tensor.h"
#include "neutrino_implement/core/dataformat/Particle.h"
#include "neutrino_implement/core/dataformat/Voxel.h"

namespace neutrino_implement {

/**
   \class ProcessBase
   User defined class ParentParticleSeg ... these comments are
   used to generate
   doxygen documentation!
*/

struct particle_node{
  int trackID;
  int parentID;
  int ancestorID;
  bool primary;
  const Particle * reference;
  particle_node * parent;
  std::vector<const particle_node *> daughters;
};

class ParentParticleSeg : public ProcessBase {
 public:
  /// Default constructor
  ParentParticleSeg(
      const std::string name = "ParentParticleSeg");

  /// Default destructor
  ~ParentParticleSeg() {}

  void configure(const PSet&);

  void initialize();

  bool process(IOManager& mgr);

  void finalize();

  neutrino_implement::VoxelSet cluster_merger(const neutrino_implement::SparseCluster2D & clusters,
                                 particle_node * primary_node);

  neutrino_implement::VoxelSet cluster_merger(const neutrino_implement::SparseCluster3D & clusters,
                                 particle_node * primary_node);
 private:

  void get_all_daughter_ids(std::vector<int> & ids, const particle_node * node);


  std::string _cluster3d_producer;
  std::string _cluster2d_producer;
  std::string _output_producer;
  std::string _particle_producer;

};

/**
   \class neutrino_implement::ParentParticleSegFactory
   \brief A concrete factory class for neutrino_implement::ParentParticleSeg
*/
class ParentParticleSegProcessFactory
    : public ProcessFactoryBase {
 public:
  /// ctor
  ParentParticleSegProcessFactory() {
    ProcessFactory::get().add_factory("ParentParticleSeg",
                                      this);
  }
  /// dtor
  ~ParentParticleSegProcessFactory() {}
  /// creation method
  ProcessBase* create(const std::string instance_name) {
    return new ParentParticleSeg(instance_name);
  }
};
}

#endif
/** @} */  // end of doxygen group
