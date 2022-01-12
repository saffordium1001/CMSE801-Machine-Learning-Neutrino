
#ifndef __NEUTRINO_IMPLEMENT_FILTER_PARTICLECOUNTFILTER_H__
#define __NEUTRINO_IMPLEMENT_FILTER_PARTICLECOUNTFILTER_H__

#include "neutrino_implement/core/processor/ProcessBase.h"
#include "neutrino_implement/core/processor/ProcessFactory.h"
namespace neutrino_implement {

  /**
     \class ProcessBase
     User defined class ParticleCountFilter ... these comments are used to generate
     doxygen documentation!
  */
  class ParticleCountFilter : public ProcessBase {

  public:

    /// Default constructor
    ParticleCountFilter(const std::string name="ParticleCountFilter");

    /// Default destructor
    ~ParticleCountFilter(){}

    void configure(const neutrino_implement::PSet&);

    void initialize();

    bool process(neutrino_implement::IOManager& mgr);

    void finalize();

  private:

    std::string _part_producer;
    size_t _max_part_count;
    size_t _min_part_count;
    std::vector<size_t> _part_count_v;
  };

  /**
     \class neutrino_implement::ParticleCountFilterFactory
     \brief A concrete factory class for neutrino_implement::ParticleCountFilter
  */
  class ParticleCountFilterProcessFactory : public ProcessFactoryBase {
  public:
    /// ctor
    ParticleCountFilterProcessFactory() { ProcessFactory::get().add_factory("ParticleCountFilter",this); }
    /// dtor
    ~ParticleCountFilterProcessFactory() {}
    /// creation method
    ProcessBase* create(const std::string instance_name) { return new ParticleCountFilter(instance_name); }
  };

}

#endif
/** @} */ // end of doxygen group
