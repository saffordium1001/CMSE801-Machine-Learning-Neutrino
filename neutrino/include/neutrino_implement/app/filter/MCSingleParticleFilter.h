
#ifndef __NEUTRINO_IMPLEMENT_FILTER_MCSINGLEPARTICLEFILTER_H__
#define __NEUTRINO_IMPLEMENT_FILTER_MCSINGLEPARTICLEFILTER_H__

#include "neutrino_implement/core/processor/ProcessBase.h"
#include "neutrino_implement/core/processor/ProcessFactory.h"
namespace neutrino_implement {

  /**
     \class ProcessBase
     User defined class MCSingleParticleFilter ... these comments are used to generate
     doxygen documentation!
  */
  class MCSingleParticleFilter : public ProcessBase {

  public:

    /// Default constructor
    MCSingleParticleFilter(const std::string name="MCSingleParticleFilter");

    /// Default destructor
    ~MCSingleParticleFilter(){}

    void configure(const neutrino_implement::PSet&);

    void initialize();

    bool process(neutrino_implement::IOManager& mgr);

    void finalize();

  private:

    std::string _part_producer;
    double _shower_min_energy;
    double _track_min_energy;
    double _proton_min_energy;
  };

  /**
     \class neutrino_implement::MCSingleParticleFilterFactory
     \brief A concrete factory class for neutrino_implement::MCSingleParticleFilter
  */
  class MCSingleParticleFilterProcessFactory : public ProcessFactoryBase {
  public:
    /// ctor
    MCSingleParticleFilterProcessFactory() { ProcessFactory::get().add_factory("MCSingleParticleFilter",this); }
    /// dtor
    ~MCSingleParticleFilterProcessFactory() {}
    /// creation method
    ProcessBase* create(const std::string instance_name) { return new MCSingleParticleFilter(instance_name); }
  };

}

#endif
/** @} */ // end of doxygen group
