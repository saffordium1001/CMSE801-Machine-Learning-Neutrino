
#ifndef __NEUTRINO_IMPLEMENT_FILTER_EMPTYTENSORFILTER_H__
#define __NEUTRINO_IMPLEMENT_FILTER_EMPTYTENSORFILTER_H__

#include "neutrino_implement/core/processor/ProcessBase.h"
#include "neutrino_implement/core/processor/ProcessFactory.h"
namespace neutrino_implement {

  /**
     \class ProcessBase
     User defined class EmptyTensorFilter ... these comments are used to generate
     doxygen documentation!
  */
  class EmptyTensorFilter : public neutrino_implement::ProcessBase {

  public:

    /// Default constructor
    EmptyTensorFilter(const std::string name="EmptyTensorFilter");

    /// Default destructor
    ~EmptyTensorFilter(){}

    void configure(const neutrino_implement::PSet&);

    void initialize();

    bool process(neutrino_implement::IOManager& mgr);

    void finalize();

  private:
    void configure_labels(const PSet& cfg);
    std::vector<std::string> _tensor3d_producer_v, _tensor2d_producer_v;
    std::vector<size_t>      _min_voxel2d_count_v;
    std::vector<float>       _min_voxel2d_value_v;
    std::vector<size_t>      _min_voxel3d_count_v;
    std::vector<float>       _min_voxel3d_value_v;
  };

  /**
     \class neutrino_implement::EmptyTensorFilterFactory
     \brief A concrete factory class for neutrino_implement::EmptyTensorFilter
  */
  class EmptyTensorFilterProcessFactory : public ProcessFactoryBase {
  public:
    /// ctor
    EmptyTensorFilterProcessFactory() { ProcessFactory::get().add_factory("EmptyTensorFilter",this); }
    /// dtor
    ~EmptyTensorFilterProcessFactory() {}
    /// creation method
    ProcessBase* create(const std::string instance_name) { return new EmptyTensorFilter(instance_name); }
  };

}

#endif
/** @} */ // end of doxygen group
